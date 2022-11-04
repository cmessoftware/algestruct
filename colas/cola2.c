
#include <stdio.h>
#include<time.h>

typedef struct Nodo
{
    int num;
	struct Nodo *sig;
}TNodo;


void push(TNodo **pc, TNodo **nc, int num)
{
	TNodo *q = malloc(sizeof(TNodo));
    q->num = num;
   
	//q->sig = NULL;
	if ((*pc) == NULL)
	{
		*pc = *nc = q;
    }
	else
	{
          (*nc)->sig = q;
          (*nc) = q;
 	}
}


TNodo pop(TNodo **pc)
{
    TNodo* aux;
    TNodo datos;

	datos=**pc;

	aux=*pc;

	*pc=(*pc)->sig;
	free(aux);

    return datos;
}

void showQueue(TNodo *pc)
{
    for( ; pc->sig != NULL; pc = pc->sig)
        printf(">%d\n",pc->num);

}


void main()
{
    TNodo *pc = NULL;
    TNodo *nc = NULL;
    
    //Cargar la pila
    //srand(time(NULL));

    for(int i = 0; i < 10; i++)
        push(&pc,&nc,i+1);

    showQueue(pc);

    pop(&pc);

    puts("----------------------");

    showQueue(pc);

}