/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Enemy
*/

#ifndef ENEMY_HPP_
#define ENEMY_HPP_
#include "../Games.hpp"

class Enemy {
    public:
        Enemy(int px, int py, int dx, int dy)
        {
            posx = px;
            posy = py;
            dirx = dx;
            diry = dy;
        }
        void moveasside(Games *game)
        {
            game->mat[posy][posx] = 7;
            if (dirx == 0) {
                if (posx != 3 && game->posx < posx)
                    posx -= 1;
                if (posx != 100 - 4 && game->posx > posx)
                    posx += 1;                                       //In func of the size
            }
            else {
                int dep = (std::rand() % 3) - 1;
                if (posy != 3 && game->posy < posy)
                    posy -= 1;
                if (posy != 40 - 4 && game->posy > posy)
                    posy += 1; 
            }   
            game->mat[posy][posx] = 8;
        }
        ~Enemy();
        int posx;
        int posy;
        int dirx; 
        int diry;

    protected:
    private:
};

#endif /* !ENEMY_HPP_ */
