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
#include "../Games.hpp"

class SolarFox : public Games
{
    public:
        SolarFox();//const std::string lib);
        void AddBullet(Bullet bul);

        void loop(Games *game);
        virtual void key_event(int key, SolarFox*);
        ~SolarFox();
        int playerdirx;
        int playerdiry;

    protected:
        std::list<Bullet> bullets;
        std::string lib;
    private:
};

#endif /* !SOLARFOX_HPP_ */
