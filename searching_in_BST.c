#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*left;
    struct node *right;
};
struct node * createNode(int data)
{
    struct node * n=(struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;

    return n;
}

void inOrder(struct node * root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
int isBST(struct node * root)
{
    if(root!=NULL)
    {
        struct node *prev=NULL;
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev!=NULL && prev->data>root->data)
        {
            return 0;
        }
        prev=root;
        isBST(root->right);
    }
    else
    {
        return 1;
    }
}

struct node * search(struct node * root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==key)
    {
        return root;
    }
    else if(root->data>key)
    {
        return search(root->left,key);
    }
    else
    {
        return search(root->right,key);
    }
}
int main()
{
    struct node * p1=createNode(5);
    struct node * p2=createNode(3);
    struct node * p3=createNode(6);
    struct node * p4=createNode(1);
    struct node * p5=createNode(4);

    p1->left=p2;
    p1->right=p3;
    p2->left=p4;
    p2->right=p5;

    inOrder(p1);
    printf("\n");
    if(isBST(p1))
    {
        printf("it is A BST\n");
    }
    struct node * n=search(p1,10);
    if(n!=NULL)
    {
        printf("element is %d\n",n->data);
    }
    else
    {
        printf("element not found \n");
    }
}