//
// Created by tokoyama on 21/04/21.
//

#ifndef DSALAB_HEAP_H
#define DSALAB_HEAP_H

#endif //DSALAB_HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zconf.h>

#define N 1000

int size = 0, a[N];

int getMinElement() {
    return a[0];
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int leftChild(int x) {
    return 2 * x + 1;
}

int rightChild(int x) {
    return 2 * x + 2;
}

int parent(int x) {
    return (x - 1) / 2;
}

void heapify(int i) {
    if (size == 1)
        return;
    int index = i;
    if (leftChild(i) < size && a[leftChild(i)] > a[index])
        index = leftChild(i);
    if (rightChild(i) < size && a[rightChild(i)] > a[index])
        index = rightChild(i);
    if (index != i) {
        swap(&a[i], &a[index]);
        heapify(index);
    }
}

void buildHeap() {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(i);
}

void deleteNode(int array[], int num) {
    int i;
    for (i = 0; i < size; i++) {
        if (num == array[i])
            break;
    }

    swap(&array[i], &array[size - 1]);
    size -= 1;
    buildHeap();
}

int deleteMax() {
    if (size <= 0)
        return INT_MIN;
    if (size == 1) {
        return a[--size];
    }
    int maxval = getMinElement();
    swap(&a[0], &a[size - 1]);
    size--;
    heapify(0);
    return maxval;
}

void insert(int value) {
    if (size == 0) {
        a[0] = value;
        size++;
        return;
    }
    a[size++] = value;
    buildHeap();
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    size = n;
    buildHeap();
    for(int i=0;i<size;i++)
        printf("%d ",&a[i]);

    return 0;
}