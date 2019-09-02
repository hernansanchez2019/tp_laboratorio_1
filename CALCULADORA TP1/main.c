#include <stdio.h>
#include <stdlib.h>
#include "OperacionesAritmeticas.h"


int main() {
    int numero1;   // se declaran variables
    int numero2;
    float resultado;
    char opcion;

   do{


    system("COLOR 0A");
   printf("\n\t ******* CALCULADORA ******* ");
   printf("\nIngresar primer numero = ");  // se piden los datos a ejecutar
    scanf("%d" , &numero1);
    printf("\nIngresar segundo numero = ");
    scanf("%d", &numero2);
    printf("\nCalcular la suma = OPCION (a) ");  // menu de opciones
    printf("\nCalcular la resta = OPCION (b) ");
    printf("\nCalcular la division = OPCION (c) ");
    printf("\nCalcular la multiplicacion = OPCION (d)");
    printf("\nCalcular el factorial = OPCION (e)");
    printf("\nPara finalizar = OPCION (5)");
    fflush(stdin);
    scanf("%c" , &opcion);

    switch (opcion) {  // con cada de una de las opciones que el usuario elija se ejecuta el siguiente comando
        case 'a':
            resultado = suma( numero1,numero2);
            printf("\nLa suma de %d + %d es = %.2f" ,numero1 , numero2 , resultado);  // en caso que se ejecute la opcion a realiza la suma
            break;
        case 'b':
            resultado = resta( numero1 , numero2);
            printf("\nLa resta de %d - %d es = %.2f" ,numero1 , numero2 , resultado); // en caso que se ejecute la opcion b se resta
            break;
        case 'd':
            resultado = multiplicacion(numero1,numero2);
            printf("\nLa multiplicacion de %d * %d es = %.2f" ,numero1 , numero2 , resultado);  // en caso qie se ejecute la opcion d realiza la multiplicacion
            break;
        case 'c':
                if ( numero2!=0)  //   en caso que la division de 0 entra a la funcion IF
                {
            resultado = division(numero1,numero2);
            printf("\nLa division de %d / %d es = %.2f" ,numero1 , numero2 , resultado);
            break;
                }

                else
                {

                printf("\nNo se puede realizar la division"); // si la operacio no se puede realizar se ejecuta el mensaje de error
                }
                    break;
        case 'e':

           if (numero1=='0')
            {   printf("\nEl factorial de %d es = 1 " , numero1 );

            } else if ( numero1<0){  // en caso que el numero sea negativo se ejecuta el siguiente mensaje de error

                printf("\nEl factorial %d no se puede realizar" , numero1);
            }
                else {
                resultado= factorial(numero1);

            printf("\nEl factorial de %d es = %.2f" , numero1, resultado);
            }

            if ( numero2=='0'){
                 printf("\nEl factorial de %d es = 1 " , numero2 );

            }
                else if ( numero2<0)
            {
                printf("\nEl factorial %d no se puede realizar" , numero2);

            }
                else {

                resultado= factorial(numero2);
                printf("\nEl factorial de %d es = %.2f" , numero2, resultado);
                break;
            }


        case '5' :
            printf("\nFinalizo la operacion");
            break;

        default:
            printf("\nOpcion incorrecta");
    }




    } while ( opcion!='5'); // en caso que el usuario ejecute la opcion 5 la calculadora finalizara


    system("COLOR 0C" );
    return 0;
}
