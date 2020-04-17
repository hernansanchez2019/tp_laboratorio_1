

/** \brief
 *
 * \param numero1 float Primer parametro a calcular
 * \param numero2 float Segundo parametro a calcular
 * \return float devuelve la suma de los dos parametros
 *
 */
float suma(float numero1,float numero2)
{
    float resultado;

    resultado= numero1+numero2;

    return resultado;
}

/** \brief
 *
 * \param numero1 int Primer parametro a calcular
 * \param numero2 int Segundo parametro a calcular
 * \return int  devuelve la resta de los dos parametros
 *
 */
int resta(int numero1,int numero2)
{
    float resultado;

    resultado= numero1-numero2;

    return resultado;

}
/** \brief
 *
 * \param numero1 int Primer parametro a calcular
 * \param numero2 int Segundo parametro a calcular
 * \return int devuelve la multiplicacion de los parametros
 *
 */
int multiplicacion(int numero1,int numero2)
{
    float resultado;

    resultado= numero1*numero2;

    return resultado;
}
/** \brief
 *
 * \param numero1 int Primer parametro a calcular
 * \param numero2 int Segundo parametro a calcular
 * \return int devuelve la division de los parametros
 *
 */
int division(int numero1,int numero2)
{

    float resultado;

    resultado= numero1/numero2;

    return resultado;

}

/** \brief
 *
 * \param numero1 int le pasamos un parametro
 * \return int nos devuelve el factorial de ese numero
 *
 */
int factorial(int numero1)

{
    int resultado=1;
    int i;

    for (i=numero1; i>0 ; i--)
    {
        //factoriamos variables

        resultado= i * resultado;

    }


    return resultado;


}
