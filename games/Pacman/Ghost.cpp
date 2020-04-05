/*
** EPITECH PROJECT, 2020
** OOP_arcade
** File description:
** Ghost
*/

#include "Ghost.hpp"
#include <cstdlib>
#include <ctime>

Ghost::Ghost(int x, int y)
{
    posx = x;
    posy = y;
    last_path = 1;
    diry = -1;
    dirx = 0;
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

int Ghost::get_dirx()
{
    return dirx;
}

int Ghost::get_diry()
{
    return diry;
}

void Ghost::set_last_path(int c)
{
    last_path = c;
}

char Ghost::get_last_path()
{
    return last_path;
}

void Ghost::move(int_x4 allowed_moves)
{
    if (allowed_moves.right == 1 && allowed_moves.left == 1 && allowed_moves.up == 0 && allowed_moves.down == 0 && diry == 0) {
        posx += dirx;
        return;
    }
    if (allowed_moves.right == 0 && allowed_moves.left == 0 && allowed_moves.up == 1 && allowed_moves.down == 1 && dirx == 0) {
        posy += diry;
        return;
    }
    std::srand(std::time(nullptr));

    int done = 0;
    int choice = 0;

    while (!done) {
        choice = std::rand() % 4;
        if (allowed_moves.left == 1 && choice == 0) {
            dirx = -1;
            diry = 0;
            done = 1;
        }
        if (allowed_moves.right == 1 && choice == 1) {
            dirx = 1;
            diry = 0;
            done = 1;
        }
        if (allowed_moves.up == 1 && choice == 2) {
            dirx = 0;
            diry = -1;
            done = 1;
        }
        if (allowed_moves.down == 1 && choice == 3) {
            dirx = 0;
            diry = 1;
            done = 1;
        }
    }

    posx += dirx;
    posy += diry;
}