#include "Universe.h"
#include "../CycleActions/CycleAction.h"
#include "../Tools/Logger.h"

Universe::Universe(unsigned int Size, unsigned int Cycles, std::vector<std::unique_ptr<CycleAction>>& NewActions)
{
    Space = std::vector<Void>(Size);
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
            Action->Action(this);
        }

        ++CyclesCurrent;
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

    if (BorderRight >= Space.size())
    {
        BorderRight = Location;
    }

    Civilizations.back()->BorderLeft = BorderLeft;
    Civilizations.back()->BorderRight = BorderRight;
    Space[Location].Civilization = Civilizations.back().get();
}

std::vector<Void> &Universe::GetVoids()
{
    return Space;
}

unsigned int Universe::GetSize() const
{
    return Space.size();
}

unsigned int Universe::GetCurrentCycle() const
{
    return CyclesCurrent;
}
