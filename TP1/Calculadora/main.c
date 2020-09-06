#include <stdio.h>
#include <stdlib.h>


int suma(int num1, int num2);



int main()
{
    int num1;
    int num2;
    int respuesta;
    int flag=0;
    int resultado;



    do
    {


        printf(" 1.  Ingresar 1er operando ");

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
                system("cls");
                break;

            }

        case 2:

            if(flag==0)
            {
                printf(" 2.  Ingresar 2do operando (B=y)= ");
                scanf("%d",&num2);
                system("cls");
                break;
            }



        case 3:
            if(flag==0)
            {

                printf(" 1.  Ingresar 1er operando (%d) ",num1);

                printf("\n 2.  Ingresar 2er operando (%d) ", num2);

                printf("\n 3.  Calcular todas las operaciones\n\n  a) Calcular la suma (%d+%d)\n  b) Calcular la resta (%d-%d)\n  c) Calcular la division (%d/%d)\n  d) Calcular la multiplicacion (%d*%d)\n  e) Calcular el factorial (%d!) (%d!)\n",num1,num2,num1,num2,num1,num2,num1,num2,num1,num2);

                printf("\n 4.  Informar resultados\n");

                printf("\n 5.  Salir\n\n");

                flag=1;
                system("PAUSE");
                system("cls");
                break;

            }

            else
            {
                printf("No hay numeros para Operar\n");
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

                printf(" a) El resultado de %d+%d es %d \n", num1, num2, resultado);
                system("PAUSE");
                system("cls");
                break;

            }

        }

    }
    while(respuesta!=5);


    return 0;
}

int suma(int num1, int num2)
{
    int resultado;

    resultado= num1 + num2;

    return resultado;
}
