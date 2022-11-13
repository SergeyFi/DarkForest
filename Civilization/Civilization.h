#pragma once
#include "../Color/Color.h"


struct Civilization
{
    unsigned int Age = 0;
    unsigned int BorderLeft = 0;
    unsigned int BorderRight = 0;
    struct Color Color;
};
