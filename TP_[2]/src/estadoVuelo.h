/*
 * estadoVuelo.h
 *
 *  Created on: 6 may. 2022
 *      Author: Hernan
 */

#ifndef ESTADOVUELO_H_
#define ESTADOVUELO_H_

typedef struct
{
	int id;
	char descripcion[20];

}eEstadoVuelo;


#endif /* ESTADOVUELO_H_ */

/*brief CARGAMOS LA DESCRIPCION DE LOS VUELOS, SI ESTA ACTIVO O CANCELADO
 * \param eESTADO VUELO
 * \param tamaño
 * \param id del VUELO
 * \param descripcion
 *return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*/
int cargarDescripcionVuelo(eEstadoVuelo vuelo[], int tam, int id, char desc[]);
