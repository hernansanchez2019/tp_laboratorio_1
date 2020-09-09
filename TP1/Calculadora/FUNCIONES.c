#include "FUNCIONES.h"


int suma(int num1, int num2)
{
    int resultado;

    resultado= num1 + num2;

    return resultado;
}


int resta(int num1, int num2)

{
    int resultado;

    resultado= num1 - num2;

    return resultado;
}


int producto(int num1, int num2)
{
    int resultado;

    resultado= num1 * num2;

    return resultado;
}


float division(int num1, int num2)
{
    float resultado;

    resultado= (float)num1 / num2;

    return resultado;
}


int factorial(int num1)

{
    int resultado=1;
    int i;

    for (i=num1; i>0 ; i--)
    {
        //factoriamos variables
        resultado= i * resultado;
    }

    return resultado;

}
