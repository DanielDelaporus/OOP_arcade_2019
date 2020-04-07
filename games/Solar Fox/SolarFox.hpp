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

class SolarFox : public Igames
{
    public:
        SolarFox();//const std::string lib);
        void AddBullet(Bullet bul, int);
        void MakeADiamond(int cx, int cy, Games*);

        int loop(int deltatime);
        virtual void key_event(int) override;//, SolarFox*);
        ~SolarFox();
        int is_around(int, int, int);

        virtual Games GetGame() override {return *game;};
        Enemy *upEnemy;
        Enemy *downEnemy;
        Enemy *leftEnemy;
        Games *game;
        Enemy *rightEnemy;

    protected:
        std::list<Bullet> bullets;
        std::string lib;


    private:
};

#endif /* !SOLARFOX_HPP_ */
