#include "Universe.h"
#include "../Tools/Logger.h"
#include "../CycleActions/CycleAction.h"
#include <thread>
#include <chrono>

Universe::Universe(FVector2D Size, unsigned int Cycles, struct FActionsData& NewActions)
{
    VoidsData = {std::vector<std::vector<Void>>(Size.X, std::vector<Void>(Size.Y))};
    ActionsData = std::move(NewActions);
    CyclesData.CyclesMax = Cycles;
}

void Universe::StartSimulation()
{
    Logger::Print("Simulation is started.");

    while (CyclesData.CyclesCurrent < CyclesData.CyclesMax)
    {
        for (auto& Action : ActionsData.Actions)
        {
            Action->Action(this, VoidsData, CivilizationsData);
        }

        ++CyclesData.CyclesCurrent;

        std::this_thread::sleep_for(std::chrono::microseconds(CycleSleepTime));
    }

    Logger::Print("Simulation is finished.");
}

const FVoidsData& Universe::GetVoids() const
{
    return VoidsData;
}

const FCivilizationsData& Universe::GetCivilizations() const
{
    return CivilizationsData;
}

FVector2D Universe::GetSize() const
{
    return {static_cast<unsigned int>(VoidsData.Voids.size()),
            static_cast<unsigned int>(VoidsData.Voids.back().size())};
}

const FCyclesData& Universe::GetCyclesData() const
{
    return CyclesData;
}

void Universe::SetCycleSleepTime(unsigned int SleepTime)
{
    CycleSleepTime = SleepTime;
}
