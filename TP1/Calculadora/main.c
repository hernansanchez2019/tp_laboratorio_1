#include <stdio.h>
#include <stdlib.h>
#include "FUNCIONES.h"

int main()
{


    int num1;
    int num2;
    int respuesta;
    int flag=0;
    int resultado;
    float resultadoDivision;
    int resultado1factorial;
    int resultado2factorial;

    do
    {
        printf("\t********* Calculadora ********* ");

        printf("\n\n 1.  Ingresar 1er operando ");

        printf("\n 2.  Ingresar 2er operando ");

        printf("\n 3.  Calcular todas las operaciones");

        printf("\n 4.  Informar resultados");

        printf("\n 5.  Salir\n");

        printf("\nIngrese una opcion --> 1/2/3/4/5\n");
        scanf("%d", &respuesta);

        system("cls");

        switch(respuesta)
        {
        case 1:

            if(flag==0)
            {
                printf(" 1.  Ingresar 1er operando (A=x)= ");
                scanf("%d",&num1);
                flag=1;
                system("cls");
                break;
            }

        case 2:
            printf(" 2.  Ingresar 2do operando (B=y)= ");
            scanf("%d",&num2);
            flag=1;
            system("cls");
            break;

        case 3:
            if(flag==0)
            {

                printf("No hay numeros para Operar\n");
                system("PAUSE");
                system("cls");
                break;

            }

            else
            {

                printf(" 1.  Ingresar 1er operando (%d) ",num1);

                printf("\n 2.  Ingresar 2er operando (%d) ", num2);

                printf("\n 3.  Calcular todas las operaciones\n\n  a) Calcular la suma (%d+%d)\n  b) Calcular la resta (%d-%d)\n  c) Calcular la division (%d/%d)\n  d) Calcular la multiplicacion (%d*%d)\n  e) Calcular el factorial (%d!) (%d!)\n",num1,num2,num1,num2,num1,num2,num1,num2,num1,num2);

                printf("\n 4.  Informar resultados\n");

                printf("\n 5.  Salir\n\n");
                system("PAUSE");
                system("cls");
                break;
            }

        case 4:
            if(flag==0)
            {
                printf("No hay Resultados para Mostrar\n");
                system("PAUSE");
                system("cls");
                break;
            }
            else
            {
                resultado= suma(num1,num2);
                printf(" a) El resultado de %d+%d es = %d  \n", num1, num2, resultado);

                resultado= resta(num1,num2);
                printf(" b) El resultado de %d-%d es = %d  \n", num1, num2, resultado);


                resultado=producto(num1,num2);
                printf(" c) El resultado de %d*%d es = %d  \n", num1, num2, resultado);

                resultado1factorial=factorial(num1);
                resultado2factorial=factorial(num2);
                printf(" d) El factorial de %d es = %d y El factorial de %d es: %d \n", num1, resultado1factorial,num2,resultado2factorial);

                if(num2==0)
                {
                    printf(" e) El resultado de %d/%d es = No se puede dividir por cero \n", num1, num2);
                    system("PAUSE");
                    system("cls");
                }

                else
                {
                    resultadoDivision= (float)division(num1,num2);
                    printf(" e) El resultado de %d/%d es = %.2f  \n", num1, num2, resultadoDivision);
                    system("PAUSE");
                    system("cls");
                    break;
                }
            }

            break;

        case 5:
            printf("\nApagando...");
            system("PAUSE");
            system("cls");
            break;
        }

    }
    while(respuesta!=5);

     return 0;

}







