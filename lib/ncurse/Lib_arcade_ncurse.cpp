/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Lib_arcade_ncurse
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<chrono>
#include<ctime>
#include<sstream>
#include<ncurses.h>
#include <thread>
#include <chrono>

#include "Lib_arcade_ncurse.hpp"

Lib_arcade_ncurse::Lib_arcade_ncurse()
{
    WINDOW *wind = initscr();

    if (!has_colors()) {
        printw("terminal doesn't support colors");
        getch();
    }
    start_color();

    

}

Lib_arcade_ncurse::~Lib_arcade_ncurse()
{
    endwin();
}

void Lib_arcade_ncurse::refresh()
{

}

void Lib_arcade_ncurse::clear()
{
    
}