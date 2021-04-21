//
// Created by tokoyama on 25/02/21.
//

#include <stdbool.h>
#include <memory.h>
#include <stdio.h>

#ifndef DSALAB_QUESTION_G_H
#define DSALAB_QUESTION_G_H

#endif //DSALAB_QUESTION_G_H


// Optimized implementation of Bubble sort
//#include <stdio.h>
int c=0;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n-1; i++)
    {
        swapped = false;
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                c++;
                swapped = true;
            }
        }

        // IF no two elements were swapped by inner loop, then break
        if (swapped == false)
            break;
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}

// Driver program to test above functions
void solve ()
{
    int arr[] = {1, 20 ,6, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    bubbleSort(a, n);
//    printf("Sorted array: \n");
//    printArray(array, n);
    printf("%d",c);
//    return 0;
}
