//server for named pipe
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main()
{  
   int fd = 0;
   char *path = "/tmp/mypipe";
   fd = mkfifo(path,0666);
   if(fd == -1)
   {
      printf("Unable to crated named pipe\n");
      return -1;
   }


   return 0;
}