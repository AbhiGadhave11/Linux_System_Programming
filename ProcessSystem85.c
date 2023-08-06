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
   printf("Server application running\n");

   shmid = shmget(key,shmsize,IPC_CREAT|0666);

   printf("Shared Memory Allocated Successfully...\n");
   ptr = shmat(shmid,NULL,0);
   if(ptr != NULL)
   {
      printf("Shared Memory Attached Successfully...\n");
   }
   *ptr = 'H';
   ptr++;
   *ptr = 'e';
   ptr++;
   *ptr = 'l';
   ptr++;
   *ptr = 'l';
   ptr++;
   *ptr = 'l';
   ptr++;
   *ptr = 'o';
   ptr++;
   *ptr = '\0';
   ptr++;
   printf("Data Written in shared memory Successfully\n");
   
   return 0;
}