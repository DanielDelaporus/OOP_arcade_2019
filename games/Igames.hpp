/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Igames
*/

#ifndef IGAMES_HPP_
#define IGAMES_HPP_

#include "Games.hpp"

class Igames {
    public:
        virtual ~Igames() = default;
        virtual void key_event(int key) = 0;
        virtual int loop(int) = 0;
        virtual Games GetGame() = 0;

    protected:
    private:
};

typedef Igames* createg_t();
typedef void destroyg_t(Igames*);

#endif /* !IGAMES_HPP_ */
