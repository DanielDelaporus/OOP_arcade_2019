/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SolarFox
*/

#include "Nibler.hpp"
#include "Enemy.hpp"
#include "../Games.hpp"

#define WIDTH 100
#define HEIGHT 40

Nibler::Nibler()
{
    game = new Games;
    game->name = "SolarFox";
    game->score = 0;
    game->posx = WIDTH / 2;
    game->posy = HEIGHT / 2;
    game->width = 20;
    game->height = 20;
    game->playerdirx = 0;
    game->playerdiry = -1;
    for (int i = 0; i < game->width; i++)
        for (int j = 0; j < game->height; j++)
            game->mat[j][i] = 0;
    snake_size = 3;
    dir = 0;
    f.x = 
}

Nibler::~Nibler()
{
    delete game;
}

int Nibler::loop(int deltatime)
{
    if (deltatime % 80 ==0) {
        for (int i = 1; i < snake_size; i++)
        {
            s[i].x = s[i-1].x;
            s[i].y = s[i-1].y;
        }
        if (dir == 3)
            s[0].x += 1;
        if (dir == 2)
            s[0].x -= 1;
        if (dir == 1)
            s[0].y -= 1;
        if (dir == 0)
            s[0].y += 1;
        for (int i = 0; i < snake_size; i++) {
            game->mat[s[i].x][s[i].y] = 7;
        }
        return 0;
    }
}

void Nibler::key_event(int key)    // NEVER COLLIDES WITH 0 LAYER (WHICH IS WALLS)
{
    if (key == Event::UP && game->mat[game->posy - 1][game->posx] != 7 && game->playerdiry != 1) {
        if (dir != 0)
            dir = 1;
    }
    if (key == Event::DOWN && game->mat[game->posy + 1][game->posx] != 7 && game->playerdiry != -1) {
        if (dir != 1)
            dir = 0;
    }
    if (key == Event::LEFT && game->mat[game->posy][game->posx - 1] != 7 && game->playerdirx != 1) {
        if (dir != 3)
            dir = 2;
    }
    if (key == Event::RIGHT && game->mat[game->posy][game->posx + 1] != 7 && game->playerdirx != -1) {
        if (dir != 2)
            dir = 3;
    }
}

extern "C" Igames* create() {
    return new Nibler;
}

extern "C" void destroy(Igames* p) {
    delete p;
}