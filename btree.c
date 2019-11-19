#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node* lchild;
   struct node* rchild;
};

typedef struct node* NODE;

NODE getnode(int key)
{
   NODE p=(NODE)malloc(sizeof(struct node));
   if(p==NULL)
   {
      printf("Memory wasn't allocated");
      exit(1);
   }
   else
   {
      p->data=key;
      p->rchild=NULL;
      p->lchild=NULL;
      return p;
   }
}

void inorder(NODE root)
{
   if(root==NULL)
     return;
   inorder(root->lchild);
   printf("%d ",root->data);
   inorder(root->rchild);
}

void preorder(NODE root)
{
   if(root==NULL)
     return;
   printf("%d ",root->data);
   preorder(root->lchild);
   preorder(root->rchild);
}

void postorder(NODE root)
{
   if(root==NULL)
     return;
   postorder(root->lchild);
   postorder(root->rchild);
   printf("%d ",root->data);
}

NODE insert(NODE root,int key)
{
   if(root==NULL)
     return root=getnode(key);
   if(key<root->data)
     root->lchild=insert(root->lchild,key);
   else if(key>root->data)
     root->rchild=insert(root->rchild,key);
   return root;
}

int search(NODE root,int key)
{
   int value=1;
   if(root==NULL)
     return 0;
   if(key<root->data)
     value=search(root->lchild,key);
   else if(key>root->data)
     value=search(root->rchild,key);
   return value;
}

NODE min(NODE root)
{
    NODE p;
    if(root->lchild==NULL)
      return root;
     p=min(root->lchild);
    return p;
}

NODE max(NODE root)
{
    NODE p;
    if(root->rchild==NULL)
      return root;
     p=max(root->rchild);
    return p;
}

NODE delete(NODE root,int key)
{
    if(root==NULL)
        return root;
    if(key<root->data)
        root->lchild=delete(root->lchild,key);
    else if(key>root->data)
        root->rchild=delete(root->rchild,key);
    else
    {
        if(root->lchild==NULL)
        {
            NODE temp=root->rchild;
            free(root);
            return temp;
        }
        else if(root->rchild==NULL)
        {
            NODE temp=root->lchild;
            free(root);
            return temp;
        }
        NODE temp=min(root->rchild);
        root->data=temp->data;
        root->rchild=delete(root->rchild,temp->data);
    }
    return root;
}

int main()
{
   int i,item,choice=0;
   NODE p,root=NULL;
   printf("Enter:\n(1)Insertion of Key\n(2)Inorder Display\n(3)Preorder Display\n(4)Postorder Display\n");
   printf("(5)Searching a key\n(6)Deletion of a key\n(7)Minimum key value\n(8)Maximum key value\n(9)Exit\n");
   for(i=0;choice!=9;i++)
   {
      printf("\nEnter your choice:\n");
      scanf("%d",&choice);
      switch(choice)
      {
         case 1: printf("Enter key to be inserted: ");
                 scanf("%d",&item);
                 root=insert(root,item);
                 break;

         case 2: inorder(root);
                 printf("\n");
                 break;

         case 3: preorder(root);
                 printf("\n");
                 break;

         case 4: postorder(root);
                 printf("\n");
                 break;

         case 5: printf("Enter key to be searched: ");
                 scanf("%d",&item);
                 if(search(root,item)==1)
                  printf("Key found in binary tree!!\n");
                 else
                  printf("Key does not exist!!\n");
                 break;

         case 6: printf("Enter the key to be deleted: ");
                 scanf("%d",&item);
                 p=delete(root,item);
                 printf("\n");
                 break;

         case 7: p=min(root);
                 if(p==NULL)
                    printf("The Binary Tree is empty\n");
                 else
                    printf("Minimum key value: %d\n",p->data);
                 break;

         case 8: p=max(root);
                 if(p==NULL)
                    printf("The Binary Tree is empty\n");
                 else
                    printf("Maximum key value: %d\n",p->data);
                 break;

         case 9: exit(0);

         default: break;
      }
   }
   return 0;
}
