#include<stdio.h>

/// @brief Devuelve cantidad de numeros encontrados.
/// @param vector 
/// @param tam 
/// @param num 
/// @return 
int buscar_numero(int vector[], int tam, int num)
{
    int cant = 0;

    for(int i = 0 ; i < tam; i++)
    {
        if(vector[i] == num)
        {
            cant++;
        }
    }

    return cant;
}

/// @brief Te devuelve las posiciones dentro del vector de los numeros encontrados.
/// @param vector 
/// @param tam 
/// @param num 
/// @return 
int buscar_numero_pos(int vector[], int posiciones[],int tam, int num)
{
    int cant = 0;
  
    for(int i = 0 ; i < tam; i++)
    {
        if(vector[i] == num)
        {
            posiciones[cant] = i;
            cant++;
        }
    }

    return cant;
}


void mostrar(int vector[], int tam)
{
    int i = 0;
    while(tam > 0)
    {
        printf("%d , ",vector[i]);
        tam--; //tam = tam - 1;
    }

}

void clear_vector(int vector[],int tam)
{
    for(int i = 0 ; i < tam; i++)
        vector[i] = 0;

}

/// @brief  "1,4,10"
/// @param posiciones 
/// @param tam 
/// @param pos 
void armar_lista_posiciones(int posiciones[],int tam, char pos[])
{
    int j = 0;
    

    for(int i = 0 ; posiciones[i] != 0 ; i++)
    {
        pos[j] = posiciones[i];
        pos[j++] = ',';
        j++;
    }

    pos[j++] = '\0';

}


int main(void)
{
    int tam = 12;
    int num = 5;
    int vec[] = {23,45,67,6,45,7,8,9,10,44,45,23};
    int posiciones[tam];
    char pos[2*tam];

    printf("NUMERO\n");
    scanf("%d",&num);
    
    //clear_vector(posiciones, tam);

    int encontrados = buscar_numero_pos(vec,posiciones,tam,num);

    armar_lista_posiciones(posiciones,tam,pos);


    if(encontrados > 0)
        printf("El numero %d fue encontrado %d veces en las posiciones %s\n",num,encontrados,pos);
    else
        printf("El numero %d NO fue encontrado\n",num);


    // int resultado = buscar_numero(vec,tam,num);

    // if(resultado > 0)
    //     printf("El numero %d fue encontrado %d veces\n",num,resultado);
    // else
    //     printf("El numero %d NO fue encontrado\n",num);


    return 0;

}