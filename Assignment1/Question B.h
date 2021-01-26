//
// Created by tokoyama on 21/01/21.
//
#include <stdio.h>
#include <stdlib.h>

#ifndef DSALAB_QUESTION_B_H
#define DSALAB_QUESTION_B_H

#endif //DSALAB_QUESTION_B_H

struct Node {
    char data;
    struct Node *next; // Pointer to next node in DLL
    struct Node *prev; // Pointer to previous node in DLL
};

void push(struct Node **head_ref, char new_data) {

    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = new_data;

    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

int checkPalindrome(struct Node *left) {

    if (left == NULL)
        return 1;
    struct Node *right = left;
    while (right->next != NULL)
        right = right->next;

    while (left != right) {
        if (left->data != right->data)
            return 0;

        left = left->next;
        right = right->prev;
    }
    return 1;
}

void Palindrome() {
    int n;
    scanf("%d", &n);
    char a[n + 1];
    scanf("%s", a);

    struct Node *head = NULL;
    for (int i = 0; a[i] != '\0'; ++i) {
        push(&head, a[i]);
    }
    if (checkPalindrome(head)==0)
        printf("NOT A PALINDROME");
    else
        printf("PALINDROME");

}
