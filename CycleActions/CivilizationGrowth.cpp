#include "CivilizationGrowth.h"


void CivilizationGrowth::Action(class Universe* Universe,std::vector<Void>& Voids, std::vector<std::unique_ptr<Civilization>>& Civilizations)
{
    for (auto& Civilization : Civilizations)
    {
        auto& LeftVoid = Voids[Civilization->BorderLeft];
        auto& RightVoid = Voids[Civilization->BorderRight];

        if (LeftVoid.Civilization == nullptr)
        {
            Voids[Civilization->BorderLeft].Civilization = Civilization.get();

            if (Civilization->BorderLeft != 0)
            {
                Civilization->BorderLeft -= 1;
            }
        }

        if (RightVoid.Civilization == nullptr)
        {
            Voids[Civilization->BorderRight].Civilization = Civilization.get();

            if (Civilization->BorderRight != Universe->GetSize())
            {
                Civilization->BorderRight += 1;
            }
        }
    }
}
