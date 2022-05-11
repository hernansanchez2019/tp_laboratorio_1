/*
 * funcionesPersonales.h
 *
 *  Created on: 6 may. 2022
 *      Author: Hernan
 */

#ifndef FUNCIONESPERSONALES_H_
#define FUNCIONESPERSONALES_H_



/// @fn int getFloat(char[], char[])
/// @brief VALIDAMOS QUE SE INGRESE UN FLOTANTE
///
/// @pre
/// @post
/// @param mensaje
/// @param mensajeErros
/// @return RETORNAMOS EL RESULTADO flotante VALIDADO
int getFloat(char mensaje[],char mensajeErros[]);//que sea un numero flotante


#endif /* FUNCIONESPERSONALES_H_ */


/// @fn void getString(char[], char[], int)
/// @brief VALIDAMOS EL LARGO DE LA CADENA
///
/// @pre
/// @post
/// @param palabra PASAMOS POR VALOR UNA CADENA
/// @param mensaje LE PASAMOS UN MENSAJE
/// @param tamanio EL TAMAÑO QUE QUEREMOS QUE TENGA EL ARRAY
void getString(char palabra[],char mensaje[],int tamanio);


/// @fn int getInt(char[], char[])
/// @brief VALIDAMOS QUE SE INGRESE UN ENTERO
///
/// @pre
/// @post
/// @param mensaje MENSAJE PARA PEDIR ENTERO AL USUARIO
/// @param mensajeErros MENSAJE DE ERROR
/// @return RETORNAMOS EL RESULTADO ENTERO VALIDADO
int getInt(char mensaje[],char mensajeErros[]);


/// @fn int esNumerica(char[])
/// @brief VERIFICAMOS QUE SE ESTAN INGRESANDO NUMEROS
///
/// @pre
/// @post
/// @param auxiliar
/// @return SI DEVUELVE 0 ES POR QUE INGRESO NUMERO, SINO LETRAS.
int esNumerica(char auxiliar[]);




/*/*brief HARDDCODEAMOS ALGUNOS DATOS PARA PROBAR
 * \param estructura pasajeros
 * \param tamaño
 * \param cantidad de elementos
 * \param siguiente id

 *return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok*/
int hardcodearPasajeros(ePassenger vec[], int tam, int cant, int* pNextId);


/*brief MOSTRAMOS UN PASAJERO
 * \param eEPASAJEROS
 * \param ETIPOPASAJEROS
 * \param TAMAÑO TIPO PASAJEROS
 * \param eESTADOVUELO
 * \param tamaño estado vuelo
 */
void mostrarPasajero(ePassenger pasajero,eTipoPassenger tipo[],int tams,eEstadoVuelo vuelo[],int tamv);


/*brief MOSTRAMOS EL MENU DE PASAJEROS
 *
 *return retonamos la opcion elegida por el usuario*/
int menuPasajeros();

/*brief BUSCAMOS UN PASAJERO LIBRE
 * param array pasajeros
 * \param tamaño
 * \param siguiente indice
 *return RETORNA EL PASAJERO LIBRE*/
int buscarLibre(ePassenger vec[], int tam, int* pIndex);


/*brief MOSTRAMOS EL MENU DE MODIFICAR PASAJEROS
 *
 *return retonamos la opcion elegida por el usuario*/
int menuModificarPasajero();



/*brief MODIFICAMOS AL PASAJERP
 *  * \param eEPASAJEROS
 *  \param tamaño pasajeros
 * \param ETIPOPASAJEROS
 * \param TAMAÑO TIPO PASAJEROS
 * \param eESTADOVUELO
 * \param tamaño estado vuelo
 *
 *return retonamos la opcion elegida por el usuario*/
int modificarPasajero(ePassenger vec[], int tam,eTipoPassenger tipo[],int tams,eEstadoVuelo vuelo[],int tamv);


/*brief MOSTRAMOS EL SUB MENU DE INFORMES
 *
 *return retonamos la opcion elegida por el usuario*/

int subMenuInformes();

/*brief INFORMES
 * \param eEPASAJEROS
 *  \param tamaño pasajeros
 * \param ETIPOPASAJEROS
 * \param TAMAÑO TIPO PASAJEROS
 * \param eESTADOVUELO
 * \param tamaño estado vuelo
 */

void informes(ePassenger vec[], int tam,eTipoPassenger tipo[],int tams,eEstadoVuelo vuelo[],int tamv);



/*brief Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio
promedio.
 * \param eEPASAJEROS
 *  \param tamaño pasajeros
 */
int promedioPasajes(ePassenger vec[], int tam);


/*brief Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’
 *  * \param eEPASAJEROS
 * * \param eESTADOVUELO
 * \param tamaño estado vuelo
 */
int listadoCodVueloYestado(ePassenger vec[], int tam,eEstadoVuelo vuelo[],int tamv);
