#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <GL/glut.h>

constexpr int res = 1;                      //0=160x120 1=360x240 4=640x480
constexpr int SW = 160 * res;               //Screen width
constexpr int SH = 120 * res;               //Screen height
constexpr int SW2 = SW / 2;                 //Half of screen width
constexpr int SH2 = SH / 2;                 //Half of screen height
constexpr int pixelScale = 4 / res;         //OpenGL pixel scale
constexpr int GLSW = SW * pixelScale;       //OpenGL window width
constexpr int GLSH = SH * pixelScale;       //OpenGL window height
constexpr int numSect = 4;                  //Number of sectors
constexpr int numWall = 16;                 //Number of walls
//------------------------------------------------------------------------------

struct Time
{
    int fr1, fr2;           //Frame 1 frame 2, to create constant frame rate
};

struct Keys
{
    int w, s, a, d;         //Move up, down, left, right
    int sl, sr;             //Strafe left, right 
    int m;                  //Move up, down, look up, down
};

struct Math
{
    float cos[360];         //Save sin cos in values 0-360 degrees
    float sin[360];
};

struct Player 
{
    int x, y, z;            //Player position, Z is up
    int a;                  //Playe angle of roation, left and right
    int l;                  //Variable to look uo and down
};

struct Walls
{
    int x1, x2;             //Bottom line point 1
    int y1, y2;             //Bottom line point 2
    int c;                  //Wall color
};

struct Sector 
{
    int ws, we;             //Wall number start and end
    int z1, z2;             //Height of bottom and top
    int d;                  //Add Y distances to sort drawing order
    int c1, c2;             //Bottom and top color;
    int surf[SW];           //To hold points for surfaces
    int surface;            //Is there a surfaces to draw
};

Sector S[30];
Walls W[30];
Player P;
Math M;
Time T;
Keys K;

//------------------------------------------------------------------------------

void Pixel(int x, int y, int c)                  //Draw a pixel at x/y with rgb
{
    int rgb[3];
    switch (c) {
    case 0: rgb[0] = 255;   rgb[1] = 255;   rgb[2] = 0;     break; //Yellow	
    case 1: rgb[0] = 160;   rgb[1] = 160;   rgb[2] = 0;     break; //Yellow darker	
    case 2: rgb[0] = 0;     rgb[1] = 255;   rgb[2] = 0;     break; //Green	
    case 3: rgb[0] = 0;     rgb[1] = 160;   rgb[2] = 0;     break; //Green darker	
    case 4: rgb[0] = 0;     rgb[1] = 255;   rgb[2] = 255;   break; //Cyan	
    case 5: rgb[0] = 0;     rgb[1] = 160;   rgb[2] = 160;   break; //Cyan darker
    case 6: rgb[0] = 160;   rgb[1] = 100;   rgb[2] = 0;     break; //Brown	
    case 7: rgb[0] = 110;   rgb[1] = 50;    rgb[2] = 0;     break; //Brown darker
    case 8: rgb[0] = 0;     rgb[1] = 60;    rgb[2] = 130;   break; //Background 
    }

    glColor3ub(rgb[0], rgb[1], rgb[2]);
    glBegin(GL_POINTS);
    glVertex2i(x * pixelScale + 2, y * pixelScale + 2);
    glEnd();
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
        P.x += dy;
        P.y -= dx;
    }
    if (K.sl == 1) 
    {
        P.x -= dy;
        P.y += dx;
    }

    //Move up, down, look up, look down
    if (K.a == 1 && K.m == 1) 
    { 
        P.l -= 1;
    }
    if (K.d == 1 && K.m == 1) 
    { 
        P.l += 1;
    }
    if (K.w == 1 && K.m == 1)
    {
        P.z -= 4;
    }
    if (K.s == 1 && K.m == 1)
    {
        P.z += 4;
    }
}

