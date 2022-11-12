#pragma once

struct Color
{
    unsigned char R = 0;
    unsigned char G = 0;
    unsigned char B = 0;
};

struct Civilization
{
    unsigned int Age = 0;
    unsigned int BorderLeft = 0;
    unsigned int BorderRight = 0;
    struct Color Color;
};
