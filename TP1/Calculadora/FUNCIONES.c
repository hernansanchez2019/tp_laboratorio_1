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
    int resultado;

    if (num1 == 0)
    {
        resultado = 1;
    }

    else
    {
        resultado = num1* factorial(num1-1);
    }

    return resultado;

}
