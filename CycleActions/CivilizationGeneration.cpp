#include "CivilizationGeneration.h"
#include "../Tools/Randomizer.h"
#include "../Tools/Logger.h"

CivilizationGeneration::CivilizationGeneration(double GenerationProbability)
{
    Probability = GenerationProbability;
}

void CivilizationGeneration::Action(class Universe* Universe, FVoidsData& Voids, FCivilizationsData& Civilizations)
{
    auto Chance = Randomizer::RandRange(0.0f, 1.0f);

    if (Chance <= Probability)
    {

    }
}
