/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Print_mat
*/

#ifndef PRINT_MAT_HPP_
#define PRINT_MAT_HPP_

#include "Lib_arcade_ncurse.hpp"

void printSolar(int index, Games game)
{
    init_pair(1, COLOR_BLACK, COLOR_CYAN);
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(3, COLOR_BLACK, COLOR_BLACK);
    init_pair(4, COLOR_BLACK, COLOR_RED);
    init_pair(5, COLOR_GREEN, COLOR_BLACK);
    init_pair(6, COLOR_RED, COLOR_BLACK);
    init_pair(7, COLOR_BLACK, COLOR_BLUE);
    attron(COLOR_PAIR(index + 1));
    switch (index)
    {
        case 0:
            printw("#");                     //Walls
            break;
        case 1:
            if (game.playerdiry == 1)
                printw("v");
            if (game.playerdiry == -1)
                printw("^");
            if (game.playerdirx == 1)
                printw(">");
            if (game.playerdirx == -1)
                printw("<");                     //Walls
            break;
        case 2:
            printw(" ");                     //Walls
            break;
        case 3:
            printw("@");                     //Walls
            break;
        case 4:
            printw("*");                     //Walls
            break;
        case 5:
            printw("*");                     //Walls
            break;
        case 6:
            printw(" ");                     //Walls
            break;
        
        default:
            break;
    }
    attroff(COLOR_PAIR(index + 1));
}

void printPac(int index, Games game)
{
    init_pair(1, COLOR_BLACK, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    init_pair(6, COLOR_BLUE, COLOR_BLACK);
    init_pair(7, COLOR_BLUE, COLOR_BLACK);
    init_pair(8, COLOR_BLUE, COLOR_BLACK);
    init_pair(9, COLOR_RED, COLOR_BLACK);

    attron(COLOR_PAIR(index + 1));
    switch (index)
    {
        case 0:
            printw(" ");                     //Walls
            break;
        case 1:
            printw(" ");
            break;
        case 2:
            if (game.playerdiry == 1)
                printw("v");
            if (game.playerdiry == -1)
                printw("^");
            if (game.playerdirx == 1)
                printw(">");
            if (game.playerdirx == -1 || (game.playerdirx == 0 && game.playerdiry == 0))
                printw("<");                     //Walls
            break;
        case 3:
            printw("*");                     //Walls
            break;
        case 4:
            printw("o");                     //Walls
            break;
        case 5:
            printw("|");                     //Walls
            break;
        case 6:
            printw("-");                     //Walls
            break;
        case 7:
            printw("+");                     //Walls
            break;
        case 8:
            printw("A");                     //Walls
            break;
        
        default:
            break;
    }
    attroff(COLOR_PAIR(index + 1));
}

void printSelect(Games game)
{
    if (!has_colors()) {
        printw("terminal doesn't support colors");
        getch();
    }
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);


    move(25, 50);
    attron(COLOR_PAIR((game.posx == 0) + 1));
    printw("---SolarFox---");
    attroff(COLOR_PAIR((game.posx == 0) + 1));


    move(27, 50);
    attron(COLOR_PAIR((game.posx != 0) + 1));
    printw("--- Pacman ---");
    attroff(COLOR_PAIR((game.posx != 0) + 1));

    move(25, 75);
    attron(COLOR_PAIR((game.posy == 0) + 1));
    printw("---ncurse---");
    attroff(COLOR_PAIR((game.posy == 0) + 1));

    move(27, 75);
    attron(COLOR_PAIR((game.posy != 0) + 1));
    printw("---SFML---");
    attroff(COLOR_PAIR((game.posy != 0) + 1));


}

#endif /* !LIB_ARCADE_NCURSE_HPP_ */