#pragma once
#include "../Universe/Universe.h"
#include "../Void/Void.h"

class CycleAction
{
public:
    virtual void Action(class Universe* Universe, FVoidsData& VoidsData, FCivilizationsData& CivilizationsData) = 0;

    virtual ~CycleAction() = default;
};
