#pragma once
#include "CycleAction.h"


class CivilizationGrowth: public CycleAction
{
public:
    void Action(Universe* Universe) override;
};