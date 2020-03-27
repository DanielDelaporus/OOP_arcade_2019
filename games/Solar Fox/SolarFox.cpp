/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SolarFox
*/

#include "SolarFox.hpp"
#include "../Games.hpp"
//#include "../lib/ncurse/.hpp"
//#include "../lib/SFML/.hpp"
#define WIDTH 100
#define HEIGHT 40

SolarFox::SolarFox()
{
    name = "SolarFox";
    posx = WIDTH / 2;
    posy = HEIGHT / 2;
    for (int i = 0; i < WIDTH; i++)
        for (int j = 0; j < HEIGHT; j++)
            mat[j][i] = 0;
    for (int i = 3; i < WIDTH - 3; i++)
        for (int j = 3; j < HEIGHT - 3; j++)
            mat[j][i] = 2;
    mat[posy][posx] = 1;
}

void SolarFox::loop()
{
}
