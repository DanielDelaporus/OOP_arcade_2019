/*
** EPITECH PROJECT, 2020
** OOP_arcade
** File description:
** Ghost
*/

#include "Ghost.hpp"

Ghost::Ghost(int x, int y)
{
    posx = x;
    posy = y;
    last_path = 1;
}

Ghost::~Ghost() {}

int Ghost::get_x()
{
    return posx;
}

int Ghost::get_y()
{
    return posy;
}

char Ghost::get_last_path()
{
    return last_path;
}

void Ghost::move(int_x4 allowed_moves, int c)
{
    last_path = c;
    if (allowed_moves.left == 1 && allowed_moves.right == 1) {
        dirx = 0;
        diry = 0;
    }
    if (allowed_moves.up == 1 && allowed_moves.down == 1) {
        dirx = 0;
        diry = 0;
    }
    posx += dirx;
    posy += diry;
}