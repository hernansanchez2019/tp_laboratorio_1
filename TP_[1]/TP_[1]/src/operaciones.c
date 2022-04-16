/*
 * operaciones.c
 *
 *  Created on: 12 abr. 2022
 *      Author: Hernan
 */

#include "operaciones.h"
#include <stdio.h>
#include <stdlib.h>


void cargaDeDatos()
{


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

}



void informeResultados(float aerolineas, float latam, float km)
{
    float aerolineasDebito;
    float aerolineasCredito;
    float aerolineasBitcoin;
    float precioPorKmAerolinea;

    float latamDebito;
    float latamCredito;
    float latamBitcoin;
    float precioPorKmLatam;

    float diferencia;

    printf("KMs Ingresados: %.0f km\n\n", km);

    printf("Precio Aerolineas: $ %.0f\n", aerolineas);


    aerolineasDebito= descuentoDebito(aerolineas);
    printf("a) Precio con tarjeta de debito: $ %.2f\n", aerolineasDebito );

    aerolineasCredito= interesCredito(aerolineas);
    printf("b) Precio con tarjeta de credito: $ %.2f\n", aerolineasCredito);

    aerolineasBitcoin= costoConBitcoin(aerolineas);
    printf("c) Precio pagando con bitcoin: %f BTC\n", aerolineasBitcoin);

    precioPorKmAerolinea = precioUnitario(aerolineas);
    printf("d) Mostrar precio unitario: $ %.4f\n\n", precioPorKmAerolinea);

    ////////////////////////////////////////////////////////////////////
    printf("Precio Latam: $ %.0f\n", latam);

    latamDebito= descuentoDebito(latam);
    printf("a) Precio con tarjeta de debito: $ %.2f\n", latamDebito );

    latamCredito= interesCredito(latam);
    printf("b) Precio con tarjeta de credito: $ %.2f\n", latamCredito);

    latamBitcoin= costoConBitcoin(latam);
    printf("c) Precio pagando con bitcoin: %f BTC\n", latamBitcoin);

    precioPorKmLatam = precioUnitario(latam);
    printf("d) Mostrar precio unitario: $ %.4f\n\n", precioPorKmLatam);

    diferencia = diferenciaPrecio(aerolineas,latam);
    printf("La diferencia de precio es: $ %.2f\n", diferencia);


}

void menuModificado(float km)
{

    printf("1.  Ingresar Kilometros:( km= %.0f)\n\n", km);
    printf("2.  Ingresar Precio de Vuelos:(Aerolineas = y, Latam = z)\n");
    printf("    - Precio vuelo Aerolineas:\n    - Precio vuelo Latam:\n\n");
    printf("3.  Calcular todos los costos:\n");
    printf("    a) Tarjeta de debito (descuento 10%%)\n");
    printf("    b) Tarjeta de credito (interes 25%%)\n");
    printf("    c) Bitcoin (1 BTC -> 4606954.55 Pesos Argentinos)\n");
    printf("    d) Mostrar precio por km (precio unitario)\n");
    printf("    e) Mostrar diferencia de precio ingresada (Latam - Aerolineas)\n\n");
    printf("4.  Informar Resultados \n ''Latam:\n");
    printf("    a) Precio con tarjeta de debito: r\n");
    printf("    b) Precio con tarjeta de credito: r\n");
    printf("    c) Precio pagando con bitcoin: r\n");
    printf("    d) Precio unitario: r\n");
    printf("    Aerolineas:\n");
    printf("    a) Precio con tarjeta de debito: r\n");
    printf("    b) Precio con tarjeta de credito: r\n");
    printf("    c) Precio pagando con bitcoin: r\n");
    printf("    d) Precio unitario: r\n");
    printf("    La diferencia de precio es: r'' \n\n");
    printf("5.  Carga forzada de datos\n");
    printf("6.  Salir\n");

}

void menuModificado2(float aerolineas, float latam, float km)
{

    printf("1.  Ingresar Kilometros:( km= %.0f)\n\n", km);
    printf("2.  Ingresar Precio de Vuelos:(Aerolineas = %.0f, Latam = %.0f)\n", aerolineas, latam);
    printf("    - Precio vuelo Aerolineas:\n    - Precio vuelo Latam:\n\n");
    printf("3.  Calcular todos los costos:\n");
    printf("    a) Tarjeta de debito (descuento 10%%)\n");
    printf("    b) Tarjeta de credito (interes 25%%)\n");
    printf("    c) Bitcoin (1 BTC -> 4606954.55 Pesos Argentinos)\n");
    printf("    d) Mostrar precio por km (precio unitario)\n");
    printf("    e) Mostrar diferencia de precio ingresada (Latam - Aerolineas)\n\n");
    printf("4.  Informar Resultados \n ''Latam:\n");
    printf("    a) Precio con tarjeta de debito: r\n");
    printf("    b) Precio con tarjeta de credito: r\n");
    printf("    c) Precio pagando con bitcoin: r\n");
    printf("    d) Precio unitario: r\n");
    printf("    Aerolineas:\n");
    printf("    a) Precio con tarjeta de debito: r\n");
    printf("    b) Precio con tarjeta de credito: r\n");
    printf("    c) Precio pagando con bitcoin: r\n");
    printf("    d) Precio unitario: r\n");
    printf("    La diferencia de precio es: r'' \n\n");
    printf("5.  Carga forzada de datos\n");
    printf("6.  Salir\n");


}



