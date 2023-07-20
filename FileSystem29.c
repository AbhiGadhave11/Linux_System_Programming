#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

#pragma pack(1)
struct FileInfo
{
    char FileName[20];
    int FileSize;
};

int main(int argc,char *argv[])
{
    char DirName[20];
    char name[30] = {'\0'};
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    struct FileInfo fobj;
    int fd = 0;
    printf("Entet the Directory name : ");
    scanf("%s",DirName);
    dp = opendir(DirName);
    
    if(dp == NULL)
    {
        printf("Unable to open the direcotry\n");
        return -1;
    }
    
    fd = creat("FileCombine.txt",0777);
    while((entry = readdir(dp)) != NULL)
    {
        
        sprintf(name,"%s/%s",DirName,entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode)){
            fobj.FileSize = sobj.st_size;
            strcpy(fobj.FileName,entry->d_name);
            write(fd,&fobj,sizeof(fobj));
        } 
    }
    
    closedir(dp);
    return 0;
}