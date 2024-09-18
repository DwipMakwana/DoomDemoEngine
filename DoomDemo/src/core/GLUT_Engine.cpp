#define _USE_MATH_DEFINES

#include <cmath>
#include <math.h>
#include <GL/glut.h>
#include <ft2build.h>
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <string>

#include FT_FREETYPE_H

#include "include/core/GLUT_Engine.h"
#include "include/util/TextureLoader.h"

TextureLoader* texLoader = new TextureLoader();
FT_Library ft;
FT_Face face;

void DrawPixel(int x, int y, int r, int g, int b)                  //Draw a pixel at x/y with rgb
{
    glColor3ub(r, g, b);
    glBegin(GL_POINTS);
    glVertex2i(x * pixelScale + 2, y * pixelScale + 2);
    glEnd();
}

void DrawCustomText(const char* text, float x, float y, float r, float g, float b, int size) 
{
    const char* p;
    FT_GlyphSlot glyph = face->glyph;

    // Set text color
    glColor3f(r, g, b); 
    // Set text size
    FT_Set_Pixel_Sizes(face, 0, size); 

    for (p = text; *p; p++) {
        if (FT_Load_Char(face, *p, FT_LOAD_RENDER)) {
            continue;
        }

        // Create a texture from the glyph bitmap
        GLuint textureID;
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RGBA,
            glyph->bitmap.width,
            glyph->bitmap.rows,
            0,
            GL_RGBA,
            GL_UNSIGNED_BYTE,
            glyph->bitmap.buffer
        );

        float x2 = x + glyph->bitmap_left;
        float y2 = y - glyph->bitmap_top;
        float w = glyph->bitmap.width;
        float h = glyph->bitmap.rows;

        // Ensure the texture coordinates are within the range [0, 1]
        float texCoords[8] = {
            0.0f, 0.0f,
            1.0f, 0.0f,
            1.0f, 1.0f,
            0.0f, 1.0f
        };

        glBegin(GL_QUADS);
        glTexCoord2fv(texCoords);
        glTexCoord2f(0, 0); glVertex2f(x2, y2);
        glTexCoord2f(1, 0); glVertex2f(x2 + w, y2);
        glTexCoord2f(1, 1); glVertex2f(x2 + w, y2 + h);
        glTexCoord2f(0, 1); glVertex2f(x2, y2 + h);
        glEnd();

        // Delete the texture
        glDeleteTextures(1, &textureID);

        x += (glyph->advance.x >> 6);
        y += (glyph->advance.y >> 6);
    }

    glDisable(GL_BLEND);
}

void MovePlayer()
{
    //Move up, down, left, right
    if (K.a == 1 && K.m == 0)
    {
        P.a -= 4;

        if (P.a < 0)
        {
            P.a += 360;
        }
    }
    if (K.d == 1 && K.m == 0)
    {
        P.a += 4;

        if (P.a > 359)
        {
            P.a -= 360;
        }
    }

    int dx = M.sin[P.a] * 10.0;
    int dy = M.cos[P.a] * 10.0;

    if (K.w == 1 && K.m == 0)
    {
        P.x += dx;
        P.y += dy;
    }
    if (K.s == 1 && K.m == 0)
    {
        P.x -= dx;
        P.y -= dy;
    }

    //Strafe left, right
    if (K.sr == 1)
    {
        P.x -= dy;
        P.y += dx;
    }
    if (K.sl == 1)
    {
        P.x += dy;
        P.y -= dx;
    }

    //Look up, look down
    if (K.a == 1 && K.m == 1)
    {
        P.l -= 1;
    }
    if (K.d == 1 && K.m == 1)
    {
        P.l += 1;
    }
    //Move up, down
    if (K.w == 1 && K.m == 1)
    {
        P.z += 4;
    }
    if (K.s == 1 && K.m == 1)
    {
        P.z -= 4;
    }
}

void ClearBackground()
{
    for (int y = 0; y < SH; y++)
    {
        for (int x = 0; x < SW; x++) { DrawPixel(x, y, 64, 64, 64); } //Clear background color
    }
}

void ClipBehindPlayer(int* x1, int* y1, int* z1, int x2, int y2, int z2)    //Clip line
{
    float da = *y1;
    float db = y2;

    float d = da - db;
    if (d == 0)
    {
        d = 1;
    }

    float s = da / (da - db);

    *x1 = *x1 + s * (x2 - (*x1));
    *y1 = *y1 + s * (y2 - (*y1)); if (*y1 == 0) { *y1 = 1; }
    *z1 = *z1 + s * (z2 - (*z1));
}

