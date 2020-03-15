/*
** EPITECH PROJECT, 2020
** Arcade_Bootstrap
** File description:
** foo
*/

// gcc -fpic -shared -o libbar.so bar.c

#include <stdio.h>

void __attribute__((constructor)) bar_constructor();
void __attribute__((destructor)) bar_destructor();

void bar_constructor()
{
    printf("[libbar] Loading bar library...\n");
}

void bar_destructor()
{
    printf("[libbar] foo closing...\n");
}

void bar_entryPoint()
{
    printf("[libbar] Entry point for bar!\n");
}