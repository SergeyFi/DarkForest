#pragma once

#include "../Void/Void.h"
#include "../Civilization/Civilization.h"
#include <vector>
#include <memory>

struct FVector2D
{
    unsigned int X = 0;
    unsigned int Y = 0;
};

struct FVoidsData
{
    std::vector<std::vector<Void>> Voids;
};

struct FActionsData
{
    std::vector<std::unique_ptr<class CycleAction>> Actions;
};

struct FCivilizationsData
{
    std::vector<std::unique_ptr<Civilization>> Civilizations;
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
