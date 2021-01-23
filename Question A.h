//
// Created by tokoyama on 21/01/21.
//
#include<stdio.h>

#ifndef DSALAB_QUESTION_A_H
#define DSALAB_QUESTION_A_H

#endif //DSALAB_QUESTION_A_H

int fl = 0, n;
char s[105];




void check(int ind, int x) {
    if (x == 4) {
        if (fl == 0) {
            printf("YES\n");
        }
        printf("%d ", ind - 3);
        return;
    }
    switch (x) {
        case 0 :
            if (s[ind] == 'b') {
                check(ind + 1, x + 1);
            }
            break;
        case 1 :
            if (s[ind] == 'a') {
                check(ind + 1, x + 1);
            }
            break;
        case 2 :
            if (s[ind] == 'a') {
                check(ind + 1, x + 1);
            }
            break;
        case 3 :
            if (s[ind] == 'b') {
                check(ind + 1, x + 1);
            }
            break;
    }
    if (ind % 4 == 3 && x == 0) {
        if (n > ind + 4) {
            check(ind + 1, 0);
        }
        if (n > ind + 5) {
            check(ind + 2, 0);
        }
        if (n > ind + 6) {
            check(ind + 3, 0);
        }
        if (n > ind + 7) {
            check(ind + 4, 0);
        }
    }
}


void baab() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d\n", &n);
    scanf("%s", s);

    if (n <= 3) {
        printf("NO\n");
        return;
    }

    check(0, 0);

    if (n >= 5) {
        check(1, 0);
    }

    if (n >= 6) {
        check(2, 0);
    }

    if (n >= 7) {
        check(3, 0);
    }

    if (!fl) {
        printf("NO\n");
    }


}