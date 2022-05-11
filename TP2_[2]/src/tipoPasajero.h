/*
 * tipoPasajero.h
 *
 *  Created on: 6 may. 2022
 *      Author: Hernan
 */

#ifndef TIPOPASAJERO_H_
#define TIPOPASAJERO_H_

typedef struct
{
	int id;
	char descripcion[20];

}eTipoPassenger;

#endif /* TIPOPASAJERO_H_ */

/*brief CARGAMOS LA DESCRIPCION DE LOS PASAJEROS, SI SON TURISTAS, BUSSINES, PRIMERA CLASE
 * \param eTIPOPASAJERO
 * \param tamaño
 * \param id del pasajero
 * \param descripcion
 *return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int cargarDescripcionPasajero(eTipoPassenger tipo[], int tam, int id, char desc[]);

