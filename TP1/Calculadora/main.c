#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int respuesta;
    int flag=0;
    //int resultado;

    do
    {


        printf(" 1.  Ingresar 1er operando (A=x) ");

        printf("\n 2.  Ingresar 2er operando (B=y) ");

        printf("\n 3.  Calcular todas las operaciones\n\n  a) Calcular la suma (A+B)\n  b) Calcular la resta (A-B)\n  c) Calcular la division (A/B)\n  d) Calcular la multiplicacion (A*B)\n  e) Calcular el factorial (A!)\n");

        printf("\n 4.  Informar resultados\n\n  a) El resultado de A+B es: r \n  b) El resultado de A-B es: r\n  c) El resultado de A/B es: r o No es posible dividir por cero\n  d) El resultado de A*B es: r\n  e) El factorial de A es: r1 y El factorial de B es: r2\n ");

        printf("\n 5.  Salir\n");

        printf("\nIngrese una opcion --> 1/2/3/4/5\n");
        scanf("%d", &respuesta);


        system("cls");


        switch(respuesta)
        {
        case 1:
            printf(" 1.  Ingresar 1er operando (A=x)= ");
            scanf("%d",&num1);
            system("PAUSE");
            system("cls");
            break;


        case 2:
            printf(" 2.  Ingresar 2do operando (B=y)= ");
            scanf("%d",&num2);
            system("PAUSE");
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
                printf(" 1.  Ingresar 1er operando (%d=x) ",num1);

                printf("\n 2.  Ingresar 2er operando (B=y) ");

                printf("\n 3.  Calcular todas las operaciones\n\n  a) Calcular la suma (A+B)\n  b) Calcular la resta (A-B)\n  c) Calcular la division (A/B)\n  d) Calcular la multiplicacion (A*B)\n  e) Calcular el factorial (A!)\n");

                printf("\n 4.  Informar resultados\n\n  a) El resultado de A+B es: r \n  b) El resultado de A-B es: r\n  c) El resultado de A/B es: r o No es posible dividir por cero\n  d) El resultado de A*B es: r\n  e) El factorial de A es: r1 y El factorial de B es: r2\n ");

                printf("\n 5.  Salir\n");





            }



        }


    }
    while(respuesta!=5);


    return 0;
}
