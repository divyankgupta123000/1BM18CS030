#include<stdio.h>
#include<conio.h>
void main()
{
int i;
struct stud
{
 float m[8];
};
struct stud s;
clrscr();
printf("Enter the marks in the following subjects respectively:\n(1)OOP with Java (2)Discrete Mathematics (3)Logic Design (4)Logistics (5)Computer Architecture (6)Data Structures (7)Constitution of India & Professional Ethics (8)Project Work (9)Physical Activity\n");
scanf("%f %f %f %f",&s.m[0],&s.m[1],&s.m[2],&s.m[3],&s.m[4],&s.m[5],&s.m[6],&s.m[7],&s.m[8]);
printf("Entered marks in order are:\n");
for(i=0;i<9;i++)
 printf("Marks of subject %d: %f\n",i+1,s.m[i]);
getch();
}