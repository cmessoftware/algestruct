#include <stdio.h>

typedef struct Empresa
{
    int servicio;
    float precio;
    struct Empresa *sig;
}TEmpresa;

typedef struct Pedido
{
    int codCliente;
    int servicio;
    int cantidad;
    struct Pedido *sig;
}TPedido;

typedef struct Orden
{
    int codCliente;
    int servicio;
    int cantidad;
    float monto;
}TOrden;

 void apilarPedido(TPedido **pa, int codCliente ,int servicio, int cantidad)
 {
        TPedido *q;   //Nuevo nodo
        q = (TPedido*)malloc(sizeof(TPedido));
        q->cantidad = cantidad;
        q->codCliente = codCliente;
        q->servicio = servicio;

        if(*pa == NULL)  //Pila vacia
        {
           *pa = q; /*porque hay uno solo*/
        }
        else
        {
           q->sig = (*pa);
           (*pa) = q;
        }
     
}

TPedido* desapilarPedido(TPedido **pa)
{
        TPedido *aux;   
        
        if(*pa == NULL)  //Pila vacia
        {
           return NULL;
        }
        else
        {
           
        //    while((*pa)->sig != NULL)
        //    {
        //         prev = (*pa);
        //         (*pa) = (*pa)->sig;
        //    }
           
        //    prev->sig = NULL; //Prev es el nuevo Ultimo.

           aux = *pa;
           (*pa)->sig = NULL; 
           return aux;
        }

}

float GetMonto(int servicio)
{}


void addOrdenes(TPedido* p, float monto)
{}

void mostrar(TPedido* p)
{
    for(;p->sig!= NULL; p = p->sig)
    {
        printf("Servicio: %d\n",p->servicio);
        printf("Cod Cliente: %d\n",p->codCliente);
        printf("Cantidad: %d\n",p->cantidad);
        puts("------------------------------------");
    }
}

void main()
{
    TPedido *PPedido = NULL;
    TPedido *PActual = NULL;    
    int cantidad = 0;
    int codCliente = 0;
    int servicio = 0;

    for(int i=0 ; i < 10; i++)
    {
        cantidad = 10+i;
        codCliente = 123+i;
        servicio = 1000+i;
        apilarPedido(&PActual,codCliente , servicio, cantidad);
    }

    char op;

    // while(op != 'S')
    // {
    //     printf("Ya son las 15?\n (S/N)");
    //     scanf("%c",&op);
    // }

    mostrar(PActual);
    puts("------------------------------------");

    TPedido* Pdesapilado = desapilarPedido(&PActual);

    mostrar(PActual);
    puts("------------------------------------");
    mostrar(Pdesapilado);
    puts("------------------------------------");
       
    
    // for(int i=0 ; i < 10; i++)
    // {
    //    TPedido* Pdesapilado = desapilarPedido(&PActual);
       
    //    float monto = GetMonto(Pdesapilado->servicio);

    //    addOrdenes(&Pdesapilado, monto);

    // }

}

