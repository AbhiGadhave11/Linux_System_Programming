#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{  
   int FD[2];
   int iret = 0;
   char Arr[] = "Abhijit Gadhave";
   char Buffer[512];
   pipe(FD);
   iret = fork();
   if(iret == 0) // child Process
   {
      printf("Child Process scheduled for writing into pipe\n");
      close(FD[0]);
      write(FD[1],Arr,strlen(Arr));
      exit(0);
   }
   else
   {
      printf("Parent process scheduled for reading from pipe\n");
      close(FD[1]);
      read(FD[0],Buffer,sizeof(Buffer));
      printf("Data from pipe is : %s\n",Buffer);
   }

   return 0;
}