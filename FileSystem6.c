#include<stdio.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
    char fname[20];
    int fd = 0;
    printf("Enter the File Name that you want to open : \n");
    scanf("%s",fname);

    fd = open(fname,O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }
    else{
        printf("File is Successfully Opened with fd : %d\n",fd);
    }
    return 0;
}

//O_RDONLY --> Read Mode
//O_RDWR  --> Read + write mode
//O_WRONLY --> Write Mode
//O_CREATE --> Create Mode