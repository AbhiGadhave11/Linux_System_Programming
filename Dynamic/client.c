#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;

    void (*fptr)();
    ptr = dlopen("library.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load the library\n");
        return -1;
    }

    fptr = dlsym(ptr,"display");
    if(fptr == NULL)
    {
        printf("Unable to load the address the function\n");
        return -1;
    }
    fptr();
    return 0;
}

// gcc client.c -rdyanmic -o Myexe
// ./Myexe