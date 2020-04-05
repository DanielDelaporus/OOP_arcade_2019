/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Print_mat
*/

#ifndef PRINT_MAT_HPP_
#define PRINT_MAT_HPP_

#include "Lib_arcade_sfml.hpp"

void printSolar(int index, Games game, sf::RectangleShape &box)
{
    switch (index)
    {
        case 0:
            box.setFillColor(sf::Color::Cyan);                      //Walls
            break;
        case 1:
            box.setFillColor(sf::Color::Black);                   //Walls
            break;
        case 2:
            box.setFillColor(sf::Color::White);                     //Walls
            break;
        case 3:
            box.setFillColor(sf::Color::Blue);                     //Walls
            break;
        case 4:
            box.setFillColor(sf::Color::Green);                     //Walls
            break;
        case 5:
            box.setFillColor(sf::Color::Yellow);                     //Walls
            break;
        case 6:
            box.setFillColor(sf::Color::Red);                     //Walls
            break;
        
        default:
            break;
    }
}

void printPac(int index, Games game, sf::RectangleShape &box)
{
    switch (index)
    {
        case 0:
            box.setFillColor(sf::Color::Cyan);                      //Walls
            break;
        case 1:
            box.setFillColor(sf::Color::Black);                   //Walls
            break;
        case 2:
            box.setFillColor(sf::Color::White);                     //Walls
            break;
        case 3:
            box.setFillColor(sf::Color::Blue);                     //Walls
            break;
        case 4:
            box.setFillColor(sf::Color::Green);                     //Walls
            break;
        case 5:
            box.setFillColor(sf::Color::Yellow);                     //Walls
            break;
        case 6:
            box.setFillColor(sf::Color::Red);                     //Walls
            break;
        case 7:
            box.setFillColor(sf::Color::Black);                   //Walls
            break;
        case 8:
            box.setFillColor(sf::Color::Magenta);                    //Walls
            break;
        
        default:
            break;
    }
}

#endif /* !LIB_ARCADE_NCURSE_HPP_ */