/*
** EPITECH PROJECT, 2020
** OOP_arcade
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include <iostream>
#include "Ghost.hpp"
#include "../Igames.hpp"
#include "../Games.hpp"

class Ghost;

struct int_x4
{
    int up;
    int right;
    int down;
    int left;
};

class Pacman : public Igames {
    public:
        Pacman(std::string const);
        ~Pacman();
        void drawmap() const;
        void move_player();
        void update_ghost();
        void key_event(int);
        int loop(int);
        Games GetGame();
        int_x4 get_allowed_moves(int, int);

    protected:
        Games *game;
        Ghost *Blinky;
        Ghost *Pinky;
};

#endif /* !PACMAN_HPP_ */