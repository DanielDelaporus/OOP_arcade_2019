/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Games
*/

#ifndef GAMES_HPP_
#define GAMES_HPP_

#include <string>
#include "Igames.hpp"

class Games : public Igames
{
    public:
        //Games() {};
        int height = 40;
        int width = 100;
        int mat[40][100];
        int posx;
        int posy;
        std::string name;
        void key_event(int key)    // NEVER COLLIDES WITH 0 LAYER (WHICH IS WALLS)
        {
            if (key == KEY_UP && mat[posy - 1][posx] != 0) {
                    mat[posy][posx] = 2;
                    mat[posy - 1][posx] = 1;
                    posy--;
            }
            if (key == KEY_DOWN && mat[posy + 1][posx] != 0) {
                    mat[posy][posx] = 2;
                    mat[posy + 1][posx] = 1;
                    posy++;
            }
            if (key == KEY_LEFT && mat[posy][posx - 1] != 0) {
                    mat[posy][posx] = 2;
                    mat[posy][posx - 1] = 1;
                    posx--;
            }
            if (key == KEY_RIGHT && mat[posy][posx + 1] != 0) {
                    mat[posy][posx] = 2;
                    mat[posy][posx + 1] = 1;
                    posx++;
            }
        }

    protected:
    private:
};

#endif /* !GAMES_HPP_ */
