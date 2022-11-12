#include "Universe.h"
#include "../CycleActions/CycleAction.h"
#include "../Tools/Logger.h"
#include <thread>
#include <chrono>

Universe::Universe(unsigned int Size, unsigned int Cycles, std::vector<std::unique_ptr<CycleAction>>& NewActions)
{
    Voids = std::vector<Void>(Size);
    Actions = std::move(NewActions);
    CyclesMax = Cycles;
    CyclesCurrent = 0;
}

void Universe::StartSimulation()
{
    Logger::Print("Simulation is started.");

    while (CyclesCurrent < CyclesMax)
    {
        for (auto& Action : Actions)
        {
            Action->Action(this, Voids, Civilizations);
        }

        ++CyclesCurrent;

        std::this_thread::sleep_for(std::chrono::milliseconds(CycleSleepTime));
    }

    Logger::Print("Simulation is finished.");
}

void Universe::AddCivilization(std::unique_ptr<Civilization>& Civilization, unsigned int Location)
{
    Civilizations.emplace_back(std::move(Civilization));

    unsigned int BorderLeft = Location - 1;
    unsigned int BorderRight = Location + 1;

    if (BorderLeft == -1)
    {
        BorderLeft = 0;
    }

    if (BorderRight >= Voids.size())
    {
        BorderRight = Location;
    }

    Civilizations.back()->BorderLeft = BorderLeft;
    Civilizations.back()->BorderRight = BorderRight;
    Voids[Location].Civilization = Civilizations.back().get();
}

const std::vector<Void>& Universe::GetVoids() const
{
    return Voids;
}

const std::vector<std::unique_ptr<Civilization>>& Universe::GetCivilizations() const
{
    return Civilizations;
}

unsigned int Universe::GetSize() const
{
    return Voids.size();
}

unsigned int Universe::GetCurrentCycle() const
{
    return CyclesCurrent;
}

void Universe::SetCycleSleepTime(unsigned int Milliseconds)
{
    CycleSleepTime = Milliseconds;
}
