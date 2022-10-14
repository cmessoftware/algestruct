#include<stdio.h>

int fibonacci(int n);

int main(void)
{
    printf("%d\n",fibonaccir(6));

}

int fibonaccir(int n)
{
    if (n<=2){
        return n;
    } else {
        return fibonaccir(n-1) + fibonaccir(n-2);
    }
}

int fibonacci(int n)
{
    int f[n];
    f[0] = 1;
    f[1] = 2;

    for(int i = 2; i < n ; i++)
    {
        f[i] = f[i-1] + f[i-2];
    }

    return f[n-1];
}
