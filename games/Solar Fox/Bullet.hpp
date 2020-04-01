/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Bullet
*/

#ifndef BULLET_HPP_
#define BULLET_HPP_

class Bullet {
    public:
        Bullet(int tox, int toy, int px, int py);
        ~Bullet();
        int dirx;
        int diry;
        int posx;
        int posy;
        int move(int id);


    protected:
    private:
};

#endif /* !BULLET_HPP_ */
