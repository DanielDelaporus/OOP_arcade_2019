/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** Lib_arcade_ncurse
*/

#include "Lib_arcade_ncurse.hpp"
//#include "../../games/Solar Fox/Bullet.cpp"
//#include "../../games/Games.hpp"
#include "../../games/Select/SelectScreen.hpp"
#include <string>
#include "Print_mat.cpp"


#define LEFTMARGINE 40


void Lib_arcade_ncurse::printInColor(int index) {


    if (!has_colors()) {
        printw("terminal doesn't support colors");
        getch();
    }
    start_color();

    if (game.name == "SolarFox")
        printSolar(index, game);
    if (game.name == "Pacman")
        printPac(index, game);

}

void ref(){ refresh();}

Event Lib_arcade_ncurse::Keypressed(){
    assign_game(game);
    int key = getch();
    timeout(25);
    if (key == KEY_UP)
        return Event::UP;
    if (key == KEY_DOWN)
        return Event::DOWN;
    if (key == KEY_LEFT)
        return Event::LEFT;
    if (key == KEY_RIGHT)
        return Event::RIGHT;
    if (key == ' ')
        return Event::SHOOT;
    if (key == 27)
        return Event::QUIT;
    return Event::ENTER;
}

void Lib_arcade_ncurse::destroy(){ endwin();}
void Lib_arcade_ncurse::init(int x, int y){(void)x; (void)y; wind = initscr();}
Lib_arcade_ncurse::Lib_arcade_ncurse(){ init(0, 0); keypad(stdscr, TRUE); noecho(); nodelay(wind, TRUE); }
Lib_arcade_ncurse::~Lib_arcade_ncurse(){ destroy();}
void Lib_arcade_ncurse::clear(){ erase();}

void Lib_arcade_ncurse::refresh(Games game)
{
    clear();
    assign_game(game);
    if (game.name != "Select") 
    {
        for (int i = 0; i < game.height; i++)    {
            for (int j = 0; j < game.width; j++) {
                move(5+i, LEFTMARGINE+j);
                printInColor(game.mat[i][j]);
            }
        }
        move(45, (LEFTMARGINE/2) + 64);
        printw("Score : ");
        printw(std::to_string(game.score).data());
    }
    else
    {
        printSelect(game);
    }
    ref();
}

void Lib_arcade_ncurse::endgame()
{
    if (game.name == "Select")
        return;
    while (getch())
    {
        clear();
        move(30, (LEFTMARGINE/2) + 64);
        printw("GAME OVER");
        move(32, (LEFTMARGINE/2) + 64);
        if (game.score == 1)//Total
            printw("You Win !");
        else {
            printw("Score : ");
            printw(std::to_string(game.score).data());
        }
    }
}



//int main (void)
//{
//    SelectScreen *fox = new SelectScreen;
//    int key = 0;
//    int time = 0;
//    Lib_arcade_ncurse *lib = new Lib_arcade_ncurse();
//    lib->assign_game(*fox->game);
//    lib->refresh(lib->game);
//    while (1000) {
//        Event nowkey = lib->Keypressed();
//        if (nowkey == Event::QUIT)
//            break;
//        else
//            fox->key_event(nowkey);
//        if (fox->loop(time))
//            break;
//        time++;
//        lib->refresh(*fox->game);
//    }
//    lib->endgame();
//    lib->~Lib_arcade_ncurse();
//    return 0;
//}

extern "C" IgraphicLib* create() {
    return new Lib_arcade_ncurse;
}

extern "C" void destroy(IgraphicLib* p) {
    delete p;
}