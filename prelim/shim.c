#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdlib.h>
#include <stdio.h>


__attribute__((destructor)) void destroy(void) 
{
    printf("we're done.\n");
}



int rand(void) {
    int (*original_rand)(void) =  dlsym(RTLD_NEXT, "rand");
    return original_rand() % 100;
    //return 25;
}
