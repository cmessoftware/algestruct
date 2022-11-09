
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define CANT_HOJAS 10

typedef struct arbol
{
  int dato;
  struct arbol *izq;
  struct arbol *der;
} arbolNodo;

void crear (arbolNodo ** hoja, int *);
void insertar (arbolNodo ** hoja, int elem);
void inorder (arbolNodo * hoja);
void preorder (arbolNodo * hoja);
void postorder (arbolNodo * hoja);
int promedio(arbolNodo *hoja, int );
arbolNodo* crearNodo(arbolNodo **hoja , arbolNodo* der, arbolNodo* izq, int dato);

int
main ()
{
  int cont = 0, raiz, cont1 = 0;
  printf ("arboles\n");
  arbolNodo *arbol = NULL;
  arbolNodo *aux = NULL;
  crear (&arbol, &raiz);
  printf ("**************\n");
  aux = arbol;
  printf ("mostrar arbol INORDER\n");
  inorder(arbol);
  printf ("\n***************\n");
  aux = arbol;
  printf ("mostrar arbol PREORDER\n");
  preorder(arbol);
  printf ("\n***************\n");
  aux = arbol;
  printf ("mostrar arbol POSTORDER\n");
    postorder(arbol);
  arbol = aux;
  printf ("\n***************\n");



  
  return 0;
}

arbolNodo* crearNodo(arbolNodo **hoja , arbolNodo* der, arbolNodo* izq, int dato)
{
      //Creo la hoja vacia
      (*hoja) = (arbolNodo *) malloc (sizeof (arbolNodo));
      (*hoja)->dato = dato;
      (*hoja)->der = der;
      (*hoja)->izq = izq;

      return (*hoja);
}

void crear (arbolNodo ** hoja, int *raiz)
{
  int num;
  int i = 0;
  *raiz = i;
  int elementos[] = {1,10,5,15,8,11,6,18,-5,0};
  while(i < CANT_HOJAS)
  {
     srand(time(NULL));
     insertar (&(*hoja), elementos[i]);
     i++;
  }
 
}


void insertar (arbolNodo ** hoja, int elem)
{
  int num = elem;
  if (elem == -1)
    return;
  if (*hoja == NULL)
  {		//Creo la hoja vacia
    crearNodo(hoja , NULL ,NULL, elem);
  }
  else
  {
      if (num > (*hoja)->dato)
        insertar (&(*hoja)->der, elem);
      else
        insertar (&(*hoja)->izq, elem);
	}

  return;
}



void inorder (arbolNodo * hoja)
{
  if (hoja != NULL)
    {
      inorder (hoja->izq);
      printf ("%d ", hoja->dato);
      inorder (hoja->der);
  }
  
  return;
}


void preorder (arbolNodo * hoja)
{
  if (hoja != NULL)
    {
      printf ("%d ", hoja->dato);
      preorder (hoja->izq);
      preorder (hoja->der);
  }
  
  return;
}

void postorder (arbolNodo * hoja)
{
  if (hoja != NULL)
  {
      postorder (hoja->izq);
      postorder (hoja->der);
      printf ("%d ", hoja->dato);
  }
  
  return;
}



