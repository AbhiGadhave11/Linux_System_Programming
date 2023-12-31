#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc,char *argv[])
{
    int fd = 0;
    if(argc != 2)
    {
        printf("Invalid Arguments\n");
        return -1;
    }
    fd = open(argv[1],O_RDWR | O_CREAT);
    if(fd == -1){
        printf("Unable to open the file\n");
        return -1;
    }
    printf("File is successfully opened with fd = %d\n",fd);
    
    return 0;
}