#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>

int No = 10;
void fun()
{
    No++;
    printf("Running process PID is : %d\n and value of No is %d\n",getpid(),No);

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