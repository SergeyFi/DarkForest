#include "Universe/Universe.h"
#include "CycleActions/CivilizationGeneration.h"


int main()
{
    std::vector<std::unique_ptr<CycleAction>> Actions;
    Actions.emplace_back(std::make_unique<CivilizationGeneration>(0.0001f));

    Universe FirstUniverse(10000000, 100000, Actions);
    FirstUniverse.StartSimulation();
}
