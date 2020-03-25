/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Debian]
** File description:
** IgraphicLib
*/

#ifndef IGRAPHICLIB_HPP_
#define IGRAPHICLIB_HPP_

#include "../games/Games.hpp"

class IgraphicLib {
    public:
        virtual ~IgraphicLib() = default;
        virtual void refresh(Games) = 0;
        virtual void clear() = 0;
    protected:
    private:
};

#endif /* !IGRAPHICLIB_HPP_ */
