/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SolarFox
*/

#include "SolarFox.hpp"
#include "Enemy.hpp"
#include "../Games.hpp"

#define WIDTH 100
#define HEIGHT 40

void SolarFox::MakeADiamond(int cx, int cy, Games *game)
{
    game->mat[cy    ][cx + 2] = 9;
    game->mat[cy + 1][cx + 1] = 9;
    game->mat[cy + 1][cx + 2] = 9;
    game->mat[cy + 1][cx + 3] = 9;
    game->mat[cy + 2][cx    ] = 9;
    game->mat[cy + 2][cx + 1] = 9;
    game->mat[cy + 2][cx + 2] = 9;
    game->mat[cy + 2][cx + 3] = 9;
    game->mat[cy + 2][cx + 4] = 9;
    game->mat[cy + 3][cx + 1] = 9;
    game->mat[cy + 3][cx + 2] = 9;
    game->mat[cy + 3][cx + 3] = 9;
    game->mat[cy + 4][cx + 2] = 9;
}

SolarFox::SolarFox()
{
    game = new Games;
    game->name = "SolarFox";
    game->score = 0;
    game->posx = WIDTH / 2;
    game->posy = HEIGHT / 2;
    game->width = 100;
    game->height = 40;
    to_destroyy = 0;
    to_destroyx = 0;
    game->playerdirx = 0;
    game->playerdiry = -1;
    for (int i = 0; i < game->width; i++)
        for (int j = 0; j < game->height; j++)
            game->mat[j][i] = 7;
    for (int i = 3; i < WIDTH - 3; i++)
        for (int j = 3; j < HEIGHT - 3; j++)
            game->mat[j][i] = 1;

    game->mat[2][game->posx] = 8;
    upEnemy = new Enemy(game->posx, 2, 0, 1);
    game->mat[game->height - 3][game->posx] = 8;
    downEnemy = new Enemy(game->posx, game->height - 3, 0, -1);

    game->mat[game->posy][2] = 8;
    leftEnemy = new Enemy(2, game->posy, 1, 0);

    game->mat[game->posy][game->width - 3] = 8;
    rightEnemy = new Enemy(game->width -3, game->posy, -1, 0);


    MakeADiamond(15, 10, game);
    MakeADiamond(35, 10, game);
    MakeADiamond(55, 10, game);
    MakeADiamond(75, 10, game);
    MakeADiamond(15, 25, game);
    MakeADiamond(35, 25, game);
    MakeADiamond(55, 25, game);
    MakeADiamond(75, 25, game);

    game->mat[game->posy][game->posx] = 2;
}

SolarFox::~SolarFox()
{
    while (!bullets.empty())
        bullets.pop_back();
}

void SolarFox::AddBullet(Bullet bul, int Ally)
{
    if (Ally)
        bullets.push_front(bul);
    else
        bullets.push_back(bul);
}

