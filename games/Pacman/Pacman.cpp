/*
** EPITECH PROJECT, 2020
** OOP_arcade
** File description:
** Pacman
*/

#include "Pacman.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../lib/SFML/Lib_arcade_sfml.hpp"

Pacman::Pacman()
{
    // IDs :
    //      0 - empty
    //      1 - path
    //      2 - wall
    //      3 - path with coin
    //      4 - path with powerup
}

Pacman::~Pacman()
{
}

void Pacman::drawmap() const
{
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 40; j++)
            std::cout << matrix[i][j];
        std::cout << std::endl;
    }
}

void move(int dir_x, int dir_y)
{
    (void) dir_x;
    (void) dir_y;
    return;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Pacman");
    window.setFramerateLimit(5);
    
    sf::RectangleShape box(sf::Vector2f(20, 20));
    box.setFillColor(sf::Color::Red);

    sf::RectangleShape apple(sf::Vector2f(20, 20));
    apple.setFillColor(sf::Color::Green);
    
    sf::Clock timer;

    Pacman game;
    int dir_x = 0;
    int dir_y = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
        }
        if (timer.getElapsedTime().asMicroseconds() > 800)
        {
            game.drawmap();
            timer.restart();
        }
        if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::E) {
                dir_x = 0;
                dir_y = 1;
            }
            if (event.key.code == sf::Keyboard::Down) {
                dir_x = 0;
                dir_y = -1;
            }
            if (event.key.code == sf::Keyboard::Right) {
                dir_x = 1;
                dir_y = 0;
            }
            if (event.key.code == sf::Keyboard::Left) {
                dir_x = -1;
                dir_y = 0;
            }
        }
        move(dir_x, dir_y);
        window.clear();

        window.display();
    }
    window.close();
    return 0;
}