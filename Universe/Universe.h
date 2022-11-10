#pragma once

#include "../Void/Void.h"
#include <vector>

class Universe
{
public:
    explicit Universe(unsigned int Size);

private:

    std::vector<Void> Space;
};
