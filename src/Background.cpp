//
// Created by Lorena Kovacic on 06.04.2023..
//

#include "Background.h"

void Background::load_texture() {
    if (!background_texture.loadFromFile("bgr.png")) {
        throw std::exception();
    }
    background.setTexture(background_texture);
    background.setTextureRect(sf::IntRect(0, 300, 1920, 1080));
}

Background::Background(sf::RenderWindow &prozor) {
    try { load_texture(); }
    catch (std::exception &exc) {
        std::cout << exc.what();
    };
    this->prozor = &prozor;
}

void Background::draw() {
    prozor->draw(background);
}


