// Demonstration of Multiprocessing
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
   int ret1 = 0,ret2 = 0;
   int pid1  = 0,pid2 = 0;
   int status1 = 0,status2 = 0;
   ret1 = fork();
   if(ret1 == 0)
   {
      execl("./ProcessSystem64","NULL",NULL);
   }
   wait(&status1);
   ret2 = fork();
   if(ret2 == 0)
   {
      execl("./ProcessSystem65","NULL",NULL);
   }

   wait(&status2);
   return 0;
}