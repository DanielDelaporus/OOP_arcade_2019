/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SelectScreen
*/

#ifndef SELECTSCREEN_HPP_
#define SELECTSCREEN_HPP_

#include "../Igames.hpp"
#include "../Games.hpp"

class SelectScreen : public Igames
{
    public:
        SelectScreen();
        ~SelectScreen();
        virtual void key_event(int key) override;
        virtual int loop(int) override;
        virtual Games GetGame() override {return *game;};
        Games *game;
    protected:
    private:
};

#endif /* !SELECTSCREEN_HPP_ */
