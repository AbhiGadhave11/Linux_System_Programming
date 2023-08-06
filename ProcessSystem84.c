//Client for Shared Memory
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
   char *ptr = NULL;
   printf("Client application running\n");

   shmid = shmget(key,shmsize,0666);

   ptr = shmat(shmid,NULL,0);
   if(ptr != NULL)
   {
      printf("Shared Memory Attached Successfully...\n");
   }
   return 0;
}