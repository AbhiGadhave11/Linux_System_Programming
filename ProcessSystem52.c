#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret = 0;
    Ret = fork();

    if(Ret == 0){ // Child
        execl("./childProcess",NULL,NULL);
    }
    else //Parent
    { 
        printf("Parent is Running with PID : %d\n",getpid());
    }
    return 0;
}