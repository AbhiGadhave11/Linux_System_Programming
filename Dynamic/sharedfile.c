#include<stdio.h>
#include "sharedfile.h"

void display()
{
    printf("Jay Ganesha ...\n");
}

// To create .o file
// gcc -c -fPIC sharedfile.c

// To create .so file
// gcc -shared -o library.so sharedfile.o