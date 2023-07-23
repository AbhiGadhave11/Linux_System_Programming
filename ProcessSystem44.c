#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int ret = 0;

    ret = fork();

    if(ret == 0){ // child
        printf("Child Process is Running\n");
        printf("Child Says : PID of parent process is : %d\n",getppid()); //3831
        printf("Child Says : PID of Child process is : %d\n",getpid()); // 3832
    }
    else // parent
    {
        printf("Parent Process is running\n");
        printf("Parent Saya: PID of Child Process is : %d\n",ret); // 3832
        printf("Parent Says : PID of parent process is : %d\n",getpid()); // 3831
        printf("Parent Says : PID of parent process of parent i.e. Terminal is : %d\n",getppid()); // 3669
    }
    
    return 0;
}