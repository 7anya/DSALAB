//
// Created by tokoyama on 16/03/21.
//

#ifndef DSALAB_C_H
#define DSALAB_C_H

#endif //DSALAB_C_H
// Efficient C++ program to find minimum time
// required to produce m items.
#include<stdio.h>

int findItems(int arr[], int n, int temp)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += (temp/arr[i]);
    return ans;
}


int binarySearch(int *arr, int n, int m, int high)
{
    int low = 1;

    while (low < high)
    {
        int mid = (low+high)>>1;
        int itm = findItems(arr, n, mid);
        if (itm < m)
            low = mid+1;
        else
            high = mid;
    }
    return high;
}


int Time(int *arr, int n, int m)
{
    int maxval = -1000000000;
    for (int i = 0; i < n; i++)
        if(maxval<arr[i])
            maxval=arr[i];

    return binarySearch(arr, n, m, maxval * m);
}


int main()
{
    int n ;
    int k;
    scanf("%d %d",&n,&k);
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d",&a[i]);
    }
    printf("%d", Time(a, n, k));

    return 0;
}
