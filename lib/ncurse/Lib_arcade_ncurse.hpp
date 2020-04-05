/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Lib_arcade_ncurse
*/

#ifndef LIB_ARCADE_NCURSE_HPP_
#define LIB_ARCADE_NCURSE_HPP_

#include<iostream>
#include<algorithm>
#include<vector>
#include<chrono>
#include<ctime>
#include<sstream>
#include<ncurses.h>
#include <thread>
#include <chrono>

//#include "../../games/Solar Fox/SolarFox.cpp"
#include "../IgraphicLib.hpp"

class Lib_arcade_ncurse : public IgraphicLib {
    public:
        Lib_arcade_ncurse();
        ~Lib_arcade_ncurse();
        virtual void refresh(Games) override;

        void printInColor(int index);

        virtual void clear() override;

        virtual void endgame() override;

        virtual void init(int x, int y) override;
        virtual Event Keypressed() override;
        virtual void destroy() override;

        WINDOW *GetWind() const { return wind; }

        void assign_game(Games g){
            game = g;
        }
        Games game;

    protected:
        WINDOW *wind;
    private:
};


#endif /* !LIB_ARCADE_NCURSE_HPP_ */
