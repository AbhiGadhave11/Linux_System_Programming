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
    bool flag = false;
    if(argc != 3)
    {
        printf("Insufficient Arguments\n");
        return -1;
    }
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    dp = opendir(argv[1]);
    if(dp == NULL){
        printf("Unable to open the directory\n");
        return -1;
    }
    
    while((entry = readdir(dp)) != NULL){
        if(strcmp(argv[2],entry->d_name) == 0){
            flag = true;
            break;
        }
    }
    if(flag)
    {
        printf("File is Present in the directory\n");
    }
    else{
        printf("File is not present in the directory\n");
    }
    closedir(dp);
    return 0;
}