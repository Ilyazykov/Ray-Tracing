#pragma once

#define GOLD 0
#define SILVER 1     
#define SILVER_POLISHED 2
#define BRONZE 3
#define CHROME 4
#define BRASS 5
#define TIN 6
#define COPPER 7
#define PLASTIC_BLACK 8
#define RED_MATTE 9
#define GREEN_MATTE 10
#define BLUE_MATTE 11
#define WHITE_MATTE 12
#define BLACK_MATTE 13

#include "Colour.h"
#include "Material.h"


Material setMaterial( int materialID );