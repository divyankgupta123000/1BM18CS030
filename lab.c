#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node* NODE;

NODE getnode();
NODE insert_1st(NODE head1,int item);
NODE insert_2nd(NODE head2,int item);
void display(NODE head1, NODE head2);
void sort(NODE head);
NODE reverse(NODE head);
NODE concat(NODE head1,NODE head2);

int main()
{
	int i,item,choice=0;
	NODE head=NULL,head1=NULL,head2=NULL;
	printf("Enter your choice: (1)Insert in 1st list (2)Insert in 2nd list (3)Display (4)Sort (5)Reverse (6)Concatenate (7)Exit");
	for(i=0;choice!=7;i++)
	{
		printf("\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice)
		 {
			 case 1: printf("Enter the item: ");
			         scanf("%d",&item);
			         head1=insert_1st(head1,item);
			         break;

			 case 2: printf("Enter the item: ");
			         scanf("%d",&item);
			         head2=insert_2nd(head2,item);
			         break;

			 case 3: display(head1,head2);
			         break;

			 case 4: printf("Enter choice:(1)List 1 (2)List 2");
		                 scanf("%d",&i);
			         if(i==1)
			          sort(head1);
				 else
		                  sort(head2);
			         break;

			 case 5: printf("Enter choice:(1)List 1 (2)List 2");
		                 scanf("%d",&i);
			         if(i==1)
			          head1=reverse(head1);
			         else
		               head2=reverse(head2);
			         break;

			 case 6: head=concat(head1,head2);
			         break;

			 case 7: exit(0);

			 default: break;
		 }
    }
    return 0;
}

NODE getnode()
{
	NODE p;
	p=(NODE)malloc(sizeof(struct node));
	if(p!=NULL)
	 return p;
	else
	 {
		 printf("Memory couldn't be allocated");
	     exit(1);
	 }
}

NODE insert_1st(NODE head1,int item)
{
	NODE p;
	p=getnode();
	p->data=item;
	p->next=head1;
	head1=p;
	return head1;
}

NODE insert_2nd(NODE head2,int item)
{
	NODE q;
	q=getnode();
	q->data=item;
	q->next=head2;
	head2=q;
	return head2;
}

void display(NODE head1,NODE head2)
{
	NODE p,q;
	if(head1==NULL && head2==NULL)
     printf("Both lists are empty\n");
    else if(head1==NULL)
	 printf("List 1 is empty\n");
	else if(head2==NULL)
	 printf("List 2 is empty\n");
     if(head1!=NULL)
     {
     p=head1;
	 printf("List 1: ");
        while(p!=NULL)
	 {
		printf("%d ",p->data);
		p=p->next;
	 }
     }
     if(head2!=NULL)
     {
         q=head2;
	printf("\nList 2: ");
	while(q!=NULL)
	 {
		printf("%d ",q->data);
		q=q->next;
	 }
     }
}

void sort(NODE head)
{
	NODE p=head;
	NODE q=NULL;
	int temp;
	if(head==NULL)
		return;
    while(p->next!=NULL)
    {
		q=p->next;
		while(q!=NULL)
		{
			if(p->data>q->data)
			{
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
			q=q->next;
		}
	    p=p->next;
	}
}


NODE reverse(NODE head)
{
	NODE curr=head,prev=NULL,nextn=NULL;
    if(head==NULL)
	{
		printf("List is Empty");
		return head;
	}
	if(head->next==NULL)
    {
		return head;
	}
    while(curr!=NULL)
	{
		nextn=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nextn;
    }
    head=prev;
    return head;
}

NODE concat(NODE head1,NODE head2)
{
	NODE p;
	if(head1==NULL)
    {
		return head2;
	}

	else if(head2==NULL)
    {
		return head1;
	}

	else
		{
			p=head1;
		    while(p->next!=NULL)
		    p=p->next;
	        p->next=head2;
            return head1;
        }
}


