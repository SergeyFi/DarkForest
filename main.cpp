#include "Universe/Universe.h"
#include "CycleActions/CivilizationGeneration.h"
#include "CycleActions/CivilizationGrowth.h"
#include "Frontend/Drawer.h"
#include <thread>

int main()
{
    std::vector<std::unique_ptr<CycleAction>> Actions;
    Actions.emplace_back(std::make_unique<CivilizationGeneration>(0.1f));
    Actions.emplace_back(std::make_unique<CivilizationGrowth>());

    Universe FirstUniverse(10000, 100, Actions);
    FirstUniverse.SetCycleSleepTime(100);

    Drawer UniverseDrawer;
    std::thread DrawerThread(&Drawer::StartDrawLoop, &UniverseDrawer);
    DrawerThread.detach();

    FirstUniverse.StartSimulation();
}
