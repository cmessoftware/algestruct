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

TPedido desapilarPedido(TPedido **pa)
{
    TPedido* aux;
    TPedido datos;

	datos=**pa;

	aux=*pa;

	*pa=(*pa)->sig;
	free(aux);

    datos.sig = NULL;

    return datos; 
}

float GetMonto(int servicio)
{}


void addOrdenes(TPedido* p, float monto)
{}

void mostrar(TPedido* p)
{
    if(p == NULL)
    {
        puts("Pila vacia\n");
        return;
    }

    if(p->sig == NULL)  //Hay un solo elemento.
    {
        printf("Servicio: %d\n",p->servicio);
        printf("Cod Cliente: %d\n",p->codCliente);
        printf("Cantidad: %d\n",p->cantidad);
        puts("------------------------------------");
    }


    for(;p->sig!= NULL; p = p->sig)
    {
        printf("Servicio: %d\n",p->servicio);
        printf("Cod Cliente: %d\n",p->codCliente);
        printf("Cantidad: %d\n",p->cantidad);
        puts("------------------------------------");
    }
}

int getLength(TPedido* p)
{
    int cant = 0;

    while(p->sig != NULL)
        cant++;

    return cant;
    
}

void main()
{
    TPedido *PPedido = NULL;
    TPedido *PActual = NULL;    
    int cantidad = 0;
    int codCliente = 0;
    int servicio = 0;

    for(int i=0 ; i < 5; i++)
    {
        cantidad = 10+i;
        codCliente = 123+i;
        servicio = 1000+i;
        apilarPedido(&PActual,codCliente , servicio, cantidad);
    }

//    for(int x = 1 ; x <= getLength(PActual);x++)
   for(int x = 1 ; x <= 5;x++)
   {
        puts("PILA ORIGNAL\n");
        mostrar(PActual);
        puts("------------------------------------");

        TPedido Pdesapilado = desapilarPedido(&PActual);

        printf("PILA %d DESAPILADOS\n",x);
        mostrar(PActual);
        puts("------------------------------------");
        puts("NODO DESAPILADO\n");
        mostrar(&Pdesapilado);
        puts("------------------------------------");
   }
    
    // for(int i=0 ; i < 10; i++)
    // {
    //    TPedido* Pdesapilado = desapilarPedido(&PActual);
       
    //    float monto = GetMonto(Pdesapilado->servicio);

    //    addOrdenes(&Pdesapilado, monto);

    // }

}

