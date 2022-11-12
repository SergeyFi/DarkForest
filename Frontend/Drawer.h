#pragma once
#include "../Universe/Universe.h"
#include "SFML/Graphics.hpp"

class Drawer
{
public:
    explicit Drawer(class Universe* Universe);

    void StartDrawLoop();

private:

    class Universe* Universe;

    void DrawUniverse(sf::RenderWindow& Window);
};
