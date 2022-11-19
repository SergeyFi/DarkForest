#include "CycleAction.h"

class CivilizationGeneration: public CycleAction
{
public:
    explicit CivilizationGeneration(double GenerationProbability);

    void Action(class Universe* Universe, FVoidsData& Voids, FCivilizationsData& Civilizations) override;

private:

    double Probability;
};
