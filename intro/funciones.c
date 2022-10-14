//Calcular el promedio de una lista de numeros
//Calcular el promedio.
#include<stdio.h>
#include <math.h>

int const N = 5;
int sumar_array(int numeros[]);
double sumar(double a, double b);
double potenciar(int numeros[N],int e);


void main()
{
    //Cargar array
    int elem = 0;  //Variable local
    int array[N];
    int i = 0;
    
    for(i = 0 ; i < N; i++)
    {
        printf("Ingrese elemento\n");
        scanf("%d", &elem); //Esta funcion pide la REFERENCIA del elem.
        array[i] = elem;  //Le cargo el VALOR de la variable elem
    }

        
    // int suma = sumar(array);  //LLamo a funcion sumar()
    // float promedio = 0;
    // printf("La suma de los elementos del array es: %d\n",suma);
    // promedio = (float)suma/N;
    // printf("El promedio de los elementos del array es: %.2f\n",promedio);

    // int e = 2;
    // double potencia = potenciar(array,e);
    // printf("La suma de potencias de grado %d de los elementos del array es: %.2f\n",e,potencia);

    
}

// double potenciar(int numeros[N],int e)
// {
//     double p = 0;

//     int i = 0;
  
//     while(i < N)
//     {
//         p = p + pow((double)numeros[i],(double)2); 
        
//         i++;
//     }

//     return p;
// }

double sumar(double a, double b)
{
    return a + b;

}

int sumar_array(int numeros[N]) 
{
    int i = 0;
    int suma = 0;

    while(i < N)
    {
        //suma = suma + numeros[i];
        //Uso la funcion sumar
        suma = sumar(suma,numeros[i]);
        i++;
    }
    
    return suma;

}

