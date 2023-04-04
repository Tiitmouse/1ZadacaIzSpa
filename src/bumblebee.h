//
// Created by Lorena Kovačić on 31.03.2023..
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
    sf::RenderWindow* window;
    EllipseShape body,wing1,wing2;
    sf::CircleShape head;
    sf::Texture body_texture,face_texture;
    void load_texture();
public:
    bumblebee(sf::RenderWindow &target);
    void draw();
    void move(int x, int y);

};


#endif //CMAKESFMLPROJECT_BUMBLEBEE_H
