/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** lib_handle
*/

#ifndef LIB_GAMES_HPP_
#define LIB_GAMES_HPP_

#include <iostream>
#include <dlfcn.h>
#include "../games/Igames.hpp"

createg_t *lib_gconstructor(std::string name);
destroyg_t *lib_gdestructor(std::string name);
void newscore(Games fox, std::string name);

#endif /* !LIB_HANDLE_HPP_ */
