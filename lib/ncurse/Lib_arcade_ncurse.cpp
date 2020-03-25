/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Lib_arcade_ncurse
*/

#include "Lib_arcade_ncurse.hpp"

enum map {
    zero = ' ',
    one = '#',
    two = '*',
};

void printInColor(int index) {
    attron(COLOR_PAIR(index));

    if (index == 0) {
        const char s = map::zero;
        printw(&s);
    }
    if (index == 1) {
        const char s = map::one;
        printw(&s);
    }
    if (index == 2) {
        const char s = map::two;
        printw(&s);
    }
    attroff(COLOR_PAIR(index));
}

Lib_arcade_ncurse::Lib_arcade_ncurse() : wind(initscr())
{
    init_pair(0, COLOR_BLACK, COLOR_WHITE);
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);

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


void Lib_arcade_ncurse::refresh(Games game/*Game*/)
{
    clear();
    for (int i = 0; i < game.height; i++)    {
        for (int j = 0; j < game.width; j++) {
            move(5+5*j, 5+5*i);
            printInColor(game.mat[i][j]);
        }
    }
}

void Lib_arcade_ncurse::clear()
{
    wclear(wind);
}

int main (void)
{
    Games *game = new Games();
    Lib_arcade_ncurse lib;
    lib.refresh(*game);
    return 0;
}