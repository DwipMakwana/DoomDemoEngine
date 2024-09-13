#include <iostream>
#include <fstream>

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
#include <string>

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

    //Define all of them here
}