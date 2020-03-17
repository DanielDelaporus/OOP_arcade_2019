/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SolarFox
*/

#include "SolarFox.hpp"

SolarFox::SolarFox()
{
    matrix[pos[0]][pos[1]] = 1;
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 30; j++) {
            if ( i < 3 || j < 3 || i > (40 - 3) || j > (30 - 3))
                matrix[j][i] = 4;
        }
    }
}

SolarFox::~SolarFox()
{
}


void SolarFox::loop()
{
    
}
