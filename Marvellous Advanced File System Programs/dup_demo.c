#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main()
{
    int fd = 0;
    int fdnew = 0;

    fd = open("Demo.txt",O_RDONLY);
    printf("File opened with FD is : %d\n",fd);

    fdnew = dup(fd);
    printf("File opened with FD is : %d\n",fdnew);    return 0;
    return 0;
}