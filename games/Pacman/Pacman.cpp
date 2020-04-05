/*
** EPITECH PROJECT, 2020
** OOP_arcade
** File description:
** Pacman
*/

#include "Pacman.hpp"
#include "Ghost.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "../../lib/IgraphicLib.hpp"

// IDs :
//      0 - empty > ' '
//      1 - path  > ' '
//      2 - path with player > 'P'
//      3 - path with coin > '.'
//      4 - path with powerup > 'o'
//      5 - wall vertical > '|'
//      6 - wall horizontal > '-'
//      7 - wall corner > '+'
//      8 - path with ghost > 'A'

Pacman::Pacman(std::string const path)
{
    Blinky = new Ghost(13 ,12);
    Pinky = new Ghost(15 ,14);
    game = new Games();

    game->name = "Pacman";

    game->width = 40;
    game->height = 40;

    game->score = 0;

    game->playerdirx = 0;
    game->playerdiry = 0;

    game->posx = 0;
    game->posy = 0;

    int i = 0;
    int j = 0;
    int rs;

    std::ifstream myfile(path);
    std::string line;

    for (i = 0; i < 40; i++)
        for (j = 0; j < 40; j++)
            game->mat[i][j] = 0;
    i = 0;
    if (myfile.is_open()) {
        while (!myfile.eof()) {
            getline(myfile, line);
            for (j = 0; j < 28; j++) {
                line[j] == '0' ? game->mat[i][j] = 0 : rs = 0;
                line[j] == ' ' ? game->mat[i][j] = 1 : rs = 0;
                line[j] == 'P' ? game->mat[i][j] = 2 : rs = 0;
                line[j] == '.' ? game->mat[i][j] = 3 : rs = 0;
                line[j] == 'o' ? game->mat[i][j] = 4 : rs = 0;
                line[j] == '|' ? game->mat[i][j] = 5 : rs = 0;
                line[j] == '-' ? game->mat[i][j] = 6 : rs = 0;
                line[j] == '+' ? game->mat[i][j] = 7 : rs = 0;
                line[j] == 'A' ? game->mat[i][j] = 8 : rs = 0;
            }
            i++;
        }
    }
    while (game->mat[game->posy][game->posx] == 0 || game->mat[game->posy][game->posx] == 1 || game->mat[game->posy][game->posx] == 5 || game->mat[game->posy][game->posx] == 6 || game->mat[game->posy][game->posx] == 7) {
        std::srand(std::time(nullptr));
        game->posx = std::rand() % 26 + 1;
        game->posy = std::rand() % 26 + 1;
    }
    game->mat[game->posy][game->posx] = 2;
    update_ghost();
}

Pacman::~Pacman()
{
}

void Pacman::drawmap() const
{
    int rs;
    char c;

    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 40; j++) {
            game->mat[i][j] == 0 ? c = ' ' : rs = 0;
            game->mat[i][j] == 1 ? c = ' ' : rs = 0;
            game->mat[i][j] == 2 ? c = 'P' : rs = 0;
            game->mat[i][j] == 3 ? c = '.' : rs = 0;
            game->mat[i][j] == 4 ? c = 'o' : rs = 0;
            game->mat[i][j] == 5 ? c = '|' : rs = 0;
            game->mat[i][j] == 6 ? c = '-' : rs = 0;
            game->mat[i][j] == 7 ? c = '+' : rs = 0;
            game->mat[i][j] == 8 ? c = 'A' : rs = 0;
            std::cout << c << ' ';
        }
        std::cout << std::endl;
    }
}

void Pacman::move_player()
{
    if (game->playerdirx == 1 && get_allowed_moves(game->posx, game->posy).right == 0)
        return;
    if (game->playerdirx == -1 && get_allowed_moves(game->posx, game->posy).left == 0)
        return;
    if (game->playerdiry == 1 && get_allowed_moves(game->posx, game->posy).down == 0)
        return;
    if (game->playerdiry == -1 && get_allowed_moves(game->posx, game->posy).up == 0)
        return;

    game->mat[game->posy][game->posx] = 1;

    game->posx += game->playerdirx;
    game->posy += game->playerdiry;

    if (game->mat[game->posy][game->posx] == 3)
        game->score++;
    game->mat[game->posy][game->posx] = 2;
}

int_x4 Pacman::get_allowed_moves(int x, int y)
{
    int_x4 allowed_moves = {0, 0, 0, 0};

    allowed_moves.right      = (game->mat[y][x + 1] == 5 || game->mat[y][x + 1] == 6 || game->mat[y][x + 1] == 7) ? 0 : 1;
    allowed_moves.down       = (game->mat[y + 1][x] == 5 || game->mat[y + 1][x] == 6 || game->mat[y + 1][x] == 7) ? 0 : 1;
    allowed_moves.left       = (game->mat[y][x - 1] == 5 || game->mat[y][x - 1] == 6 || game->mat[y][x - 1] == 7) ? 0 : 1;
    allowed_moves.up         = (game->mat[y - 1][x] == 5 || game->mat[y - 1][x] == 6 || game->mat[y - 1][x] == 7) ? 0 : 1;

    return allowed_moves;
}

#define KEY_DOWN	0402
#define KEY_UP		0403
#define KEY_LEFT	0404
#define KEY_RIGHT	0405

void Pacman::key_event(int key)
{
    if (key == Event::UP && get_allowed_moves(game->posx, game->posy).up == 1) {
        game->playerdirx = 0;
        game->playerdiry = -1;
    }
    if (key == Event::RIGHT && get_allowed_moves(game->posx, game->posy).right == 1) {
        game->playerdirx = 1;
        game->playerdiry = 0;
    }
    if (key == Event::DOWN && get_allowed_moves(game->posx, game->posy).down == 1) {
        game->playerdirx = 0;
        game->playerdiry = 1;
    }
    if (key == Event::LEFT && get_allowed_moves(game->posx, game->posy).left == 1) {
        game->playerdirx = -1;
        game->playerdiry = 0;
    }
}

void Pacman::update_ghost()
{
    int old_x = Blinky->get_x();
    int old_y = Blinky->get_y();
    int c = Blinky->get_last_path();

    Blinky->move(get_allowed_moves(Blinky->get_x(), Blinky->get_y()));

    Blinky->set_last_path(game->mat[Blinky->get_y()][Blinky->get_x()]);

    game->mat[old_y][old_x] = c;
    game->mat[Blinky->get_y()][Blinky->get_x()] = 8;
}

int Pacman::loop(int deltatime)
{
    if (deltatime % 2 == 0 || deltatime % 3 == 0)
        return 0;
    if (Blinky->get_last_path() == 2)
        return 1;
    if (game->score >= 215)
        return 1;
    update_ghost();
    move_player();
    (void) deltatime;
    if (game->posy == Blinky->get_x() && game->posx == Blinky->get_y())
        return 1;
    return 0;
}

Games Pacman::GetGame()
{
    return *game;
}

extern "C" Igames* create() {
    return new Pacman("games/Pacman/map1.pmap");
}

extern "C" void destroy(Igames* p) {
    delete p;
}

int main()
{
    Pacman game("map1.pmap");
    game.drawmap();
}