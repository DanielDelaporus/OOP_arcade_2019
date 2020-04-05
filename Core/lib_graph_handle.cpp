/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** lib_handle
*/

#include "lib_graph_handle.hpp"

create_t *lib_constructor(std::string name)
{
    create_t *constructor;
    const char* dlsym_error;
    void* handle = dlopen(name.data(), RTLD_LAZY);

    if (!handle) {
        std::cerr << "Cannot load library: " << dlerror() << '\n';
        exit (84);
    }
    dlerror();
    constructor = (create_t*) dlsym(handle, "create");
    dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol create: " << dlsym_error << '\n';
        exit (84);
    }
    return constructor;
}

destroy_t *lib_destructor(std::string name)
{
    destroy_t *destroyer;
    const char* dlsym_error;
    void* handle = dlopen(name.data(), RTLD_LAZY);

    if (!handle) {
        std::cerr << "Cannot load library: " << dlerror() << '\n';
        exit (84);
    }
    dlerror();
    destroyer = (destroy_t*) dlsym(handle, "destroy");
    dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Cannot load symbol create: " << dlsym_error << '\n';
        exit (84);
    }
    return destroyer;
}