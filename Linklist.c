#include<stdio.h>
#include<stdlib.h>

struct node
{
	int item;
	struct node *next;
};
typedef struct node* NODE;
NODE insert_front(int item,NODE head);
NODE insert_rear(int item,NODE head);
NODE insert_pos(NODE head,int item,int pos);
NODE getnode();
void display(NODE head);

void main()
{
	NODE head =NULL;
	int i,n,item,pos;
	for(i=1;n!=5;i++)
	{
		printf("Enter your choice: (1)Insert_front (2)Insert_rear (3)Insert_mid (4)Display (5)Exit \n");
		scanf("%d",&n);
		
		switch(n)
		{
			case 1: printf("Enter the no.to be inserted: ");
			        scanf("%d",&item);
					head=insert_front(item,head);
					break;
					
			case 2: printf("Enter the no.to be inserted: ");
			        scanf("%d",&item);
					head=insert_rear(item,head);
					break;
					
			case 3: printf("Enter the no.to be inserted & position: ");
			        scanf("%d",&item);
					scanf("%d",&pos);
					head=insert_pos(head,item,pos);
					break;
					
			case 4: display(head);
			        break;
					
			case 5: exit(0);
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
	
	NODE insert_front(int item,NODE head)
	{
		NODE p;
		p=getnode();
		p->item=item;
		p->next=head;
		head=p;
		return head;
	}
	
	NODE insert_rear(int item,NODE head)
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
		}
		else
		{
			head=q;
                }
                
                q->next=NULL;
                return head;
	}
	
	NODE insert_pos(NODE head,int item,int pos)
	{
		NODE curr,prev=NULL,newn;
		int count=1;
		newn=getnode();
		newn->item=item;
		newn->next=NULL;
		
		if(head==NULL)
		{
			if(pos==1)
			 return newn;
			else
			{
				printf("Invalid Position\n");
				return head;
			}
		}
		
		else if(pos==1)
		{
			newn->next=head;
			head=newn;
			return head;
		}
		
		else
		{
			curr=head;
			while(curr->next!=NULL && count!=pos)
			{
				prev=curr;
				curr=curr->next;
				count++;
			}
			if(count==pos)
			{
				prev->next=newn;
				newn->next=curr;
				return head;
			}
			else
			{
				printf("Invalid Position\n");
				return head;
			}
		}
	}
	
	void display(NODE head)
	{
		NODE p;
		if(head==NULL)
		{
			printf("List is Empty\n");
			exit(0);
		}
		p=head;
		while(p!=NULL)
		{
			printf("%d  ",p->item);
			p=p->next;
		}
	}
