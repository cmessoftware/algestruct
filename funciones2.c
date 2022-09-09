//Calcular el promedio de una lista de numeros
//Calcular el promedio.
#include<stdio.h>
#include <math.h>

int pasavalor(int a);
int pasaref(int *a);

int main(void)
{
    int a = 19;
    int rv = pasavalor(a);
    printf("%d\n",rv);

    int rr = pasaref(&a); //Le paso la direccion de memoria de a.
    printf("%d\n",rr);
    printf("%d\n",a);
    printf("%p\n",&a);
    rr = pasaref(&a); 
    puts("");
    printf("%d\n",rr);
    printf("%d\n",a);
    printf("%p\n",&a);
    
}

/// @brief Pasa por valor un entero
/// @param a 
/// @return 
int pasavalor(int a)
{
    //Proceso la var de entrada

    a = a%2; 

    //retorno un valor
    return a;
}

/// @brief Pasa por referencia un variable
/// @param a 
/// @return otra variable
int pasaref(int *a)
{

    int b = (*a)%2;

    *a = (*a)*2;

    return b;

}

