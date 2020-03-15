/*
** EPITECH PROJECT, 2020
** Arcade_Bootstrap
** File description:
** foo
*/

// gcc -fpic -shared -o libgra.so gra.c

#include <stdio.h>

void __attribute__((constructor)) gra_constructor();
void __attribute__((destructor)) gra_destructor();

void gra_constructor()
{
    printf("[libgra] Loading gra library...\n");
}

void gra_destructor()
{
    printf("[libgra] Gra's getting out...\n");
}

void gra_entryPoint()
{
    printf("[libgra] Another entry point!\n");
}