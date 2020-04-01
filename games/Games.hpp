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
        ~Games(){};
        int height = 40;
        int width = 100;
        int mat[40][100];
        int posx;
        int posy;
        int playerdirx;
        int playerdiry;
        std::string name;

        void key_event(int key);
    protected:

    private:
};

#endif /* !GAMES_HPP_ */
