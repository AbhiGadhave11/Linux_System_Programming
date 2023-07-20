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
    
    printf("Entet the Directory name : ");
    scanf("%s",DirName);
    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open the direcotry\n");
        return -1;
    }
    while((entry = readdir(dp)) != NULL){
        // printf("%s\n",entry->d_name);
        sprintf(name,"%s/%s",DirName,entry->d_name);
        printf("%s\n",name);
    }
    
    closedir(dp);
    return 0;
}