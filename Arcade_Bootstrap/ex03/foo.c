/*
** EPITECH PROJECT, 2020
** Arcade_Bootstrap
** File description:
** foo
*/

// gcc -fpic -shared -o libfoo.so foo.c

#include <stdio.h>

void __attribute__((constructor)) foo_constructor();
void __attribute__((destructor)) foo_destructor();

void foo_constructor()
{
    printf("[libfoo] Loading foo library...\n");
}

void foo_destructor()
{
    printf("[libfoo] foo closing...\n");
}

void foo_entryPoint()
{
    printf("[libfoo] Entry point for foo!\n");
}