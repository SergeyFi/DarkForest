#include "Drawer.h"
#include <thread>
#include <chrono>
#include <cmath>


Drawer::Drawer(struct Universe* Universe)
{
    this->Universe = Universe;
}

void Drawer::StartDrawLoop()
{
    sf::RenderWindow Window(sf::VideoMode(), "DarkForest", sf::Style::Fullscreen);

    while (Window.isOpen())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(16));

        Window.clear({41, 46, 62});

        DrawUniverse(Window);

        Window.display();
    }
}

void Drawer::DrawUniverse(sf::RenderWindow& Window)
{

}
