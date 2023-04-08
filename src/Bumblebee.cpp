//
// Created by Lorena Kovacic on 31.03.2023..
//

#include "Bumblebee.h"

void Bumblebee::load_texture() {
    if (!body_texture.loadFromFile("marko_fur.JPG")) {
        throw std::exception();
    }
    if (!face_texture.loadFromFile("marko_face.png")) {
        throw std::exception();
    }
}

Bumblebee::Bumblebee(sf::RenderWindow &target) : body(EllipseShape(sf::Vector2f(50.f, 40.f))),
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
    body.setTexture(&body_texture);
    body.setTextureRect(sf::IntRect(10, 10, 400, 100));
    body.setOutlineThickness(5.f);
    body.setOutlineColor(sf::Color(150, 150, 150, 255));
    body.move(1200, 80);
    //first wing
    wing1.setFillColor(sf::Color(0, 150, 200, 100));
    wing1.setOutlineThickness(2.f);
    wing1.setOutlineColor(sf::Color::Cyan);
    wing1.move(1250, 68);
    wing1.rotate(330);
    //second wing
    wing2.setFillColor(sf::Color(0, 150, 200, 100));
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
    rotatingPoint.setFillColor(sf::Color::Transparent);
    rotatingPoint.move(1244, 110);

}

Bumblebee::Bumblebee(sf::RenderWindow &target, sf::Vector2<float> stoppingPoint) : Bumblebee(target) {
    stopMarko = stoppingPoint.x;
}

void Bumblebee::draw() {
    drawMarko();
}

void Bumblebee::move(int x, int y) {
    body.move(x, y);
    wing1.move(x, y);
    wing2.move(x, y);
    head.move(x, y);
    rotatingPoint.move(x, y);
}

sf::Vector2<float> Bumblebee::middle() {
    sf::Vector2 sredina = rotatingPoint.getPosition();
    sredina.x += rotatingPoint.getRadius();
    sredina.y += rotatingPoint.getRadius();
    return sredina;
}

void Bumblebee::drawMarko() {

    if (middle().x < 1200 && middle().x > 1000) { fullCircleRotation = true; }
    else if (angle >= 360) {
        fullCircleRotation = false;
        angle = 0;
    }
    if (middle().x < 500 && middle().x > 400) { fullCircleRotation = true; }
    else if (angle >= 360) { fullCircleRotation = false; }

    if (satStart.getElapsedTime().asMilliseconds() >= 5000) {
        window->draw(body, middleMarko);
        window->draw(wing1, middleMarko);
        window->draw(head, middleMarko);
        flap();
        if (satRotation.getElapsedTime().asMilliseconds() >= 30 && middle().x > stopMarko) {
            move(-4, 1);
            if (fullCircleRotation) {
                middleMarko.rotate(10, rotatingPoint.getPosition());
                angle = angle + 10;
            }

            satRotation.restart();
        }
    }
}

void Bumblebee::flap() {

    if (wing1.getRotation() <= 300) {
        wingFlaping = true;
    } else if (wing1.getRotation() >= 330) wingFlaping = false;

    if (satWings.getElapsedTime().asMicroseconds() >= 5) {
        if (wingFlaping) {
            wing1.rotate(1);
            wing2.rotate(-1);
        } else {
            wing1.rotate(-1);
            wing2.rotate(1);
        }

        window->draw(wing1, middleMarko);
        window->draw(wing2, middleMarko);

        satWings.restart();
    }

}



