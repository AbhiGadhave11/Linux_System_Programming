#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

//Prototype of every thread function
//void *________(void *________)
//{}

void *ThreadProc1(void *ptr)
{
  int fd = 0,iCnt=0,i=0,iRet = 0;
   char Buffer[512];
   fd = open("Demo.txt",O_RDONLY);

   while((iRet=read(fd,Buffer,sizeof(Buffer))) != 0)
   {
      for(i=0;i<iRet;i++)
      {
         if(Buffer[i]>='A' && Buffer[i]<='Z')
         {
            iCnt++;
         }
      }
   }
   printf("Number of Capital Characters are : %d\n",iCnt);
   close(fd);
   pthread_exit(NULL);
}


void *ThreadProc2(void *ptr)
{
   int fd = 0,iCnt=0,i=0,iRet = 0;
   char Buffer[512];
   fd = open("Demo.txt",O_RDONLY);

   while((iRet=read(fd,Buffer,sizeof(Buffer))) != 0)
   {
      for(i=0;i<iRet;i++)
      {
         if(Buffer[i]>='a' && Buffer[i]<='z')
         {
            iCnt++;
         }
      }
   }
   printf("Number of Small Characters are : %d\n",iCnt);
   close(fd);
   pthread_exit(NULL);
}

int main()
{  
   pthread_t TID1,TID2;
   int ret1 = 0,ret2 = 0;

   ret1 = pthread_create(&TID1, // Address of pthread_attr_t structure object
                        NULL,  //Thread Attributes
                        ThreadProc1, // Address of CallBack Function
                        NULL); // Parameters to callBack Function

   if(ret1 != 0)
   {
      printf("Unable to create thread\n");
      return -1;
   }

   ret2 = pthread_create(&TID2, // Address of pthread_attr_t structure object
                        NULL,  //Thread Attributes
                        ThreadProc2, // Address of CallBack Function
                        NULL); // Parameters to callBack Function

   printf("Thread1 is Created with ID : %d\n",TID1);
   if(ret2 != 0)
   {
      printf("Unable to create thread\n");
      return -1;
   }
   printf("Thread2 is Created with ID : %d\n",TID2);
   pthread_join(TID1,NULL);
   pthread_join(TID2,NULL);

   printf("End of main thread\n");
   
   return 0;
}