/*
 * operaciones.h
 *
 *  Created on: 12 abr. 2022
 *      Author: Hernan
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_


#endif /* OPERACIONES_H_ */


char pedirOpcionMenu(char mensaje[],char minimo,char maximo);
float descuentoDebito(float precio);
float interesCredito(float precio);
float costoConBitcoin(float precio);
float precioUnitario(float precio);
float diferenciaPrecio(float precioAerolineas,float precioLatam);
void menuResultadosForzados(float kilometros,float precioAerolineas,float precioLatam);
void informeResultados(float aerolineas, float latam, float km);
void menu();
void menuModificado(float km);
void menuModificado2(float aerolineas, float latam, float km);
