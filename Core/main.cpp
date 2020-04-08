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
#include <fstream>

int main(int argc, char **argv)
{
    std::string lib_core;
    if (argc != 2) {
        std::cout << "Usage: ./arcade path_to_lib/lib.so" << std::endl;
        return 0;
    }
    std::string name;
    std::cout << "Enter name : "; // no flush needed
    std::cin >> name;

    std::ifstream d("./playerprofile/"+name,std::fstream::out);

    if (!d.is_open()) {
        std::fstream f("./playerprofile/"+name,std::fstream::out);
        f << "0\n0\n0\n";
        f.close();
    }
    d.close();

    lib_core = argv[1];

    createg_t *create_game = lib_gconstructor("./games/lib_arcade_SelectScreen.so");
    destroyg_t *destroy_game = lib_gdestructor("./games/lib_arcade_SelectScreen.so");
    Igames *fox = create_game();

    create_t *create_graph;
    destroy_t *destroy_graph;

    create_graph = lib_constructor(lib_core);
    destroy_graph = lib_destructor(lib_core);
    IgraphicLib *lib = create_graph();

    int which_lib;

    if (lib_core == "./lib/lib_arcade_ncurse.so")
        which_lib = 0;
    else if ("./lib/lib_arcade_sfml.so")
        which_lib = 1;
    else
        which_lib = 2;
    
    int time = 0;

    lib->assign_game(fox->GetGame());
    lib->refresh(fox->GetGame());
    while (1000) {
        Event nowkey = lib->Keypressed();
        if (nowkey == Event::QUIT)
            break;
        else if (nowkey == Event::NEXT_GRAPH || nowkey == Event::PREV_GRAPH){
            destroy_graph(lib);
            if ((which_lib == 2 && nowkey == Event::NEXT_GRAPH) || (which_lib == 1 && nowkey == Event::PREV_GRAPH)) {
                create_graph = lib_constructor("./lib/lib_arcade_ncurse.so");
                which_lib = 0;
            }
            else if ((which_lib == 1 && nowkey == Event::NEXT_GRAPH) || (which_lib == 0 && nowkey == Event::PREV_GRAPH)){
                //create_graph = lib_constructor("./lib/lib_arcade_caca.so");
                which_lib = 2;
            }
            else {
                create_graph = lib_constructor("./lib/lib_arcade_sfml.so");
                which_lib = 1;
            }
        }
        else
            fox->key_event(nowkey);
        if (fox->loop(time))
            break;
        time++;
        lib->refresh(fox->GetGame());
    }
    lib->endgame(name);
    int which_game = fox->GetGame().posx;
    which_lib = fox->GetGame().posy;
    destroy_graph(lib);
    destroy_game(fox);


    //Things were chosen
    if (which_game == 0)
        create_game = lib_gconstructor("./games/lib_arcade_solarfox.so");
    else if (which_game == 1)
        create_game = lib_gconstructor("./games/lib_arcade_pacman.so");
    else
        create_game = lib_gconstructor("./lib/lib_arcade_nibbler.so");

    if (which_lib == 0)
        create_graph = lib_constructor("./lib/lib_arcade_ncurse.so");
    else if (which_lib == 1)
        create_graph = lib_constructor("./lib/lib_arcade_sfml.so");
    else
        create_graph = lib_constructor("./lib/lib_arcade_caca.so");

    fox = create_game();
    lib = create_graph();

    time = 0;
    lib->assign_game(fox->GetGame());
    lib->refresh(fox->GetGame());
    while (1000) {
        Event nowkey = lib->Keypressed();
        if (nowkey == Event::QUIT)
            break;
        else  if (nowkey == Event::NEXT_GRAPH || nowkey == Event::PREV_GRAPH){
            destroy_graph(lib);
            if ((which_lib == 2 && nowkey == Event::NEXT_GRAPH) || (which_lib == 1 && nowkey == Event::PREV_GRAPH)) {
                create_graph = lib_constructor("./lib/lib_arcade_ncurse.so");
                which_lib = 0;
            }
            else if ((which_lib == 1 && nowkey == Event::NEXT_GRAPH) || (which_lib == 0 && nowkey == Event::PREV_GRAPH)){
                //create_graph = lib_constructor("./lib/lib_arcade_caca.so");
                which_lib = 2;
            }
            else {
                create_graph = lib_constructor("./lib/lib_arcade_sfml.so");
                which_lib = 1;
            }
            lib = create_graph();
            lib->assign_game(fox->GetGame());
            lib->refresh(fox->GetGame());

        }
        else if (nowkey == Event::NEXT_GAME || nowkey == Event::PREV_GAME){
            destroy_game(fox);
            if ((which_game == 2 && nowkey == Event::NEXT_GAME) || (which_game == 1 && nowkey == Event::PREV_GAME)) {
                create_game = lib_gconstructor("./games/lib_arcade_solarfox.so");
                which_game = 0;
            }
            else if ((which_game == 2 && nowkey == Event::NEXT_GAME) || (which_game == 1 && nowkey == Event::PREV_GAME)){
                create_game = lib_gconstructor("./games/lib_arcade_nibbler.so");
                which_game = 2;
            }
            else {
                create_game = lib_gconstructor("./games/lib_arcade_pacman.so");
                which_game = 1;
            }
            fox = create_game();
            time = 0;
            lib->assign_game(fox->GetGame());
            lib->refresh(fox->GetGame());
        }
        else
            fox->key_event(nowkey);
        lib->refresh(fox->GetGame());
        if (fox->loop(time))
            break;
        time++;
        lib->refresh(fox->GetGame());
    }
    newscore(fox->GetGame(), name);
    lib->endgame(name);
    destroy_graph(lib);
    destroy_game(fox);
    return 0;
}