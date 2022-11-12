#pragma once

#include "../Universe/Universe.h"

class CycleAction
{
public:
    virtual void Action(class Universe* Universe,std::vector<Void>& Voids, std::vector<std::unique_ptr<Civilization>>& Civilizations) = 0;

    virtual ~CycleAction() = default;
};
