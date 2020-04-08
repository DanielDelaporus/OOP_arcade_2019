/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SolarFox
*/

#ifndef SOLARFOX_HPP_
#define SOLARFOX_HPP_

#include<string>
#include<list>
#include <algorithm>
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "../Igames.hpp"
#include "../Games.hpp"

class Nibler : public Igames
{
    public:
        Nibler();
        int loop(int deltatime);
        virtual void key_event(int) override;
        ~Nibler();

        virtual Games GetGame() override {return *game;};

    protected:
        Games *game;
        int fx;
        int fy;
        typedef struct snake {
            int x;
            int y;
        } snake;
        snake s[100];
        typedef struct fruit {
            int x;
            int y;
        } fruit;
        fruit f;
        int dir;
        int snake_size;
    private:
};

#endif /* !SOLARFOX_HPP_ */
