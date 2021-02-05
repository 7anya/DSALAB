//
// Created by tokoyama on 04/02/21.
//

#include <math.h>

#ifndef DSALAB_QUESTIONA_H
#define DSALAB_QUESTIONA_H

#endif //DSALAB_QUESTIONA_H

//#define int long long;
int div1=0,div2=0;
int f[100000];
int check(int n)
{
    int c=0;
    for (int i = 2; i < n ; ++i) {
        if(n%i==0)
            c++;
    }
//    printf("\n %d =%d",n,c);
    if(c<=1)
        return 0;
    else
    {   c=0;
        for(int i=n-1;i>=2;i--)
        {   if(c>=2)
            break;

            if(n%i==0)
            {
//                printf("%d ***",i);
                if(c==0)
                    div1=i;
                else
                    div2=i;
                c++;
            }

        }
//        printf("\n %d $$ %d\n ",div1,div2);
        return 1;
    }
}
void solveA()
{
    int n;
    scanf("%d",&n);
    f[0]=0;
    f[1]=0;
    f[2]=2;

    for (int i = 3; i <=n;++i) {
        if(check(i)==1)
        {
            f[i]=f[div1]+f[div2];


        }
        else
        {
            f[i]=i;
        }
//        printf("%d ",f[i]);
    }
    printf("%d",f[n]);
//    printf("\n %d $$ %d\n ",div1,div2);
}