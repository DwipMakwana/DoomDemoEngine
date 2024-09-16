#include <iostream>
#include <fstream>
#include <string>

#include "textures/T_00.h"
#include "textures/T_01.h"
#include "textures/T_02.h"
#include "textures/T_03.h"
#include "textures/T_04.h"
#include "textures/T_05.h"
#include "textures/T_06.h"
#include "textures/T_07.h"
#include "textures/T_08.h"
#include "textures/T_09.h"
#include "textures/T_10.h"
#include "textures/T_11.h"
#include "textures/T_12.h"
#include "textures/T_13.h"
#include "textures/T_14.h"
#include "textures/T_15.h"
#include "textures/T_16.h"
#include "textures/T_17.h"
#include "textures/T_18.h"
#include "textures/T_19.h"
#include "textures/T_NUMBERS.h"
#include "textures/T_VIEW2D.h"

#include "include/core/Engine.h"
#include "include/util/TextureLoader.h"

void TextureLoader::Load()
{
    std::ifstream file("level/level.h");

    if (!file.is_open()) {
        std::cerr << "Error opening level.h" << std::endl;
        return;
    }

    int s, w;

    // Number of sectors
    file >> numSect;

    // Load all sectors
    for (s = 0; s < numSect; ++s) {
        file >> S[s].ws >> S[s].we >> S[s].z1 >> S[s].z2 >> S[s].st >> S[s].ss;
    }

    // Number of walls
    file >> numWall;

    // Load all walls
    for (s = 0; s < numWall; ++s) {
        file >> W[s].x1 >> W[s].y1 >> W[s].x2 >> W[s].y2 >> W[s].wt >> W[s].u >> W[s].v >> W[s].shade;
    }

    // Player position angle and look
    file >> P.x >> P.y >> P.z >> P.a >> P.l;

    file.close();

    printf("Level loaded!");
}

void TextureLoader::DefineTextures()
{
    Textures[0].name = T_00;
    Textures[0].h = T_00_HEIGHT;
    Textures[0].w = T_00_WIDTH;

    Textures[1].name = T_01;
    Textures[1].h = T_01_HEIGHT;
    Textures[1].w = T_01_WIDTH;

    Textures[2].name = T_02;
    Textures[2].h = T_02_HEIGHT;
    Textures[2].w = T_02_WIDTH;

    Textures[3].name = T_03;
    Textures[3].h = T_03_HEIGHT;
    Textures[3].w = T_03_WIDTH;

    Textures[4].name = T_04;
    Textures[4].h = T_04_HEIGHT;
    Textures[4].w = T_04_WIDTH;

    Textures[5].name = T_05;
    Textures[5].h = T_05_HEIGHT;
    Textures[5].w = T_05_WIDTH;

    Textures[6].name = T_06;
    Textures[6].h = T_06_HEIGHT;
    Textures[6].w = T_06_WIDTH;

    Textures[7].name = T_07;
    Textures[7].h = T_07_HEIGHT;
    Textures[7].w = T_07_WIDTH;

    Textures[8].name = T_08;
    Textures[8].h = T_08_HEIGHT;
    Textures[8].w = T_08_WIDTH;

    Textures[9].name = T_09;
    Textures[9].h = T_09_HEIGHT;
    Textures[9].w = T_09_WIDTH;

    Textures[10].name = T_10;
    Textures[10].h = T_10_HEIGHT;
    Textures[10].w = T_10_WIDTH;

    Textures[11].name = T_11;
    Textures[11].h = T_11_HEIGHT;
    Textures[11].w = T_11_WIDTH;

    Textures[12].name = T_12;
    Textures[12].h = T_12_HEIGHT;
    Textures[12].w = T_12_WIDTH;

    Textures[13].name = T_13;
    Textures[13].h = T_13_HEIGHT;
    Textures[13].w = T_13_WIDTH;

    Textures[14].name = T_14;
    Textures[14].h = T_14_HEIGHT;
    Textures[14].w = T_14_WIDTH;

    Textures[15].name = T_15;
    Textures[15].h = T_15_HEIGHT;
    Textures[15].w = T_15_WIDTH;

    Textures[16].name = T_16;
    Textures[16].h = T_16_HEIGHT;
    Textures[16].w = T_16_WIDTH;

    Textures[17].name = T_17;
    Textures[17].h = T_17_HEIGHT;
    Textures[17].w = T_17_WIDTH;

    Textures[18].name = T_18;
    Textures[18].h = T_18_HEIGHT;
    Textures[18].w = T_18_WIDTH;

    Textures[19].name = T_19;
    Textures[19].h = T_19_HEIGHT;
    Textures[19].w = T_19_WIDTH;
}