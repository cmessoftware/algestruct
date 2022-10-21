#include <stdio.h>

void cargar (int *vec, int tam)
{ 
    vec[0] = 6;
    vec[1] = 2;
    vec[2] = 9;
    vec[3] = 4;
    vec[4] = 1;
    // //for (int i=0; i<tam; i++){ 
    //     printf ("Ingrese un valor de\n", i);
    //     scanf ("%d", &vec[i]);
    // }
}
    

int sumar (int *vec, int tam)
{
    int acum=0;

    for (int i=0; i<tam; i++){
        acum=acum + vec[i];
    }
    return acum;
}

float promedio (int suma, int tam)
{
    float prom=0;
    prom= (float)suma/(float)tam;

    return prom;

}



int main (){
    int tam=5;
    int vector[tam];
    cargar (vector, tam);
    int suma=sumar (vector, tam);
    float prom = promedio(suma, tam);
    printf ("El promedio es %.2f", prom);
}