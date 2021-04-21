//
// Created by tokoyama on 13/04/21.
//

#ifndef DSALAB_E_H
#define DSALAB_E_H

#endif //DSALAB_E_H
// C++ implementation of the above approach


#include <stdio.h>


#define SIZE 3
const int N = 3;

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to return the minimized sum
int minSum(int A[], int B[], int C[], int i,
           int n, int curr, int dp[SIZE][N]) {
    if (n <= 0)
        return 0;
    if (dp[n][curr] != -1)
        return dp[n][curr];
    if (curr == 0) {
        return dp[n][curr] = max(B[i] + minSum(A, B, C, i + 1, n - 1, 1, dp),
                                 C[i] + minSum(A, B, C, i + 1, n - 1, 2, dp));
    }
    if (curr == 1)
        return dp[n][curr]= max(A[i] + minSum(A, B, C, i + 1, n - 1, 0, dp),
                             C[i] + minSum(A, B, C, i + 1, n - 1, 2, dp));
    return dp[n][curr]= max(A[i] + minSum(A, B, C, i + 1, n - 1, 0, dp),
                         B[i] + minSum(A, B, C, i + 1, n - 1, 1, dp));
}

// Driver code
void solve() {
    int A[] = {10, 20, 30};
    int B[] = {40, 50, 60};
    int C[] = {70, 80, 90};

    // Initialize the dp[][] array
    int dp[SIZE][N];
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = -1;

    // min(start with A[0], start with B[0], start with C[0])
    printf("%d", max(A[0] + minSum(A, B, C, 1, SIZE - 1, 0, dp),
                     max(B[0] + minSum(A, B, C, 1, SIZE - 1, 1, dp),
                         C[0] + minSum(A, B, C, 1, SIZE - 1, 2, dp))));

//    return 0;
}
