#include<stdio.h>


void main(void)
{
    int a = 10;

    int *pa = &a;

    int **ppa = pa;

    int *b = pa;
    int **c = &b;
    int ***d = &c;
    int ****e = &d;

    printf("%d\n",a);
    printf("%p\n",pa);
    printf("%p\n",ppa);

    puts("--------------------------");


}