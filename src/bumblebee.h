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

class bumblebee {
private:
    void load_texture();
    sf::RenderWindow* window;
    EllipseShape body,wing1,wing2;
    sf::CircleShape head,rotatingPoint;
    sf::Texture body_texture,face_texture;
    sf::Vector2<float> middle();
    sf::Transform middleMarko;
    sf::Clock sat,sat2;
    float angle = 0;
    float stopMarko = 0;
    bool circle = false;
public:
    bumblebee(sf::RenderWindow &target);
    bumblebee(sf::RenderWindow &target, sf::Vector2<float> stoppingPoint);
    void draw();
    void drawMarko();
    void move(int x, int y);

};


#endif //CMAKESFMLPROJECT_BUMBLEBEE_H
