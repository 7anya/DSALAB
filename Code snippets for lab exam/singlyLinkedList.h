//
// Created by tokoyama on 21/04/21.
//

#include <lzma.h>
#include <malloc.h>

#ifndef DSALAB_SINGLYLINKEDLIST_H
#define DSALAB_SINGLYLINKEDLIST_H

#endif //DSALAB_SINGLYLINKEDLIST_H
struct Node {
    int data;
    struct Node *next;
};
typedef struct Node Node;

static void reverse(struct Node **head_ref) {
    struct Node *prev = NULL;
    struct Node *current = *head_ref;
    struct Node *next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
        current->next = prev;
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

/* Function to push a Node */
void push(struct Node **head_ref, int new_data) {
    struct Node *new_node
            = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

/* Given a reference (pointer to pointer)
to the head of a list and an int,
inserts a new Node on the front of the list. */
void push1(Node **head_ref, int new_data) {
    /* 1. allocate Node */
    struct Node *new_node
            = (struct Node *) malloc(sizeof(struct Node));

    /* 2. put in the data */
    new_node->data = new_data;

    /* 3. Make next of new Node as head */
    new_node->next = (*head_ref);

    /* 4. move the head to point to the new Node */
    (*head_ref) = new_node;
}

// Given a Node prev_node, insert a
// new Node after the given
// prev_node
void insertAfter(Node *prev_node, int new_data) {

    // 1. Check if the given prev_node is NULL
    if (prev_node == NULL) {
        return;
    }

    // 2. Allocate new Node
    struct Node *new_node
            = (struct Node *) malloc(sizeof(struct Node));

    // 3. Put in the data
    new_node->data = new_data;

    // 4. Make next of new Node as
    // next of prev_node
    new_node->next = prev_node->next;

    // 5. move the next of prev_node
    // as new_node
    prev_node->next = new_node;
}

// Given a reference (pointer to pointer) to the head
// of a list and an int, appends a new Node at the end
void append(Node **head_ref, int new_data) {
    // 1. allocate Node
    struct Node *new_node
            = (struct Node *) malloc(sizeof(struct Node));
    Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}
// Given a reference (pointer to pointer)
// to the head of a list and a key, deletes
// the first occurrence of key in linked list
void deleteNode(Node** head_ref, int key)
{

    // Store head Node
    Node* temp = *head_ref;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        free(temp);           // free old head
        return;
    }

    else
    {
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        // If key was not present in linked list
        if (temp == NULL)
            return;

        // Unlink the Node from linked list
        prev->next = temp->next;

        // Free memory
        free(temp);
    }
}
void deleteNodeAtPostion(struct Node **head_ref, int position)
{
    if (*head_ref == NULL)
        return;

    struct Node* temp = *head_ref;
    if (position == 0)
    {
        *head_ref = temp->next;   // Change head
        free(temp);               // free old head
        return;
    }

    for (int i=0; temp!=NULL && i<position-1; i++)
        temp = temp->next;

    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
        return;

    // Node temp->next is the Node to be deleted
    // Store pointer to the next of Node to be deleted
    struct Node *next = temp->next->next;

    // Unlink the Node from linked list
    free(temp->next);  // Free memory

    temp->next = next;  // Unlink the deleted Node from list
}
void deleteList(struct Node** head_ref)
{
    /* deref head_ref to get the real head */
    struct Node* current = *head_ref;
    struct Node* next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    /* deref head_ref to affect the real head back
       in the caller. */
    *head_ref = NULL;
}
/* Counts no. of nodes in linked list */
int getCount(struct Node* head)
{
    int count = 0;  // Initialize count
    struct Node* current = head;  // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}
void printMiddle(struct Node *head)
{
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;

    if (head!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is [%d]\n\n", slow_ptr->data);
    }
}
int detectLoop(struct Node* list)
{
    struct Node *slow_p = list, *fast_p = list;

    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return 1;
        }
    }
    return 0;
}
void removeLoop(struct Node* loop_node, struct Node* head)
{
    struct Node* ptr1;
    struct Node* ptr2;

    /* Set a pointer to the beginning of the Linked List and
      move it one by one to find the first node which is
      part of the Linked List */
    ptr1 = head;
    while (1) {
        /* Now start a pointer from loop_node and check if
       it ever reaches ptr2 */
        ptr2 = loop_node;
        while (ptr2->next != loop_node
               && ptr2->next != ptr1)
            ptr2 = ptr2->next;

        /* If ptr2 reahced ptr1 then there is a loop. So
        break the loop */
        if (ptr2->next == ptr1)
            break;

        /* If ptr2 did't reach ptr1 then try the next node
         * after ptr1 */
        ptr1 = ptr1->next;
    }

    /* After the end of loop ptr2 is the last node of the
     loop. So make next of ptr2 as NULL */
    ptr2->next = NULL;
}
struct Node *newNode(int key)
{
    struct Node *temp =
            (struct Node*)malloc(sizeof(struct Node));
    temp->data = key;
    temp->next = NULL;
    return temp;
}
int countNodes(struct Node *n)
{
    int res = 1;
    struct Node *temp = n;
    while (temp->next != n)
    {
        res++;
        temp = temp->next;
    }
    return res;
}

/* This function detects and counts loop
   nodes in the list. If loop is not there
   in then returns 0 */
int countNodesinLoop(struct Node *list)
{
    struct Node  *slow_p = list, *fast_p = list;

    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;

        /* If slow_p and fast_p meet at some point
           then there is a loop */
        if (slow_p == fast_p)
            return countNodes(slow_p);
    }

    /* Return 0 to indeciate that ther is no loop*/
    return 0;
}
struct Node* sortedIntersect(
        struct Node* a,
        struct Node* b)
{
    struct Node* result = NULL;
    struct Node** lastPtrRef = &result;

    /* Advance comparing the first
     nodes in both lists.
    When one or the other list runs
     out, we're done. */
    while (a != NULL && b != NULL) {
        if (a->data == b->data) {
            /* found a node for the intersection */
            push(lastPtrRef, a->data);
            lastPtrRef = &((*lastPtrRef)->next);
            a = a->next;
            b = b->next;
        }
        else if (a->data < b->data)
            a = a->next; /* advance the smaller list */
        else
            b = b->next;
    }
    return (result);
}

void toUse()
{
    Node* head = NULL;

    // Insert 6. So linked list becomes 6->NULL
    append(&head, 6);

    // Insert 7 at the beginning.
    // So linked list becomes 7->6->NULL
    push(&head, 7);

    // Insert 1 at the beginning.
    // So linked list becomes 1->7->6->NULL
    push(&head, 1);

    // Insert 4 at the end. So
    // linked list becomes 1->7->6->4->NULL
    append(&head, 4);

    // Insert 8, after 7. So linked
    // list becomes 1->7->8->6->4->NULL
    insertAfter(head->next, 8);

}