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
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

#include "../IgraphicLib.hpp"

class Lib_arcade_sfml : public IgraphicLib {
    public:
        Lib_arcade_sfml();
        ~Lib_arcade_sfml();
        virtual void refresh(Games) override;

        void printInColor(int index, sf::RectangleShape &box);

        virtual void clear() override;

        virtual void endgame(std::string) override;

        virtual void init(int x, int y) override;
        virtual Event Keypressed() override;
        virtual void destroy() override;

        sf::RenderWindow *GetWind() const { return window; }

        void assign_game(Games g){
            game = g;
        }
        Games game;

    protected:
        sf::RenderWindow *window;
    private:
};


#endif /* !LIB_ARCADE_NCURSE_HPP_ */
