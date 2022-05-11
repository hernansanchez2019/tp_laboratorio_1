/*
 * ArrayPassenger.c
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


int printPassengers(ePassenger vec[], int tam,eTipoPassenger tipo[],int tams,eEstadoVuelo vuelo[],int tamv)
{
    int todoOk = 0;
    int flag = 1;
    if( vec != NULL && tam > 0)
    {
        system("cls");
        printf("       *** Listado de pasajeros y vuelos ***\n\n");
        printf("   ID       Nombre         Apellido      Precio       Cod.Vuelo   T.Pasajero   E.Vuelo\n");
        printf("-----------------------------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty)
            {
                mostrarPasajero(vec[i],tipo,tams,vuelo,tamv);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("     No hay pasajeros en el sistema\n");
        }

        todoOk = 1;
    }
    return todoOk;
}


int initPassengers(ePassenger vec[], int tam)
{
    int todoOk = 0;
    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}


int addPassengers(ePassenger vec[], int tam, int* pNextId)
{
    int todoOk = 0;
    int indice;
    char aux[20];
    char auxCodVuelo[6];
    int auxEntero;
    float auxFloat;
    ePassenger nuevoPasajero;



    if( vec != NULL && pNextId != NULL && tam > 0)
    {
        system("cls");
        printf("    *** Alta Pasajero ***\n\n");
        buscarLibre(vec, tam, &indice);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
        	nuevoPasajero.id = *pNextId;
           printf("Ingrese nombre: ");
            fflush(stdin);
            gets(aux);

            while(strlen(aux)>20)
            {
            	printf("Error...Reingrese nombre: ");
            	fflush(stdin);
            	gets(aux);
            }

            strcpy(nuevoPasajero.name,aux);

            printf("Ingrese apellido: ");
             fflush(stdin);
            gets(aux);

             while(strlen(aux)>20)
                {
                      	printf("Error...Reingrese apellido: ");
                      	fflush(stdin);
                        gets(aux);
                     }

                        strcpy(nuevoPasajero.lastName,aux);



      auxFloat = getFloat("Ingrese precio del vuelo", "Error...Reingrese precio: ");

      nuevoPasajero.price = auxFloat;



             printf("Ingrese codigo del vuelo abc1234 : ");
            fflush(stdin);
            gets(auxCodVuelo);


            while(strlen(auxCodVuelo)>6)
            {
            	printf("Error...Reingrese codigo: ");
            	fflush(stdin);
            	gets(auxCodVuelo);
            }

            strcpy(nuevoPasajero.flyCode,auxCodVuelo);



        auxEntero = getInt("Ingrese tipo de pasajero\n 1. First\n 2. Business\n 3. Turista : \n", "Error...Reingrese tipo de pasajero: ");


           while(auxEntero > 3 || auxEntero < 1)
            {
        	   auxEntero = getInt("Ingrese tipo de pasajero\n 1. First\n 2. Business\n 3. Turista : \n", "Error...Reingrese tipo de pasajero: ");

            }


            nuevoPasajero.idTipoPassenger = auxEntero;



           auxEntero = getInt("Ingrese estado del vuelo\n 1. ACTIVO\n2. CANCELADO :  ", "Error...Reingrese estado del vuelo: ");


            while(auxEntero > 2 || auxEntero < 1)
            {
               auxEntero = getInt("Ingrese estado del vuelo\n 1. ACTIVO\n2. CANCELADO :  ", "Error...Reingrese estado del vuelo: ");

            }

            nuevoPasajero.idEstadoVuelo = auxEntero;


            nuevoPasajero.isEmpty = 0;

            vec[indice] = nuevoPasajero;

            (*pNextId)++;

            todoOk = 1;
        }
    }
    return todoOk;
}


int removePassenger(ePassenger vec[], int tam,eTipoPassenger tipo[],int tams,eEstadoVuelo vuelo[],int tamv)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
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

                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's' || confirma == 'S')
                {
                    vec[indice].isEmpty = 1;

                }
                else
                {
                    printf("Baja cancelada por el usuario\n");
                }

            }

            todoOk = 1;
        }
    }
    return todoOk;
}


int findPassengerById(ePassenger vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty  && vec[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int sortPassengers(ePassenger vec[],int tam,eTipoPassenger tipo[],int tams)
{

	 int todoOk = 0;
	    ePassenger auxPasajero;


	    if( vec != NULL && tam > 0)
	    {
	        for(int i=0; i < tam - 1; i++)
	        {
	            for(int j= i+1; j < tam; j++)
	            {
	               if( strcmp(vec[i].lastName, vec[j].lastName) >0)

	                {
	               		  auxPasajero = vec[i];
	               		  vec[i] = vec[j];
	               		  vec[j] = auxPasajero;
	                }

	               else
	               {
	            	  if( strcmp(vec[i].lastName, vec[j].lastName)== 0)
	            	  {
	            		  if(strcmp(tipo[i].descripcion, tipo[j].descripcion) > 0)
	            		  {
	            			  auxPasajero = vec[i];
	            			  vec[i] = vec[j];
	            			  vec[j] = auxPasajero;
	            		  }

	            	  }

	               }
	            }
	        }
	        todoOk = 1;
	    }
	    return todoOk;


}

int sortPassengersByCode(ePassenger vec[], int tam,eEstadoVuelo vuelo[],int tamv)
{
	int todoOk = 0;

	    char descripcion[20];
	    ePassenger aux;

	    if( vec != NULL && tam > 0 && vuelo != NULL && tamv > 0)
	    {
	        cargarDescripcionVuelo(vuelo, tamv, vec->idEstadoVuelo, descripcion);


	        for(int i=0 ; i < tam - 1 ; i++)
	        {
	        	for(int j = i + 1 ; j < tam ; j++)
	        	{
	        		if(stricmp(vec[i].flyCode,vec[j].flyCode) > 0)
	        		{
	        			aux = vec[i];
	        			vec[i] = vec[j];
	        			vec[j] = aux;

	        		}

	        	}
	        }




	    }
	    return todoOk;
}
