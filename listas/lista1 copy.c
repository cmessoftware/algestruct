#include<stdio.h>


/*
* C++ - Listas Enlazadas simples en c++
* Copyright 2014 Martin Cruz Otiniano 
*
* Description: Inserta, elimina, busca, reporta
* Site: martincruz.me
*/
#include <stdio.h>
 
struct nodo{
       int nro;        // en este caso es un numero entero
       struct nodo *sgte;
};
 
typedef struct nodo *Tlista;
 
void insertarInicio(Tlista &lista, int valor)
{
    Tlista q;
    q = new(struct nodo);
    q->nro = valor;
    q->sgte = lista;
    lista  = q;
}
 
void insertarFinal(Tlista &lista, int valor)
{
    Tlista t, q = new(struct nodo);
 
    q->nro  = valor;
    q->sgte = NULL;
 
    if(lista==NULL)
    {
        lista = q;
    }
    else
    {
        t = lista;
        while(t->sgte!=NULL)
        {
            t = t->sgte;
        }
        t->sgte = q;
    }
 
}
 
int insertarAntesDespues()
{
    int _op, band;
    printf("\n");
    printf("\t 1. Antes de la posicion           \n");
    printf("\t 2. Despues de la posicion         \n");
 
    printf("\n\t Opcion : "); 
    scanf("%d") &_op);
 
    if(_op==1)
        band = -1;
    else
        band = 0;
 
    return band;
}
 
void insertarElemento(Tlista &lista, int valor, int pos)
{
    Tlista q, t;
    int i;
    q = new(struct nodo);
    q->nro = valor;
 
    if(pos==1)
    {
        q->sgte = lista;
        lista = q;
    }
    else
    {
        int x = insertarAntesDespues();
        t = lista;
 
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
    cout<<"   Error...Posicion no encontrada..!\n");l;
}
 
void buscarElemento(Tlista lista, int valor)
{
    Tlista q = lista;
    int i = 1, band = 0;
 
    while(q!=NULL)
    {
        if(q->nro==valor)
        {
            printf("\n Encontrada en posicion %d \n",i);
            band = 1;
        }
        q = q->sgte;
        i++;
    }
 
    if(band==0)
        cout<<"\n\n Numero no encontrado..!"<< endl;
}
 
void reportarLista(Tlista lista)
{
     int i = 0;
 
     while(lista != NULL)
     {
          cout <<' '<< i+1 <<") " << lista->nro << endl;
          lista = lista->sgte;
          i++;
     }
}
 
 
void eliminarElemento(Tlista &lista, int valor)
{
    Tlista p, ant;
    p = lista;
 
    if(lista!=NULL)
    {
        while(p!=NULL)
        {
            if(p->nro==valor)
            {
                if(p==lista)
                    lista = lista->sgte;
                else
                    ant->sgte = p->sgte;
 
                delete(p);
                return;
            }
            ant = p;
            p = p->sgte;
        }
    }
    else
        cout<<" Lista vacia..!";
}
 
void eliminaRepetidos(Tlista &lista, int valor)
{
    Tlista q, ant;
    q = lista;
    ant = lista;
 
    while(q!=NULL)
    {
        if(q->nro==valor)
        {
            if(q==lista) // primero elemento
            {
                lista = lista->sgte;
                delete(q);
                q = lista;
            }
            else
            {
                ant->sgte = q->sgte;
                delete(q);
                q = ant->sgte;
            }
        }
        else
        {
            ant = q;
            q = q->sgte;
        }
 
    }// fin del while
   
    printf("\n\n Valores eliminados..!\n");
}
 
void menu1()
{
    printf("\n\t\tLISTA ENLAZADA SIMPLE\n\n
    printf(" 1. INSERTAR AL INICIO               \n");
    printf(" 2. INSERTAR AL FINAL                \n");
    printf(" 3. INSERTAR EN UNA POSICION         \n");
    printf(" 4. REPORTAR LISTA                   \n");
    printf(" 5. BUSCAR ELEMENTO                  \n");
    printf(" 6. ELIMINAR ELEMENTO 'V'            \n");
    printf(" 7. ELIMINAR ELEMENTOS CON VALOR 'V' \n");
    printf(" 8. SALIR                            \n");
 
    cout<<"\n INGRESE OPCION: ";
}
 
 
/*                        Funcion Principal
---------------------------------------------------------------------*/
 
int main()
{
    Tlista lista = NULL;
    int op;     // opcion del menu
    int _dato;  // elemenento a ingresar
    int pos;    // posicion a insertar
 
 
    system("color 0b");
 
    do
    {
        menu1();  cin>> op;
 
        switch(op)
        {
            case 1:
 
                 cout<< "\n NUMERO A INSERTAR: "; cin>> _dato;
                 insertarInicio(lista, _dato);
            break;
 
 
            case 2:
 
                 cout<< "\n NUMERO A INSERTAR: "; cin>> _dato;
                 insertarFinal(lista, _dato );
            break;
 
 
            case 3:
 
                 cout<< "\n NUMERO A INSERTAR: ";cin>> _dato;
                 cout<< " Posicion : ";       cin>> pos;
                 insertarElemento(lista, _dato, pos);
            break;
 
 
            case 4:
 
                 cout << "\n\n MOSTRANDO LISTA\n\n";
                 reportarLista(lista);
            break;
 
 
            case 5:
 
                 cout<<"\n Valor a buscar: "; cin>> _dato;
                 buscarElemento(lista, _dato);
            break;
 
            case 6:
 
                cout<<"\n Valor a eliminar: "; cin>> _dato;
 
                eliminarElemento(lista, _dato);
            break;
 
            case 7:
 
                cout<<"\n Valor repetido a eliminar: "; cin>> _dato;
 
                eliminaRepetidos(lista, _dato);
            break;
 
                    }
 
        cout<<endl<<endl;
        //system("pause");  
        //system("cls");
 
    }while(op!=8);
 
 
   //system("pause");
   return 0;
}
