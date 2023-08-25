#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>

int main()
{
    int fd = 0;
    fd = open("Demo4.txt",O_RDONLY);
    if(fd == -1)
    {
        perror("Unable to open the file");
        if(errno == 2)
        {
            int fd1 = creat("Demo4.txt",0777);
            if(fd1 == -1){
                perror("Unable to create the file\n");
                return -1;
            }
        }
    }

    printf("File is Successfully Opened\n");


    return 0;
}