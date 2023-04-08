//
// Created by Lorena Kovacic on 06.04.2023..
//

#ifndef CMAKESFMLPROJECT_BACKGROUND_H
#define CMAKESFMLPROJECT_BACKGROUND_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "iostream"

class Background {
private:
    sf::Texture background_texture;
    sf::Sprite background;
    sf::RenderWindow *prozor;

    void load_texture();

public:
    Background(sf::RenderWindow &prozor);

    void draw();

};


#endif //CMAKESFMLPROJECT_BACKGROUND_H
