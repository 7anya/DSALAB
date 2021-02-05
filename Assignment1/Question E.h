//
// Created by tokoyama on 21/01/21.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef DSALAB_QUESTION_E_H
#define DSALAB_QUESTION_E_H

#endif //DSALAB_QUESTION_E_H
struct Node {
    int data;
    struct Node *next; // Pointer to next node in DLL
    struct Node *prev; // Pointer to previous node in DLL
};

void printLL(struct Node *head) {
    while (head != NULL) {
        printf("%d", head->data);
        head = head->next;
    }

}

void append(struct Node **head_ref, int new_data) {
    /* 1. allocate node */
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));

    struct Node *last = *head_ref; /* used in step 5*/

    /* 2. put in the data  */
    new_node->data = new_data;

    /* 3. This new node is going to be the last node, so
          make next of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new
          node as head */
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;

    /* 7. Make last node as previous of new node */
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
void INC()
{
    struct node *p = tail;
    while(p != NULL && p->data == 1)
    {
        p->data = 0;
        p = p->prev;
    }
    if(p != NULL)
        p->data = 1;
}

void DEC()
{
    struct node *p = tail;
    while(p != NULL && p->data == 0)
    {
        p->data = 1;
        p = p->prev;
    }
    if(p != NULL)
        p->data = 0;
}

void digital() {
    int bits;
    scanf("%d", &bits);
    struct Node *head = NULL;
    while (bits != 0) {
        push(&head, bits % 10);
        bits /= 10;
    }
    int t;
    char s[10];
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        if (strcmp(s, "LS") == 0) {

            append(&head, 0);
            head = head->next;
        } else if (strcmp(s, "RS") == 0) {
            push(&head, 0);
            struct Node *temp = head;
            while (temp->next->next != NULL)
                temp = temp->next;
            temp->next = NULL;

        } else if (strcmp(s, "LR") == 0) {
            append(&head, head->data);
            head = head->next;
        } else if (strcmp(s, "RR") == 0) {
            struct Node *last = head;
            while (last->next != NULL) {
                last = last->next;
            }
            push(&head, last->data);
            struct Node *temp = head;
            while (temp->next->next != NULL)
                temp = temp->next;
            temp->next = NULL;
        } else if (strcmp(s, "INC") == 0) {
            ;
        } else {
            ;
        }
        printLL(head);
    }
    printf("\n ans:");
    printLL(head);

}