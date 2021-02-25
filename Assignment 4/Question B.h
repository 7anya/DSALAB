//
// Created by tokoyama on 24/02/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>

#ifndef DSALAB_QUESTION_B_H
#define DSALAB_QUESTION_B_H

#endif //DSALAB_QUESTION_B_H
struct element
{
    int index;
    int val;
};
int replace(struct element a[], int n) {
    struct element b[n];int  k = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i].val == -1)
            continue;
        b[k++] = a[i];
    }
    for (int i = 0; i < k; ++i) {
        a[i] = b[i];
    }
    return k;
}

void print(struct element a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i].val);
    }
    printf("\n");
}

void solve() {
    int n, alpha, beta;
    scanf("%d", &n);
    struct element a[n];
    scanf("%d", &alpha);
    scanf("%d", &beta);
    int m=INT_MIN,ind;
    for (int i = 0; i < n; ++i) {

        scanf("%d", &a[i].val);
      a[i].index=i;
    }

    while (n > 1) {
        if (n % 2 == 1) {
            a[n - 1].val += beta;
//            print(a, n);
        }
        for (int i = 0; i < n - 1; i += 2) {
            if (a[i].val > a[i + 1].val) {
                a[i].val = abs(a[i].val - alpha * (a[i].val - a[i + 1].val));
                a[i + 1].val = -1;
//                print(a, n);
            } else if (a[i + 1].val > a[i].val) {
                a[i + 1].val = abs(a[i + 1].val- alpha * (a[i + 1].val - a[i].val));
                a[i].val = -1;
//                print(a, n);
            } else {
                a[i].val = -1;
                a[i + 1].val = -1;
//                print(a, n);
            }
        }
        n = replace(a, n);
//        print(a, n);
    }
    if (a[0].val == -1)
        printf("-1 -1");
    else
        printf("%d %d",a[0].index+1, a[0].val);

}