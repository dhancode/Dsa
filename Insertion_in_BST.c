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

void insertion (struct node * root,int key)
{
    struct node *prev=NULL;
    while(root!=NULL)
    {
        prev=root;
        if(root->data==key)
        {
            printf("element can't be entered ,already exist %d\n",key);
            return;
        }
        else if(root->data>key)
        {
            root=root->left;
        }
        else
        {
            root=root->right;
        }
    }
    struct node *new=createNode(key);
    if(prev->data>key)
    {
        prev->left=new;
    }
    else
    {
        prev->right=new;
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

    
    insertion(p1,7);
    printf("%d",p1->right->right->data);

}