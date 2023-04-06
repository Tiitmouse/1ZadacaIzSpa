//
// Created by Lorena Kovacic on 29.03.2023..
//

#ifndef CMAKESFMLPROJECT_FLOWER_H
#define CMAKESFMLPROJECT_FLOWER_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <array>
#include <cmath>
class Flower{
private:
    sf::CircleShape veliki;
    std::array<sf::CircleShape, 6> latice;
    sf::Vector2<float> middle_stem();
    sf::RectangleShape stem;
    sf::ConvexShape list1, list2;
    sf::Clock sat, satlatica;
    sf::RenderWindow *prozor;
    int laticecounter=0;

public:
    Flower(sf::RenderWindow &prozor);
    void draw();
    void move(int x, int y);
    sf::Vector2<float> middle() const;
};


#endif //CMAKESFMLPROJECT_FLOWER_H
