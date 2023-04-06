#include <iostream>
#include <SFML/Graphics.hpp>
#include "Background.h"
#include "Flower.h"
#include "bumblebee.h"
int main()
{
    sf::RenderWindow window = sf::RenderWindow{ { 1920u, 780 }, "CMake SFML Project" };
    window.setFramerateLimit(144);
    Background bg(window);
    Flower cvijet(window);
    bumblebee Marko(window,cvijet.middle());

    cvijet.move(300.f,50.f);
    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        bg.draw();
        cvijet.draw();
        Marko.draw();
        window.display();
    }
}