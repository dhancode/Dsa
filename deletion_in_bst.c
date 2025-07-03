#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node * createNode(int data)
{
    struct node * n=(struct node *)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void inOrder(struct node *root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
struct node * inorderPred(struct node *root)
{
    root=root->left;
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root;

}
struct node * deleteNode(struct node * root,int key)
{
    struct node *pre;
    if(root==NULL)
    {
        return NULL;
    }
    else if(root->left==NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }
    if(root->data>key)
    {
        root->left=deleteNode(root->left,key);
    }
    else if(root->data<key)
    {
        root->right=deleteNode(root->right,key);
    }
    else
    {
        pre=inorderPred(root);
        root->data=pre->data;
        root->left=deleteNode(root->left,pre->data);
    }
    return root;
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

    inOrder(p1);//before deletion 
    printf("\n");
    deleteNode(p1,3);
    inOrder(p1);



}