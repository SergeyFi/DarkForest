#include "Universe/Universe.h"
#include "CycleActions/CivilizationGeneration.h"

int main()
{
    std::vector<std::unique_ptr<CycleAction>> Actions;
    Actions.emplace_back(std::make_unique<CivilizationGeneration>());

    Universe FirstUniverse(10, 100, Actions);
}
