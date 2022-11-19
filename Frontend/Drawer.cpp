#include "Drawer.h"
#include <thread>
#include <chrono>
#include <cmath>
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
    sf::Image Image;
    Image.create(Universe->GetSize().X, Universe->GetSize().Y, {26, 31, 47});

    for (auto x = 0; x < Universe->GetSize().X; ++x)
    {
        for (auto y = 0; y < Universe->GetSize().Y; ++y)
        {
            auto CivCandidate = Universe->GetVoids().Voids[x][y].Civilization;

            if (CivCandidate != nullptr)
            {
                auto CivColor = CivCandidate->Color;
                Image.setPixel(x, y, {CivColor.Red, CivColor.Green, CivColor.Blue});
            }
        }
    }

    sf::Texture Texture;
    Texture.loadFromImage(Image);

    sf::Sprite Sprite;
    Sprite.setTexture(Texture);
    Sprite.scale(3.0f, 3.0f);

    Window.draw(Sprite);
}
