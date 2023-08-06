//Server for Shared Memory
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/shm.h>

int main()
{
   int shmid = 0;
   int shmsize = 100;
   int key = 1234;
   printf("Server application running\n");

   shmid = shmget(key,shmsize,IPC_CREAT|0666);

   printf("Shared Memory Allocated Successfully\n");
   return 0;
}