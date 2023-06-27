#include <stdio.h>

long fatorial_r(long n)
{
    if((n==1) || (n==0))
    {
        return 1;
    }else
        return (fatorial_r(n-1)*n);
}

long fatorial_i(int n)
{
    long fat;

    if((n==1) || (n==0))
    {
        fat = 1;
    }else
        for(fat=1; n>1; n--)
        {
            fat=fat*n;
        }

    return fat;
}
int main (int argc, char** argv)
{
    long n = 5;

    printf("%ld\n", fatorial_r(n));
    printf("%ld\n", fatorial_i(n));
    return 0;
}
//
// Created by yago on 20/06/23.
//
