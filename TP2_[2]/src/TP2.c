/*
 ============================================================================
 Name        : Trabajo Pr�ctico n�mero 2
 Author      : Roberto Hernan Sanchez
 DNI	     : 36495489
 Copyright   : Your copyright notice
 Description : sistema para administrar los pasajeros de cada vuelo
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tipoPasajero.h"
#include "estadoVuelo.h"
#include "ArrayPassenger.h"
#include "funcionesPersonales.h"

#define TAM 2000
#define TAMS 3
#define TAMV 2



int main(void)

{
	setbuf(stdout,NULL);

	int proximoId = 1000;
	char salir = 'n';
	int flag=0;

	ePassenger pasajeros[TAM];

	eTipoPassenger tiposPasajeros[TAMS]=
	    {
	        {1, "firts" },
	        {2, "business" },
	        {3, "turista" }
	    };

	eEstadoVuelo vuelo[TAMV]=
	{
		{1, "ACTIVO" },
		{2, "CANCELADO"}

	};

	initPassengers(pasajeros, TAM);


	do
	{
		switch(menuPasajeros())
		{

		case 1:

			if(!flag || flag==2)
            {
				addPassengers(pasajeros, TAM, &proximoId);
                printf("Pasajero cargado con exito!!!\n");
                flag=1;
            }
            else
            {
                printf("No se pudo cargar el pasajero\n");
            }
            break;


		case 2:
			if(flag|| flag==2)
			{
				removePassenger(pasajeros, TAM,tiposPasajeros,TAMS,vuelo,TAMV);
				printf("Baja exitosa!!!");

			}
			else
			{
				printf("No hay pasajeros cargados");
			}

					break;


		case 3:
			if(flag|| flag==2)
			{
				modificarPasajero(pasajeros, TAM,tiposPasajeros,TAMS,vuelo,TAMV);
				printf("Modificacion exitosa !!!");
			}
			else
			{
				printf("No hay pasajeros cargados");

			}
				break;


		case 4:
			if(flag|| flag==2)
			{
			system("cls");
			informes(pasajeros, TAM, tiposPasajeros, TAMS, vuelo, TAMV);
			}
			else
			{
				printf("No hay pasajeros cargados");
			}


			system("cls");
				break;


		case 5:
				hardcodearPasajeros(pasajeros, TAM, 6, &proximoId);
				printf("Carga Forzada Realizada !!!\n");
				flag=2;
		        break;


		case 6:
				printf("\nPrograma Finalizado ! \n");
		        salir = 's';
			break;
		}

		system("pause");

	}while(salir != 's');


	return EXIT_SUCCESS;
}

