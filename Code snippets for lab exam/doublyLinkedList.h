//
// Created by tokoyama on 21/04/21.
//

#ifndef DSALAB_SNIPPS_H
#define DSALAB_SNIPPS_H

#endif //DSALAB_SNIPPS_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//doubly linked list
struct Node {
    int data;
    struct Node *next; // Pointer to next Node in DLL
    struct Node *prev; // Pointer to previous Node in DLL
};

void printLL(struct Node *head) {
    while (head != NULL) {
        printf("%d", head->data);
        head = head->next;
    }

}

void append(struct Node **head_ref, int new_data) {
    /* 1. allocate Node */
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));

    struct Node *last = *head_ref; /* used in step 5*/

    /* 2. put in the data  */
    new_node->data = new_data;

    /* 3. This new Node is going to be the last Node, so
          make next of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new
          Node as head */
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last Node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last Node */
    last->next = new_node;

    /* 7. Make last Node as previous of new Node */
    new_node->prev = last;

}

void push(struct Node **head_ref, int new_data) {

    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = new_data;

    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}

void use()
{
    struct Node *head = NULL;
//example of function call
push(&head,8);
}

