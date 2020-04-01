/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Bullet
*/

#include "Bullet.hpp"

Bullet::Bullet(int tox, int toy, int px, int py)
{
    dirx = tox;
    diry = toy;
    posx = px;
    posy = py;

};
int Bullet::move(int id)
{
    if (id == 0) {
        return 1;
    }
    posx += dirx;
    posy += diry;
    return 0;
};
Bullet::~Bullet()
{
}
