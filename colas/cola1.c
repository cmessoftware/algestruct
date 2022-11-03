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
    int codeRec;
    int cantReg;
    int numReg;

}Receta;


typedef struct NombreReceta
{
  char nombre[15];
  int paridad;

}NombreReceta;

typedef struct Ingrediente
{
    char nombre[15];
    int stock;
    int costo;

}Ingrediente;


void add(struct Pedido **pedido, char *nombre)
{
	Pedido *nuevoPedido = malloc(sizeof(struct Pedido));
	strcpy(nuevoPedido->nombre, nombre);
	nuevoPedido->sig = NULL;
	if ((*pedido) == NULL)
	{
		*pedido = nuevoPedido;
	}
	else
	{
		add(&(*pedido)->sig, nombre);
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



void main()
{
// 1. La cola de pedidos puede contener códigos de recetas inexistentes, con los cuales se debe armar una pila que
// contenga el código de receta y el número de teléfono.

    Pedido * P = NULL;

    cargarPedidos(&P)

    Pedido *PE = clonarPedido(P);

    cargarPedidoInexistentes(&PE);

    int nuevoStock = actualizarStock(PE);


}