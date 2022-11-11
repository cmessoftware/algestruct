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

void apilarPedido(TPedido **pa,TPedido **pactual, TPedido pedido); //Hecha
TPedido desapilarPedido(TPedido **pa); //Hecha
TPedido desapilarPedidoRec(TPedido **pa);
float GetMonto(int servicio);
void addOrdenes(TPedido* p, float monto);
void mostrar(TPedido* p); //Hecha
int getLength(TPedido* p);

void main()
{
    TPedido *PPedido = NULL;
    TPedido *pa = NULL;    
    TPedido *pactual = NULL;
    
    for(int i=0 ; i < 100; i++)
    {
        TPedido pedido;
        pedido.cantidad = 10+i;
        pedido.codCliente = 123+i;
        pedido.servicio = 1000+i;
        apilarPedido(&pa,&pactual,pedido);
    }

//    for(int x = 1 ; x <= getLength(PActual);x++)
//    for(int x = 1 ; x <= 5;x++)
//    {
         puts("PILA ORIGNAL\n");
         mostrar(pa);
         puts("------------------------------------");

        //  puts("DESAPILO UN ELEMENTO!!!");
        //  TPedido pUltimo = desapilarPedido(&pa);
        //  mostrar(pa);
        //  puts("------------------------------------");

         puts("DESAPILO TODOS!!!");
         TPedido pUltimo = desapilarPedidoRec(&pa);
         mostrar(pa);
         puts("------------------------------------");

//         printf("PILA %d DESAPILADOS\n",x);
//         mostrar(PActual);
//         puts("------------------------------------");
//         puts("NODO DESAPILADO\n");
//         mostrar(&Pdesapilado);
//         puts("------------------------------------");
//    }
   
}

void apilarPedido(TPedido **pa,TPedido **pactual, TPedido pedido)
 {

        TPedido *nuevo;   //Nuevo nodo
        nuevo = (TPedido*)malloc(sizeof(TPedido));
        nuevo->cantidad = pedido.cantidad;
        nuevo->codCliente = pedido.codCliente;
        nuevo->servicio = pedido.servicio;

        if(*pa == NULL)  //Pila vacia, nuevo es el primero.
        {
           *pa = nuevo; /*porque hay uno solo*/
           *pactual = nuevo;
        }
        else
        {
           (*pactual)->sig = nuevo;
           (*pactual) = nuevo; 
        }
     
}

TPedido desapilarPedidoRec(TPedido **pa)  //Vacia la pila
{
    TPedido dato;

    if(*pa == NULL)
    {
        puts("PILA VACIADA!!");
        return dato;  
    }

    printf("Servicio: %d\n",(*pa)->servicio);
    dato = **pa;
  
    desapilarPedidoRec(&((*pa)->sig));    

    return dato;
}

TPedido desapilarPedido(TPedido **pa)
{
    TPedido *pPrimero = *pa;
    TPedido *pPrev;
    TPedido *pAux;

    
    while((*pa)->sig != NULL)
    {
        pPrev = (*pa);
        (*pa) = (*pa)->sig;
    }
    
    //Ya tengo en *pa el ultimo elemento cargado.
    TPedido dato = **pa;  //Dato tiene el contenido de *pa
    pAux = *pa;
    pPrev->sig = NULL; //Es el nuevo ultimo.

    free(pAux);

    *pa = pPrimero;

    return dato;
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
       
    mostrar(p->sig);
    
    //Post orden para PILAS
    printf("Servicio: %d\n",p->servicio);
    printf("Cod Cliente: %d\n",p->codCliente);
    printf("Cantidad: %d\n",p->cantidad);
    puts("------------------------------------");


    return;
}

int getLength(TPedido* p)
{
    int cant = 0;

    while(p->sig != NULL)
        cant++;

    return cant;
    
}


