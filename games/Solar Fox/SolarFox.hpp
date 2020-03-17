/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SolarFox
*/

#ifndef SOLARFOX_HPP_
#define SOLARFOX_HPP_

#include<string>

class SolarFox {
    public:
        SolarFox(const std::string lib);
        void loop();
        ~SolarFox();

    protected:
        std::string lib;
        int pos[2];
        int width = 40;
        int height = 30;
        int matrix[30][40];
    private:
};

#endif /* !SOLARFOX_HPP_ */
