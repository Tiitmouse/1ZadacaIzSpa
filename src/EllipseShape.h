//
// Created by Lorena Kovačić on 31.03.2023..
//

#ifndef CMAKESFMLPROJECT_ELLIPSESHAPE_H
#define CMAKESFMLPROJECT_ELLIPSESHAPE_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <array>
#include <cmath>

class EllipseShape: public sf::Shape
{
private :
    sf::Vector2f m_radius;
public :

    explicit EllipseShape(const sf::Vector2f& radius);

    void setRadius(const sf::Vector2f& radius);

    const sf::Vector2f& getRadius() const;

    virtual std::size_t getPointCount() const;

    virtual sf::Vector2f getPoint(std::size_t index) const;

};


#endif //CMAKESFMLPROJECT_ELLIPSESHAPE_H
