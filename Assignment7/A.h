//
// Created by tokoyama on 26/03/21.
//

#ifndef DSALAB_A_H
#define DSALAB_A_H

#endif //DSALAB_A_H

// C++ implementation of efficient algorithm to find
// smaller element on left side
#include<stdio.h>
int size=0;
struct element
{
    int val;
    int index;
};
struct element stack[1000];
// Prints smaller elements on left side of every element
void printPrevSmaller(int arr[], int n)
{

    for (int i=0; i<n; i++)
    {

        while (size!=0 && stack[size-1].val >= arr[i])
            size--;
        if (size==0)
            printf( "%d ",-1 );
        else
            printf( "%d ",stack[size-1].index+1 );
        stack[size].val=arr[i];
        stack[size++].index=i;

    }
}

/* Driver program to test insertion sort */
void solve()
{
    int arr[] = {2, 5, 3, 7, 8, 1, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    printPrevSmaller(arr, n);
//    return 0;
}