void menu()
{
    printf("1.  Ingresar Kilometros:( km=x)\n\n");
    printf("2.  Ingresar Precio de Vuelos:(Aerolineas = y, Latam = z)\n");
    printf("    - Precio vuelo Aerolineas:\n    - Precio vuelo Latam:\n\n");
    printf("3.  Calcular todos los costos:\n");
    printf("    a) Tarjeta de debito (descuento 10%%)\n");
    printf("    b) Tarjeta de credito (interes 25%%)\n");
    printf("    c) Bitcoin (1 BTC -> 4606954.55 Pesos Argentinos)\n");
    printf("    d) Mostrar precio por km (precio unitario)\n");
    printf("    e) Mostrar diferencia de precio ingresada (Latam - Aerolineas)\n\n");
    printf("4.  Informar Resultados \n ''Latam:\n");
    printf("    a) Precio con tarjeta de debito: r\n");
    printf("    b) Precio con tarjeta de credito: r\n");
    printf("    c) Precio pagando con bitcoin: r\n");
    printf("    d) Precio unitario: r\n");
    printf("    Aerolineas:\n");
    printf("    a) Precio con tarjeta de debito: r\n");
    printf("    b) Precio con tarjeta de credito: r\n");
    printf("    c) Precio pagando con bitcoin: r\n");
    printf("    d) Precio unitario: r\n");
    printf("    La diferencia de precio es: r'' \n\n");
    printf("5.  Carga forzada de datos\n");
    printf("6.  Salir\n");

}


float descuentoDebito(float precio)
{

    float resultadoDescuesto;
    float descuesto;

    descuesto = precio * 0.10;
    resultadoDescuesto = precio - descuesto;

    return resultadoDescuesto;

}


float interesCredito(float precio)
{

    float resultadoInteres;
    float interes;

    interes = precio * 0.25;
    resultadoInteres = precio + interes;

    return resultadoInteres;

}


float costoConBitcoin(float precio)
{

    float precioBitcoin;


    precioBitcoin = (precio * 1 ) / 4606954.55;


    return precioBitcoin;


}


void menuResultadosForzados(float kilometros,float precioAerolineas,float precioLatam)
{

    float aerolineasDebito;
    float aerolineasCredito;
    float aerolineasBitcoin;
    float precioPorKmAerolinea;

    float latamDebito;
    float latamCredito;
    float latamBitcoin;
    float precioPorKmLatam;

    float diferencia;


    printf("KMs Ingresados: %.0f km\n\n", kilometros);

    printf("Precio Aerolineas: $ %.0f\n", precioAerolineas);


    aerolineasDebito= descuentoDebito(precioAerolineas);
    printf("a) Precio con tarjeta de debito: $ %.2f\n", aerolineasDebito );

    aerolineasCredito= interesCredito(precioAerolineas);
    printf("b) Precio con tarjeta de credito: $ %.2f\n", aerolineasCredito);

    aerolineasBitcoin= costoConBitcoin(precioAerolineas);
    printf("c) Precio pagando con bitcoin: %f BTC\n", aerolineasBitcoin);

    precioPorKmAerolinea = precioUnitario(precioAerolineas);
    printf("d) Mostrar precio unitario: $ %.2f\n\n", precioPorKmAerolinea);

    ////////////////////////////////////////////////////////////////////
    printf("Precio Latam: $ %.0f\n", precioLatam);

    latamDebito= descuentoDebito(precioLatam);
    printf("a) Precio con tarjeta de debito: $ %.2f\n", latamDebito );

    latamCredito= interesCredito(precioLatam);
    printf("b) Precio con tarjeta de credito: $ %.2f\n", latamCredito);

    latamBitcoin= costoConBitcoin(precioLatam);
    printf("c) Precio pagando con bitcoin: %f BTC\n", latamBitcoin);

    precioPorKmLatam = precioUnitario(precioLatam);
    printf("d) Mostrar precio unitario: $ %.2f\n\n", precioPorKmLatam);

    diferencia = diferenciaPrecio(precioAerolineas,precioLatam);
    printf("La diferencia de precio es: $ %.2f\n", diferencia);



}


float precioUnitario(float precio)
{

    float resultadoUnitario;

    resultadoUnitario = precio / 7090;

    return resultadoUnitario;

}


float diferenciaPrecio(float precioAerolineas,float precioLatam)
{
    float diferencia;

    diferencia= precioAerolineas - precioLatam ;

    return diferencia;

}


char pedirOpcionMenu(char mensaje[],char minimo,char maximo)
{

    char opcion;

    printf("%s %c y %c : ",mensaje,minimo,maximo);
    fflush(stdin);
    scanf("%c",&opcion);

    while(opcion < '1' || opcion > '6')
    {
        printf("Error...%s %c y %c : ",mensaje,minimo,maximo);
        fflush(stdin);
        scanf("%c",&opcion);
    }

    return opcion;
}
