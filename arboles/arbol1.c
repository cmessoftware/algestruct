
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
arbolNodo* crearNodo(int dato);
arbolNodo * crearManual();


int main ()
{
  int cont = 0, raiz, cont1 = 0;
  printf ("arboles\n");
  arbolNodo *arbol = NULL;
  arbolNodo *aux = NULL;
  //crear (&arbol, &raiz);
  arbol = crearManual();
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


arbolNodo* crearNodo(int dato)
{
      arbolNodo* hoja = (arbolNodo *) malloc (sizeof (arbolNodo));
      hoja->dato = dato;
      hoja->der = NULL;
      hoja->izq = NULL;

      return hoja;
}

void crear (arbolNodo ** hoja, int *raiz)
{
  int num;
  int i = 0;
  *raiz = i;
  int elementos[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  while(i < CANT_HOJAS)
  {
     insertar (&(*hoja), elementos[i]);
     i++;
  }
}

arbolNodo * crearManual()
{
    int x = 0;
    arbolNodo *hoja = crearNodo(++x);
    printf("%s: %d\n","raiz",x);
    hoja->izq = crearNodo(++x);
    printf("%s: %d\n","izq",x);
    hoja->der = crearNodo(++x);
    printf("%s: %d\n","der",x);
    hoja->izq->izq = crearNodo(++x);
    printf("%s: %d\n","izq",x);
    hoja->izq->der = crearNodo(++x);
    printf("%s: %d\n","der",x);
    hoja->der->izq = crearNodo(++x);
    printf("%s: %d\n","izq",x);
    hoja->der->der = crearNodo(++x);
    printf("%s: %d\n","der",x);
    hoja->izq->izq->izq = crearNodo(++x);
    printf("%s: %d\n","izq",x);
    hoja->izq->izq->der = crearNodo(++x);
    printf("%s: %d\n","der",x);
    hoja->izq->der->izq = crearNodo(++x);
    printf("%s: %d\n","izq",x);
    hoja->izq->der->der = crearNodo(++x);
    printf("%s: %d\n","der",x);
    hoja->der->izq->izq = crearNodo(++x);
    printf("%s: %d\n","izq",x);
    hoja->der->izq->der = crearNodo(++x);
    printf("%s: %d\n","der",x);
    hoja->der->der->izq = crearNodo(++x);
    printf("%s: %d\n","izq",x);
    hoja->der->der->der = crearNodo(++x);
    printf("%s: %d\n","der",x);
   
    return hoja;

}

void insertar (arbolNodo ** hoja, int elem)
{
  int num = elem;
  if (elem == -1)
    return;
  if (*hoja == NULL)
  {		//Creo la hoja vacia
    hoja = crearNodo(elem);
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



