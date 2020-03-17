/*
** EPITECH PROJECT, 2020
** OOP_arcade
** File description:
** Pacman
*/

#include "Pacman.hpp"
#include <iostream>

Pacman::Pacman()
{
    // IDs :
    //      0 - empty
    //      1 - path
    //      2 - wall
    //      3 - path with coin
    //      4 - path with powerup

    for (int i = 0; i < 40; i++)
        for (int j = 0; j < 40; j++)
            matrix[i][j] = 0;
    
    for (int j = 0; j < 40; j++)
        matrix[0][j] = 2;

    for (int j = 0; j < 40; j++)
        matrix[39][j] = 2;
    
    for (int i = 0; i < 40; i++)
        matrix[i][0] = 2;
    
    for (int i = 0; i < 40; i++)
        matrix[i][39] = 2;
    
    
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