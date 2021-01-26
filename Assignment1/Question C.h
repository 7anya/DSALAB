//
// Created by tokoyama on 21/01/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <zconf.h>

#ifndef DSALAB_QUESTION_C_H
#define DSALAB_QUESTION_C_H

#endif //DSALAB_QUESTION_C_H


void dinnerTable() {
    int max = INT_MIN;
    int curr = 0;
    int t;
    char s;
    int add, sub;
    scanf("%d", &t);
    while (t--) {


        scanf("%c", &s);
        if (s == 'E') {


            scanf("%d", &add);
            printf("number :%d", add);
            curr += add;
            printf("c=%d\n",curr);
        } else {
            int temp;
            scanf("%d", &sub);
            for (int i = 1; i <= sub; ++i) {
                scanf("%d", &temp);
            }
            curr -= sub;
        }
        if (curr > max)
            max = curr;
    printf("eeee%d\n",curr);
    }
    printf("%d", max);
}