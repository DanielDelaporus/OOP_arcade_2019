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
        Games()
        {
            for (int i = 0; i < 40; i++) {
                for (int j = 0; j < 30; j++) {
                    if ( i < 3 || j < 3 || i > (40 - 3) || j > (30 - 3))
                        mat[j][i] = 1;
                }
            }
        };
        ~Games() {}
        int height = 30;
        int width = 40;
        int mat[30][40];

    protected:

        std::string name;
    private:
};

#endif /* !GAMES_HPP_ */
