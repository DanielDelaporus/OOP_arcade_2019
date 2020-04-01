/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SolarFox
*/

#include "SolarFox.hpp"

#define WIDTH 100
#define HEIGHT 40

SolarFox::SolarFox()
{
    name = "SolarFox";
    posx = WIDTH / 2;
    posy = HEIGHT / 2;
    playerdirx = 0;
    playerdiry = -1;
    for (int i = 0; i < WIDTH; i++)
        for (int j = 0; j < HEIGHT; j++)
            mat[j][i] = 0;
    for (int i = 3; i < WIDTH - 3; i++)
        for (int j = 3; j < HEIGHT - 3; j++)
            mat[j][i] = 2;
    mat[posy][posx] = 1;
}

SolarFox::~SolarFox()
{
    while (!bullets.empty())
        bullets.pop_back();
}

void SolarFox::AddBullet(Bullet bul)
{
    bullets.push_front(bul);
}


void SolarFox::loop(Games *game)
{
    std::list<Bullet>::iterator tmp = bullets.begin();
    for (; tmp != bullets.end(); tmp++) {
        game->mat[tmp->posy][tmp->posx] = 2; //Turns into nothingness
        if (tmp->move(game->mat[tmp->posy + tmp->diry][tmp->posx +tmp->dirx]))
            tmp->~Bullet();
        else 
            game->mat[tmp->posy][tmp->posx] = 4;
    }
}

void SolarFox::key_event(int key, SolarFox *game)    // NEVER COLLIDES WITH 0 LAYER (WHICH IS WALLS)
{
    if (key == KEY_UP && game->mat[game->posy - 1][game->posx] != 0) {
        game->mat[game->posy][game->posx] = 2;
        game->mat[game->posy - 1][game->posx] = 1;
        game->posy--;
        game->playerdirx = 0;
        game->playerdiry = -1;
    }
    if (key == KEY_DOWN && game->mat[game->posy + 1][game->posx] != 0) {
        game->mat[game->posy][game->posx] = 2;
        game->mat[game->posy + 1][game->posx] = 1;
        game->posy++;
        game->playerdirx = 0;
        game->playerdiry = 1;
    }
    if (key == KEY_LEFT && game->mat[game->posy][game->posx - 1] != 0) {
        game->mat[game->posy][game->posx] = 2;
        game->mat[game->posy][game->posx - 1] = 1;
        game->posx--;
        game->playerdiry = 0;
        game->playerdirx = -1;
    }
    if (key == KEY_RIGHT && game->mat[game->posy][game->posx + 1] != 0) {
        game->mat[game->posy][game->posx] = 2;
        game->mat[game->posy][game->posx + 1] = 1;
        game->posx++;
        game->playerdiry = 0;
        game->playerdirx = 1;
    }
    if (key == ' ') {
        Bullet *newbull = new Bullet(game->playerdirx, game->playerdiry, game->posx + game->playerdirx, game->posy + game->playerdiry);
        game->mat[game->posx + game->playerdirx][game->posy + game->playerdiry] = 4;
        game->AddBullet(*newbull);
    }
}
