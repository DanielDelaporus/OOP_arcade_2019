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
    //      2 - path with player
    //      3 - path with coin
    //      4 - path with powerup
    //      5 - wall vertical
    //      6 - wall horizontal
    //      7 - wall corner
    //      8 - path with ghost
    pos_x = 1;
    pos_y = 1;
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

void Pacman::move_player(int dir_x, int dir_y)
{
    pos_x += dir_x;
    pos_y += dir_y;
}

int_x4 Pacman::get_allowed_moves() const
{
    int_x4 allowed_moves = {0, 0, 0, 0};
    if (matrix[pos_x][pos_y + 1] != 5 && matrix[pos_x][pos_y + 1] != 6 && matrix[pos_x][pos_y + 1] != 7)
        allowed_moves.up = 1;
    if (matrix[pos_x + 1][pos_y] != 5 && matrix[pos_x + 1][pos_y] != 6 && matrix[pos_x + 1][pos_y] != 7)
        allowed_moves.right = 1;
    if (matrix[pos_x][pos_y - 1] != 5 && matrix[pos_x][pos_y - 1] != 6 && matrix[pos_x][pos_y - 1] != 7)
        allowed_moves.down = 1;
    if (matrix[pos_x - 1][pos_y] != 5 && matrix[pos_x - 1][pos_y] != 6 && matrix[pos_x - 1][pos_y] != 7)
        allowed_moves.left = 1;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Pacman");
    window.setFramerateLimit(5);
    
    sf::RectangleShape wall(sf::Vector2f(20, 20));
    wall.setFillColor(sf::Color::Black);

    sf::RectangleShape player(sf::Vector2f(20, 20));
    player.setFillColor(sf::Color::Yellow);
    
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
            int_x4 allowed_moves = game.get_allowed_moves();
            if (event.key.code == sf::Keyboard::Up && allowed_moves.up = 1) {
                dir_x = 0;
                dir_y = 1;
            }
            if (event.key.code == sf::Keyboard::Down && allowed_moves.down = 1) {
                dir_x = 0;
                dir_y = -1;
            }
            if (event.key.code == sf::Keyboard::Right && allowed_moves.right = 1) {
                dir_x = 1;
                dir_y = 0;
            }
            if (event.key.code == sf::Keyboard::Left && allowed_moves.left = 1) {
                dir_x = -1;
                dir_y = 0;
            }
        }
        game.move_player(dir_x, dir_y);
        window.clear();
        window.draw(player);
        window.display();
    }
    window.close();
    return 0;
}