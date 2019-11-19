#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
  struct node *prev;
};
typedef struct node* Node;
Node getnode()
{
  Node p;
  p=(Node)malloc(sizeof(struct node));
  if(p!=NULL)
  return p;
  else
  {
    printf("Memory was not allocated\n");
    exit(0);
  }
}
Node insertfront(Node head,int item)
{
    Node p=getnode();
    p->data=item;
    p->next=NULL;
    p->prev=NULL;
    if(head==NULL)
        return p;
    else
    {
        p->next=head;
        head->prev=p;
        p->prev=NULL;
        head=p;
        return head;
    }
}
Node insertend(Node head,int item)
{
    Node q,p=getnode();
    p->data=item;
    p->prev=NULL;
    p->next=NULL;
    if(head==NULL)
        return p;
    else{
        q=head;
        while(q->next!=NULL)
            q=q->next;
        q->next=p;
        p->prev=q;
        return head;
    }
}
Node insleft(Node head,int item,int n)
{
    int f=0;
    Node q,p=getnode();
    p->data=item;
    if(head==NULL)
    {
        printf("Empty list\n");
        return head;
    }
    else if(n==head->data)
    {
        p->prev=NULL;
        p->next=head;
        head->prev=p;
        head=p;
        return head;
    }
    else
    {
        q=head;
        while(q->next!=NULL)
        {
            if(q->data==n)
            {
                f=1;
                break;
            }
            q=q->next;
        }
        if(f==1)
        {
            q->prev->next=p;
            p->prev=q->prev;
            p->next=q;
            q->prev=p;
            return head;
        }
        else if(q->data==n)
        {
            q->prev->next=p;
            p->prev=q->prev;
            p->next=q;
            q->prev=p;
            return head;
        }
        else
        {
            printf("Not Found\n");
            return head;
        }
    }
}
Node delfront(Node head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    else if(head->next==NULL)
    {
        printf("%d is deleted\n",head->data);
        free(head);
        return NULL;
    }
    else
    {
        printf("%d is deleted\n",head->data);
        head=head->next;
        free(head->prev);
        head->prev=NULL;
    }
    return head;
}
Node delback(Node head)
{
    Node p;
    if(head==NULL)
    {
        printf("List is empty\n");
        return head;
    }
    if(head->next==NULL)
    {
        printf("%d is deleted\n",head->data);
        free(head);
        return NULL;
    }
    p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    printf("%d is deleted\n",p->data);
    p->prev->next=NULL;
    free(p);
    return head;
}
Node del(Node head,int value)
{
  Node p;
  int x=0;
  if(head==NULL)
  {
    printf("List is empty\n");
    return head;
  }
  if(head->next==NULL && head->data==value)
  {
      printf("%d is deleted\n",head->data);
      free(head);
      return NULL;
  }
     else if(head->data==value)
    {
        p=head;
        printf("Deleted element is %d\n",head->data);
         head=head->next;
        free(p);
        return head;
    }
    else{
        p=head;
        while(p->next!=NULL)
        {
            if(p->data==value)
            {
                x=1;
                break;
            }
            p=p->next;
        }
        if(x==1)
        {
            printf("Deleted element is %d\n",p->data);
            p->next->prev=p->prev;
            p->prev->next=p->next;
        }
        else if(p->data==value)
        {
            printf("Deleted element is %d\n",p->data);
            p->prev->next=NULL;
            free(p);
            return head;
        }
        else
        {
            printf("Value not found\n");
            return head;
        }
    }
}
void disp(Node head)
{
  Node p;
  if(head==NULL)
  {
    printf("list is empty\n");
    return;
  }
  p=head;
  while(p!=NULL)
  {
    printf("%d\n",p->data);
    p=p->next;
  }
}
void main()
{
    Node head=NULL,p;
    int ch,item,x=1,y=1;
    printf("Enter\n1.insert front\n2.insert rear\n3.insert left\n4.delete value specified\n5.delete front\n6.delete rear\n7.display\n8.exit\n");
    scanf("%d",&ch);
    while(1)
    {
        switch(ch)
        {
        case 1:
            printf("Enter the number to be inserted\n");
            scanf("%d",&item);
            head=insertfront(head,item);
            break;
        case 2:
           printf("Enter the number to be inserted\n");
            scanf("%d",&item);
            head=insertend(head,item);
            break;
        case 3:
            printf("Enter the element to be inserted\n");
            scanf("%d",&item);
            printf("Enter the value of it's successor\n");
            scanf("%d",&x);
            head=insleft(head,item,x);
            break;
        case 4:
            printf("Enter the value to be deleted\n");
            scanf("%d",&item);
            head=del(head,item);
            break;
        case 5:
          head=delfront(head);
          break;
        case 6:
            head=delback(head);
            break;
        case 7:
            disp(head);
            break;
        case 8:
            exit(0);
        default:
            break;
        }
    printf("Enter your choice:\n");
    scanf("%d",&ch);
    }
}