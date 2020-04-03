/*
** EPITECH PROJECT, 2020
** OOP_arcade
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include <iostream>
#include "../Igames.hpp"

struct int_x4
{
    int up;
    int right;
    int down;
    int left;
};

class Pacman : public Igames { 
    public:
        Pacman();
        ~Pacman();
        void drawmap() const;
        void move_player(int, int);
        int_x4 get_allowed_moves() const;

    protected:
        int pos_x;
        int pos_y;
        int matrix[40][40];
        std::string map_path;
    private:
};

#endif /* !PACMAN_HPP_ */
