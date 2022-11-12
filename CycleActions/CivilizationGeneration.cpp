#include "CivilizationGeneration.h"
#include "../Tools/Randomizer.h"
#include "../Tools/Logger.h"

CivilizationGeneration::CivilizationGeneration(double GenerationProbability)
{
    Probability = GenerationProbability;
}

void CivilizationGeneration::Action(class Universe* Universe,std::vector<Void>& Voids, std::vector<std::unique_ptr<Civilization>>& Civilizations)
{
    auto Chance = Randomizer::RandRange(0.0f, 1.0f);

    if (Chance <= Probability)
    {
        std::unique_ptr<Civilization> NewCivilization = std::make_unique<Civilization>();

        Logger::Print("Civilization was born: " + std::to_string( Universe->GetCurrentCycle()) + " cycle");

        Universe->AddCivilization(NewCivilization, Randomizer::RandRangeUnsigned(0, Universe->GetSize()));
    }
}
