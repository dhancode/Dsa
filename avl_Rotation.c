#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

int max(int a,int b)
{
    return a>b?a:b;
}

struct node * createNode(int val)
{
    struct node * n=(struct node *)malloc(sizeof(struct node));
    n->left=NULL;
    n->right=NULL;
    n->height=1;
    n->data=val;
    return n;
}

int getHeight(struct node * n)
{
    if(n==NULL)
    {
        return 0;
    }
    else
    {
        return n->height;
    }
}
int balanceFactor(struct node *n)
{
    if(n==NULL)
    {
        return 0;
    }
    else
    {
        return getHeight(n->left)-getHeight(n->right);
    }
}



struct node * rightRotate(struct node * y)
{
    struct node * x=y->left;
    struct node * T2=x->right;

    x->right=y;
    y->left=T2;

    x->height=max(getHeight(x->left),getHeight(x->right))+1;
    y->height=max(getHeight(y->left),getHeight(y->right))+1;

    return x;
}


struct node * leftRotate(struct node * x)
{
    struct node * y=x->right;
    struct node * T2=y->left;

    y->left=x;
    x->right=T2;

    x->height=max(getHeight(x->left),getHeight(x->right))+1;
    y->height=max(getHeight(y->left),getHeight(y->right))+1;

    return y;
}


struct node * insert(struct node * node,int val)
{
    if(node==NULL)
    {
        return createNode(val);
    }
    if(val<node->data)
    {
        node->left=insert(node->left,val);
    }
    else if(val>node->data)
    {
        node->right=insert(node->right,val);
        
    }
    else
    {
        return node;
    }
    
    node->height=max(getHeight(node->left),getHeight(node->right))+1;

    int bf=balanceFactor(node);
    //left left
    if(bf>1 && node->left->data>val)
    {
        return rightRotate(node);
    }
    //right right
    if(bf<-1 && node->right->data<val)
    {
        return leftRotate(node);
    }
    // left right
    if(bf>1 && node->left->data<val)
    {
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }

    //right left
    if(bf<-1 && node->right->data>val)
    {
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(struct node * root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{
    struct node * root=NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,6);
    root=insert(root,3);

    preOrder(root);
}