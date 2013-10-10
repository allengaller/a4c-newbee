#include<stdio.h>
#include<stdlib.h>

struct stu
{   
  int num;  
  char *name;   
  char sex; 
  float score;  
}boy[5]={  
          {101,"yuexingtian",'M',98}, 
          {102,"yuechaotian",'M',99}, 
          {103,"tommy      ",'M',100}, 
          {104,"jack chen",'M',88}, 
          {105,"milk liu",'F',66},  
         };

main()
{ 
  struct stu *ps; 
  printf("Number\tName\t\t\tSex\tScore\t\n"); 
  for(ps=boy;ps<boy+5;ps++)   
  printf("%d\t%s\t\t%c\t%f\t\n",ps->num,ps->name,ps->sex,ps->score);  
  getchar();
} 
  
