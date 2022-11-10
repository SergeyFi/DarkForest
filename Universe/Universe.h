#pragma once

#include "../Void/Void.h"
#include "../Civilization/Civilization.h"
#include <vector>
#include <memory>


class CycleAction;

class Universe
{
public:
    explicit Universe(unsigned int Size, unsigned int Cycles, std::vector<std::unique_ptr<CycleAction>> NewActions);

    void StartSimulation();

private:

    std::vector<Void> Space;
    std::vector<Civilization> Civilizations;
    std::vector<std::unique_ptr<CycleAction>> Actions;

    unsigned int CyclesMax;
    unsigned int CyclesCurrent;
};
