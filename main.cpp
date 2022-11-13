#include "Universe/Universe.h"
#include "CycleActions/CivilizationGeneration.h"
#include "CycleActions/CivilizationGrowth.h"
#include "Frontend/Drawer.h"
#include <thread>
#include <chrono>

int main()
{
    // Setup universe
    std::vector<std::unique_ptr<CycleAction>> Actions;
    Actions.emplace_back(std::make_unique<CivilizationGrowth>());
    Actions.emplace_back(std::make_unique<CivilizationGeneration>(0.001f));


    Universe FirstUniverse(100000, 100000, Actions);
    FirstUniverse.SetCycleSleepTime(1);

    // Draw thread
    Drawer UniverseDrawer(&FirstUniverse);
    std::thread DrawerThread(&Drawer::StartDrawLoop, &UniverseDrawer);
    DrawerThread.detach();

    // Start simulation
    FirstUniverse.StartSimulation();

    std::this_thread::sleep_for(std::chrono::seconds(300));
}
