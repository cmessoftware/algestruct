#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
 
struct node{
       int nro;        // en este caso es un numero entero
       struct node *next;
};
 
typedef struct node Tlist;


void showList(Tlist *L)
{
    for( ; L !=NULL; L = L->next)
        printf("Elemento: %d \n",L->nro);
}

void showListRec(Tlist *L)
{
    if(L == NULL) return;
    printf("Elemento: %d \n",L->nro);
    return showListRec(L->next);
}

void add(Tlist **list, int value)
{
    Tlist* q;
    q = (Tlist*)malloc(sizeof(Tlist));
    q->nro = value;
    q->next = *list;
    *list  = q;
}

/// @brief Insercion ordenada de menor a mayor por nro. Suponemos todos diferentes.
/// @param list 
/// @param value 
void insert_by_value(Tlist *list, int value)
{
    Tlist q;
    Tlist lst = *list;

    q = (Tlist*)malloc(sizeof(Tlist));
    q->nro = value;

    //Es lista vacia --> agrego porque es el primero.
    if(lst == NULL)
    {
        add(list,value);
        return;
    }

    //for( ; list->next != NULL; list = list->next)
    //Recorro la lista
    Tlist prev = lst;
  
    while(lst->next != NULL)
    {
        if(prev == lst && lst->nro > value)  //Este nuevo valor se debe agregar al ppio.
        {
          add(&lst,value);
          *list = lst;
          return;            
        } 
        else if(lst->nro > value) //Mayor que alguno nodo, menos el ultimo.
        {
            prev->next = q;
            q->next = lst;   
            return;
        }

        prev = lst;
        lst = lst->next;
    }
    
    //Verificar si values sera el ultimo nodo o el anteultimo.
    if(lst->nro > value)  //Es el anteultimo
    {
        prev->next = q;
        lst->next = NULL;
        q->next = lst;
        return;
    }
    else //Es el ultimo.
    {
        q->next = NULL;
        lst->next = q;
        return;
    }

    return;
}

void main()
{
    Tlist *L = NULL;
    int value = 10;



    for(int i =0 ; i < 5;i++)
        add(&L,value+i);

    showListRec(L);
 
    // puts("----------------------------");
 
    // Tlist *L2 = NULL;

    // for( ; L !=NULL; L = L->next)
    //     add(&L2,L->nro);
       
    //showList(L2);

}


