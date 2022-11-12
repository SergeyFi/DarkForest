#pragma once
#include "CycleAction.h"


class CivilizationGrowth: public CycleAction
{
public:
    void Action(class Universe* Universe,std::vector<Void>& Voids, std::vector<std::unique_ptr<Civilization>>& Civilizations) override;
};
