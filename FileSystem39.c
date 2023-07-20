#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdbool.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
    if(argc != 3){
        printf("Insufficient Argumennts\n");
        return -1;
    }
    int fd1 = 0,fd2 = 0;
    struct stat sobj1,sobj2;
    char buffer1[1024];
    char buffer2[1024];
    fd1 = open(argv[1],O_RDONLY);
    fd2 = open(argv[2],O_RDONLY);
    if(fd1 == -1 || fd2 == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }
    fstat(fd1,&sobj1);
    fstat(fd2,&sobj2);
    if(sobj1.st_size != sobj2.st_size)
    {
        printf("Files are different\n");
        return -1;
    }
    int ret = 0;
    while((ret = read(fd1,buffer1,sizeof(buffer1))) != 0)
    {
        ret = read(fd2,buffer2,sizeof(buffer2));
        
        if(memcmp(buffer1,buffer2,ret) != 0)
        {
            printf("Data is not equal\n");
            break;
        }
    }
    if(ret == 0)
    {
        printf("Both files are Indentical\n");
    }
    close(fd1);
    close(fd2);
    return 0;
}