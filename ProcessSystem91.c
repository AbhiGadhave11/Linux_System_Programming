#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main()
{
  char filename1[30],filename2[30];
  int ret = 0;
  printf("Enter the existing file name \n");
  scanf("%s",filename1);

  printf("Enter the name for hardlink : \n");
  scanf("%s",filename2);

  ret = link(filename1,filename2);
  if(ret == 0)
  {
      printf("Hardlink gets created successfully\n");
  }

   return 0;
}