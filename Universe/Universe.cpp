#include "Universe.h"
#include "../CycleActions/CycleAction.h"

Universe::Universe(unsigned int Size, unsigned int Cycles, std::vector<std::unique_ptr<CycleAction>> NewActions)
{
    Space.reserve(Size);
    Actions = std::move(NewActions);
    CyclesMax = CyclesCurrent;
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
