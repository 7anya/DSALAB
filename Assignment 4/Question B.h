//
// Created by tokoyama on 24/02/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>

#ifndef DSALAB_QUESTION_B_H
#define DSALAB_QUESTION_B_H

#endif //DSALAB_QUESTION_B_H

int replace(int a[], int n) {
    int b[n], k = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == -1)
            continue;
        b[k++] = a[i];
    }
    for (int i = 0; i < k; ++i) {
        a[i] = b[i];
    }
    return k;
}

void print(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void solve() {
    int n, alpha, beta;
    scanf("%d", &n);
    int a[n];
    scanf("%d", &alpha);
    scanf("%d", &beta);
    int m=INT_MIN,ind;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if(a[i]>m)
        {
            m=a[i];
            ind=i;
        }
    }

    while (n > 1) {
        if (n % 2 == 1) {
            a[n - 1] += beta;
//            print(a, n);
        }
        for (int i = 0; i < n - 1; i += 2) {
            if (a[i] > a[i + 1]) {
                a[i] = abs(a[i] - alpha * (a[i] - a[i + 1]));
                a[i + 1] = -1;
//                print(a, n);
            } else if (a[i + 1] > a[i]) {
                a[i + 1] = abs(a[i + 1] - alpha * (a[i + 1] - a[i]));
                a[i] = -1;
//                print(a, n);
            } else {
                a[i] = -1;
                a[i + 1] = -1;
//                print(a, n);
            }
        }
        n = replace(a, n);
//        print(a, n);
    }
    if (a[0] == -1)
        printf("-1 -1");
    else
        printf("%d %d",ind+1, a[0]);

}