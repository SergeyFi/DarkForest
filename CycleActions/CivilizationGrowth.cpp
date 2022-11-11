#include "CivilizationGrowth.h"

void CivilizationGrowth::Action(Universe* Universe)
{
    for (auto& Civilization : Universe->GetCivilizations())
    {
        auto LeftVoid = Universe->GetVoids()[Civilization->BorderLeft];

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
            auto RightVoid = Universe->GetVoids()[Civilization->BorderLeft];

            if (RightVoid.Civilization == nullptr)
            {
                RightVoid.Civilization = Civilization.get();

                if (Civilization->BorderRight < Universe->GetSize())
                {
                    Civilization->BorderRight += 1;
                }
            }
        }
    }
}