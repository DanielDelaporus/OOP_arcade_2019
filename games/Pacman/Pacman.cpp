/*
** EPITECH PROJECT, 2020
** OOP_arcade
** File description:
** Pacman
*/

#include "Pacman.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

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

int main(int argc, char *argv[])
{
    sf::Event event;
    int dir_x = 0;
    int dir_y = 0;

    while (1) {
        if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Up) {
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
    }
    return 0;
}