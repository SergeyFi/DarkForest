#include "CycleAction.h"

class CivilizationGeneration: public CycleAction
{
public:
    explicit CivilizationGeneration(double GenerationProbability);

    void Action(class Universe* Universe,std::vector<Void>& Voids, std::vector<std::unique_ptr<Civilization>>& Civilizations) override;

private:

    double Probability;
};
