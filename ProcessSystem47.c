#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>

void fun()
{
    printf("Running process PID is : %d\n",getpid());
}


int main()
{
    int ret = 0;
    ret = fork();
    
    if(ret == 0)
        fun();
    else    
        fun();
    return 0;
}