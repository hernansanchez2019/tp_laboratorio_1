/*
 * funcionesPersonales.c
 *
 *  Created on: 6 may. 2022
 *      Author: Hernan
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tipoPasajero.h"
#include "estadoVuelo.h"
#include "ArrayPassenger.h"
#include "funcionesPersonales.h"

int listadoCodVueloYestado(ePassenger vec[], int tam,eEstadoVuelo vuelo[],int tamv)
{
	int todoOk=0;

	if(vec!=NULL && vuelo!=NULL && tam > 0 && tamv > 0)
	{
		sortPassengersByCode(vec, tam, vuelo, tamv);

		printf("Cod.Vuelo     Estado Vuelo\n");
		printf("-----------------------------------\n");

		for(int i=0 ; i < tam ; i++)
		{
			printf("%s     %s\n", vec[i].flyCode, vuelo[i].descripcion);
		}
	}



	return todoOk;
}

int hardcodearPasajeros(ePassenger vec[], int tam, int cant, int* pNextId)
{
    int todoOk = 0;
    ePassenger pasajero[3] =
    {
        {0, "juan", "sanchez", 100, "FGH567",1,1,0,1,100},
        {0, "miguel", "acosta", 100, "ERT678",2,2,0,2,102},
        {0, "juana", "perez", 100, "GHJ234",3,1,0,3,100}

    };

    if( vec != NULL && pNextId != NULL && tam > 0 && tam <= 10 && cant <= tam)
    {
        for(int i=0; i < cant; i++)
        {
            vec[i] = pasajero[i];
            vec[i].id = *pNextId;
            (*pNextId)++;
        }
        todoOk = 1;
    }
    return todoOk;

}

void mostrarPasajero(ePassenger pasajero,eTipoPassenger tipo[],int tams,eEstadoVuelo vuelo[],int tamv)
{

	char descripcion[20];
	char descripVuelo[20];

	cargarDescripcionPasajero(tipo, tams, pasajero.idTipoPassenger, descripcion);
	cargarDescripcionVuelo(vuelo, tamv,pasajero.idEstadoVuelo,descripVuelo);



    printf("%8d    %8s      %8s    %8.2f     %8s     %8s    %8s\n",
    		pasajero.id,
			pasajero.name,
			pasajero.lastName,
			pasajero.price,
			pasajero.flyCode,
			descripcion,
			descripVuelo
            );
}


int menuPasajeros()
{

    int opcion;

    system("cls");
    printf("     *** Administracion de pasajeros y vuelos ***\n\n");
    printf("1. Alta \n");
    printf("2. Baja \n");
    printf("3. Modificar\n");
    printf("4. Informar\n");
    printf("5. Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}


int buscarLibre(ePassenger vec[], int tam, int* pIndex)
{

    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int menuModificarPasajero()
{
    int opcion;

    printf("     *** Campo a modificar ***\n\n");
    printf("1. Nombre\n");
    printf("2. Apellido\n");
    printf("3. Precio\n");
    printf("4. Codigo de vuelo\n");
    printf("5. Tipo de pasajero\n");
    printf("6. Estado de vuelo\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


int modificarPasajero(ePassenger vec[], int tam,eTipoPassenger tipo[],int tams,eEstadoVuelo vuelo[],int tamv)
{
    int todoOk = 0;
    int indice;
    int id;
    char auxCad[100];
    char auxCodVuelo[6];
    float auxFlotante;
    int auxEntero;


    if( vec != NULL && tam > 0 )
    {
    	printPassengers(vec, tam,tipo,tams,vuelo,tamv);
        printf("Ingrese id: ");
        scanf("%d", &id);

        if( findPassengerById(vec, tam, id, &indice))
        {

            if(indice == -1)
            {
                printf("No existe un pasajero con id: %d en el sistema\n", id);
            }
            else
            {

               mostrarPasajero(vec[indice],tipo,tams,vuelo,tamv);

                switch(menuModificarPasajero())
                {

                case 1:
                	 printf("Ingrese nombre: ");
                	 fflush(stdin);
                	 gets(auxCad);

                	while(strlen(auxCad)>20)
                	  {
                	       	printf("Error...Reingrese nombre: ");
                	      	fflush(stdin);
                	     	gets(auxCad);
                     }

                	   strcpy(vec[indice].name,auxCad);

                    break;

                case 2:
                	 printf("Ingrese apellido: ");
                	 fflush(stdin);
                	  gets(auxCad);

                	while(strlen(auxCad)>20)
                	     {
                	            	printf("Error...Reingrese apellido: ");
                	                fflush(stdin);
                	               gets(auxCad);
                	     }

                	     strcpy(vec[indice].lastName,auxCad);

                    break;

                case 3:

                    printf("Ingrese nuevo precio: ");
                    scanf("%f", &auxFlotante);
                    vec[indice].price = auxFlotante;
                    printf("Precio modificado!");
                    break;

                case 4:

                	 printf("Ingrese codigo del vuelo abc1234 : ");
                	fflush(stdin);
                	gets(auxCodVuelo);

                	while(strlen(auxCodVuelo)>6)
                	    {
                	           	printf("Error...Reingrese codigo: ");
                	           	fflush(stdin);
                	           	gets(auxCodVuelo);
                	      }

                	    strcpy(vec[indice].flyCode,auxCodVuelo);
                    break;

                case 5:


                    printf("Ingrese tipo de pasajero\n");
                    printf("1. First\n");
                    printf("2. Business\n");
                    printf("3. Turista : \n");
                    scanf("%d",&auxEntero);

                    while(auxEntero > 3 || auxEntero < 1)
                    {
                    	  printf("Error...ingrese tipo de pasajero\n");
                    	            printf("1. First\n");
                    	            printf("2. Business\n");
                    	            printf("3. Turista : \n");
                    	            scanf("%d",&auxEntero);
                    }


                    vec[indice].idTipoPassenger = auxEntero;
                	break;


                case 6:

                	 printf("Ingrese estado del vuelo\n");
                	            printf("1. ACTIVO\n");
                	            printf("2. CANCELADO :  ");
                	            scanf("%d", &auxEntero);


                	            while(auxEntero > 2 || auxEntero < 1)
                	            {
                	            	  printf("Error...ingrese estado de vuelo\n");
                	            	  printf("1. ACTIVO\n");
                	            	  printf("2. CANCELADO :  ");
                	            	  scanf("%d",&auxEntero);
                	            }

                	            vec[indice].idEstadoVuelo = auxEntero;

                    break;

                }



            }

            todoOk = 1;
        }
    }
    return todoOk;
}






int subMenuInformes()
{
	int opcion;

	system("cls");

	printf("*** INFORMES ***\n\n");

	printf("1. Listado de los pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero\n");
	printf("2. Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio.\n");
	printf("3. Listado de los pasajeros por Codigo de vuelo y estados de vuelos �ACTIVO�\n");
	printf("4. Volver al menu principal\n");
	printf("Ingrese una opcion: ");
	scanf("%d", &opcion);

	return opcion;
}

void informes(ePassenger vec[], int tam,eTipoPassenger tipo[],int tams,eEstadoVuelo vuelo[],int tamv)
{

	char seguir = 'n';

	do
	{
		switch(subMenuInformes())
		{

		case 1:

			system("cls");
			sortPassengers(vec, tam,tipo,tams);
			printPassengers(vec, tam, tipo, tams, vuelo, tamv);
			system("pause");
			system("cls");
			break;

		case 2:
			system("cls");
			promedioPasajes(vec, tam);
			system("pause");
			system("cls");
			break;

		case 3:
			system("cls");
			listadoCodVueloYestado(vec, tam, vuelo, tamv);
			system("pause");
			system("cls");
			break;


		case 4:
			seguir = 's';
			break;

		}



	}while(seguir != 's');



}

int promedioPasajes(ePassenger vec[], int tam)
{
    int todoOk = 0;
    float acumPasajes = 0;
    int contPasajeros = 0;
    float promedio = 0;
    int precioProMaximo = 0;

    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty)
            {
            	acumPasajes += vec[i].price;
            	contPasajeros++;
            }


        }
        if(contPasajeros != 0)
        {
            promedio = acumPasajes / contPasajeros;
        }

        for(int i=0; i < tam; i++)
        {
        	 if(vec[i].price > promedio)
        	 {
        		 precioProMaximo++;
        	 }
        }


        system("cls");
        printf("     *** Promedio de Pasajes $$$ ***\n\n");

        printf("Promedio pasajes: $ %.2f\n", promedio);
        printf("Total: $ %.2f\n", acumPasajes);

        if(precioProMaximo==0)
        {
        	printf("Ningun pasajero supera el precio promedio\n");
        }
        else
        {
        	printf("Cantidad de pasajeros que superan el promedio: %d\n", precioProMaximo);
        }


        todoOk = 1;
    }
    return todoOk;
}

