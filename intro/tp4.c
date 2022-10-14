#include<stdio.h>


int main()
{
    //Declaramos las variables.
    //llanta --> si llanta=1 esta ok y si llanta=0 esta fallada.
    //turnos
    //prod_desde y prod_hasta
    //Tamano 14 a 19
    //Pilas --> pila_ok1 a pila_ok6  y pila_err1 a pila_err6 --> 10 elementos.
    //Cajas --> cajas_ok1 a cajas_ok6 y cajas_err1 a cajas_err6 --> 10 elementos.

    const int prod_desde = 14;
    const int prod_hasta = 19;
    int cont_llantaok1 = 0;
    int cont_llantaerr1 = 0;
    int cont_llantaok2 = 0;
    int cont_llantaerr2 = 0;
    int cont_cajasok1 = 0;
    int cont_cajaserr1 = 0;
    int cont_cajasok2 = 0;
    int cont_cajaserr2 = 0;

    /*
    Repetir mientras 1=1  --> No para nunca.
        si llanta = 1 entonces
            si  tipo llanta = 1 entonces
                cargar en pok1
                cont_llantaok1++
            fin si
            si  tipo llanta = 2 entonces
                cargar en pok2
                cont_llantaok2++
            fin si
            si  tipo llanta = 3 entonces
                cargar en pok3
                cont_llantaok++
            fin si
            si  tipo llanta = 4 entonces
                cargar en pok1
                cont_llantaok++
            fin si
            si  tipo llanta = 5 entonces
                cargar en pok1
                cont_llantaok++
            fin si
            si  tipo llanta = 6 entonces
                cargar en pok6
                cont_llantaok++
            fin si
        fin si

        si llanta = 0 entonces
            si  tipo llanta = 1 entonces
                cargar en perr1
                cont_llantaerr1++
            fin si
            si  tipo llanta = 2 entonces
                cargar en perr2
                cont_llantaerr1++
            fin si
            si  tipo llanta = 3 entonces
                cargar en perr3
                cont_llantaerr++
            fin si
            si  tipo llanta = 4 entonces
                cargar en perr1
                cont_llantaerr++
            fin si
            si  tipo llanta = 5 entonces
                cargar en perr1
                cont_llantaerr++
            fin si
            si  tipo llanta = 6 entonces
                cargar en perr6
                cont_llantaerr++
            fin si
        fin si

        si cont_llantaok1 <= 10 
                cargar caja ok
                cont_cajasok++
                cont_llantaok1 = 0; 
        fin si

         si cont_llantaok2 <= 10 
                cargar caja ok
                cont_cajaserr++
                cont_llantaok2 = 0; 
        fin si

        //Completar los 6 casos

         si cont_llantaerr1 <= 10 
                cargar caja ok
                cont_cajasok++
                cont_llantaerr1 = 0; 
        fin si

         si cont_llantaerr2 <= 10 
                cargar caja ok
                cont_cajaserr++
                cont_llantaerr2 = 0; 
        fin si

         //Completar los 6 casos

     
    Fin Repetir mientras
    
    */
}

/*Funciones 

cargar en pila(ok, numero_pila, numero_llanta)

   si  numero_pila = 1 y ok = 1 entonces
        pok1[indice] = numero_llanta
        indice1++  //Se carga en un indice incremental.
   fin si

   si  numero_pila = 2 y ok = 1 entonces
        pok2[indice] = numero_llanta
        indice2++  //Se carga en un indice incremental.
   fin si

    //Completar las 6 pilas

   si  numero_pila = 1 y ok = 0 entonces
        perr1[indice] = numero_llanta
        indice1++  //Se carga en un indice incremental.
   fin si

   si  numero_pila = 2 y ok = 0 entonces
        perr2[indice] = numero_llanta
        indice2++  //Se carga en un indice incremental.
   fin si
   //Completar las 6 pilas

fin cargar en pila

*/

