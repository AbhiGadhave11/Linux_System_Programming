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
    
    printf("Enter the File Name :- \n");
    scanf("%s",fname);
    int fd = 0;
    fd = open(fname,O_RDONLY);
    read(fd,&sobj,sizeof(sobj));
    printf("Roll Number :- %d\n",sobj.Roll_No);
    printf("Name :- %s\n",sobj.sname);
    printf("Marks :- %f\n",sobj.marks);
    printf("Age :- %d\n",sobj.Age);

    return 0;
}