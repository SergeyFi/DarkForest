#pragma once

#include "../Void/Void.h"
#include "../Civilization/Civilization.h"
#include <vector>
#include <memory>


class CycleAction;

class Universe
{
public:
    explicit Universe(unsigned int Size, unsigned int Cycles, std::vector<std::unique_ptr<CycleAction>>& NewActions);

    void StartSimulation();

    void AddCivilization(std::unique_ptr<Civilization>& Civilization, unsigned int Location);

    std::vector<Void>& GetVoids();

    unsigned int GetSize() const;

    unsigned int GetCurrentCycle() const;

private:

    std::vector<Void> Space;
    std::vector<std::unique_ptr<Civilization>> Civilizations;
    std::vector<std::unique_ptr<CycleAction>> Actions;

    unsigned int CyclesMax;
    unsigned int CyclesCurrent;
};
