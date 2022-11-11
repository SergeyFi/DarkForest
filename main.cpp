#include "Universe/Universe.h"
#include "CycleActions/CivilizationGeneration.h"


int main()
{
    std::vector<std::unique_ptr<CycleAction>> Actions;
    Actions.emplace_back(std::make_unique<CivilizationGeneration>(0.1f));

    Universe FirstUniverse(10000, 100, Actions);
    FirstUniverse.StartSimulation();
}
