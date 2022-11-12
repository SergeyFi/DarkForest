#include "CivilizationGrowth.h"

void CivilizationGrowth::Action(class Universe* Universe,std::vector<Void>& Voids, std::vector<std::unique_ptr<Civilization>>& Civilizations)
{
    for (auto& Civilization : Civilizations)
    {
        auto LeftVoid = Voids[Civilization->BorderLeft];

        if (LeftVoid.Civilization == nullptr)
        {
            LeftVoid.Civilization = Civilization.get();

            if (Civilization->BorderLeft > 0)
            {
                Civilization->BorderLeft -= 1;
            }
        }
        else
        {
            auto RightVoid = Voids[Civilization->BorderLeft];

            if (RightVoid.Civilization == nullptr)
            {
                RightVoid.Civilization = Civilization.get();

                if (Civilization->BorderRight < Voids.size())
                {
                    Civilization->BorderRight += 1;
                }
            }
        }
    }
}
