/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SelectScreen
*/

#include "SelectScreen.hpp"

SelectScreen::SelectScreen()
{
    game = new Games;
    game->posx = 0;
    game->posy = 0;
    game->name = "Select";
    game->playerdirx = 0; //0: COLOMN GAME     1: COLOMN LIB   
}


void SelectScreen::key_event(int key)
{
    if (game->playerdirx == 0) {
        if (key == Event::UP && game->posx != 0)
            game->posx -= 1;
        if (key == Event::DOWN && game->posx != 2)
            game->posx += 1;
        if (key == Event::LEFT && game->playerdirx != 0)
            game->playerdirx -= 1;
        if (key == Event::RIGHT && game->playerdirx != 1)
            game->playerdirx += 1;
    }
    else
    {
        if (key == Event::UP && game->posy != 0)
            game->posy -= 1;
        if (key == Event::DOWN && game->posy != 2)
            game->posy += 1;
        if (key == Event::LEFT && game->playerdirx != 0)
            game->playerdirx -= 1;
        if (key == Event::RIGHT && game->playerdirx != 1)
            game->playerdirx += 1;
    }
    if (key == Event::SHOOT)
        game->score = 1;
    
}

int SelectScreen::loop(int deltatime)
{
    (void)deltatime;
    if (game->score != 0)
        return 1;
    return 0;
}

SelectScreen::~SelectScreen(){}


extern "C" Igames* create() {
    return new SelectScreen;
}

extern "C" void destroy(Igames* p) {
    delete p;
}