/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Games
*/

#ifndef GAMES_HPP_
#define GAMES_HPP_

#include <string>

enum Event {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        ENTER,
        SHOOT,
        PAUSE,      //go back to menu
        RESTART,    //restart game
        QUIT,       //exit
        PREV_GRAPH, //previous graphic library
        NEXT_GRAPH, //next graphic library
        PREV_GAME,  //previous game
        NEXT_GAME   //next game
    };

class Games
{
    public:
        Games(){};
        ~Games(){};
        int height;
        int width;
        int mat[40][100];
        int posx;
        int posy;
        int playerdirx;
        int playerdiry;
        int score;
        std::string name;

        //void key_event(int key);
    protected:

    private:
};

#endif /* !GAMES_HPP_ */
