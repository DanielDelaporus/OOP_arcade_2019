/*
** EPITECH PROJECT, 2020
** OOP_arcade
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include <iostream>

class Pacman {
    public:
        Pacman();
        ~Pacman();
        void drawmap() const;

    protected:
        int pos[2];
        int matrix[40][40];
        std::string map_path;
    private:
};

#endif /* !PACMAN_HPP_ */
