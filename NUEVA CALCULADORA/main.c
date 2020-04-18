#include <stdio.h>
#include <stdlib.h>
#include "OPERACIONES.h"



int main()
{

    float primerNumero;
    float segundoNumero;
    int opcion;
    float resultado;

    do
    {
        printf("******** Calculadora********\n");
        printf("1. Ingresar 1er operando (A=x)=\n");

        printf("2. Ingresar 2do operando (B=y)=\n");

        printf("3. Calcular todas las operaciones\n");

        printf("4. Informar resultados \n");

        printf("5. Salir\n");

        switch (opcion)
        {
        case 1:
            printf("1. Ingresar primer operando (A=x)=");
            scanf("%f",&primerNumero);
            break;
        case 2:
            printf("1. Ingresar segundo operando (A=x)=");
            scanf("%f",&segundoNumero);
            break;
        case 3:
            printf("a) Calcular la suma (%.2f+%.2f)\n",primerNumero,segundoNumero);
            printf("b) Calcular la resta (%.2f-%.2f)\n",primerNumero,segundoNumero);
            printf("c) Calcular la multiplicacion (%.2f*%.2f)\n",primerNumero,segundoNumero);
            printf("d) Calcular la division (%.2f/%.2f)\n",primerNumero,segundoNumero);
            printf("e) Calcular el factorial (%.2f y de %.2f)\n",primerNumero,segundoNumero);
            break;
        case 4:
            //suma
            resultado=suma(primerNumero,segundoNumero);
            printf("a) El resultado de %.2f+%.2f es: %.2f\n",primerNumero,segundoNumero,resultado);

            //resta

            resultado=resta(primerNumero,segundoNumero);
            printf("b) El resultado de %.2f-%.2f es: %.2f\n",primerNumero,segundoNumero,resultado);

            //multiplicacion

            resultado=multiplicacion(primerNumero,segundoNumero);
            printf("c) El resultado de %.2f*%.2f es: %.2f\n",primerNumero,segundoNumero,resultado);

            //division

            resultado=division(primerNumero,segundoNumero);

            if(segundoNumero==0)
            {
                printf("d) No es posible dividir por cero\n");
            }
            else
            {
                printf("d) El resultado de %.2f/%.2f es: %.2f\n",primerNumero,segundoNumero,resultado);
            }

            //factorial

            resultado=factorial(primerNumero);

            if (primerNumero==0)
            {
                printf("e) El resultado del factorial del 1°operando: %.2f es: 1\n",primerNumero);

            }
            else if ( primerNumero<0)     // en caso que el numero sea negativo se ejecuta el siguiente mensaje de error
            {

                printf("e) El factorial %.2f no se puede realizar\n",primerNumero);
            }
            else
            {
                resultado= factorial(primerNumero);

                printf("e) El resultado del factorial del 1°operando: %.2f es: %.2f\n",primerNumero, resultado);
            }

            //  SEGUNDO FACTORIAL

            resultado=factorial(segundoNumero);

            if (segundoNumero==0)
            {
                printf("e) El resultado del factorial del 2°operando: %.2f es: 1\n",segundoNumero);

            }
            else if ( segundoNumero<0)     // en caso que el numero sea negativo se ejecuta el siguiente mensaje de error
            {

                printf("e) El factorial %.2f no se puede realizar\n",segundoNumero);
            }
            else
            {
                resultado= factorial(segundoNumero);

                printf("e) El resultado del factorial del 2°operando: %.2f es: %.2f\n",segundoNumero, resultado);

            }

        }


        printf("Ingrese una opcion : \n");


        scanf("%d",&opcion);

        system("cls");
    }
    while(opcion< 1 || opcion!= 5 || opcion > 5 );


    return 0;

}
