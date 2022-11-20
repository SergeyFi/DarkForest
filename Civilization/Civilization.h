#pragma once
#include "../Color/Color.h"
#include <vector>
#include <memory>

struct FCivilizationsData
{
    std::vector<std::unique_ptr<class Civilization>> Civilizations;
};

struct Civilization
{
    struct Color Color;
    std::vector<struct Void*> Border;
};
