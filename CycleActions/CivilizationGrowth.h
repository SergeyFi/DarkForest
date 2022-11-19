#pragma once
#include "CycleAction.h"


class CivilizationGrowth: public CycleAction
{
public:
    void Action(class Universe* Universe, FVoidsData& Voids, FCivilizationsData& Civilizations) override;
};
