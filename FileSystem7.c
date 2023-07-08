#include<stdio.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
    int fd = 0;
    if(argc != 2)
    {
        printf("Invalid Number of Arguments");
        return -1;
    }
    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {
        printf("Unable TO Open the File\n");
        return -1;
    }
    else{
        printf("File is Successfully Opened with fd : %d\n",fd);
    }
    return 0;
}

