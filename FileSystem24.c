#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
    char DirName[20];
    char name[30];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    printf("Entet the Directory name : ");
    scanf("%s",DirName);
    dp = opendir(DirName);
    
    if(dp == NULL)
    {
        printf("Unable to open the direcotry\n");
        return -1;
    }
    while((entry = readdir(dp)) != NULL)
    {
        
        sprintf(name,"%s/%s",DirName,entry->d_name);
        stat(name,&sobj);
        printf("File Name : %20s \t\tFile Size : %d\n",name,sobj.st_size);
    }
    
    closedir(dp);
    return 0;
}