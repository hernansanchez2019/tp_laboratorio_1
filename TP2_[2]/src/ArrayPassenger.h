/*
 * ArrayPassenger.h
 *
 *  Created on: 6 may. 2022
 *      Author: Hernan
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include "tipoPasajero.h"
#include "estadoVuelo.h"

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
	int idTipoPassenger;
	int idEstadoVuelo;

}ePassenger;

#endif /* ARRAYPASSENGER_H_ */

/** \brief Imprime el array de pasajeros de forma encolumnada.
*
* \param list Passenger*
* \param tamaño pasajeros
* \param EtipoPAsajeros
* \param tamaño tipo pasajeros
* \param eESTadoVuelo
* \param tamaño vuelo int
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int printPassengers(ePassenger vec[], int tam,eTipoPassenger tipo[],int tams,eEstadoVuelo vuelo[],int tamv);


/** \brief Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
(isEmpty) en TRUE en todas las posiciones del array.
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(ePassenger vec[], int tam);

/** \briefAgrega en un array de pasajeros existente los valores recibidos como parámetro en la primer
posición libre.
* \param list passenger*
* \param len int
*\param siguiente indice
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok*/
int addPassengers(ePassenger vec[], int tam, int* pNextId);

/** \brief Busca un pasajero recibiendo como parámetro de búsqueda su Id.
*
* \param list Passenger*
* \param len int
* \param id int
* * \param indice int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*/
int findPassengerById(ePassenger vec[], int tam, int id, int* pIndex);



/** \brief Elimina de manera lógica (isEmpty Flag en 1) un pasajero recibiendo como parámetro su Id.
*
* \param list Passenger*
* \param len int
* \param EtipoPasajero
*  \param len int
* \param eEstadoVuelo
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok

*/
int removePassenger(ePassenger vec[], int tam,eTipoPassenger tipo[],int tams,eEstadoVuelo vuelo[],int tamv);

/** \brief Ordena el array de pasajeros por apellido y tipo de pasajero de manera ascendente o
descendente.
*
* \param list Passenger*
* \param len int
* \param EtipoPasajero
* \param tamaño
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int sortPassengers(ePassenger vec[],int tam,eTipoPassenger tipo[],int tams);


/** \brief Ordena el array de pasajeros por código de vuelo y estado de vuelo de manera ascendente o
descendente.
*
* \param list Passenger*
* \param len int
* \param estadoVuelo
* \param tamaño vuelos
* * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByCode(ePassenger vec[], int tam,eEstadoVuelo vuelo[],int tamv);


