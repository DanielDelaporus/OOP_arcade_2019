/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Lib_arcade_ncurse
*/

#ifndef LIB_ARCADE_GTK_HPP_
#define LIB_ARCADE_GTK_HPP_

#include<iostream>
#include<algorithm>
#include<vector>
#include<chrono>
#include<ctime>
#include<sstream>
#include<thread>
#include<caca.h>
#include "../IgraphicLib.hpp"

class Lib_arcade_caca : public IgraphicLib {
    public:
        Lib_arcade_caca();
        ~Lib_arcade_caca();
        virtual void refresh(Games) override;

        virtual void clear() override;

        virtual void endgame() override;

        virtual void init(int x, int y) override;
        virtual Event Keypressed() override;
        virtual void destroy() override;

        void assign_game(Games g){
            game = g;
        }
        Games game;

    protected:
        caca_display_t *display;
        caca_canvas_t *canvas;
    private:
};


#endif /* !LIB_ARCADE_NCURSE_HPP_ */