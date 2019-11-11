#include<stdio.h>
#include<stdlib.h>

void push(long item,long s[],long *t);
void pop(long *t);
long max(long s[],long t);

int main()
{
    long stack[100000],top=-1;
    long item,n,choice,i;
    scanf("%ld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%ld",&choice);
        switch(choice)
        {
            case 1: scanf("%ld",&item);
                    push(item,stack,&top);
                    break;

            case 2: pop(stack,&top);
                    break;

            case 3:
                    printf("%ld\n",max(stack,top));
                    break;

            default: exit(0);
        }
    }
    return 0;
}

void push(long item,long s[],long *t)
{
    if(*t==99999)
     return;
    *t=*t+1;
    s[*t]=item;
}

void pop(long *t)
{
    if(*t==-1)
     return;
    *t=*t-1;
}

long max(long s[],long t)
{
    long i,maxi=0;
    for(i=t;i>=0;i--)
    {
        if(s[i]>maxi)
        maxi=s[i];
    }
    return maxi;
}
