/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Print_mat
*/

#ifndef PRINT_MAT_HPP_
#define PRINT_MAT_HPP_

#include "Lib_arcade_ncurse.hpp"

void printlib(int index, Games game)
{
    init_pair(1, COLOR_BLACK, COLOR_BLACK); // Nothing -> 0
    init_pair(2, COLOR_BLACK, COLOR_BLACK); // Nothing 2-> 1
    init_pair(3, COLOR_YELLOW, COLOR_BLACK); //player  1->2 player
    init_pair(4, COLOR_YELLOW, COLOR_BLACK); // coins 4->3  Playershoot
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK); // powerup 5->4 Enemyshoot
    init_pair(6, COLOR_BLUE, COLOR_BLACK);   // Walls horr 
    init_pair(7, COLOR_BLUE, COLOR_BLACK);   // Walls vert 
    init_pair(8, COLOR_BLUE, COLOR_BLACK);   // Walls Cross 0->7
    init_pair(9, COLOR_RED, COLOR_BLACK);    // Enemy 3->8
    init_pair(10, COLOR_BLUE, COLOR_BLUE); //Destructible walls 6->9

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
        case 9:
            printw(" ");                     //Walls
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
    init_pair(3, COLOR_BLACK, COLOR_RED);

    move(20, 62);
    attron(COLOR_PAIR(3));
    printw("---ARCADE---");
    attroff(COLOR_PAIR(3));

    move(25, 50);
    attron(COLOR_PAIR((game.posx == 0) + 1));
    printw("---SolarFox---");
    attroff(COLOR_PAIR((game.posx == 0) + 1));


    move(27, 50);
    attron(COLOR_PAIR((game.posx == 1) + 1));
    printw("--- Pacman ---");
    attroff(COLOR_PAIR((game.posx == 1) + 1));

    move(29, 50);
    attron(COLOR_PAIR((game.posx == 2) + 1));
    printw("--- Nibbler ---");
    attroff(COLOR_PAIR((game.posx == 2) + 1));

    move(25, 75);
    attron(COLOR_PAIR((game.posy == 0) + 1));
    printw("---ncurse---");
    attroff(COLOR_PAIR((game.posy == 0) + 1));

    move(27, 75);
    attron(COLOR_PAIR((game.posy == 1) + 1));
    printw("---SFML---");
    attroff(COLOR_PAIR((game.posy == 1) + 1));

    move(29, 75);
    attron(COLOR_PAIR((game.posy == 2) + 1));
    printw("---GTK---");
    attroff(COLOR_PAIR((game.posy == 2) + 1));
}

#endif /* !LIB_ARCADE_NCURSE_HPP_ */