#pragma once
#include "../Universe/Universe.h"

class Drawer
{
public:
    explicit Drawer(class Universe* Universe);

    void StartDrawLoop();

private:

    class Universe* Universe;
};
