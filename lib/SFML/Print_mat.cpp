/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Print_mat
*/

#ifndef PRINT_MAT_HPP_
#define PRINT_MAT_HPP_

#include "Lib_arcade_sfml.hpp"

void printlib(int index, Games game, sf::RectangleShape &box)
{
    switch (index)
    {
        case 0:
            box.setFillColor(sf::Color::Black);                      //Walls
            break;
        case 1:
            box.setFillColor(sf::Color::Black);                   //Walls
            break;
        case 2:
            box.setFillColor(sf::Color::Green);                     //Walls
            break;
        case 3:
            box.setFillColor(sf::Color::Yellow);                     //Walls
            break;
        case 4:
            box.setFillColor(sf::Color::Magenta);                     //Walls
            break;
        case 5:
            box.setFillColor(sf::Color::Blue);                     //Walls
            break;
        case 6:
            box.setFillColor(sf::Color::Blue);                     //Walls
            break;
        case 7:
            box.setFillColor(sf::Color::Blue);                   //Walls
            break;
        case 8:
            box.setFillColor(sf::Color::Red);                    //Walls
            break;
        case 9:
            box.setFillColor(sf::Color::Cyan);                    //Walls
            break;
        default:
            break;
    }
}

void printSelect(Games game, sf::RenderWindow *window)
{
    sf::Font font;
    sf::Text text;
    if (font.loadFromFile("lib/SFML/arial.ttf"))
    {
        text.setPosition(250, 50);
        text.setFont(font);
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::Red);
        text.setStyle(sf::Text::Bold);
        text.setString("---ARCADE---");
        window->draw(text);

        text.setCharacterSize(15);

        text.setPosition(250, 150);
        text.setString("---SolarFox---");
        if (game.posx == 0)
            text.setFillColor(sf::Color::Green);
        else
            text.setFillColor(sf::Color::White);
        window->draw(text);
        
        text.setPosition(250, 170);
        text.setString("---Pacman ---");
        if (game.posx == 1)
            text.setFillColor(sf::Color::Green);
        else
            text.setFillColor(sf::Color::White);
        window->draw(text);

        text.setPosition(250, 190);
        text.setString("---Nibbler---");
        if (game.posx == 2)
            text.setFillColor(sf::Color::Green);
        else
            text.setFillColor(sf::Color::White);
        window->draw(text);
        
        text.setPosition(450, 150);
        text.setString("---ncurse---");
        if (game.posy == 0)
            text.setFillColor(sf::Color::Green);
        else
            text.setFillColor(sf::Color::White);
        window->draw(text);
        
        text.setPosition(450, 170);
        text.setString("---SFML---");
        if (game.posy == 1)
            text.setFillColor(sf::Color::Green);
        else
            text.setFillColor(sf::Color::White);
        window->draw(text);

        text.setPosition(450, 190);
        text.setString("---GTK---");
        if (game.posy == 2)
            text.setFillColor(sf::Color::Green);
        else
            text.setFillColor(sf::Color::White);
        window->draw(text);
    }
}

#endif /* !LIB_ARCADE_NCURSE_HPP_ */