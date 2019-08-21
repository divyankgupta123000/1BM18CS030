#include<stdio.h>
#include<conio.h>

int prec(char x);
void push(char x,char s[50],int *t);
void pop(int *t);

int main()
{
  char stack[50],out[50],in[50];
  int i,j=0,top=-1;
  int a,b;
  clrscr();
  printf("Enter infix expression: ");
  scanf("%s",in);
  printf("\nThe postfix expression is: ");
  for(i=0;in[i]!='\0';i++)
   {
     if((in[i]>='A'&&in[i]<='Z') || (in[i]>='a'&&in[i]<='z'))
      {
	out[j]=in[i];
	printf("%c",out[j]);
	j++;
      }
     else if(in[i]=='^'||in[i]=='/'||in[i]=='*'||in[i]=='+'||in[i]=='-')
      {
	a=prec(in[i]);
	if((top==-1)||(stack[top]=='('))
	 push(in[i],stack,&top);
	else
	 {
	   b=prec(stack[top]);
	   if(a>b)
	    push(in[i],stack,&top);
	   else
	    {
	      do
	       {
		 pop(&top);
		 b=prec(stack[top]);
	       }while(b>=a);
	    }
	  }
       }
      else if(in[i]=='(')
       push(in[i],stack,&top);
      else if(in[i]==')')
       {
	 while(stack[top]!='(')
	  {
	    out[j]=stack[top];
	    printf("%c",out[j]);
	    j++;
	    pop(&top);
	  }
	 pop(&top);
       }
   }
  getch();
  return 0;
}

int prec(char x)
{
  if(x=='^')
   return 3;
  else if(x=='/' || x=='*')
   return 2;
  else if(x=='+' || x=='-')
   return 1;
  else
     return 0;
}

void push(char x,char s[50],int *t)
{
  *t=*t+1;
  s[*t]=x;
}

void pop(int *t)
{
  *t=*t-1;
}

