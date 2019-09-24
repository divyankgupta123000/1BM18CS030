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
NODE delete_front(NODE head);
NODE delete_rear(NODE head);
NODE delete_pos(NODE head,int pos);
void display(NODE head);

void main()
{
	NODE head=NULL;
	int i,n,item,pos;
	for(i=1;n!=8;i++)
	{
		printf("Enter your choice: (1)Insert_front (2)Insert_rear (3)Insert_mid (4)Delete_front (5)Delete_rear (6)Delete_mid (7)Display (8)Exit \n");
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
					
			case 4: head=delete_front(head);
			        break;
					
			case 5: head=delete_rear(head);
					break;
					
            case 6: printf("Enter the position for deletion: ");
			        scanf("%d",&pos);
					head=delete_pos(head,pos);
                    break;
					
			case 7: display(head);
			        break;
					
			case 8: exit(0);
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
			printf("The list is Empty\n");
			exit(0);
		}
		p=head;
		while(p->next!=NULL)
		{
			printf("%d ",p->item);
			p=p->next;
		}
		printf(" %d",p->item);
	}
	
	
   NODE delete_front(NODE head)
	{
		NODE p;
		
		if(head==NULL)
		 {
			 printf("The list is empty\n");
		     return head;
		 }
		 
	    p=head;
	    head=p->next;
		free(p);
	    return head;
	
	}


  NODE delete_rear(NODE head)
  { 
	NODE p,q;
	
	if(head==NULL)
		 {
			 printf("The list is empty\n");
		     return head;
		 }
	p=head;	 
	while(p->next!=NULL)
	{
		q=p;
		p=p->next;
	}
	q->next=NULL;
	free(q);
  }	


  NODE delete_pos(NODE head,int pos)
  {
	NODE p,q;
	int count=1;
	
	if(head==NULL)
	{
		printf("The list is empty\n");
	    return head;
	}
	
	p=head;
	if(p->next==NULL)
	{
		if(pos==1)
			{
		     free(p);
			 head=NULL;
			 return head;
			}
	    else
			printf("Invalid Position\n");
			return head;
	}
	
	while(count<pos && p->next!=NULL)
	{
		q=p;
		p=p->next;
		count++;
	}
	
	if(p->next!=NULL)
	  {
	     q=p->next;
	     p->next=q->next;
	     free(q);
		 return head;
	  }
    
	else
	 {
       if(pos==count)
        {
			q->next==NULL;
		    free(p);
			return head;
		}
		
		else
			printf("Invalid Position\n");
			return head;
	 }
  }	