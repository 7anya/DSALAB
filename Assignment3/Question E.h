//
// Created by tokoyama on 11/02/21.
//

#include <stdio.h>
#include <string.h>

#ifndef DSALAB_QUESTION_E_H
#define DSALAB_QUESTION_E_H

#endif //DSALAB_QUESTION_E_H


int x=0;

int f(int n)
{
    char a[10],k;
    scanf("%s",a);
    scanf("%d",&k);
    if(strcmp(a,"FD")==0)
        x+=a;

}
void solveE()
{
  int n;
  scanf("%d",&n);

  int ans=f(n);
  printf("%d",&ans);
}