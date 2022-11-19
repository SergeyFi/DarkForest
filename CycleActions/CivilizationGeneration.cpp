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
        auto X = Randomizer::RandRangeUnsigned(0, Universe->GetSize().X);
        auto Y= Randomizer::RandRangeUnsigned(0, Universe->GetSize().Y);

        if (Voids.Voids[X][Y].Civilization != nullptr)
        {
            return;
        }

        std::unique_ptr<Civilization> NewCivilization = std::make_unique<Civilization>();
        NewCivilization->Color.Red = Randomizer::RandRange(0.0f, 255.0f);
        NewCivilization->Color.Green = Randomizer::RandRange(0.0f, 255.0f);
        NewCivilization->Color.Blue = Randomizer::RandRange(0.0f, 255.0f);

        Voids.Voids[X][Y].Civilization = NewCivilization.get();
        Civilizations.Civilizations.emplace_back(std::move(NewCivilization));

        Logger::Print("Civilization was born: " + std::to_string( Universe->GetCyclesData().CyclesCurrent) + " cycle");
    }
}
