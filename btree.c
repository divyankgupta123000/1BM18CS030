#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* lchild;
    struct node* rchild;
};
typedef struct node* Node;
Node getnode(int item)
{
    Node p;
    p=(Node)malloc(sizeof(struct node));
    p->data=item;
    p->lchild=NULL;
    p->rchild=NULL;
    return p;
}
void disp_lvl(Node root)
{
  if(root==NULL)
  return;
  
}

void disp_in(Node root)
{
    if(root==NULL)
    {
        return;
    }
    disp_in(root->lchild);
    printf("%d ",root->data);
    disp_in(root->rchild);
}
void disp_post(Node root)
{
    if(root==NULL)
    {
        return;
    }
    disp_in(root->lchild);
    disp_in(root->rchild);
    printf("%d ",root->data);
}
void disp_pre(Node root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->data);
    disp_in(root->lchild);
    disp_in(root->rchild);
}
int max(Node root)
{
    int large=0;
    Node p=root;
    if(root==NULL)
        return -9999;
    while(p!=NULL)
    {
        if(p->data>large)
            large=p->data;
        p=p->rchild;
    }
    return large;
}
int min(Node root)
{
    int small=10000;
    Node p=root;
    if(root==NULL)
        return -9999;
    while(p!=NULL)
    {
        if(p->data<small)
            small=p->data;
        p=p->lchild;
    }
    return small;
}
int search(Node root,int key)
{
    while(root!=NULL)
    {
        if(key>root->data)
            root=root->rchild;
        else if(key<root->data)
            root=root->lchild;
        else
            return 1;
    }
    return 0;
}
Node insert(Node root,int item)
{
    if(root==NULL)
        return getnode(item);
    if(item < root->data)
        root->lchild=insert(root->lchild,item);
    else if(item > root->data)
        root->rchild=insert(root->rchild,item);
    return root;
}
Node del(Node root,int key)
{
    Node temp;
    if(root==NULL)
    {
        return root;
    }
    if(key < root->data)
    {
        root->lchild=del(root->lchild,key);
    }
    else if(key > root->data)
    {
        root->rchild=del(root->rchild,key);
    }
    else
    {
        if(root->lchild==NULL)
        {
            temp=root->rchild;
            free(root);
            return temp;
        }
        else if(root->rchild==NULL)
        {
            temp=root->lchild;
            free(root);
            return temp;
        }
        else
        {
            temp->data=min(root->rchild);
            root->data=temp->data;
            root->rchild=del(root->rchild,temp->data);
        }
    }
    return root;
}
void main()
{
    Node root=NULL;
    int item,n;
    printf("Enter\n1.insert\n2.delete\n3.display in-order\n4.display post-order\n5.display pre-order\n6.search a particular element\n7.find maximum value\n8.find minimum value\n");
	do{
        printf("Enter your choice:\n");
		scanf("%d",&n);
        switch(n)
        {
            case 1:
                printf("Enter the element to be inserted\n");
                scanf("%d",&item);
                root=insert(root,item);
                break;
            case 2:
                printf("Enter th element to be deleted\n");
                scanf("%d",&item);
                root=del(root,item);
                break;
            case 3:
                disp_in(root);
                break;
            case 4:
                disp_post(root);
                break;
            case 5:
                disp_pre(root);
                break;
            case 6:
                printf("enter the element to be searched\n");
                scanf("%d",&item);
                if(search(root,item)==1)
                    printf("The number %d is present in the tree\n",item);
                else
                    printf("Not present");
                    break;
            case 7:
                item=max(root);
                printf("The maximum value in the tree is %d\n",item);
                break;
            case 8:
                item=min(root);
                printf("The minimum value in the tree is %d\n",item);
                break;
        }
        printf("to continue press 1\n");
        scanf("%d",&n);
    }while(n==1);
}