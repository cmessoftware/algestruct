//En una escuela primaria se ha pedido a los alumnos que donen un libro para armar una biblioteca. 
//Se desea:
//a. Incorporar los datos de los Libros a una lista, en forma ordenada. La información 
//correspondiente a cada libro es: título, género, autor, tema, editorial.
//b. Informar la cantidad de fábulas y cuentos infantiles donados.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 10

typedef struct etiquetaLibros
{
    int id;
    char titulo[30];
    char genero[10];
    char autor[30];
    char tema[10];
    char editorial[30];
    struct etiquetaLibros *sig; //¿Acá le tengo que poner el tipo de la estructura o el nombre?
}Libros;

Libros *punterolista;

Libros *listavacia(Libros *punterolista);
void cargardatos(Libros **punterolista);
void insertarordenado(Libros **punterolista);

int main()
{

    Libros L = NULL;

    for(int i=0; i < N; i++)
        cargardatos(&L);
    
}

//¿Como puedo hacer para pasarle toda la estructura libro sin necesidad de escribir cada campo?
void cargardatos(Libros **pl)
{
    char hay, titulo, autor, editorial, genero, tema;
    int id = 0;

    Libros nuevo = (Libros*)malloc(sizeof(Libros)); 

    puts("¿Desea agregar un nuevo libro? s/n\n");
    scanf("%c", hay);

    while(hay == "s")
    {
        puts("Ingrese el titulo del libro\n");
        scanf("%s", nuevo.titulo, "\n");
        puts("Ingrese el autor del libro\n");
        scanf("%s", nuevo.autor, "\n");
        puts("Ingrese la editorial del libro\n");
        sacnf("%s", nuevo.editorial, "\n");
        puts("Ingrese el genero del libro\n");
        scanf("%s", nuevo.genero, "\n");
        puts("Ingrese el tema del libro\n");
        scanf("%s", nuevo.tema, "\n");
               
        insertarordenado(&pl, &nuevo); //Ya la crear ordenada.

        puts("¿Desea agregar mas Libros?\n");
        scanf("%c", hay, "\n");

    }
   
}

Libros *listavacia(Libros *pl)
{
    pl = NULL;
    return pl;
}

void insertarordenado(Libros **pl, Libros *nuevo)
{
    Libros  *anterior, *actual;

    strcpy((*pl)->titulo, nuevo->titulo);
    strcpy((*pl)->autor, nuevo->autor);
    strcpy((*pl)->editorial, nuevo->editorial);
    strcpy((*pl)->genero, nuevo->genero);
    strcpy((*pl)->tema, nuevo->tema);
    (*pl)->id = (*pl)->id + 1;

    //procedo a agregar el libro a la lista
    nuevo = (Libros*)malloc(sizeof(Libros));
    
    if((*pl) == NULL)
    {
        (*pl) = nuevo;  //Es el primer elemento.
    }
    if((*pl)->id < nuevo->id)  //Lo inserto aca  
    {
         nuevo->sig = (*pl);
         (*pl)->sig = NULL;   
    }
    //NO hay otra condicion porque siempre el nuevo id sera el mayor.
    
}