#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define BLOCKSIZE 1024
int main(int argc,char *argv[])
{
    int fdSource = 0;
    int fdDest = 0;
    int Ret = 0;

    char Buffer[BLOCKSIZE] = {'\0'};
    if(argc != 3)
    {
        printf("Invalid Number of Arguments\n");
        return -1;
    }

    fdSource = open(argv[1],O_RDONLY);
    if(fdSource == -1)
    {
        printf("Unable to open Source File\n");
        return -1;
    }

    fdDest = creat(argv[2],0777);
    if(fdDest == -1)
    {
        printf("Unable to Create Destination File\n");
        close(fdSource);
        return -1;
    }

    while ((Ret = read(fdSource,Buffer,BLOCKSIZE)) != 0)
    {
        write(fdDest,Buffer,Ret);
        memset(Buffer,0,BLOCKSIZE);
    }
    
    close(fdSource);
    close(fdDest);

    return 0;
}