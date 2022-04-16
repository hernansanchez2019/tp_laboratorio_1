/*
 * operaciones.h
 *
 *  Created on: 12 abr. 2022
 *      Author: Hernan
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_


#endif /* OPERACIONES_H_ */

/// @brief Cargamos los datos en el programa
///
void cargaDeDatos();


/// @brief Preguntamos que opcion quiere y devuelve el caracter
///
/// @param mensaje Pregunta para el usuario
/// @param minimo opcion minima
/// @param maximo opcion maxima para que quede validado
/// @return retornamos el caracter
char pedirOpcionMenu(char mensaje[],char minimo,char maximo);

/// @brief Realizamos la operacion para realizar el descuento con debito
///
/// @param precio Pasamos el precio del vuelo
/// @return retornamos el precio con el descuento ya hecho
float descuentoDebito(float precio);

/// @brief Realizamos la operacion para realizar el interes con credito
///
/// @param precio Pasamos el precio del vuelo
/// @return retornamos el precio con el interes ya hecho
float interesCredito(float precio);

/// @brief Realizamos la operacion para realizar el valor con Bitcoin
///
/// @param precio Pasamos el precio del vuelo
/// @return retornamos el precio con el interes ya hecho
float costoConBitcoin(float precio);

/// @brief Precio por kilometro
///
/// @param precio Pasamos el precio del vuelo
/// @return Retornamos el precio por kilometro
float precioUnitario(float precio);

/// @brief Calculamos la diferencia de precio entre los vuelos
///
/// @param precioAerolineas Pasamos el precio del vuelo aerolineas
/// @param precioLatam Pasamos el precio del vuelo latam
/// @return Retornamos la diferencia en precio
float diferenciaPrecio(float precioAerolineas,float precioLatam);

/// @brief Mostramos el menu con los resultados que se hardcodearon
///
/// @param kilometros  hardcodeado
/// @param precioAerolineas precio hardcodeado
/// @param precioLatam precio hardcodeado
void menuResultadosForzados(float kilometros,float precioAerolineas,float precioLatam);

/// @brief Mostramos el menu con los resultados
///
/// @param aerolineas Pasamos el precio del vuelo
/// @param latam Pasamos el precio del vuelo
/// @param km Pasamos los kilometros
void informeResultados(float aerolineas, float latam, float km);

/// @brief Mostramos el menu de opciones
///
void menu();

/// @brief Mostramos el menu con los kilometros cargados
///
/// @param km pasamos los kilometros
void menuModificado(float km);

/// @brief Mostramos el menu con los kilometros cargados y el precio de los vuelos
///
/// @param aerolineas Pasamos el precio del vuelo
/// @param latam Pasamos el precio del vuelo
/// @param km Pasamos los kilometros
void menuModificado2(float aerolineas, float latam, float km);