void ClearBackground()
{
    for (int y = 0; y < SH; y++)
    {
        for (int x = 0; x < SW; x++) { Pixel(x, y, 8); } //Clear background color
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

void DrawWall(int x1, int x2, int b1, int b2, int t1, int t2, int c, int s)
{
    int x, y;

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
    if (x1 < 1)
    {
        x1 = 1;
    }
    if (x2 < 1)
    {
        x2 = 1;
    }
    //Clip right
    if (x1 > SW - 1)
    {
        x1 = SW - 1;
    }
    if (x2 > SW - 1)
    {
        x2 = SW - 1;
    }

    //Draw x vertical lines
    for (x = x1; x < x2; x++)
    {
        //The Y start and end point
        int y1 = dyb * (x - xs + 0.5) / dx + b1;        //Y bottom point
        int y2 = dyt * (x - xs + 0.5) / dx + t1;        //Y Top point
        
        //Clip Y
        if (y1 < 1)
        {
            y1 = 1;
        }
        if (y2 < 1)
        {
            y2 = 1;
        }
        if (y1 > SH - 1)
        {
            y1 = SH - 1;
        }
        if (y2 > SH - 1)
        {
            y2 = SH - 1;
        }

        //Surface
        if (S[s].surface == 1)          //Save bottom points
        {
            S[s].surf[x] = y1;
            continue;
        }
        if (S[s].surface == 2)          //Save top points
        {
            S[s].surf[x] = y2;
            continue;
        }
        if (S[s].surface == -1)         //Bottom
        {
            for (y = S[s].surf[x]; y < y1; y++)
            {
                Pixel(x, y, S[s].c2);
            }
        }
        if (S[s].surface == -2)         //Top
        {
            for (y = y1; y < S[s].surf[x]; y++)
            {
                Pixel(x, y, S[s].c2);
            }
        }

        //Normal wall
        for (y = y1; y < y2; y++)
        {
            Pixel(x, y, c);
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
    int s, w, loop;
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
        }
        else if (P.z > S[s].z2)     //Top surface
        {
            S[s].surface = 2;
        }
        else                        //No surfaces
        {
            S[s].surface = 0;
        }

        for (loop = 0; loop < 2; loop++)
        {
            for (w = S[s].ws; w < S[s].we; w++)
            {
                //Offset bottom 2 points by player
                int x1 = W[w].x1 - P.x, y1 = W[w].y1 - P.y;
                int x2 = W[w].x2 - P.x, y2 = W[w].y2 - P.y;

                //Swap for surface
                if (loop == 0)
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
                wz[0] = 0 - P.z + ((P.l * wy[0]) / 32.0);
                wz[1] = 0 - P.z + ((P.l * wy[1]) / 32.0);
                wz[2] = wz[0] + S[s].z2;
                wz[3] = wz[1] + S[s].z2;                                 //Top line has the same z

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
                DrawWall(wx[0], wx[1], wy[0], wy[1], wy[2], wy[3], W[w].c, s);
            }
            //Find average sector distance
            S[s].d /= (S[s].we - S[s].ws);
            //Flip to negative to draw surface
            S[s].surface *= -1;
        }
    }
}

void Display()
{
    if (T.fr1 - T.fr2 >= 50)                        //Only draw 20 frames/second
    {
        ClearBackground();
        MovePlayer();
        Draw3D();

        T.fr2 = T.fr1;
        glutSwapBuffers();
        glutReshapeWindow(GLSW, GLSH);             //prevent window scaling
    }

    T.fr1 = glutGet(GLUT_ELAPSED_TIME);          //1000 Milliseconds per second
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

int LoadSectors[] =
{
    //Wall Start, Wall end, z1 height, z2 height, bottom color, top color
    0, 4, 0, 40, 2, 3,        //Sector 1
    4, 8, 0, 40, 4, 5,        //Sector 2
    8, 12, 0, 40, 6, 7,       //Sector 3
    12, 16, 0, 40, 0, 1,      //Sector 4
};

int LoadWalls[] =
{
    //x1, y1, x2, y2, color
    0, 0, 32, 0, 0,
    32, 0, 32, 32, 1,
    32, 32, 0, 32, 0,
    0, 32, 0, 0, 1, 

    64, 0, 96, 0, 2,
    96, 0, 96, 32, 3,
    96, 32, 64, 32, 2,
    64, 32, 64, 0, 3,

    64, 64, 96, 64, 4,
    96, 64, 96, 96, 5,
    96, 96, 64, 96, 4,
    64, 96, 64, 64, 5,

    0, 64, 32, 64, 6,
    32, 64, 32, 96, 7,
    32, 96, 0, 96, 6,
    0, 96, 0, 64, 7,
};

void Init()
{
    int x;
    // Store sin/cos in degrees
    for (x = 0; x < 360; x++)                               //Pre-calculate sin cos in degrees
    {
        M.cos[x] = cos(x / 180.0 * M_PI);
        M.sin[x] = sin(x / 180.0 * M_PI);
    }

    //Init player variables
    P.x = 70; P.y = -110; P.z = 20; P.a = 0; P.l = 0;       

    //Load sectors
    int s, w, v1 = 0, v2 = 0;
    for (s = 0; s < numSect; s++)
    {
        S[s].ws = LoadSectors[v1 + 0];                          //Wall startnumber
        S[s].we = LoadSectors[v1 + 1];                          //Wall end number
        S[s].z1 = LoadSectors[v1 + 2];                          //Sector obttom height
        S[s].z2 = LoadSectors[v1 + 3] - LoadSectors[v1 + 2];    //Sector top height 
        S[s].c1 = LoadSectors[v1 + 4];
        S[s].c2 = LoadSectors[v1 + 5];
        v1 += 6;

        for (w = S[s].ws; w < S[s].we; w++)
        {
            W[w].x1 = LoadWalls[v2 + 0];        //Bottom x1
            W[w].y1 = LoadWalls[v2 + 1];        //Bottom x2
            W[w].x2 = LoadWalls[v2 + 2];        //Top x2
            W[w].y2 = LoadWalls[v2 + 3];        //Top y2
            W[w].c = LoadWalls[v2 + 4];         //Wall color
            v2 += 5;
        }
    }
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(GLSW / 2, GLSH / 2);
    glutInitWindowSize(GLSW, GLSH);
    glutCreateWindow("");
    glPointSize(pixelScale);                        // pixel size
    gluOrtho2D(0, GLSW, 0, GLSH);                   // origin bottom left
    Init();
    glutDisplayFunc(Display);
    glutKeyboardFunc(KeysDown);
    glutKeyboardUpFunc(KeysUp);
    glutMainLoop();
    return 0;
}

