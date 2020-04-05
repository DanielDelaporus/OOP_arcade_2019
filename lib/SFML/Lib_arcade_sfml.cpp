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
    if (game.name == "SolarFox")
        printSolar(index, game, box);
    if (game.name == "Pacman")
        printPac(index, game, box);
}

Event Lib_arcade_sfml::Keypressed(){
    assign_game(game);
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            window->close();
    }
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
        if (event.key.code == sf::Keyboard::PageUp)
            return Event::SHOOT;
        if (event.key.code == sf::Keyboard::O)
            return Event::NEXT_GAME;
        if (event.key.code == sf::Keyboard::P)
            return Event::NEXT_GRAPH;
        if (event.key.code == sf::Keyboard::Escape || !window->isOpen())
            return Event::QUIT;
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
    sf::RectangleShape box(sf::Vector2f(40, 40));
    if (game.name != "Select") 
    {
        for (int i = 0; i < game.height; i++)    {
            for (int j = 0; j < game.width; j++) {
                box.setPosition(j * 5, i * 5);
                //box.setFillColor(sf::Color::Red);
                printInColor(game.mat[i][j], box);
                window->draw(box);
                //move(5+i, LEFTMARGINE+j);
                
            }
        }
        window->display();
        //move(45, (LEFTMARGINE/2) + 64);
        //printw("Score : ");
        //printw(std::to_string(game.score).data());
    }
    else
    {
        //printSelect(game);
    }
}

void Lib_arcade_sfml::endgame()
{
    /*
    if (game.name == "Select")
        return;
    while (getch())
    {
        clear();
        //move(30, (LEFTMARGINE/2) + 64);
        printw("GAME OVER");
        move(32, (LEFTMARGINE/2) + 64);
        if (game.score == 1)//Total
            printw("You Win !");
        else {
            printw("Score : ");
            printw(std::to_string(game.score).data());
        }
        
    }
    */
}

extern "C" IgraphicLib* create() {
    return new Lib_arcade_sfml;
}

extern "C" void destroy(IgraphicLib* p) {
    delete p;
}