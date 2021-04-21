//
// Created by tokoyama on 21/04/21.
//

#ifndef DSALAB_TREE_H
#define DSALAB_TREE_H

#endif //DSALAB_TREE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* arr;
struct Node** add;

struct Node
{
    int val;
    struct Node* left,*right;
};

struct Node* newNode(int i)
{
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    add[i]=node;
    node->val=arr[i];
    node->left=NULL;
    node->right=NULL;
    return (node);
}
struct Node* delete(struct Node* root,int x)
{
    if(root==NULL)
        return NULL;
    root->left=delete(root->left,x);
    root->right=delete(root->right,x);

    if(root->val==x)
    {
        return NULL;
    }
    return root;
}

struct Node* search(struct Node* root,int data)
{
    if(!root)
        return NULL;

    else if(root->val==data)
        return root;

    else
    {
        if(search(root->left,data))
            return search(root->left,data);
        return search(root->right,data);
    }
}

void printInorder(struct Node* node)
{
    if(node==NULL)
        return;
    printInorder(node->left);
    printf("%d ",node->val);
    printInorder(node->right);
}

void swap(struct Node* temp1,struct Node* temp2)
{
    struct Node* temp;
    int temporary;

    temporary=temp1->val;
    temp1->val=temp2->val;
    temp2->val=temporary;
    temp=temp1->left;
    temp1->left=temp2->left;
    temp2->left=temp;
    temp=temp1->right;
    temp1->right=temp2->right;
    temp2->right=temp;
}

int max(int a,int b)
{
    return(a>b)?a:b;
}

int height(struct Node* node)
{
    if(node==NULL)
        return 0;

    return 1+max(height(node->left),height(node->right));
}

int diameter(struct Node* tree)
{
    if(tree==NULL)
        return 0;

    int lheight=height(tree->left);
    int rheight=height(tree->right);

    int ldiameter=diameter(tree->left);
    int rdiameter=diameter(tree->right);

    return max(lheight+rheight+1,max(ldiameter,rdiameter));
}

int main()
{
    int i,x,y,z,n,t;
    char ch;
    char string[7];
    scanf("%d %d",&n,&t);
    arr=(int*)malloc(n*sizeof(int));
    add=(struct Node*)malloc(n*sizeof(struct Node));
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    struct Node* root=newNode(0);
    for(i=0;i<n-1;i++)
    {
        scanf("%d %d%*c%c",&x,&y,&ch);
        if(ch=='L')
            ((struct Node*)add[x])->left=newNode(y);

        else
            ((struct Node*)add[x])->right=newNode(y);
    }
    /*printInorder(root);
    printf("\n");*/
    for(i=0;i<t;i++)
    {
        scanf("%s",string);
        if(strcmp(string,"DELETE")==0)
        {
            scanf("%d",&z);
            root=delete(root,z);
        }
        else
        {
            scanf("%d %d",&x,&y);
            struct Node* temp1=search(root,x);
            struct Node* temp2=search(root,y);
            swap(temp1,temp2);
        }
    }
    /*printInorder(root);
    printf("\n");*/
    printf("%d",diameter(root)-1);

    return 0;
}