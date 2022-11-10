#include "CivilizationGeneration.h"
#include "../Tools/Randomizer.h"

CivilizationGeneration::CivilizationGeneration(double GenerationProbability)
{
    Probability = GenerationProbability;
}

void CivilizationGeneration::Action(Universe* Universe)
{
    auto Chance = Randomizer::RandRange(0.0f, 1.0f);

    if (Chance <= Probability)
    {
        std::unique_ptr<Civilization> NewCivilization;

        Universe->AddCivilization(NewCivilization, Randomizer::RandRange(0, Universe->GetSize()));
    }
}
