/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Graph_load
*/

#ifndef GRAPH_LOAD_HPP_
#define GRAPH_LOAD_HPP_

#include <iostream>

class Graph_load {
    public:
        Graph_load() {
            void* handle = dlopen(path_name.data(), RTLD_LAZY);
            if (!handle) {
                std::cerr << "Cannot load library: " << dlerror() << '\n';
                exit (84);
            }
        }
        ~Graph_load() {

        }

    protected:
    private:
};

#endif /* !GRAPH_LOAD_HPP_ */
