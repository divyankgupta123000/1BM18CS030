#include<stdio.h>
#include<stdlib.h>

struct node
{
	int item;
	struct node *next;
};

typedef struct node* NODE;
NODE push(int item,NODE head);
NODE enqueue(int item,NODE head);
NODE getnode();
NODE pop(NODE head);
NODE dequeue(NODE head);
void display(NODE head);

void main()
{
	NODE head=NULL;
	int i,n,item,pos;
	for(i=1;n!=4;i++)
	{
		printf("\nEnter your choice:(1)Enqueue (2)Dequeue (3)Display (4)Exit \n");
		scanf("%d",&n);

		switch(n)
		{
			case 1: printf("Enter the no.to be inserted: ");
			        scanf("%d",&item);
					head=enqueue(item,head);
					break;
					
			case 2: head=dequeue(head);
					break;
					
			case 3: display(head);
			        break;
					
            case 4: exit(0);
					
         }
	}	
}	
	
	NODE getnode()
	{
		NODE p;
		p=(NODE)malloc(sizeof(struct node));
		if(p==NULL)
		{
			printf("Memory couldn't be allocated\n");
			exit(1);
		}
		else
		return p;
	}


	
	NODE enqueue(int item,NODE head)
	{
		NODE p,q;
		q=getnode();
		q->item=item;
		if(head!=NULL)
		{
			p=head;
			while(p->next!=NULL)
			 p=p->next;
			p->next=q;
			q->next=NULL;
			return head;
		}
		else
		{
			q->next=NULL;
			head=q;
			return head;
		}
	}
	


  NODE dequeue(NODE head)
	{
		NODE p;
		
		if(head==NULL)
		 {
			 printf("Queue is Empty\n");
		     return head;
		 }
		 
	    p=head;
	    head=p->next;
		free(p);
	    return head;
	
	}



  void display(NODE head)
	{
		NODE p;
		if(head==NULL)
		{
			printf("Queue is Empty\n");
			exit(0);
		}
		p=head;
		while(p->next!=NULL)
		{
			printf("%d ",p->item);
			p=p->next;
		}
		printf("%d",p->item);
	}