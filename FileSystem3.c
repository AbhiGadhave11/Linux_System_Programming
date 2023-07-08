#include<stdio.h>

int main(int argc,char *argv[])
{
    printf("Name of Application : %s\n",argv[0]);
    if(argc == 1)
    {
        printf("Please Enter your first name as command line argument\n");
        return -1;
    }
    else{
        printf("Welcome to Marvellous : %s\n",argv[1]);
        return 0;
    }
    
}