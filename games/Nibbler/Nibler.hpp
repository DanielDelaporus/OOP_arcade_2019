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
#include <ctime>
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
        void random_fruit();
        Games *game;
        typedef struct snake {
            int x;
            int y;
        } snake_t;
        snake_t s[100];
        typedef struct fruit {
            int x;
            int y;
        } fruit_t;
        fruit_t f;
        int dir;
        int snake_size;
    private:
};

#endif /* !SOLARFOX_HPP_ */
