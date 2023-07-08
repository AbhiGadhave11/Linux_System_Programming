#include<stdio.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
    int fd = 0;
    
    printf("Usage : Name_Of_Executable Name_Of_File\n");
    
    if(argc != 2)
    {
        printf("Invalid Number of Arguments\n");
        return -1;
    }

    fd = creat(argv[1],0777);
    if(fd == -1)
    {
        printf("Unable TO Create the File\n");
        return -1;
    }
    else{
        printf("File is Successfully Created with fd : %d\n",fd);
    }
    return 0;
}

