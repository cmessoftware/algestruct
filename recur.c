#include<stdio.h>

long factorial(int n);
long factorialr(int n);

int main(void)
{
    printf("%ld\n",factorialr(6));

}


long factorialr(int n)
{
     if(n == 1 || n==0) return 1;
     return n*factorialr(n-1);
}


long factorial(int n)
{
    long f=n;
    if(n == 1 || n==0) return 1;

    while(n > 1)
    {
        f = f*(n-1);
        n--;
    }

    return f;

}
