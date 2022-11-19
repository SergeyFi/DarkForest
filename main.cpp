#include "Universe/Universe.h"
#include "CycleActions/CivilizationGeneration.h"
#include "Frontend/Drawer.h"
#include <thread>
#include <chrono>

int main()
{
    // Setup universe
    FActionsData ActionsData;
    ActionsData.Actions.emplace_back(std::make_unique<CivilizationGeneration>(0.001f));

    Universe FirstUniverse({1000, 1000}, 100000, ActionsData);
    FirstUniverse.SetCycleSleepTime(100);

    // Draw thread
    Drawer UniverseDrawer(&FirstUniverse);
    std::thread DrawerThread(&Drawer::StartDrawLoop, &UniverseDrawer);
    DrawerThread.detach();

    // Start simulation
    FirstUniverse.StartSimulation();

    std::this_thread::sleep_for(std::chrono::seconds(300));
}
