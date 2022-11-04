#include <stdio.h>

typedef struct Pedido
	
    int codigoReceta;
    int cantidad;
    char domicilio[50];
    char telefono[20];

	struct Pedido *sig;
}Pedido;

typedef struct Receta
{
    int codRec;
    int cantReg;
    int numReg;

}Receta;


typedef struct NombreReceta
{
  int codRec; 
  char nombre[15];
  int paridad;

}NombreReceta;

typedef struct Ingrediente
{
    char nombre[15];
    int stock;
    int costo;

}Ingrediente;


void addPedido(Pedido **P,int codigoReceta,int cantidad,char* domicilio,char *telefono)
{
	Pedido *nuevoPedido = malloc(sizeof(struct Pedido));
    nuevoPedido->codigoReceta = codigoReceta;
    nuevoPedido->cantidad = cantidad;
  	strcpy(nuevoPedido->domicilio, domicilio);
	strcpy(nuevoPedido->telefono, telefono);

	nuevoPedido->sig = NULL;
	if ((*P) == NULL)
	{
		*P = nuevoPedido;
   }
	else
	{
        nuevoPedido->sig = P;
        *P = nuevoPedido;    
		//addPedido(&(*pedido)->sig, nombre);
	}
}

void imprimir(struct Pedido *pedido)
{
	while (pedido != NULL)
	{
		printf("Encontramos un nombre en la lista: '%s'\n", pedido->nombre);
		pedido = pedido->sig;
	}
}

void cargarPedidos(Pedido **p)
{
    int codigoReceta;
    int cantidad;
    char domicilio[50];
    char telefono[20];

    codigoReceta = 1;
    cantidad = 12;
    domicilio = "Calle X 123";
    telefono = "555-122132"

    addPedido(&p,codigoReceta,cantidad,domicilio,telefono)

        codigoReceta = 1;
    cantidad = 12;
    domicilio = "Calle X 123";
    telefono = "555-122132"

    addPedido(&p,codigoReceta,cantidad,domicilio,telefono)


    codigoReceta = 1;
    cantidad = 12;
    domicilio = "Calle X 123";
    telefono = "555-122132"

    addPedido(&p,codigoReceta,cantidad,domicilio,telefono)


    codigoReceta = 1;
    cantidad = 12;
    domicilio = "Calle X 123";
    telefono = "555-122132"

    addPedido(&p,codigoReceta,cantidad,domicilio,telefono)


    codigoReceta = 1;
    cantidad = 12;
    domicilio = "Calle X 123";
    telefono = "555-122132"

    addPedido(&p,codigoReceta,cantidad,domicilio,telefono)

    
}

void main()
{
// 1. La cola de pedidos puede contener códigos de recetas inexistentes, con los cuales se debe armar una pila que
// contenga el código de receta y el número de teléfono.

    Pedido * P = NULL;

    cargarPedidos(&P)

    Pedido *PE = clonarPedido(P);

    cargarPedidoInexistentes(&PE);

    int nuevoStock = actualizarStock(PE);

// Generar un archivo que contenga: Nombre de la receta (completo), cantidad solicitada, importe unitario (por
// cada receta) y el importe total de ese pedido
   generarArchivoRecetas(P);

// Imprimir un listado con todos los pedidos de recetas inexistentes o que no se pueden atender en forma
// completa, para llamar a esas personas y avisarles. En caso de no haber pedidos inexistentes o que no se pueden
// atender en forma completa, informarlo.

    imprimir(PE);

// Imprimir un listado para entregarle al repartidor con los datos de cada pedido y lo que debe cobrar. En caso de
// no haber ningún pedido a ser entregado informarlo

    imprimirReparto(P);

// Confeccionar una función que recibiendo los parámetros adecuados retorna el nombre completo de la
// receta. Utilizar aritmética de punteros
    generarNombreReceta(P);

}