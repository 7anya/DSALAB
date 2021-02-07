//
// Created by tokoyama on 04/02/21.
//

#include <stdio.h>
#include <string.h>
#ifndef DSALAB_QUESTION_E_H
#define DSALAB_QUESTION_E_H

#endif //DSALAB_QUESTION_E_H

void printAllKLengthRec(char set[], char prefix[],int n, int k)
{

    // Base case: k is 0,
    // print prefix
    if (k == 0)
    {
//        for (int i = strlen(prefix)-3; i <strlen(prefix) ; ++i) {
//            printf("%c",prefix[i]);
//        }

        printf("%s\n",prefix);
//        cout << (prefix) << endl;
        return;
    }

    // One by one add all characters
    // from set and recursively
    // call for k equals to k-1
    for (int i = 0; i < n; i++)
    {

        prefix[strlen(prefix)]=set[i];
        prefix[strlen(prefix)+1]='\0';

        printAllKLengthRec(set,prefix, n, k - 1);
    }

}

void printAllKLength(char set[], int k,int n)
{
    char a[100];

    printAllKLengthRec(set, a, n, k);
}

// Driver Code
void solveE()
{

    char set1[] = {'a', 'b'};
    int k = 3;
    printAllKLength(set1, k, 2);


}
