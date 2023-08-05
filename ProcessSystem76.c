#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

int counter = 0;

void *ThreadProc(void *ptr)
{
   int i = 0;
   counter++;
   printf("Thread executed with counter : %d\n",counter);
   for(int i=0;i<0xFFFFFFFF;i++);
   printf("Thread Completed with counter : %d\n",counter);
   pthread_exit(NULL);
}

int main()
{  
   pthread_t TID1,TID2;
   int ret = 0;

   ret = pthread_create(&TID1, // Address of pthread_attr_t structure object
                        NULL,  //Thread Attributes
                        ThreadProc, // Address of CallBack Function
                        NULL); // Parameters to callBack Function

   if(ret != 0)
   {
      printf("Unable to create thread\n");
      return -1;
   }

   ret = pthread_create(&TID2, // Address of pthread_attr_t structure object
                        NULL,  //Thread Attributes
                        ThreadProc, // Address of CallBack Function
                        NULL); // Parameters to callBack Function

   if(ret != 0)
   {
      printf("Unable to create thread\n");
      return -1;
   }
 
   pthread_join(TID1,NULL);
   pthread_join(TID2,NULL);

   printf("End of main thread\n");
   return 0;
}