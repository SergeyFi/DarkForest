#pragma once

#include "../Universe/Universe.h"

class CycleAction
{
public:
    virtual void Action(class Universe* Universe, FVoidsData& Voids, FCivilizationsData& Civilizations) = 0;

    virtual ~CycleAction() = default;
};
