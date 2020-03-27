/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Lib_arcade_ncurse
*/

#include "Lib_arcade_ncurse.hpp"
#include "../../games/Solar Fox/SolarFox.cpp"


#define LEFTMARGINE 20

enum map {
    zero = '$',
    one = '#',
    two = '*',
};

void printInColor(int index) {

    init_pair(1, COLOR_BLACK, COLOR_CYAN);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLACK);

    if (!has_colors()) {
        printw("terminal doesn't support colors");
        getch();
    }
    start_color();
    
    attron(COLOR_PAIR(index + 1));

    if (index == 0)
        printw("#");

    if (index == 1)
        printw("@");

    if (index == 2)
        printw(" ");

    if (index == 4)
        printw("*");

    if (index == 5)
        printw("*");

    attroff(COLOR_PAIR(index + 1));
}

int Lib_arcade_ncurse::key_event(int key)
{

    game.key_event(key);
    this->refresh(game);
    if (key == 27)
        return 84;
    return 0;
}

Lib_arcade_ncurse::Lib_arcade_ncurse() : wind(initscr())
{
}

Lib_arcade_ncurse::~Lib_arcade_ncurse()
{
    endwin();
}


void Lib_arcade_ncurse::refresh(Games game)
{
    clear();
    for (int i = 0; i < game.height; i++)    {
        for (int j = 0; j < game.width; j++) {
            move(5+i, LEFTMARGINE+j);
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
    SolarFox fox;
    int key = 0;
    Lib_arcade_ncurse *lib = new Lib_arcade_ncurse();
    lib->assign_game((Games)fox);
    keypad(stdscr, TRUE);
    noecho();
    lib->refresh((Games)fox);  
    while (1) {
        if (lib->key_event(getch()) == 84)
            break;
        refresh();
    }
    endwin();
    return 0;
}