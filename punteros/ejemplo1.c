#include<stdio.h>


void main(void)
{

    char *pm = "HOLA";
    char *pm2 = pm;
    int lenght = 0;
  
    //Imprime el primer elemento
    printf("%c\n",*pm);
    //Imprime la direccion de memoria del primero elemento.
    printf("%p\n",pm);
    //Imprime el contenido del tercer elemento del array.
    printf("%c\n",pm[2]);
    //Imprime el contenido del tercer elemento del array. --> Otra forma
    printf("%c\n",*(pm+2));

  
    //Imprime todo el array recorriendolo con el puntero
    while(*pm != '\0')
    {
        printf("%c",*pm);
        pm++;
    }
     printf("%c",'\n');

    pm = pm2;
    //Imprime el array considerandolo una candena de caracteres.
    printf("%s",pm);
    
    //Calculamos la longitud del array
    while(*pm !='\0')
    {
        pm++;
        lenght++;
    }

    pm = pm2;
   
    //Mostrar la cadena al reves
    int n = lenght;

    do
    {
        printf("%c",*(pm+n));
        
    }while(n--);

    //printf("%c",'\n');

}

