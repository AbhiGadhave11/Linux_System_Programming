#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>

extern char **environ;

int main()
{
   char **env = environ;

   printf("Enviornment of Running Process is :- \n");

   for(;*env!= NULL;env++)
   {
      printf("%s : \n",*env);
   }
   
   return 0;
}