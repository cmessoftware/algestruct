//Dado una lista de N numeros sacar 
//a. El promedio. 
//b.La suma 
//c.La resta 
//d. La mediana 
//e.La frecuencia de ocurrencia de todos los números.

#include<stdio.h>
#include <math.h>

double frecuencia(int numeros[]);
int numeros[10] = {1,2,3,1,4,2,3,1,1,3};

int main(void)
{
    //frecuencia(numeros[0]); 
    frecuencia(numeros); //Envias la direccion de memoria del primero elemento del array.
}

double frecuencia(int num[])
{
    double cont1,cont2,cont3,cont4;

    for(int n=0;n < 10;n++)
    {

        switch (num[n])
        {
        case 1: 
            cont1++;
            break;
        case 2: 
            cont2++;
            break;
        case 3: 
            cont3++;
            break;
        case 4: 
            cont4++;
            break;
       default:
            break;
        }
        // if(num[n] == 1) cont1++;    
        // if(num[n] == 1) cont1++;
        // if(num[n] == 1) cont1++;
        // if(num[n] == 1) cont1++;

    }


        printf("f1: %.2f\n",cont1);
        printf("f2: %.2f\n",cont2);
        printf("f3: %.2f\n",cont3);
        printf("f4: %.2f\n",cont4);


}