#pragma once

int numSect = 0;                            //Number of sectors
int numWall = 0;                            //Number of walls
int numText = 19;                           //Number of walls
int dark = 0;                               //Darken buttons
constexpr int res = 1;                      //Resolution multiplier
constexpr int SW = 160 * res;               //Screen width
constexpr int SH = 120 * res;                //Screen height
constexpr int SW2 = SW / 2;                 //Half of screen width
constexpr int SH2 = SH / 2;                 //Half of screen height
constexpr int pixelScale = 4 / res;         //OpenGL pixel scale
constexpr int GLSW = SW * pixelScale;       //OpenGL window width
constexpr int GLSH = SH * pixelScale;       //OpenGL window height

bool isEditor = false;                      //Switch between engine and level editor

struct Walls
{
    int x1, x2;             //Bottom line point 1
    int y1, y2;             //Bottom line point 2
    int wt, u, v;           //Wall texture and u//v tile
    int shade;              //Shade of the wall
    int c;                  //Wall color
};

struct Sector
{
    int ws, we;             //Wall number start and end
    int z1, z2;             //Height of bottom and top
    int d;                  //Add Y distances to sort drawing order
    int c1, c2;             //Bottom and top color;
    int st, ss;             //Surface texture and scale
    int surf[SW];           //To hold points for surfaces
    int surface;            //Is there a surfaces to draw
};

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

struct Grid
{
    int mx, my;             //Rounded mouse position
    int addSect;            //0=nothing, 1=add sector
    int wt, wu, wv;         //Wall texture, uv texture tile
    int st, ss;             //Surface texture, surface scale
    int z1, z2;             //Bottom and top height
    int scale;              //Scale down grid
    int move[4];            //0=wall ID, 1=v1v2, 2=wallID, 3=v1v2
    int selS, selW;         //Select sector/wall
};

Grid G;
Player P;
Math M;
Time T;
Keys K;
Sector S[128];
Walls W[256];