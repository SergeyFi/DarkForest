#pragma once
#include <random>

class Randomizer
{
public:
    static double RandRange(double Start, double End);

    static unsigned int RandRangeUnsigned(unsigned int Start, unsigned int End);

private:

    static std::random_device RandomDevice;
    static std::mt19937 MTRandomGenerator;
};
