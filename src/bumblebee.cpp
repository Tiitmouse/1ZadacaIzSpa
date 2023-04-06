//
// Created by Lorena Kovacic on 31.03.2023..
//

#include "bumblebee.h"

void bumblebee::load_texture() {
    if (!body_texture.loadFromFile("marko_fur.jpg")) {
        throw std::exception();
    }
    if (!face_texture.loadFromFile("marko_face.png")) {
        throw std::exception();
    }
}

bumblebee::bumblebee(sf::RenderWindow &target) : body(EllipseShape(sf::Vector2f(50.f, 40.f))),
                                                 wing1(EllipseShape(sf::Vector2f(20.f, 10.f))),
                                                 wing2(EllipseShape(sf::Vector2f(20.f, 10.f))) {
    window = &target;

    try {
        load_texture();
    }
    catch (std::runtime_error &error) {
        std::cout << error.what();
    }

    //body
    //body.setFillColor(sf::Color::Yellow);
    body.setTexture(&body_texture);
    body.setTextureRect(sf::IntRect(10, 10, 400, 100));
    body.setOutlineThickness(5.f);
    body.setOutlineColor(sf::Color(150, 150, 150, 255));
    body.move(1200, 80);
    //first wing
    wing1.setFillColor(sf::Color::Transparent);
    wing1.setOutlineThickness(2.f);
    wing1.setOutlineColor(sf::Color::Cyan);
    wing1.move(1250, 65);
    wing1.rotate(330);
    //second wing
    wing2.setFillColor(sf::Color::Transparent);
    wing2.setOutlineThickness(2.f);
    wing2.setOutlineColor(sf::Color::Cyan);
    wing2.move(1235, 80);
    wing2.rotate(230);
    //head
    head.setRadius(30.f);
    head.setTexture(&face_texture);
    head.setOutlineThickness(5.f);
    head.setOutlineColor(sf::Color(150, 150, 150, 255));
    head.move(1170, 80);
    //rotating point
    rotatingPoint.setRadius(4.f);
    rotatingPoint.setFillColor(sf::Color::White);
    rotatingPoint.move(1244, 110);


}

bumblebee::bumblebee(sf::RenderWindow &target, sf::Vector2<float> stoppingPoint) : bumblebee(target){
    stopMarko = stoppingPoint.x + 200;
}

void bumblebee::draw() {
    drawMarko();
}

void bumblebee::move(int x, int y) {
    body.move(x, y);
    wing1.move(x, y);
    wing2.move(x, y);
    head.move(x, y);
    rotatingPoint.move(x, y);
}

sf::Vector2<float> bumblebee::middle() {
    sf::Vector2 sredina = rotatingPoint.getPosition();
    sredina.x += rotatingPoint.getRadius();
    sredina.y += rotatingPoint.getRadius();
    return sredina;
}

void bumblebee::drawMarko() {

    if (middle().x < 1000 && middle().x > 900) {circle = true;}
    else if (angle >= 360){ circle = false;}

    if (sat.getElapsedTime().asMilliseconds() >= 5000) {
        window->draw(body, middleMarko);
        window->draw(wing1, middleMarko);
        window->draw(head, middleMarko);
        window->draw(wing2, middleMarko);
        window->draw(rotatingPoint, middleMarko);

        if (sat2.getElapsedTime().asMilliseconds() >= 30 && middle().x > stopMarko) {
            move(-4, 1);
            if (circle) {
                middleMarko.rotate(10, rotatingPoint.getPosition());
                angle = angle + 10;
            }

            sat2.restart();
        }
    }
}



