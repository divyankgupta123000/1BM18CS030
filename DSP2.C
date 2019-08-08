#include<stdio.h>
#include<conio.h>
struct student
 {
  char id[10];
  int age;
  int marks;
 };
void main()
{
 struct student st[50];
 int i,n;
 clrscr();
 printf("Enter no. of students: ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
  {
   printf("\nEnter Id, Age & Marks of Student %d:\n",i+1);
    scanf("%s %d %d",&st[i].id,&st[i].age,&st[i].marks);
     if(st[i].age>20 && st[i].marks>=0 && st[i].marks<=100)
      {
       if(st[i].marks>=65)
	printf("Student %d is eligible for admission\n",i+1);
       else
	printf("Student %d isn't eligible for admission\n",i+1);
      }
     else
      printf("Student %d's data isn't valid for admission\n",i+1);
  }
 getch();
}