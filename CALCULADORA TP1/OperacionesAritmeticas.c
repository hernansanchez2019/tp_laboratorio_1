#include "OperacionesAritmeticas.h"

int suma(  int A, int B)

{
    int resultado;
    resultado = A + B ;  // sumamos variables

    return resultado;

}

int resta(  int A, int B)

{
   int resultado;
    resultado = A - B ; // restamos variables

    return resultado;

}


int  multiplicacion(  int A, int B)

{
    int resultado;
    resultado = A * B ; // multiplicamos variables

    return resultado;

}

float division(  int A, int B)

{
    float resultado;
    resultado = (float)A / B ; //dividimos variables

    return resultado;

}

int factorial(  int A)

{
    int resultado=1;
    int i;

    for (i=(int)A; i>0 ; i--){  //factoriamos variables

        resultado= i * resultado;
    }




    return resultado;

}
