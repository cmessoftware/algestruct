//1. Se lee una secuencia de números que se almacena en una lista encadenada. 
//Además se lee otro número por teclado. 
//Se desea:
//a. Determinar cuántas veces aparece ese número en la lista.
//b. Eliminarlo si aparece una sola vez, si no existe imprimir un mensaje indicando este hecho.

#include <stdio.h>
#include <stdlib.h>

//se crea la estructura de la lista de números donde después se le va a enganchar el vector

typedef struct etiquetavecnum
{
    int numero;
    struct etiquetavecnum *sig;
}Numero;


//cargar de la lista simple con el vector
void armarlista(Numero **punterolist, int numero);

//procedimiento para buscar si el número ingreado por teclado es igual al ingresado previamente por mi en el vector
int buscar(Numero *punterolista, int numero);

//procedimiento para eliminar el elemento que se encontró una vez
void eliminar(Numero **punterolista, int numero);

void mostrar(Numero *p);
//programa principal
int main()
{
    //declaro la cabeza de la lista
    Numero *punterolista;

    //declaro los valores que va a tener mi vector

    int n;
    int numero;
    punterolista = NULL;

    printf("Ingrese un número: \n");
    scanf("%d", &numero);

   do
   {
        puts("Ingrese un numero: ");
        scanf("%d", &n);
        if(n < 0 ) break;
        armarlista(&punterolista,n);
   }while( n >= 0); //Termina cuando n es negativo

    mostrar(punterolista);
    puts("=======================================================");
    //determino cuantas veces aparece el valor buscado
    int contador = buscar(punterolista, numero); 

    if(contador == 0)
    {
        puts("El número no existe en la lista\n");
        return 0;
    }

    if(contador > 1)
    {
        printf("El número aparece %d veces\n", contador);
    }
    else
    {
        //el número solo aparece una vez por lo cual procedo a eliminarlo
        eliminar(&punterolista, numero);
    }

    mostrar(punterolista);

    return 0;
}

void mostrar(Numero *p)
{

    while(p != NULL)
    {
        printf("> %d\n",p->numero);
        p = p->sig;
    }
}

//se empieza a cargar la lista con los valores asignados
void armarlista(Numero **punterolista, int num)
{
    //declaro variables locales
    Numero *nuevo;

    //reservo el espacio para el tipo de lista simple
    nuevo = (Numero*)malloc(sizeof(Numero));
    nuevo->numero = num;
    //le asigno a siguiente NULL
    nuevo->sig = NULL;

    //en el caso de que la cabeza no sea NULL tengo que recorrer la lista hasta el final
    if(*punterolista == NULL)
    {
        *punterolista = nuevo;
    }
    else
    {
        //no es el primero lo inserto al inicio
        nuevo->sig = *punterolista;
        *punterolista = nuevo;
    }
}

int buscar(Numero *punterolista, int numero)
{
    int cont = 0;

    while(punterolista != NULL)
    {
        if(numero == punterolista->numero)
        {
            cont++;
        }
        punterolista = punterolista->sig;
    }

    return cont;

}

void eliminar(Numero **punterolista,int numero)
{
    Numero *actual;
    Numero *anterior;
    Numero *aux;

    actual = *punterolista;
    anterior = NULL;

    // while(actual->sig != NULL && numero != actual->numero)
    // {
    //     actual = actual->sig;
    // }
  
    while(actual != NULL)
    {
       
        if(actual->numero == numero)
        {
            if(anterior == NULL)  //Es el primero.
                anterior = actual;
           
            actual = actual->sig; 
            aux = anterior->sig;
            anterior->sig = actual;
            free(aux);
            return;
        }

        anterior = actual;
        actual = actual->sig;

    }

    if(actual == NULL)
    {
        printf("El numero %d no existe en la lista.",numero);
        return;
    }
}

