#include<stdio.h>
#define SIZE 50

void insert(int q[SIZE],int item,int *r)
 {
	 if(*r==SIZE-1)
	 {
		 printf("Queue Overflow");
		 return;
	 }
	 *r=*r+1;
	 q[*r]=item;
 }
 
int delete(int q[SIZE],int *f,int *r)
 {
	 int item;
	 if(*f>*r)
	 {
		 printf("Queue Underflow\n");
		 return -9999;
	 }
	 item=q[*f];
	 *f=*f+1;
	 return item;
 }
 
void display(int q[SIZE],int f,int r) 
 {
	 int i;
	 if(f>r)
	 {
		 printf("Queue is Empty");
		 return;
	 }
	 printf("Contents of queue are:\n");
	 for(i=f;i<=r;i++)
	  printf("%d\n",q[i]);
 }
 
int main()
{
	int front=0,rear=-1;
	int item,q[SIZE],ch_op,ch_q;
	do
	{
		printf("1->Insert\n2->Delete\n3->Display\n");
		printf("Enter your choice (1,2,3,...): ");
		scanf("%d",&ch_op);
		switch(ch_op)
		{
			case 1: printf("\nEnter the element to be inserted:\n");
			        scanf("%d",&item);
					insert(q,item,&rear);
					break;
					
			case 2: ch_q=delete(q,&front,&rear);
			        printf("\nThe deleted element is: %d\n",ch_q);
					break;
					
			case 3: display(q,front,rear);
			        break;
					
			default: break; 
		}
	}while(ch_op==1||ch_op==2||ch_op==3);

	return 0;
}