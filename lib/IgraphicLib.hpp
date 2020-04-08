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
        virtual void init(int x, int y) = 0;
        virtual Event Keypressed() = 0;
        virtual void refresh(Games) = 0;
        virtual void clear() = 0;
        virtual void destroy() = 0;
        virtual void endgame(std::string) = 0;
        virtual void assign_game(Games g) = 0;
    protected:
    private:
};

typedef IgraphicLib* create_t();
typedef void destroy_t(IgraphicLib*);

#endif /* !IGRAPHICLIB_HPP_ */
