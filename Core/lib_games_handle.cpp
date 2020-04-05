/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** lib_handle
*/

#include "lib_games_handle.hpp"

createg_t *lib_gconstructor(std::string name)
{
    createg_t *constructor;
    const char* dlsym_error;
    void* handle = dlopen(name.data(), RTLD_LAZY);

    if (!handle) {
        std::cerr << "Cannot load library: " << dlerror() << '\n';
        exit (84);
    }
    dlerror();
    constructor = (createg_t*) dlsym(handle, "create");
    dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol create: " << dlsym_error << '\n';
        exit (84);
    }
    return constructor;
}

destroyg_t *lib_gdestructor(std::string name)
{
    destroyg_t *destroyer;
    const char* dlsym_error;
    void* handle = dlopen(name.data(), RTLD_LAZY);

    if (!handle) {
        std::cerr << "Cannot load library: " << dlerror() << '\n';
        exit (84);
    }
    dlerror();
    destroyer = (destroyg_t*) dlsym(handle, "destroy");
    dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol create: " << dlsym_error << '\n';
        exit (84);
    }
    return destroyer;
}