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
    sf::Image Image;
    Image.create(Universe->GetSize(), 1, sf::Color::Black);

    for (auto i = 0; i < Universe->GetSize(); ++i)
    {
        if (Universe->GetVoids()[i].Civilization == nullptr)
        {
            Image.setPixel(i, 0, {130, 170, 255});
        }
        else
        {
            auto CivColor = Universe->GetVoids()[i].Civilization->Color;
            Image.setPixel(i, 0, {CivColor.Red, CivColor.Green, CivColor.Blue});
        }
    }

    for (auto i = 0; i < std::ceil(Universe->GetSize() / float(TextureSizeMax)); ++i)
    {
        sf::Texture Texture;
        Texture.loadFromImage(Image, {i * TextureSizeMax, 0, TextureSizeMax, 1});

        auto VoidSize = float(Window.getSize().x) / float(Universe->GetSize());

        sf::Sprite Sprite;
        Sprite.setTexture(Texture);
        Sprite.scale(VoidSize, 80.0f);
        Sprite.setPosition(i * VoidSize * TextureSizeMax, float(Window.getSize().y) / 2);

        Window.draw(Sprite);
    }
}