void DrawFloors()
{
    int x, y;
    int xo = SW / 2;    //X offset
    int yo = SH / 2;    //Y offset

    float fov = 200;
    float lookUpDown = -P.l * 2; if (lookUpDown > SH) { lookUpDown = SH; }
    float moveUpDown = P.z / 16.0; if (moveUpDown == 0) { moveUpDown = 0.001; }
    
    int ys = -yo, ye = -lookUpDown;

    if (moveUpDown < 0) 
    { 
        ye = -lookUpDown; ye = yo + lookUpDown; 
    }

    for (y = -yo; y < ye; y++)
    {
        for (x = -xo; x < xo; x++)
        {
            float z = y + lookUpDown; if (z == 0) { z = 0.0001; }
            float fx = x / z * moveUpDown;       //World floor X
            float fy = fov / z * moveUpDown;     //World floor Y
            float rx = fx * M.sin[P.a] - fy * M.cos[P.a] + (P.y / 30.0);
            float ry = fx * M.cos[P.a] + fy * M.sin[P.a] - (P.x / 30.0);

            //Remove negative values
            if (rx < 0)
            {
                rx = -rx + 1;
            }
            if (ry < 0)
            {
                ry = -ry + 1;
            }

            int c = 191 * (255 - (z / (float)yo));

            if ((int)rx % 2 == (int)ry % 2)
            {
                DrawPixel(x + xo, y + yo, c, c, c);
            }
            else
            {
                DrawPixel(x + xo, y + yo, 64, 64, 64);
            }
        }
    }
}

void DrawWall(int x1, int x2, int b1, int b2, int t1, int t2, int s, int w, int frontBack)
{
    int x, y;

    //Wall texture
    int wt = W[w].wt;

    //Horizontal wall texture starting and step value
    float ht = 0, ht_step = (float)texLoader->Textures[wt].w * W[w].u / (float)(x2 - x1);

    //Hold differences in the distance
    int dyb = b2 - b1;          //Y distance of the bottom line
    int dyt = t2 - t1;          //Y distance of the top line
    int dx = x2 - x1;           //X Distance

    if (dx == 0)
    {
        dx = 1;
    }

    int xs = x1;                //Hold the initial x1 starting positions

    //Clip X
    //Clip left
    if (x1 < 0)
    {
        ht -= ht_step * x1;
        x1 = 0;
    }
    if (x2 < 0)
    {
        x2 = 0;
    }
    //Clip right
    if (x1 > SW)
    {
        x1 = SW;
    }
    if (x2 > SW)
    {
        x2 = SW;
    }

    //Draw x vertical lines
    for (x = x1; x < x2; x++)
    {
        //The Y start and end point
        int y1 = dyb * (x - xs + 0.5) / dx + b1;        //Y bottom point
        int y2 = dyt * (x - xs + 0.5) / dx + t1;        //Y Top point

        //Vertical wall texture starting and step value
        float vt = 0, vt_step = (float)texLoader->Textures[wt].h * W[w].v / (float)(y2 - y1);

        //Clip Y
        if (y1 < 0)
        {
            vt -= vt_step * y1;
            y1 = 0;
        }
        if (y2 < 0)
        {
            y2 = 0;
        }
        if (y1 > SH)
        {
            y1 = SH;
        }
        if (y2 > SH)
        {
            y2 = SH;
        }

        //Draw front wall
        if (frontBack == 0)
        {
            if(S[s].surface == 1)
            {
                S[s].surf[x] = y1;
            }
            if (S[s].surface == 2)
            {
                S[s].surf[x] = y2;
            }

            //Normal wall
            for (y = y1; y < y2; y++)
            {
                int pixel = (int)(texLoader->Textures[wt].h - ((int)vt % texLoader->Textures[wt].h) - 1) * 3 * texLoader->Textures[wt].w + ((int)ht % texLoader->Textures[wt].w) * 3;
                int r = texLoader->Textures[wt].name[pixel + 0] - W[w].shade / 2; if (r < 0) { r = 0; }
                int g = texLoader->Textures[wt].name[pixel + 1] - W[w].shade / 2; if (g < 0) { g = 0; }
                int b = texLoader->Textures[wt].name[pixel + 2] - W[w].shade / 2; if (b < 0) { b = 0; }
                DrawPixel(x, y, r, g, b);
                vt += vt_step;
            }
            ht += ht_step;
        }

        if (frontBack == 1)
        {
            //Surfaces
            int xo = SW / 2;                //X offset
            int yo = SH / 2;                //Y offset
            float fov = 200;                //FOV
            int x2 = x - xo;                //x - x offset
            int wo;                         //Wall offset
            float tile = S[s].ss * 7;       //Imported surface tile

            if (S[s].surface == 1)
            {
                y2 = S[s].surf[x];
                wo = S[s].z1;
            }
            if (S[s].surface == 2)
            {
                y1 = S[s].surf[x];
                wo = S[s].z2;
            }

            float lookUpDown = -P.l * 6.2;                      if (lookUpDown > SH) { lookUpDown = SH; }
            float moveUpDown = (float)P.z - wo / (float)yo;     if (moveUpDown == 0) { moveUpDown = 0.001; }
            int ys = y1 - yo, ye = y2 - yo;

            for (y = ys; y < ye; y++)
            {
                float z = y + lookUpDown; if (z == 0) { z = 0.0001; }
                float fx = x2 / z * moveUpDown * tile;         //World floor X
                float fy = fov / z * moveUpDown * tile;        //World floor Y
                float rx = fx * M.sin[P.a] - fy * M.cos[P.a] + (P.y / 60.0 * tile);
                float ry = fx * M.cos[P.a] + fy * M.sin[P.a] - (P.x / 60.0 * tile);

                //Remove negative values
                if (rx < 0)
                {
                    rx = -rx + 1;
                }
                if (ry < 0)
                {
                    ry = -ry + 1;
                }

                //Textures
                int st = S[s].st;
                int pixel = (int)(texLoader->Textures[st].h - ((int)ry % texLoader->Textures[st].h) - 1) * 3 * texLoader->Textures[st].w + ((int)rx % texLoader->Textures[st].w) * 3;
                int r = texLoader->Textures[st].name[pixel + 0];
                int g = texLoader->Textures[st].name[pixel + 1];
                int b = texLoader->Textures[st].name[pixel + 2];
                DrawPixel(x2 + xo, y + yo, r, g, b);
            }
        }
    }
}

