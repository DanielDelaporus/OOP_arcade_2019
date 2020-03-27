/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SolarFox
*/

#ifndef SOLARFOX_HPP_
#define SOLARFOX_HPP_

#include<string>

class SolarFox : public Games
{
    public:
        SolarFox();//const std::string lib);
        void loop();
        ~SolarFox() {};
    protected:
        std::string lib;
    private:
};

#endif /* !SOLARFOX_HPP_ */
