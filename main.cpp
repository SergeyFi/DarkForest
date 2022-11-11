#include "Universe/Universe.h"
#include "CycleActions/CivilizationGeneration.h"
#include "CycleActions/CivilizationGrowth.h"

int main()
{
    std::vector<std::unique_ptr<CycleAction>> Actions;
    Actions.emplace_back(std::make_unique<CivilizationGeneration>(0.1f));
    Actions.emplace_back(std::make_unique<CivilizationGrowth>());

    Universe FirstUniverse(10000, 100, Actions);
    FirstUniverse.StartSimulation();
}
