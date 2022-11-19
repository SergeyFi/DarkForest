#include "Randomizer.h"

std::random_device Randomizer::RandomDevice = std::random_device();
std::mt19937 Randomizer::MTRandomGenerator = std::mt19937(RandomDevice());

double Randomizer::RandRange(double Start, double End)
{
    std::uniform_real_distribution<double> dist(Start, End);

    return dist(MTRandomGenerator);
}

unsigned int Randomizer::RandRangeUnsigned(unsigned int Start, unsigned int End)
{
    std::uniform_int_distribution<long long int> dist(Start, End);

    auto a = dist(MTRandomGenerator);

    return a;
}
