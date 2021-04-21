//
// Created by tokoyama on 26/03/21.
//

#ifndef DSALAB_B_H
#define DSALAB_B_H

#endif //DSALAB_B_H
// C++ program to find largest
// rectangle with all 1s
// in a binary matrix
#include <stdio.h>
#define max(a,b) a>b?a:b


// Rows and columns in input matrix

int R,C;


int maxHist(int row[])
{

    int  result[1000];
    int size=0;

    int top_val;

    int max_area = 0;


    int area = 0;


    int i = 0;
    while (i < C) {

        if (size==0 || row[result[size-1]] <= row[i])
//            result.push(i++);
        result[size++]=i++;

        else {
            top_val = row[result[size-1]];
            size--;
              area = top_val * i;

            if (size!=0)
                area = top_val * (i - result[size-1] - 1);
            max_area = max(area, max_area);
        }
    }

    // Now pop the remaining bars from stack and calculate
    // area with every popped bar as the smallest bar
    while (size!=0) {
        top_val = row[result[size-1]];
        size--;
        area = top_val * i;
        if (size!=0)
            area = top_val * (i - result[size--] - 1);

        max_area = max(area, max_area);
    }
    return max_area;
}


int maxRectangle(int A[][C])
{

    int result = maxHist(A[0]);


    for (int i = 1; i < R; i++) {

        for (int j = 0; j < C; j++)

            if (A[i][j])
                A[i][j] += A[i - 1][j];

        result = max(result, maxHist(A[i]));
    }

    return result;
}

// Driver code
void solve()
{
    int a[100][100];
    scanf("%d %d",R,C);
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            scanf("%d",&a[i][j]);
        }
    }

   printf("%d",maxRectangle(a));

//    return 0;
}
