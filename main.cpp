#include "Universe/Universe.h"
#include "CycleActions/CivilizationGeneration.h"


int main()
{
    std::vector<std::unique_ptr<CycleAction>> Actions;
    Actions.emplace_back(std::make_unique<CivilizationGeneration>(0.1f));

    Universe FirstUniverse(100000, 10000, Actions);
    FirstUniverse.StartSimulation();
}
