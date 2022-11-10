#include "CivilizationGeneration.h"

void CivilizationGeneration::Action(Universe* Universe)
{
    std::unique_ptr<Civilization> NewCivilization;

    Universe->AddCivilization(NewCivilization, 0);
}