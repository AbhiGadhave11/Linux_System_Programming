#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

//Prototype of every thread function
//void *________(void *________)
//{}

void *ThreadProc(void *ptr)
{
   for(int i=1;i<=1000;i++)
   {
      printf("Thread with Counter : %d\n",i);
   }
}

int main()
{  
   pthread_attr_t TID;
   int ret = 0;

   ret = pthread_create(&TID, // Address of pthread_attr_t structure object
                        NULL,  //Thread Attributes
                        ThreadProc, // Address of CallBack Function
                        NULL); // Parameters to callBack Function

   if(ret != 0)
   {
      printf("Unable to create thread\n");
      return -1;
   }
   printf("Thread is Created with ID : %d\n",TID);
   pthread_join(&TID,NULL);

   printf("End of main thread\n");
   return 0;
}