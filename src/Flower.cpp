//
// Created by Lorena Kovacic on 29.03.2023..
//

#include "Flower.h"

Flower::Flower(sf::RenderWindow &prozor) {
    this->prozor = &prozor;

    veliki.setRadius(100.f);
    veliki.setFillColor(sf::Color::Yellow);
    veliki.setPosition(100.f, 100.f);

    float rotate_angle = 14;

    for (auto &latica: latice) {
        latica.setRadius(60.f);
        latica.setFillColor(sf::Color::Red);
        latica.setPosition(middle());
        latica.rotate(rotate_angle);
        rotate_angle += 60;
    }

    stem.setSize(sf::Vector2f(400.f, 16.f));
    stem.rotate(90);
    stem.move(middle() + sf::Vector2f(8, 0));
    stem.setFillColor(sf::Color::Green);

    list1.setFillColor(sf::Color::Green);
    list1.setPointCount(4);
    list1.setPoint(0, sf::Vector2f(0.f, 230.f));
    list1.setPoint(1, sf::Vector2f(100.f, 150.f));
    list1.setPoint(2, sf::Vector2f(270.f, 110.f));
    list1.setPoint(3, sf::Vector2f(150.f, 200.f));
    list1.move(middle_stem());

    list2.setPosition(0, 0);

    list2.setFillColor(sf::Color::Green);
    list2.setPointCount(4);
    list2.setPoint(0, sf::Vector2f(0.f, 230.f));
    list2.setPoint(1, sf::Vector2f(100.f, 150.f));
    list2.setPoint(2, sf::Vector2f(270.f, 110.f));
    list2.setPoint(3, sf::Vector2f(150.f, 200.f));
    list2.rotate(list2.getRotation() + 60);
    list2.move(middle_stem() - sf::Vector2f(30, 0));


    move(80, 100);
}

void Flower::draw() {
    if (sat.getElapsedTime().asMilliseconds() >= 700) {
        prozor->draw(stem);
    }
    if (sat.getElapsedTime().asMilliseconds() >= 1400) {
        prozor->draw(veliki);
        if (satlatica.getElapsedTime().asMilliseconds() >= 300 && sat.getElapsedTime().asMilliseconds() >= 2000) {
            if (showLaticeCounter < 6) showLaticeCounter++;
            satlatica.restart();
        }
        for (int j = 0; j < showLaticeCounter; j++) prozor->draw(latice[j]);
    }
    if (sat.getElapsedTime().asMilliseconds() >= 4000) {
        prozor->draw(list1);
    }
    if (sat.getElapsedTime().asMilliseconds() >= 4500) {
        prozor->draw(list2);
    }


}

sf::Vector2<float> Flower::middle() const {

    sf::Vector2 sredina = veliki.getPosition();
    sredina.x += veliki.getRadius();
    sredina.y += veliki.getRadius();
    return sredina;
}

void Flower::move(int x, int y) {
    list1.move(x, y);
    list2.move(x, y);
    stem.move(x, y);
    veliki.move(x, y);
    for (auto &latica: latice) {
        latica.move(x, y);
    }
}

sf::Vector2<float> Flower::middle_stem() {
    auto st = stem.getPosition();
    st -= sf::Vector2f(8, 0);
    return st;
}


