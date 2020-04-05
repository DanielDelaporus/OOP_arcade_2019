/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Debian]
** File description:
** Lib_arcade_sfml
*/

#include "Lib_arcade_sfml.hpp"

Lib_arcade_sfml::Lib_arcade_sfml()
{
    _x = 0;
    _y = 0;
}

Lib_arcade_sfml::~Lib_arcade_sfml()
{
}


void Lib_arcade_sfml::init(int x, int y) {
    window = new sf::RenderWindow(sf::VideoMode(x, y), "Arcade");
    _x = x;
    _y = y;
    window->setFramerateLimit(5);
}

Event Lib_arcade_sfml::Keypressed(int key) {

}

sf::RectangleShape addPixel(sf::Vector2f position, sf::Uint8 red, sf::Uint8 green, sf::Uint8 blue)
{
    sf::RectangleShape pixel;
    pixel.setSize({ 1.f, 1.f });
    pixel.setFillColor({ red, green, blue });
    pixel.setPosition(position);
    return pixel;
}

void Lib_arcade_sfml::refresh(Games game) {
    //sf::RectangleShape box(sf::Vector2f(20, 20));
    for (int i = 0; i < _x; i++)
    {
        for (int j = 0; j < _y; j++) {
            //if (game.mat[i][j] == 0) {
                sf::RectangleShape box(sf::Vector2f(20, 20));
                box.setFillColor(sf::Color::Red);
                box.setPosition(i * size, j * size);
                window->draw(box);
            //}
        }
    }
    window->display();
}

void Lib_arcade_sfml::clear() {
    window->clear();
}

void Lib_arcade_sfml::destroy() {
    window->close();
}