#pragma once
#include "../Civilization/Civilization.h"

struct FVoidsData
{
    std::vector<std::vector<Void>> Voids;
};

struct Void
{
    struct Civilization* Civilization = nullptr;
};

