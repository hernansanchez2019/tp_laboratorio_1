#include "FUNCIONES.h"

/** \brief
 *
 * \param num1 int Le pedimos al usuario el primer numero a calcular
 * \param num2 int Le pedimos al usuario el segundo numero a calcular
 * \return int retornamos el resultado entero de la suma
 *
 */
int suma(int num1, int num2)
{
    int resultado;

    resultado= num1 + num2;

    return resultado;
}

/** \brief
 *
 * \param num1 int Le pedimos al usuario el primer numero a calcular
 * \param num2 int Le pedimos al usuario el segundo numero a calcular
 * \return int retornamos el resultado entero de la resta
 *
 */
int resta(int num1, int num2)

{
    int resultado;

    resultado= num1 - num2;

    return resultado;
}

/** \brief
 *
 * \param num1 int Le pedimos al usuario el primer numero a calcular
 * \param num2 int Le pedimos al usuario el segundo numero a calcular
 * \return int retornamos el resultado entero de la multiplicacion
 *
 */
int producto(int num1, int num2)
{
    int resultado;

    resultado= num1 * num2;

    return resultado;
}

/** \brief
 *
 * \param num1 int Le pedimos al usuario el primer numero a calcular
 * \param num2 int Le pedimos al usuario el segundo numero a calcular
 * \return float retornamos el resultado en decimales de la division
 *
 */
float division(int num1, int num2)
{
    float resultado;

    resultado= (float)num1 / num2;

    return resultado;
}

/** \brief
 *
 * \param num1 int Le pedimos al usuario el primer numero a calcular
 * \return int retornamos el factorial de un numero
 *
 */
int factorial(int num1)

{
    int resultado=1;
    int i;

    for (i=num1; i>0 ; i--)
    {
        //factoriamos variables
        resultado= i * resultado;
    }

    return resultado;

}
