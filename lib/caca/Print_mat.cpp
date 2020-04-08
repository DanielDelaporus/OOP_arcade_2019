/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Print_mat
*/

#ifndef PRINT_MAT_HPP_
#define PRINT_MAT_HPP_

#include <caca.h>

void printlib(int index, int x, int y, caca_canvas *canvas)
{
    switch (index)
    {
        case 0:
            caca_put_char(canvas, x, y, ' ');
            break;
        case 1:
            caca_put_char(canvas, x, y, ' ');
            break;
        case 2:
            caca_put_char(canvas, x, y, 'P');
            break;
        case 3:
            caca_put_char(canvas, x, y, '.');
            break;
        case 4:
            caca_put_char(canvas, x, y, 'o');
            break;
        case 5:
            caca_put_char(canvas, x, y, 'W');
            break;
        case 6:
            caca_put_char(canvas, x, y, 'W');
            break;
        case 7:
            caca_put_char(canvas, x, y, 'W');
            break;
        case 8:
            caca_put_char(canvas, x, y, 'A');
            break;
        case 9:
            caca_put_char(canvas, x, y, '9');
            break;
        default:
            break;
    }
}

/*
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
*/

#endif /* !LIB_ARCADE_NCURSE_HPP_ */