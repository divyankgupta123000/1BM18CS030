#include<stdio.h>
#include<conio.h>
struct student
{
  char id[10];
  int age,marks;
};

void main()
{
  struct student s;
  clrscr();
  printf("Enter the Id, Age & Marks:\n");
  scanf("%s %d %d",&s.id,&s.age,&s.marks);
  if(s.age>20 && s.marks>=0 && s.marks<=100)
   {
    if(s.marks>=65)
     printf("The student is eligible for admission");
    else
     printf("The student is not eligible for admission");
   }
  else
   printf("Data is not valid for admission");
 getch();
}