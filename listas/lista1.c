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
       struct node *next;
};
 
typedef struct node *Tlist;
 
 
void add(Tlist *list, int value)
{
    Tlist q;
    q = malloc(sizeof(Tlist));
    q->nro = value;
    q->next = *list;
    *list  = q;
}
 
void add_end(Tlist list, int value)
{
    Tlist t, q = malloc(sizeof(Tlist));
 
    q->nro  = value;
    q->next = NULL;
 
    if(list==NULL)
    {
        list = q;
    }
    else
    {
        t = list;
        while(t->next!=NULL)
        {
            t = t->next;
        }
        t->next = q;
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
        else if(lst->nro > value)
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


/// @brief Si laposicion existe devulve pos sino -1
/// @param list 
/// @param pos 
/// @param value 
/// @return 
int insert_by_pos(Tlist list, int pos, int value)
{
    Tlist q, t;
    int i;
    q = malloc(sizeof(Tlist));
    q->nro = value;
 
    if(pos==1)
    {
        q->next = list;
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
                q->next = t->next;
                t->next = q;
                return pos;
            }
            t = t->next;
        }
    }
    return -1;
}
 
/// @brief Si lo encuentra devulve la posiscion sino -1.
/// @param list 
/// @param value 
/// @return 
int search(Tlist list, int value)
{
    Tlist q = list;
    int i = 1, band = 0;
    int pos = -1;
 
    while(q!=NULL)
    {
        if(q->nro==value)
        {
            pos = i;
            band = 1;
        }
        q = q->next;
        i++;
    }
 
    if(band==0)
        return  pos;
}
 
void show_list(Tlist list)
{
     int i = 0;
 
     while(list != NULL)
     {
          printf("%d : %d\n", i+1 , list->nro);
          list = list->next;
          i++;
     }
}
 
/// @brief si no encuentra el nodo a borrar devuelve -1 sino 0.
/// @param list 
/// @param value 
/// @return 
int deleteElement(Tlist list, int value)
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
                    list = list->next;
                else
                    ant->next = p->next;
 
                //delete(p,value);
                return 0;
            }
            ant = p;
            p = p->next;
        }
    }
    else
        return -1;
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
                list = list->next;
                //delete(q,value);
                q = list;
            }
            else
            {
                ant->next = q->next;
                //delete(q,value);
                q = ant->next;
            }
        }
        else
        {
            ant = q;
            q = q->next;
        }
 
    }// fin del while
}
 
void menu1()
{
    printf("\n\t\tlist ENLAZADA SIMPLE\n\n");
    printf(" 1. INSERTAR AL INICIO               \n");
    printf(" 2. INSERTAR AL FINAL                \n");
    printf(" 3. INSERTAR EN UNA POSICION         \n");
    printf(" 4. REPORTAR list                    \n");
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
    int LIST_SIZE = 20;
    int data = 1000;  // elemenento a ingresar
    int i=0;

    int nros[20] = {-1,-5,1,9,2,6,32,100,-23,-100,44,22,-34,5,0,56,43,-90,88,3};

    srand(time(NULL));
    while(i < LIST_SIZE)
    {
        //add(&L,rand()%data);
        add(&L,nros[i]);
        i++;
    }

    printf("Lista desordenada\n");
    show_list(L);
    puts("--------------");
    printf("Ordeno la lista\n");
    puts("--------------");
    
    Tlist listAux = NULL;
    while(L != NULL)
    {
        insert_by_value(&listAux,L->nro);
        //Muestro la lista mientras se va creando.
        //show_list(L);
        L = L->next;
    }
    printf("Lista ordenada\n");
    show_list(listAux);
    puts("--------------");

    deleteElement(listAux,44);
    
    printf("Verifico si borro adecuadamente.\n");
    show_list(listAux);

    return 0;
}
