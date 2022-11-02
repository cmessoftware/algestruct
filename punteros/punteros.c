#include <stdio.h>
#include <time.h>

typedef struct nodo
{
    int num;
    struct nodo* sig;
}Nodo;


void ejemplo1()
{
    int a = 10;
    int *pa = &a;  //Asigno la direccion de memoria de a.

    printf("Valor de a: %d\n",a);
    printf("Valor de pa: %x\n",pa);
    printf("Valor de pa: %p\n",pa);
    printf("Valor de a: %d\n",*pa);    

}


void ejemplo2()
{
    int a[5] = {10,5,3,0,2};
    int *pa = &a;  //Asigno la direccion de memoria de a.
    int i = 0;

    printf("Size int: %d",sizeof(int));

    while(i < 5)
    {
        printf("Valor de a: %d\n",a[i]);
        printf("Valor de pa: %p\n",pa);
        printf("Valor de a: %d\n",*pa);   
        puts("------------------------"); 
        pa++;
        i++;
    }
}


void ejemplo3()
{
    Nodo nodos[5];
    srand(time(NULL));
    Nodo *pn = &nodos;

    for(int x = 0; x < 5; x++)
    {
       nodos[x].num = rand()%100;
       nodos[x].sig = NULL;     
    }

    int i = 0;
    while(i < 5)
    {
        printf("Valor de a: %d\n",nodos[i].num);
        printf("Valor de pa: %p\n",pn);
        printf("Valor de a: %d\n",*pn);   
        puts("------------------------"); 
        pn++;
        i++;
    }
}


void main()
{
    ejemplo3();

    return;
}