/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Lib_arcade_ncurse
*/

#include "Lib_arcade_sfml.hpp"
#include <string>
#include "Print_mat.cpp"


#define LEFTMARGINE 40


void Lib_arcade_sfml::printInColor(int index, sf::RectangleShape &box)
{
    printlib(index, game, box);
}

Event Lib_arcade_sfml::Keypressed(){
    assign_game(game);
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            window->close();
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Up)
                return Event::UP;
            if (event.key.code == sf::Keyboard::Down)
                return Event::DOWN;
            if (event.key.code == sf::Keyboard::Right)
                return Event::RIGHT;
            if (event.key.code == sf::Keyboard::Left)
                return Event::LEFT;
            if (event.key.code == sf::Keyboard::Space)
                return Event::SHOOT;
            if (event.key.code == sf::Keyboard::O)
                return Event::NEXT_GAME;
            if (event.key.code == sf::Keyboard::P)
                return Event::NEXT_GRAPH;
            if (event.key.code == sf::Keyboard::L)
                return Event::PREV_GAME;
            if (event.key.code == sf::Keyboard::M)
                return Event::PREV_GRAPH;
            if (event.key.code == sf::Keyboard::Escape || !window->isOpen())
                return Event::QUIT;
        }
    }
    return Event::ENTER;
}

void Lib_arcade_sfml::destroy(){
    window->close();
}
void Lib_arcade_sfml::init(int x, int y)
{
    window = new sf::RenderWindow(sf::VideoMode(x*20, y*20), "Arcade");
    window->setFramerateLimit(30);
}
Lib_arcade_sfml::Lib_arcade_sfml()
{
    init(50, 50);
}
Lib_arcade_sfml::~Lib_arcade_sfml()
{
    delete window;
}
void Lib_arcade_sfml::clear()
{
    window->clear();
}

void Lib_arcade_sfml::refresh(Games game)
{
    clear();
    assign_game(game);
    sf::Font font;
    sf::Text text;
    sf::RectangleShape box(sf::Vector2f(7, 7));
    
    if (game.name != "Select") 
    {
        for (int i = 0; i < game.height; i++)    {
            for (int j = 0; j < game.width; j++) {
                box.setPosition(j * 7, 100 + i * 7);
                printInColor(game.mat[i][j], box);
                window->draw(box);
            }
        }
        if (font.loadFromFile("lib/SFML/arial.ttf"))
        {
            std::string score = "Score: " + std::to_string(game.score);
            text.setString(score);
            text.setFont(font);
            text.setCharacterSize(15);
            text.setFillColor(sf::Color::Red);
            text.setPosition(0, 0);
            text.setStyle(sf::Text::Bold);
        }
    }
    else
        printSelect(game, window);
    window->display();
}

#include <iostream>
#include <fstream>

void Lib_arcade_sfml::endgame(std::string name)
{
    sf::Font font;
    sf::Text text;
    sf::Event event;
    if (game.name == "Select")
        return;
    while (1)
    {
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
                window->close();
                return;
            }
        }
        window->clear();
        if (font.loadFromFile("lib/SFML/arial.ttf"))
        {
            std::string score = "Score: " + std::to_string(game.score);
            text.setString(score);
            text.setFont(font);
            text.setCharacterSize(50);
            text.setFillColor(sf::Color::Red);
            text.setPosition(50, 50);
            text.setStyle(sf::Text::Bold);
            window->draw(text);

            if (game.name != "Pacman") {
                text.setPosition(50, 150);
                std::fstream ifs("./playerprofile/" + name, std::fstream::out | std::fstream::in);
                std::string thescore;
                int line = 0;
                int currentline = 0;
                if (game.name == "Pacman")
                    line = 1;
                if (game.name == "Nibbler")
                    line = 2;
                while (line != currentline)
                    getline(ifs, thescore);
                getline(ifs, thescore);
                if (thescore == "" )
                    thescore = "0";
                text.setString(("Highscore : " + thescore).data());
                ifs.close();
                window->draw(text);
            }
        }
        window->draw(text);
        window->display();
    }
}

extern "C" IgraphicLib* create() {
    return new Lib_arcade_sfml;
}

extern "C" void destroy(IgraphicLib* p) {
    delete p;
}