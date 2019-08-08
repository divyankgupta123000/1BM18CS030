#include<stdio.h>
#include<conio.h>
struct student
{
  char id[10];
  int age;
  int marks;
};
int validate(struct student s);
int qualify(struct student s,int i);
void main()
{
 struct student st[50];
 int i,n;
 clrscr();
 printf("Enter total no. of students: ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
  {
   printf("\nEnter Id, Age & Marks of Student %d:\n",i+1);
    scanf("%s %d %d",&st[i].id,&st[i].age,&st[i].marks);
     if(qualify(st[i],i))
      printf("Student %d is eligible for admission\n",i+1);
  }
 getch();
}

int validate(struct student s)
 {
  if(s.age>20 && s.marks>=0 && s.marks<=100)
   return 1;
  else
   return 0;
 }

int qualify(struct student s,int i)
 {
  if(validate(s))
   {
    if(s.marks>=65)
     return 1;
    else
     printf("Student %d isn't eligible for admission\n",i+1);
      return 0;
   }
  else
   {
    printf("Data is invalid for admission");
     return 0;
   }
 }