#include "Universe.h"
#include "../CycleActions/CycleAction.h"

Universe::Universe(unsigned int Size, unsigned int Cycles, std::vector<std::unique_ptr<CycleAction>>& NewActions)
{
    Space.reserve(Size);
    Actions = std::move(NewActions);
    CyclesMax = Cycles;
    CyclesCurrent = 0;
}

void Universe::StartSimulation()
{
    while (CyclesCurrent < CyclesMax)
    {
        for (auto& Action : Actions)
        {
            Action->Action(this);
        }

        ++CyclesCurrent;
    }
}

void Universe::AddCivilization(std::unique_ptr<Civilization>& Civilization, unsigned int Location)
{
    Civilizations.emplace_back(std::move(Civilization));
}

std::vector<Void> &Universe::GetSpace()
{
    return Space;
}

unsigned int Universe::GetSize()
{
    return Space.size();
}
