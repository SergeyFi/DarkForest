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
    std::uniform_int_distribution<int> dist(int(Start/2), int(End/2));
    std::uniform_int_distribution<int> dist2(int(Start/2), int(End/2));

    auto a = dist(MTRandomGenerator);
    auto b = dist2(MTRandomGenerator);

    return a + b;
}
