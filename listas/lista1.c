#include<stdio.h>
#include <stdlib.h>
#include <time.h>


/*
* C++ - lists Enlazadas simples en c++
* Copyright 2014 Martin Cruz Otiniano 
*
* Description: Inserta, elimina, busca, reporta
* Site: martincruz.me
*/
#include <stdio.h>
 
struct node{
       int nro;        // en este caso es un numero entero
       struct node *sgte;
};
 
typedef struct node *Tlist;
 
 
void add(Tlist *list, int value)
{
    Tlist q;
    q = malloc(sizeof(Tlist));
    q->nro = value;
    q->sgte = *list;
    *list  = q;
}
 
void add_end(Tlist list, int value)
{
    Tlist t, q = malloc(sizeof(Tlist));
 
    q->nro  = value;
    q->sgte = NULL;
 
    if(list==NULL)
    {
        list = q;
    }
    else
    {
        t = list;
        while(t->sgte!=NULL)
        {
            t = t->sgte;
        }
        t->sgte = q;
    }
 
}
 
int inserBeforeAfter()
{
    int op, band;
    printf("\n");
    printf("\t 1. Antes de la posicion           \n");
    printf("\t 2. Despues de la posicion         \n");
 
    printf("\n\t Opcion : "); 
    scanf("%d",&op);
 
     if(op==1)
        band = -1;
    else
        band = 0;
 
    return band;
}
 
/// @brief Insercion ordenada de menor a mayor por nro. Suponemos todos diferentes.
/// @param list 
/// @param value 
void insert_by_value(Tlist *list, int value)
{
    Tlist q;
    Tlist lst = *list;

    q = malloc(sizeof(Tlist));
    q->nro = value;

    //Es lista vacia --> agrego porque es el primero.
    if(lst == NULL)
    {
        add(list,value);
        return;
    }

    //for( ; list->sgte != NULL; list = list->sgte)
    //Recorro la lista
    Tlist current;
  
    while(lst->sgte != NULL)
    {
        if(lst->nro > value)
        {
            current->sgte = q;
            q->sgte = list;    
            return;
        }

        current = list; 
        lst = lst->sgte;
    }

    //Si llego hasta aca el nodo a insertar va AL FINAL de la lista.
    q->sgte = NULL;
    lst->sgte = q;

    return;

}



void insert_by_pos(Tlist list, int pos, int value)
{
    Tlist q, t;
    int i;
    q = malloc(sizeof(Tlist));
    q->nro = value;
 
    if(pos==1)
    {
        q->sgte = list;
        list = q;
    }
    else
    {
        int x = inserBeforeAfter();
        t = list;
 
        for(i=1; t!=NULL; i++)
        {
            if(i==pos+x)
            {
                q->sgte = t->sgte;
                t->sgte = q;
                return;
            }
            t = t->sgte;
        }
    }
    printf("   Error...Posicion no encontrada..!\n");
}
 
void search(Tlist list, int value)
{
    Tlist q = list;
    int i = 1, band = 0;
 
    while(q!=NULL)
    {
        if(q->nro==value)
        {
            printf("\n Encontrada en posicion %d \n",i);
            band = 1;
        }
        q = q->sgte;
        i++;
    }
 
    if(band==0)
        printf("\n\n Numero no encontrado..!\n");
}
 
void show_list(Tlist list)
{
     int i = 0;
 
     while(list != NULL)
     {
          printf("' '%d : %d\n", i+1 , list->nro);
          list = list->sgte;
          i++;
     }
}
 
 
void delete(Tlist list, int value)
{
    Tlist p, ant;
    p = list;
 
    if(list!=NULL)
    {
        while(p!=NULL)
        {
            if(p->nro==value)
            {
                if(p==list)
                    list = list->sgte;
                else
                    ant->sgte = p->sgte;
 
                delete(p,value);
                return;
            }
            ant = p;
            p = p->sgte;
        }
    }
    else
        printf("List empty!!");
}
 
void deleteDuplicate(Tlist list, int value)
{
    Tlist q, ant;
    q = list;
    ant = list;
 
    while(q!=NULL)
    {
        if(q->nro==value)
        {
            if(q==list) // primero elemento
            {
                list = list->sgte;
                delete(q,value);
                q = list;
            }
            else
            {
                ant->sgte = q->sgte;
                delete(q,value);
                q = ant->sgte;
            }
        }
        else
        {
            ant = q;
            q = q->sgte;
        }
 
    }// fin del while
   
    printf("\n\n valuees eliminados..!\n");
}
 
void menu1()
{
    printf("\n\t\tlist ENLAZADA SIMPLE\n\n");
    printf(" 1. INSERTAR AL INICIO               \n");
    printf(" 2. INSERTAR AL FINAL                \n");
    printf(" 3. INSERTAR EN UNA POSICION         \n");
    printf(" 4. REPORTAR list                   \n");
    printf(" 5. BUSCAR ELEMENTO                  \n");
    printf(" 6. ELIMINAR ELEMENTO 'V'            \n");
    printf(" 7. ELIMINAR ELEMENTOS CON value 'V' \n");
    printf(" 8. SALIR                            \n");
 
    printf("\n INGRESE OPCION: ");
}
 
 
/*                        Funcion Principal
---------------------------------------------------------------------*/
 
int main()
{
    Tlist L = NULL;
    int op;     // opcion del menu
    int data = 10;  // elemenento a ingresar
    int i=0;

    int nros[5] = {-1,5,1,9,2};

    while(i < 5)
    {
        insert_by_value(&L,nros[i]);
        i++;
    }

    // srand(time(NULL));
    // while(i-- > 0)
    //     add(&L,rand()%dato);
 
    show_list(L);

    return 0;
}
