#include "Drawer.h"
#include "SFML/Graphics.hpp"
#include <thread>
#include <chrono>

void Drawer::StartDrawLoop()
{
    sf::RenderWindow window(sf::VideoMode(2000, 1000), "DarkForest", sf::Style::Fullscreen);

    while (window.isOpen())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(16));

        window.clear({41, 46, 62});

        window.display();
    }
}

Drawer::Drawer(struct Universe* Universe)
{
    this->Universe = Universe;
}
