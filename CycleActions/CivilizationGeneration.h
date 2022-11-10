#include "CycleAction.h"

class CivilizationGeneration: public CycleAction
{
public:
    explicit CivilizationGeneration(double GenerationProbability);

    void Action(Universe* Universe) override;

private:

    double Probability;
};
