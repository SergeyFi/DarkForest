#pragma once

#include "../Universe/Universe.h"

class CycleAction
{
public:
    virtual void Action(Universe* Universe) = 0;
};
