#pragma once

#include "../Void/Void.h"
#include "../Civilization/Civilization.h"
#include "../DataTypes/Vector2D.h"
#include <vector>
#include <memory>

struct FActionsData
{
    std::vector<std::unique_ptr<class CycleAction>> Actions;
};

struct FCyclesData
{
    unsigned int CyclesCurrent = 0;
    unsigned int CyclesMax = 0;
};

class Universe
{
public:
    explicit Universe(FVector2D Size, unsigned int Cycles, struct FActionsData& NewActions);

    void StartSimulation();

    const FVoidsData& GetVoids() const;

    const FCivilizationsData& GetCivilizations() const;

    FVector2D GetSize() const;

    const FCyclesData& GetCyclesData() const;

    void SetCycleSleepTime(unsigned int SleepTime);

private:

    FVoidsData VoidsData;
    FCivilizationsData CivilizationsData;
    FActionsData ActionsData;
    FCyclesData CyclesData;

    unsigned int CycleSleepTime = 0;
};
