/*
 ============================================================================
 Name        : TP_[1].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

int main(void)

{

	setbuf(stdout,NULL);

	 char opcion;
	    float kilometros;
	    float latam;
	    float aerolineas;
	    int flag = 0;
	    int validoIngresoDeDato= 0;


	    menu();

	    do
	    {


	        opcion = pedirOpcionMenu("Ingrese una opcion entre ",'1','6');


	        switch(opcion)
	        {

	        case '1':

	            if(flag==0)
	            {
	                system("cls");
	                printf("1.  Ingresar Kilometros: ( km = x )");
	                validoIngresoDeDato = scanf("%f", &kilometros);

	                if(validoIngresoDeDato==0)
	                {
	                    printf("Hubo un error !!!\n");
	                    system("pause");
	                    system("cls");
	                    menu();
	                   break;
	                }
	                else
	                {
	                    printf("Cargado con exito!!!\n");
	                    system("pause");
	                    flag=1;
	                    system("cls");
	                    menuModificado(kilometros);
	                    break;
	                }
	                system("cls");
	                menuModificado(kilometros);
	                flag=1;
	                break;

	            }

	            break;

	        case '2':

	            if(flag==1)
	            {
	                system("cls");
	                printf("2. Ingresar Precio de Vuelos: (Aerolineas=y, Latam=z)\n   - Precio vuelo Aerolineas: \n   - Precio vuelo Latam:\n Aerolineas: ");
	                validoIngresoDeDato= scanf("%f", &aerolineas);

	                if(validoIngresoDeDato==0)
	                {
	                    printf("Hubo un error !!!\n");
	                    system("pause");
	                    system("cls");
	                    menuModificado(kilometros);
	                    break;
	                }
	                else
	                {
	                    printf("Cargado con exito!!!\n");

	                }

	                printf("Latam: ");
	                validoIngresoDeDato= scanf("%f", &latam);

	                if(validoIngresoDeDato==0)
	                {
	                    printf("Hubo un error !!!\n");
	                    system("pause");
	                    system("cls");
	                    menuModificado(kilometros);
	                    break;
	                }
	                else
	                {
	                    printf("Cargado con exito!!!\n");
	                    system("pause");
	                    flag=2;
	                    system("cls");
	                    menuModificado2(aerolineas,latam,kilometros);
	                    break;
	                }
	                system("pause");
	                flag=2;
	                system("cls");
	                menuModificado2(aerolineas,latam,kilometros);

	                break;

	            }
	            else
	            {
	                printf("Primero ingrese los Kilometros !!! \n");
	                break;
	            }

	        case '3':

	            if(flag==2)
	            {

	                printf("Calculos realizados con exito !!!\n");
	                system("pause");
	                system("cls");
	                flag=3;
	                menuModificado2(aerolineas,latam,kilometros);
	                break;
	            }

	            else
	            {
	                printf("Ingrese los datos por completo para calcular !!!\n");
	                break;
	            }

	        case '4':

	            if(flag==3)
	            {
	                system("cls");
	                informeResultados(aerolineas,latam,kilometros);
	                flag=0;
	                system("pause");
	                system("cls");
	                menu();
	                break;
	            }
	            else
	            {
	                printf("Ingrese datos y calcule !!!\n");
	                break;
	            }

	        case '5':
	            system("cls");
	            menuResultadosForzados(7090,162965,159339);
	            system("pause");
	            system("cls");
	            menu();
	            break;

	        default:
	            printf("\nPrograma finalizado !!!\n");
	            break;

	        }

	    }
	    while(opcion !='6');

	    return 0;

}
