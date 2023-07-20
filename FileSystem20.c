#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#pragma pack(1)

struct Student{
    int Roll_No;
    char sname[20];
    float marks;
    int Age;
};

int main(int argc,char *argv[])
{
    char fname[20];
    struct Student sobj;
    sobj.Roll_No = 11;
    sobj.marks = 89.99;
    sobj.Age = 25;
    strcpy(sobj.sname,"Rahul");
    printf("Enter the File Name :- \n");
    scanf("%s",fname);
    int fd = 0;
    fd = creat(fname,0777);
    if(fd == -1)
    {
        printf("Unable To Open the FIle\n");
        return -1;
    }

    write(fd,&sobj,sizeof(sobj));

    return 0;
}