int SolarFox::loop(int deltatime)
{
    std::list<Bullet>::iterator tmp = bullets.begin();
    for (; tmp != bullets.end(); tmp++) {
        game->mat[tmp->posy][tmp->posx] = 1;
        if (tmp->posx == to_destroyx && tmp->posy == to_destroyy) {
            tmp->~Bullet();
            to_destroyy = 0;
            to_destroyx = 0;
        }
        else{
            int ret = tmp->move(game->mat[tmp->posy + tmp->diry][tmp->posx +tmp->dirx]);
            if (ret != 0){
                if (ret == 2)
                    return 1;
                if (ret == 3) {
                    to_destroyx = tmp->posx + tmp->dirx;
                    to_destroyy = tmp->posy + tmp->diry;
                }
                else
                    tmp->~Bullet();
            }
            else {
                if (game->mat[tmp->posy + tmp->diry][tmp->posx +tmp->dirx] == 9 && tmp->FromEnemy == 0)
                    game->score++;
                if (tmp->FromEnemy)
                    game->mat[tmp->posy][tmp->posx] = 4;
                else
                    game->mat[tmp->posy][tmp->posx] = 3;
            }
        }
    }
    if (deltatime % 10 == 0) {
        game->mat[game->posy][game->posx] = 1; //nothingness
        if (game->mat[game->posy + game->playerdiry][game->posx + game->playerdirx] != 7 &&
            game->mat[game->posy + game->playerdiry][game->posx + game->playerdirx] != 8 &&
            game->mat[game->posy + game->playerdiry][game->posx + game->playerdirx] != 4 &&
            game->mat[game->posy + game->playerdiry][game->posx + game->playerdirx] != 9) 
        {
            game->mat[game->posy + game->playerdiry][game->posx + game->playerdirx] = 2;
            game->posy += game->playerdiry;
            game->posx += game->playerdirx;
        }
        else
            return 1;
    }

    if (deltatime % 80 == 0) {
        Bullet *newbull1 = new Bullet(upEnemy->dirx, upEnemy->diry, upEnemy->posx + upEnemy->dirx, upEnemy->posy + upEnemy->diry, 1);
        game->mat[upEnemy->posy + upEnemy->diry][upEnemy->posx + upEnemy->dirx] = 4;
        AddBullet(*newbull1, 0);
        Bullet *newbull2 = new Bullet(downEnemy->dirx, downEnemy->diry, downEnemy->posx + downEnemy->dirx, downEnemy->posy + downEnemy->diry, 1);
        game->mat[downEnemy->posy + downEnemy->diry][downEnemy->posx + downEnemy->dirx] = 4;
        AddBullet(*newbull2, 0);
        Bullet *newbull3 = new Bullet(leftEnemy->dirx, leftEnemy->diry, leftEnemy->posx + leftEnemy->dirx, leftEnemy->posy + leftEnemy->diry, 1);
        game->mat[leftEnemy->posy + leftEnemy->diry][leftEnemy->posx + leftEnemy->dirx] = 4;
        AddBullet(*newbull3, 0);
        Bullet *newbull4 = new Bullet(rightEnemy->dirx, rightEnemy->diry, rightEnemy->posx + rightEnemy->dirx, rightEnemy->posy + rightEnemy->diry, 1);
        game->mat[rightEnemy->posy + rightEnemy->diry][rightEnemy->posx + rightEnemy->dirx] = 4;
        AddBullet(*newbull4, 0);
    }

    if (deltatime % 20 == 0)
    {
        upEnemy->moveasside(game);
        downEnemy->moveasside(game);
        leftEnemy->moveasside(game);
        rightEnemy->moveasside(game);
    }
    return 0;
}

void SolarFox::key_event(int key)    // NEVER COLLIDES WITH 0 LAYER (WHICH IS WALLS)
{
    if (key == Event::UP && game->mat[game->posy - 1][game->posx] != 7 && game->playerdiry != 1) {
        game->playerdirx = 0;
        game->playerdiry = -1;
    }
    if (key == Event::DOWN && game->mat[game->posy + 1][game->posx] != 7 && game->playerdiry != -1) {
        game->playerdirx = 0;
        game->playerdiry = 1;
    }
    if (key == Event::LEFT && game->mat[game->posy][game->posx - 1] != 7 && game->playerdirx != 1) {
        game->playerdiry = 0;
        game->playerdirx = -1;
    }
    if (key == Event::RIGHT && game->mat[game->posy][game->posx + 1] != 7 && game->playerdirx != -1) {
        game->playerdiry = 0;
        game->playerdirx = 1;
    }
    if (key == Event::SHOOT) {
        Bullet *newbull = new Bullet(game->playerdirx, game->playerdiry, game->posx + game->playerdirx, game->posy + game->playerdiry, 0);
        game->mat[game->posy + game->playerdiry][game->posx + game->playerdirx] = 3;
        AddBullet(*newbull, 1);
    }
}

extern "C" Igames* create() {
    return new SolarFox;
}

extern "C" void destroy(Igames* p) {
    delete p;
}