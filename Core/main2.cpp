
#include "../games/Igames.hpp"
#include "../lib/IgraphicLib.hpp"
#include "lib_handle.hpp"

int main (void)
{
    create_t
    Igames *fox = new SolarFox;
    int key = 0;
    int time = 0;
    Lib_arcade_ncurse *lib = new Lib_arcade_ncurse();
    lib->assign_game(*fox->game);
    lib->refresh(lib->game);
    while (1000) {
        Event nowkey = lib->Keypressed();
        if (nowkey == Event::QUIT)
            break;
        else
            fox->key_event(nowkey);
        if (fox->loop(time))
            break;
        time++;
        lib->refresh(*fox->game);
    }
    lib->endgame();
    lib->~Lib_arcade_ncurse();
    return 0;
}