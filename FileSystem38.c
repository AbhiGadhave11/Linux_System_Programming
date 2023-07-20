#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<stdbool.h>
#include<sys/dir.h>

int main(int argc,char *argv[])
{
    if(argc != 2){
        printf("Insufficient Argumennts\n");
        return -1;
    }
    DIR *src = NULL;
    DIR *dest = NULL;
    struct dirent *entry = NULL;

    src = opendir(argv[1]);
    if(src == NULL)
    {
        printf("Unable to open source directory]\n");
        return -1;
    }

    char srcname[40];
    char destname[40];
    int iCnt = 1;
    while((entry = readdir(src)) != NULL)
    {
        sprintf(srcname,"%s/%s",argv[1],entry->d_name);
        sprintf(destname,"%s/%d.txt",argv[1],iCnt);
        rename(srcname,destname);
        iCnt++;
    }

    closedir(src);
    return 0;
}