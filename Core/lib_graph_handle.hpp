/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** lib_handle
*/

#ifndef LIB_HANDLE_HPP_
#define LIB_HANDLE_HPP_

#include <iostream>
#include <dlfcn.h>
#include "../lib/IgraphicLib.hpp"

create_t *lib_constructor(std::string name);
destroy_t *lib_destructor(std::string name);

#endif /* !LIB_HANDLE_HPP_ */
