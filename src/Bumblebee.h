//
// Created by Lorena Kovacic on 31.03.2023..
//

#ifndef CMAKESFMLPROJECT_BUMBLEBEE_H
#define CMAKESFMLPROJECT_BUMBLEBEE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "EllipseShape.h"
#include <iostream>
#include <array>
#include <cmath>

class Bumblebee {
private:
    void load_texture();

    sf::RenderWindow *window;
    EllipseShape body, wing1, wing2;
    sf::CircleShape head, rotatingPoint;
    sf::Texture body_texture, face_texture;
    sf::Transform middleMarko;
    sf::Clock satStart, satRotation, satWings;
    float angle = 0, stopMarko = 0;
    bool fullCircleRotation = false, wingFlaping = false;

    sf::Vector2<float> middle();

    void flap();

public:
    Bumblebee(sf::RenderWindow &target);

    Bumblebee(sf::RenderWindow &target, sf::Vector2<float> stoppingPoint);

    void draw();

    void drawMarko();

    void move(int x, int y);

};


#endif //CMAKESFMLPROJECT_BUMBLEBEE_H
