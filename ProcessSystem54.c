#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret = 0;
    Ret = fork();

    if(Ret == 0){ // Child
        execl("./ChildProcess","Demo","Hello",NULL);
        //parameter 1 : Name of Executable
        //Parameter 2 L Multiple Values Separated by, Which are considered as command line arguments
        //argv[0] : Demo
        // argv[1] : Hello
        // argv[2] : Marvellous
        //parameter : Enviornment Variable (NULL)
    }
    else //Parent
    { 
        printf("Parent is Running with PID : %d\n",getpid());
    }
    return 0;
}