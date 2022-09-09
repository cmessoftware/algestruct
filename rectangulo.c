#include<stdio.h>

//Declaro mis funciones
float rectangulo(float x, float y); //OJO --> ACA VA EL ;
float triangulo(float x, float y );

int main()
{
    float area = 0;
    float x = 3.3;
    float y = 4;

    area = rectangulo(x,y);
    printf("Area de rectangulo de %.2fx%.2f es %.2f\n",x,y,area);

    area = triangulo(x,y);
    printf("Area de triangulo de %.2fx%.2f es %.2f\n",x,y,area);
}

//Implementacion de la funciones

float rectangulo(float x, float y) //OJO ACA NO VA EL ;
{
    float area = 0;

    area = x*y;

    return area;

}

float triangulo(float x, float y) //OJO ACA NO VA EL ;
{
    float area = 0;

    area = x*y/2;

    return area;

}