/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SolarFox
*/

#ifndef SOLARFOX_HPP_
#define SOLARFOX_HPP_

class SolarFox {
    public:
        SolarFox();
        void loop();
        ~SolarFox();

    protected:
        int pos[2];
        int width = 40;
        int height = 30;
        int matrix[30][40];
    private:
};

#endif /* !SOLARFOX_HPP_ */
