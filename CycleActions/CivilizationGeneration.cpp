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
        NewCivilization->Color.R = Randomizer::RandRange(0.0f, 255.0f);
        NewCivilization->Color.G = Randomizer::RandRange(0.0f, 255.0f);
        NewCivilization->Color.B = Randomizer::RandRange(0.0f, 255.0f);

        Logger::Print("Civilization was born: " + std::to_string( Universe->GetCurrentCycle()) + " cycle");

        auto Location = Randomizer::RandRangeUnsigned(0, Universe->GetSize());

        Civilizations.emplace_back(std::move(NewCivilization));

        unsigned int BorderLeft = Location - 1;
        unsigned int BorderRight = Location + 1;

        if (BorderLeft == -1)
        {
            BorderLeft = 0;
        }

        if (BorderRight >= Voids.size())
        {
            BorderRight = Location;
        }

        Civilizations.back()->BorderLeft = BorderLeft;
        Civilizations.back()->BorderRight = BorderRight;
        Voids[Location].Civilization = Civilizations.back().get();
    }
}
