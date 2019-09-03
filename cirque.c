#include<stdio.h>
#define SIZE 50

void insertion(int q[SIZE],int item,int *r,int *f)
{
	if((*f==*r+1)||(*f==0 && *r==SIZE-1))
	{
		printf("Queue is full\n");
		return;
	}
	else if(*f==-1)
	 *f=0;
	 *r=(*r+1)%SIZE;
}

int delete(int q[SIZE],int *f,int *r)
{
	int item;
	if(*f==-1)
	{
		printf("Queue is Empty\n");
		return -9999;
	}
	else
	{
		item=q[*f];
		if(*f==*r)
		{
			*f=-1;
			*r=-1;
		}
		else
		 *f=(*f+1)%SIZE;
		return item;
    }
}

void display(int q[SIZE],int f,int r)
{ 
	int i;
	if(f==-1)
	printf("Queue is Empty\n");
	else
	{
		printf("Contents of queue are\n:");
		 for(i=f;i!=r;i=(i+1)%SIZE)
		 {
			 printf("%d",q[i]);
		 }
		 printf("%d\n",q[i]);
	}
}

int main()
{

	int x,f=-1,r=-1;
	int item,ch_op,q[SIZE];
	
	printf("1->Insert\n2->Delete\n3->Display\n");
	do
    {
		printf("Enter your choice: ");
	    scanf("%d",&ch_op);
	    switch(ch_op)
		{
			case 1: printf("\nEnter the element to be inserted:\n");
			        scanf("%d",&x);
				    insertion(q,x,&r,&f);
				    break;
			
			case 2: item=delete(q,&f,&r);
			        printf("\nThe deleted element is:%d\n",item);
				    break;
			
			case 3: display(q,f,r);
			        break;
			
			default: break;
	    }
	}while(ch_op==1||ch_op==2||ch_op==3);
	
	return 0;
}


