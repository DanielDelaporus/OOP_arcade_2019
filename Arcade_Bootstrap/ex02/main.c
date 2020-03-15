/*
** EPITECH PROJECT, 2020
** Arcade_Bootstrap
** File description:
** main
*/

// gcc main.c -ldl
// ./a.out ./libfoo.so ./libbar.so ./libgra.so

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <gnu/lib-names.h>

int main(int argc, char **argv)
{
    void *handle1;
    void *handle2;
    void *handle3;
    void (*func1)();
    void (*func2)();
    void (*func3)();
    char *error;

    if (argc != 4) {
        fprintf(stderr, "Arguments not right\n");
        exit(84);
    }

    // Loading argv[1]
    handle1 = dlopen(argv[1], RTLD_LAZY);
    if (!handle1) {
        fprintf(stderr, "%s\n", dlerror());
        exit(84);
    }
    dlerror();

    // Loading argv[2]
    handle2 = dlopen(argv[2], RTLD_LAZY);
    if (!handle2) {
        fprintf(stderr, "%s\n", dlerror());
        exit(84);
    }
    dlerror();

    // Loading argv[3]
    handle3 = dlopen(argv[3], RTLD_LAZY);
    if (!handle3) {
        fprintf(stderr, "%s\n", dlerror());
        exit(84);
    }
    dlerror();

    *(void **) (&func1) = dlsym(handle1, "foo_entryPoint");
    *(void **) (&func2) = dlsym(handle2, "bar_entryPoint");
    *(void **) (&func3) = dlsym(handle3, "gra_entryPoint");

    error = dlerror();
    if (error != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(84);
    }

    func1();
    func2();
    func3();

    return 0;
}
