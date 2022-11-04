#include <stdio.h>
#include <string.h>

#define NPIEZAS 3
#define NPEDIDOS 3
#define NCLIENTE 2
#define NNUEVA 3 

struct piezas{
       int idpieza;
       int cant;
       float precosto;
};

struct pedidos{
       int idcliente;
       int idpieza;
       int cant;
};

struct clientes{
       int idcliente;
       char nom[30];
       char direc[30];
       char correo[20];
       char tel[12];
};

struct nueva
{
       int idcliente;
       char nom[30];
       char tel[12];
       int cant;
       float precosto;
       int idpieza;
};

struct piezas pi[NPIEZAS];
struct pedidos pe[NPEDIDOS];
struct pedidos pea[NPEDIDOS];
struct clientes c[NCLIENTE];
struct nueva n[NNUEVA];

int i, j, k, l, m, cantpi, cantpe, cantt, totped, cantc, hay;
float acucos;


int main()
{
     hay=1;
     cantpi=0;
    
     //carga de piezas
     while (hay==1 && cantpi<NPIEZAS){
         
         printf("Ingrese el id de la pieza:\n");
         scanf("%d", &(pi[cantpi].idpieza));
         printf("Ingrese la cantidad de piezas:\n");
         scanf("%d", &(pi[cantpi].cant));
         printf("Ingrese el precio de costo:\n");
         scanf("%f", &(pi[cantpi].precosto));
    
         printf("¿Hay más piezas? S:1/N:0:\n");
         scanf("%d", &hay);
    
         cantpi++;
    
        }
  
   
     hay=1;
     cantpe=0;
     //carga de pedidos
     while (hay==1 && cantpe<NPEDIDOS){
         printf("Ingrese el id del cliente:\n");
         scanf("%d", &(pe[cantpe].idcliente));
         printf("Ingrese el id de la pieza:\n");
         scanf("%d", &(pe[cantpe].idpieza));
         printf("Ingrese la cantidad a enviar:\n");
         scanf("%d", &(pe[cantpe].cant));
         
         printf("¿Hay más pedidos? S:1/N:0:\n");
         scanf("%d", &hay);

         cantpe++;
        }
        
        //actualización de stock y buscar total de pedidos al 100%
        for (int i=0; i < cantpe; i++)
        {
            for(int j = 0 ; j< cantpi; j++ )
            {
              if ( pe[i].idpieza==pi[j].idpieza && 
                   pe[i].cant <= pi[j].cant)
               {
                   pi[j].cant = pi[j].cant - pe[i].cant;
                   totped++;
               }
            }   
        }
        
        int cant_pedidos = 0;
        //actualización de pedidos al 100%
        for (int i=0; i < totped; i++)
        {
            pea[i].idcliente = pe[i].idcliente;
            pea[i].idpieza = pe[i].idpieza;
            pea[i].cant = pe[i].cant;
            cant_pedidos++;
        }
     
        //carga de clientes
        cantc=0;
        hay = 1;
        while(hay==1 && cantc<NCLIENTE)
        {
            printf("Ingrese el id del cliente:\n");
            scanf("%d", &c[cantc].idcliente);

            printf("Ingrese el nombre del cliente:\n");
            fgets(c[cantc].nom,20,stdin);

            printf("Ingrese la dirección del cliente:\n");
            fgets(c[cantc].nom,20,stdin);

            fgets(c[cantc].direc,30,stdin);
            
            printf("Ingrese el correo del cliente:\n");
            fgets(c[cantc].correo,20,stdin);
            
            printf("Ingrese el teléfono del cliente:\n");
            fgets(c[cantc].tel,12,stdin);
            
            printf("¿Hay más clientes? S:1/N:0:\n");
            scanf("%d", &hay);

            cantc=cantc+1;
        }

        //busco clientes
        for (int k=0; k < cantc; k++)
        {
            if (c[k].idcliente = pea[k].idcliente){
                cantt++;
            }
            else k++;
        }
     
        float totalventa = 0;
        //Punto 1
        for (int m = 0; m < cant_pedidos; m++)
        {
            strcpy(n[m].nom,c[m].nom);
            strcpy(n[m].tel,c[m].tel);
            n[m].idcliente = pea[m].idcliente;
            n[m].idpieza = pea[m].idpieza;
            n[m].cant = pea[m].cant;
            n[m].precosto = pi[m].precosto*1.35;

            totalventa += n[m].precosto * n[m].cant;
        }
     
        //punto 2
        printf("El total de clientes con el 100 por ciento es de: %d\n", cantt);
        printf("El monto total que se recaudará con estas entregas es de: %.2f\n", totalventa);
    
    }
    //(200*50 + 100*50)*1.35