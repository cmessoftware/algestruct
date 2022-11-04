#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
typedef struct paciente1 {
    char nombre[20];
    char apellido[20];
    int dni;
    struct paciente1 *sig;
}adulto;

typedef struct paciente2 {
    char nombre[20];
    int dni;
    int edad;
    char ortodoncia[2];
    struct paciente2 *sig;
}pediatrico;

typedef adulto *listaA;
typedef pediatrico *listaP;

int menuInicial();

void cargarAdulto(listaA *p, char nombre[20],char apellido[20], int dni);
void cargarPediatico(listaP *p, char nombre[20],int dni,int edad, char ortodoncia[2]);

void mostrarAdulto(adulto *p);

void eliminarAdulto(listaA *p, char nombre[20],char apellido[20], int dni);

//int promedio(listaP *p,int edad,char ortodoncia[2]);

int main()
{
    int op=1;
    int paciente;
    char nombre[20];
    char apellido[20];
    int dni;
    int edad;
    char ortodoncia[2];
    int prom;
    int acum=0;
    int cont=0;

    listaA lista_adultos=NULL;
    listaP lista_pediatricos=NULL;
    
    while(op!=5){
        menuInicial();
        scanf("%i",&op);
        switch(op)
        {
        case 1:
        {
            system("clear");
            printf("\n\t1-Cargar paciente adulto\n\t2-Cargar paciente pediatrico\n");
            scanf("%d",&paciente);
            switch(paciente){
                case 1:
                {
                printf("Ingrese nombre:\n");
                scanf("%s",&nombre[0]);
                printf("Ingrese apellido:\n");
                scanf("%s",&apellido[0]);
                printf("Ingrese dni:\n");
                scanf("%d",&dni);
                cargarAdulto(&lista_adultos,nombre,apellido,dni);
                break;
                }
                case 2:
                {
                printf("Ingrese nombre:\n");
                scanf("%s",&nombre[0]);
                printf("Ingrese dni:\n");
                scanf("%d",&dni);
                printf("Ingrese edad:\n");
                scanf("%d",&edad);
                printf("Quiere ortodoncia? si/no:\n");
                scanf("%s",&ortodoncia[0]);
                if(edad>18){
                    printf("La edad debe ser menor a 18");
                }else{
                    cargarPediatico(&lista_pediatricos,nombre,dni,edad,ortodoncia);
                    prom=promedio(&lista_pediatricos,edad,ortodoncia);
                break;
                }
            }
            break;
        }//cierra el case 1
        case 2:
        {
            printf("Los pacientes adultos cargados son:\n");
            mostrarAdulto(lista_adultos);
            break;
        }//cierra el case 2
        case 3:
        {
            printf("Se elimino el ultimo adulto");
            eliminarAdulto(&lista_adultos,nombre,apellido,dni);
            break;
        }//cierra case 3
        case 4:
        {
            printf("El promedio de edad de los pacientes pediatricos es: %d",prom);
        }
        }//cierra el switch
    }//cierra el while
    return 0;
}//cierra el main

int menuInicial(){
    printf("\n\tClinica de Ortodoncia\n");
    printf("\tSeleccione la opcion que le gustaria:\n");
    printf("\t1-Cargar datos\n");
    printf("\t2-Mostar los pacientes adultos del dia\n");
    printf("\t3-Cancelar el ultimo turno solicitado de adultos\n");
    printf("\t4-Mostrar el promedio de edad de los pacientes que se colocaran ortodoncia\n");
    printf("\t5-Salir del programa\n");
    
}

void cargarAdulto(listaA *p, char nombre[20],char apellido[20], int dni)
{
    listaA aux=malloc(sizeof(adulto));
    strcpy(aux->nombre,nombre);
    strcpy(aux->apellido,apellido);
    aux->dni=dni;
    aux->sig=*p;
    *p=aux;
    printf("Se cargo un dato");
}

void cargarPediatico(listaP *p, char nombre[20],int dni,int edad, char ortodoncia[2])
{
    listaP aux=malloc(sizeof(pediatrico));
    strcpy(aux->nombre,nombre);
    aux->dni=dni;
    aux->edad=edad;
    strcpy(aux->ortodoncia,ortodoncia);
    aux->sig=*p;
    *p=aux;
}

void mostrarAdulto(adulto *p)
{
    if(p!=NULL){
        printf("|%s|->",p->nombre);
        printf("|%s|->",p->apellido);
        printf("|%d|->",p->dni);
    }
    //mostrarAdulto(p->sig);
}

void eliminarAdulto(listaA *p, char nombre[20],char apellido[20], int dni)
{
    listaA aux=*p;
    (*p)=(*p)->sig;
    free(aux);
}


int promedio(listaP *p,int edad,char ortodoncia[2])
{
    int acum=0;
    int cont=0;
    int promedio;
    //int tam=sizeof(listaP);
    for(int i=0;i<10;i++){
        if(ortodoncia="si"){
        acum+=(*p);
        cont+=1;
        }
    }
    promedio=acum/cont;
    return promedio;
}

/*
            if(paciente=1){
                printf("Ingrese nombre:\n");
                scanf("%s",&nombre[0]);
                printf("Ingrese apellido:\n");
                scanf("%s",&apellido[0]);
                printf("Ingrese dni:\n");
                scanf("%d",&dni);
                cargarAdulto(&lista_adultos,nombre,apellido,dni);
            }else{
                if(paciente=2){
                printf("Ingrese nombre:\n");
                scanf("%s",&nombre[0]);
                printf("Ingrese dni:\n");
                scanf("%d",&dni);
                printf("Ingrese edad:\n");
                scanf("%d",&edad);
                printf("Quiere ortodoncia? si/no:\n");
                scanf("%s",&ortodoncia[0]);
                if(edad>18){
                    printf("La edad debe ser menor a 18");
                }else{
                    cargarPediatico(&lista_pediatricos,nombre,dni,edad,ortodoncia);
                    prom=promedio(&lista_pediatricos,edad);
                    }
                }
                
            }
            break;*/

