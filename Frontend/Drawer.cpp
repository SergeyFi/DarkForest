#include "Drawer.h"
#include <thread>
#include <chrono>
#include "../Tools/Logger.h"

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
    float Position = 0;

    auto VoidSize = float(Window.getSize().x) / float(Universe->GetSize());

    for (auto i = 0; i < Universe->GetSize(); ++i)
    {
        sf::RectangleShape VoidShape({VoidSize, 100.0f});

        if (i % 2)
        {
            VoidShape.setFillColor({130, 170, 255});
        }
        else
        {
            VoidShape.setFillColor({156, 196, 255});
        }

        VoidShape.setPosition(Position, float(Window.getSize().y) / 2);

        Window.draw(VoidShape);

        Position += VoidSize;
    }
}
