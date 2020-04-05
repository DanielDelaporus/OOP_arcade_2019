/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Debian]
** File description:
** main
*/

#include <iostream>
#include "../games/Igames.hpp"
#include "../lib/IgraphicLib.hpp"
#include "lib_graph_handle.hpp"
#include "lib_games_handle.hpp"

#define PRINTER(x) std::cout << x << std::endl;

#include <filesystem>

/*
std::vector<std::string> &game_list()
{
    
}

std::vector<std::string> &graph_lib_list()
{

}


int launch_menu(std::string lib_core)
{
    return 0;
}
*/

int main(int argc, char **argv)
{
    std::string lib_core;
    if (argc != 2) {
        std::cout << "Usage: ./arcade path_to_lib/lib.so" << std::endl;
        return 0;
    }

    lib_core = argv[1];

    createg_t *create_game = lib_gconstructor("./games/lib_arcade_SelectScreen.so");
    destroyg_t *destroy_game = lib_gdestructor("./games/lib_arcade_SelectScreen.so");
    Igames *fox = create_game();

    create_t *create_graph = lib_constructor("./lib/lib_arcade_ncurse.so");
    destroy_t *destroy_graph = lib_destructor("./lib/lib_arcade_ncurse.so");
    IgraphicLib *lib = create_graph();
    
    
    int time = 0;

    lib->assign_game(fox->GetGame());
    lib->refresh(fox->GetGame());
    while (1000) {
        Event nowkey = lib->Keypressed();
        if (nowkey == Event::QUIT)
            break;
        else
            fox->key_event(nowkey);
        if (fox->loop(time))
            break;
        time++;
        lib->refresh(fox->GetGame());
    }
    lib->endgame();
    int which_game = fox->GetGame().posx;
    int which_lib = fox->GetGame().posy;
    destroy_graph(lib);
    destroy_game(fox);


    //Things were chosen
    if (which_game == 0)
        create_game = lib_gconstructor("./games/lib_arcade_solarfox.so");
    else
        create_game = lib_gconstructor("./games/lib_arcade_pacman.so");

    if (which_lib == 0)
        create_graph = lib_constructor("./lib/lib_arcade_ncurse.so");
    else
        create_graph = lib_constructor("./lib/lib_arcade_sfml.so");

    fox = create_game();
    lib = create_graph();

    time = 0;
    lib->assign_game(fox->GetGame());
    lib->refresh(fox->GetGame());
    while (1000) {
        Event nowkey = lib->Keypressed();
        if (nowkey == Event::QUIT)
            break;
        else if (nowkey == Event::NEXT_GRAPH){

            if (which_lib) 
                create_graph = lib_constructor("./lib/lib_arcade_ncurse.so");
            else 
                create_graph = lib_constructor("./lib/lib_arcade_sfml.so");
            lib = create_graph();
            lib->assign_game(fox->GetGame());
            lib->refresh(fox->GetGame());

        }
         else if (nowkey == Event::NEXT_GAME){
            if (which_game == 0) 
                create_game = lib_gconstructor("./games/lib_arcade_pacman.so");
            else 
                create_game = lib_gconstructor("./games/lib_arcade_solarfox.so");
            fox = create_game();
            time = 0;
            lib->assign_game(fox->GetGame());
            lib->refresh(fox->GetGame());
        }
        else
            fox->key_event(nowkey);
        if (fox->loop(time))
            break;
        time++;
        lib->refresh(fox->GetGame());
    }
    lib->endgame();
    destroy_graph(lib);
    destroy_game(fox);
    return 0;
}