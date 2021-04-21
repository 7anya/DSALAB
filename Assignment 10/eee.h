//
// Created by tokoyama on 14/04/21.
//

#ifndef DSALAB_EEE_H
#define DSALAB_EEE_H

#endif //DSALAB_EEE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *array;
struct Node **add;

struct Node {
    int data;
    struct Node *left, *right;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node *node) {
    if (node == NULL)
        return 0;

    return 1 + max(height(node->left), height(node->right));
}

struct Node *addNewNode(int i) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    add[i] = node;
    node->data = array[i];
    node->left = NULL;
    node->right = NULL;
    return (node);
}

struct Node *searchNode(struct Node *root, int data) {
    if (!root)
        return NULL;

    else if (root->data == data)
        return root;

    else {
        if (searchNode(root->left, data))
            return searchNode(root->left, data);
        return searchNode(root->right, data);
    }
}

struct Node *delete(struct Node *root, int data) {
    if (root == NULL)
        return NULL;
    root->left = delete(root->left, data);
    root->right = delete(root->right, data);

    if (root->data == data) {
        return NULL;
    }
    return root;
}

void inorderTraversal(struct Node *node) {
    if (node == NULL)
        return;
    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
}

void swapNodes(struct Node *temp1, struct Node *temp2) {
    struct Node *temp;
    int yeeeet;

    yeeeet = temp1->data;
    temp1->data = temp2->data;
    temp2->data = yeeeet;
    temp = temp1->left;
    temp1->left = temp2->left;
    temp2->left = temp;
    temp = temp1->right;
    temp1->right = temp2->right;
    temp2->right = temp;
}


int diameterOfTree(struct Node *root) {
    if (root == NULL)
        return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);

    int ldiameter = diameterOfTree(root->left);
    int rdiameter = diameterOfTree(root->right);

    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}

int main() {
    int n, t;
    char ch;
    char s[20];
    scanf("%d %d", &n, &t);
    array = (int *) malloc(n * sizeof(int));
    add = (struct Node **) (struct Node *) malloc(n * sizeof(struct Node));
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]);
    struct Node *root = addNewNode(0);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d %d%*c%c", &x, &y, &ch);
        if (ch == 'L')
            ((struct Node *) add[x])->left = addNewNode(y);

        else
            ((struct Node *) add[x])->right = addNewNode(y);
    }
    for (int i = 0; i < t; i++) {
        scanf("%s", s);
        if (strcmp(s, "DELETE") == 0) {
            int z;
            scanf("%d", &z);
            root = delete(root, z);
        } else {
            int x, y;
            scanf("%d %d", &x, &y);
            struct Node *parent1 = searchNode(root, x);
            struct Node *parent2 = searchNode(root, y);
            swapNodes(parent1, parent2);
        }
    }
    printf("%d", diameterOfTree(root) - 1);

    return 0;
}