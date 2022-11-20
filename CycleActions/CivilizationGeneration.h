#include "CycleAction.h"

class CivilizationGeneration: public CycleAction
{
public:
    explicit CivilizationGeneration(double GenerationProbability);

    void Action(class Universe* Universe, FVoidsData& VoidsData, FCivilizationsData& CivilizationsData) override;

private:

    double Probability;
};
