#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void *ThreadProc(void *ptr)
{
   int i= (int)ptr;
   printf("Value received from main thread is : %d\n",(int)ptr);
   pthread_exit((++i));
}

int main()
{  
   pthread_t TID;
   int ret = 0;
   int no = 11;
   int value = 0;

   ret = pthread_create(&TID, // Address of pthread_attr_t structure object
                        NULL,  //Thread Attributes
                        ThreadProc, // Address of CallBack Function
                        (int *)no); // Parameters to callBack Function

   if(ret != 0)
   {
      printf("Unable to create thread\n");
      return -1;
   }
   printf("Thread is Created with ID : %d\n",TID);
   pthread_join(TID,&value);
   printf("Return Value from thread is :- %d\n",value);

   printf("End of main thread\n");
   return 0;
}