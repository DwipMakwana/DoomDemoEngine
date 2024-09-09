#include <cmath>
#include <iostream>
#include <glut/glut.h>

constexpr int res = 1;                      //0=160x120 1=360x240 4=640x480
constexpr int SW = 160 * res;               //screen width
constexpr int SH = 120 * res;               //screen height
constexpr int SW2 = SW / 2;                 //half of screen width
constexpr int SH2 = SH / 2;                 //half of screen height
constexpr int pixelScale = 4 / res;         //OpenGL pixel scale
constexpr int GLSW = SW * pixelScale;       //OpenGL window width
constexpr int GLSH = SH * pixelScale;       //OpenGL window height
//------------------------------------------------------------------------------
struct Time
{
    int fr1, fr2;           //frame 1 frame 2, to create constant frame rate
};

struct Keys
{
    int w, s, a, d;         //move up, down, left, right
    int sl, sr;             //strafe left, right 
    int m;                  //move up, down, look up, down
};

Time T;
Keys K;
//------------------------------------------------------------------------------

void pixel(int x, int y, int c)                  //draw a pixel at x/y with rgb
{
    int rgb[3];
    switch (c) {
    case 0: rgb[0] = 255; rgb[1] = 255; rgb[2] = 0; break; //Yellow	
    case 1: rgb[0] = 160; rgb[1] = 160; rgb[2] = 0; break; //Yellow darker	
    case 2: rgb[0] = 0; rgb[1] = 255; rgb[2] = 0; break; //Green	
    case 3: rgb[0] = 0; rgb[1] = 160; rgb[2] = 0; break; //Green darker	
    case 4: rgb[0] = 0; rgb[1] = 255; rgb[2] = 255; break; //Cyan	
    case 5: rgb[0] = 0; rgb[1] = 160; rgb[2] = 160; break; //Cyan darker
    case 6: rgb[0] = 160; rgb[1] = 100; rgb[2] = 0; break; //brown	
    case 7: rgb[0] = 110; rgb[1] = 50; rgb[2] = 0; break; //brown darker
    case 8: rgb[0] = 0; rgb[1] = 60; rgb[2] = 130; break; //background 
    }
    glColor3ub(rgb[0], rgb[1], rgb[2]);
    glBegin(GL_POINTS);
    glVertex2i(x * pixelScale + 2, y * pixelScale + 2);
    glEnd();
}

void movePlayer()
{
    //move up, down, left, right
    if (K.a == 1 && K.m == 0) { std::cout << "left\n"; }
    if (K.d == 1 && K.m == 0) { std::cout << "right\n"; }
    if (K.w == 1 && K.m == 0) { std::cout << "up\n"; }
    if (K.s == 1 && K.m == 0) { std::cout << "down\n"; }
    //strafe left, right
    if (K.sr == 1) { std::cout << "strafe left\n"; }
    if (K.sl == 1) { std::cout << "strafe right\n"; }
    //move up, down, look up, look down
    if (K.a == 1 && K.m == 1) { std::cout << "look up\n"; }
    if (K.d == 1 && K.m == 1) { std::cout << "look down\n"; }
    if (K.w == 1 && K.m == 1) { std::cout << "move up\n"; }
    if (K.s == 1 && K.m == 1) { std::cout << "move down\n"; }
}

void clearBackground()
{
    for (int y = 0; y < SH; y++)
    {
        for (int x = 0; x < SW; x++) { pixel(x, y, 8); } //clear background color
    }
}

int tick;
void draw3D()
{
    int c = 0;
    for (int y = 0; y < SH2; y++)
    {
        for (int x = 0; x < SW2; x++)
        {
            pixel(x, y, c);
            c += 1; if (c > 8) { c = 0; }
        }
    }
    //frame rate
    tick += 1; if (tick > 20) { tick = 0; } pixel(SW2, SH2 + tick, 0);
}

void display()
{
    if (T.fr1 - T.fr2 >= 50)                        //only draw 20 frames/second
    {
        clearBackground();
        movePlayer();
        draw3D();

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

void init()
{
    // Initialize OpenGL settings here if needed
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
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(KeysDown);
    glutKeyboardUpFunc(KeysUp);
    glutMainLoop();
    return 0;
}