int Dist(int x1, int y1, int x2, int y2)
{
    int distance = sqrt((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
    return distance;
}

void Draw3D()
{
    int x, s, w, loop, frontBack, cycles;
    int wx[4], wy[4], wz[4];
    float CS = M.cos[P.a], SN = M.sin[P.a];

    //Order sectors by distance
    for (s = 0; s < numSect - 1; s++)
    {
        for (w = 0; w < numSect - s - 1; w++)
        {
            if (S[w].d < S[w + 1].d)
            {
                Sector st = S[w];
                S[w] = S[w + 1];
                S[w + 1] = st;
            }
        }
    }

    //Draw sectors
    for (s = 0; s < numSect; s++)
    {
        //Clear distance
        S[s].d = 0;

        if (P.z < S[s].z1)          //Botttom surface
        {
            S[s].surface = 1;
            cycles = 2;

            for (x = 0; x < SW; x++)
            {
                S[s].surf[s] = SH;
            }
        }
        else if (P.z > S[s].z2)     //Top surface
        {
            S[s].surface = 2;
            cycles = 2;
            
            for (x = 0; x < SW; x++)
            {
                S[s].surf[s] = 0;
            }
        }
        else                        //No surfaces
        {
            S[s].surface = 0;
            cycles = 1;
        }

        for (frontBack = 0; frontBack < cycles; frontBack++)
        {
            for (w = S[s].ws; w < S[s].we; w++)
            {
                //Offset bottom 2 points by player
                int x1 = W[w].x1 - P.x, y1 = W[w].y1 - P.y;
                int x2 = W[w].x2 - P.x, y2 = W[w].y2 - P.y;

                //Swap for surface
                if (frontBack == 1)
                {
                    int swp = x1;
                    x1 = x2;
                    x2 = swp;

                    swp = y1;;
                    y1 = y2;
                    y2 = swp;
                }

                //World X position
                wx[0] = x1 * CS - y1 * SN;
                wx[1] = x2 * CS - y2 * SN;
                wx[2] = wx[0];
                wx[3] = wx[1];                                      //Top line has the same x

                //World Y position (depth)
                wy[0] = y1 * CS + x1 * SN;
                wy[1] = y2 * CS + x2 * SN;
                wy[2] = wy[0];
                wy[3] = wy[1];                                      //Top line has the same y

                //Store the wall distance
                S[s].d += Dist(0, 0, (wx[0] + wx[1]) / 2, (wy[0] + wy[1]) / 2);

                //World Z height;
                wz[0] = S[s].z1 - P.z + ((P.l * wy[0]) / 32.0);
                wz[1] = S[s].z1 - P.z + ((P.l * wy[1]) / 32.0);
                wz[2] = S[s].z2 - P.z + ((P.l * wy[0]) / 32.0);
                wz[3] = S[s].z2 - P.z + ((P.l * wy[1]) / 32.0);           //Top line has the same z

                //Do not draw if behind the player
                if (wy[0] < 1 && wy[1] < 1) { continue; }             //Wall behind the player, do not draw!

                //Point 1 behind player, clip!
                if (wy[0] < 1)
                {
                    ClipBehindPlayer(&wx[0], &wy[0], &wz[0], wx[1], wy[1], wz[1]);      //Bottom line
                    ClipBehindPlayer(&wx[2], &wy[2], &wz[2], wx[3], wy[3], wz[3]);      //Top line
                }

                //Point 2 behind the player, clip!
                if (wy[1] < 1)
                {
                    ClipBehindPlayer(&wx[1], &wy[1], &wz[1], wx[0], wy[0], wz[0]);      //Bottom line
                    ClipBehindPlayer(&wx[3], &wy[3], &wz[3], wx[2], wy[2], wz[2]);      //Top line
                }

                //Screen X and Y positions
                wx[0] = wx[0] * 200 / wy[0] + SW2;
                wy[0] = wz[0] * 200 / wy[0] + SH2;

                wx[1] = wx[1] * 200 / wy[1] + SW2;
                wy[1] = wz[1] * 200 / wy[1] + SH2;

                wx[2] = wx[2] * 200 / wy[2] + SW2;
                wy[2] = wz[2] * 200 / wy[2] + SH2;

                wx[3] = wx[3] * 200 / wy[3] + SW2;
                wy[3] = wz[3] * 200 / wy[3] + SH2;

                //Draw points
                DrawWall(wx[0], wx[1], wy[0], wy[1], wy[2], wy[3], s, w, frontBack);
            }
            //Find average sector distance
            if (S[s].d != 0)
            {
                S[s].d /= (S[s].we - S[s].ws);
            }
        }
    }
}

void Display()
{
    if (T.fr1 - T.fr2 >= 50)                        //Only draw 20 frames/second
    {
        glClear(GL_COLOR_BUFFER_BIT);

        ClearBackground();
        MovePlayer();
        DrawFloors();
        Draw3D();
        DrawCustomText("Press enter to load level...", 100, 100, 64, 64, 64, 24);

        T.fr2 = T.fr1;
        glutSwapBuffers();
        glutReshapeWindow(GLSW, GLSH);              //prevent window scaling
    }

    T.fr1 = glutGet(GLUT_ELAPSED_TIME);             //1000 Milliseconds per second
    glutPostRedisplay();
}

void KeysDown(unsigned char key, int x, int y)
{
    if (key == 'w') { K.w = 1; }
    if (key == 's') { K.s = 1; }
    if (key == 'a') { K.a = 1; }
    if (key == 'd') { K.d = 1; }
    if (key == 'm') { K.m = 1; }
    if (key == ',') { K.sr = 1; }
    if (key == '.') { K.sl = 1; }
    if (key == 13) { texLoader->Load(); }
}

void KeysUp(unsigned char key, int x, int y)
{
    if (key == 'w') { K.w = 0; }
    if (key == 's') { K.s = 0; }
    if (key == 'a') { K.a = 0; }
    if (key == 'd') { K.d = 0; }
    if (key == 'm') { K.m = 0; }
    if (key == ',') { K.sr = 0; }
    if (key == '.') { K.sl = 0; }
}

void Init()
{
    //Pre-calculate sin cos in degrees
    for (int x = 0; x < 360; x++)
    {
        M.cos[x] = cos(x / 180.0 * M_PI);
        M.sin[x] = sin(x / 180.0 * M_PI);
    }

    //Init player variables
    P.x = 70; P.y = -110; P.z = 20; P.a = 0; P.l = 0;

    //Define textures
    texLoader->DefineTextures();
}

int wmain(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(GLSW / 2, GLSH / 2);
    glutInitWindowSize(GLSW, GLSH);
    glutCreateWindow("Doom Engine Demo");

    if (FT_Init_FreeType(&ft)) {
        std::cerr << "Could not init FreeType Library" << std::endl;
        return -1;
    }

    if (FT_New_Face(ft, "fonts/arial.ttf", 0, &face)) {
        std::cerr << "Could not open font" << std::endl;
        return -1;
    }
    
    //Pixel size
    glPointSize(pixelScale);                        
    //Origin bottom left
    gluOrtho2D(0, GLSW, 0, GLSH);                   
    
    Init();
    
    glutDisplayFunc(Display);
    glutKeyboardFunc(KeysDown);
    glutKeyboardUpFunc(KeysUp);
    
    glutMainLoop();

    FT_Done_Face(face);
    FT_Done_FreeType(ft);
    
    return 0;
}
