//
// Created by tokoyama on 21/04/21.
//

#ifndef DSALAB_TREEBUILDFROMINORDER_H
#define DSALAB_TREEBUILDFROMINORDER_H

#endif //DSALAB_TREEBUILDFROMINORDER_H
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
    char data[20];
    struct node *left;
    struct node *right;

};


struct node* addNewNode(char i[]) {
    struct node *node = (struct node *) malloc(sizeof(struct node));
    strcpy(node->data,i);
    node->left = NULL;
    node->right = NULL;
    return (node);
}
void inOrder(struct node* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%s ",root->data);
        inOrder(root->right);
    }
}
char *strrev(char *str){
    char c, *front, *back;

    if(!str || !*str)
        return str;
    for(front=str,back=str+strlen(str)-1;front < back;front++,back--){
        c=*front;*front=*back;*back=c;
    }
    return str;
}

struct node *insertLevelOrder(char arr[100][20], struct node *root,
                              int i, int n) {
    if (i < n) {

        struct node *temp = addNewNode(strrev(arr[i]));
        root = temp;

        if(strcmp(arr[2*i+1],"-1")!=0)

            root->left = insertLevelOrder(arr,
                                          root->left, 2 * i + 1, n);
        if(strcmp(arr[2*i+1+1],"-1")!=0)
            root->right = insertLevelOrder(arr,
                                           root->right, 2 * i + 2, n);
    }
    return root;
}



void invert(struct node *root) {
    if (!root)
        return;
    // root->data = reverse(root->data);
    struct node*temp;
    temp=root->left;
    root->left=root->right;
    root->right=temp;
    invert(root->left);
    invert(root->right);
}

int main() {
    int n;
    scanf("%d", &n);
    char a[100][20];

    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }
    struct node *root= insertLevelOrder(a, root, 0, n);
//    inOrder(root);
    invert(root);
//    printf("\n");
    inOrder(root);

}