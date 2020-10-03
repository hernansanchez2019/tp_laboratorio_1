#define LIBRE 0
#define OCUPADO 1
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char nombre[50];
    char apellido[50];
    float salario;
    int sector;
    int estado;
    int id;

} Eempleado;

/** \brief Cargamos empleados
 *
 * \param cliente[] Eempleado  Datos del empleado
 * \param tam int recibe la cantidad de empleados
 * \param indice int recibe el indice de empleados
 * \return void
 *
 */
void CargarEmpleados(Eempleado cliente[], int tam, int indice);


/** \brief Muestra todos los empleados
 *
 * \param cliente[] Eempleado  Datos del empleado
 * \param tam int recibe la cantidad de empleados
 * \return void
 *
 */
void MostrarEmpleados(Eempleado cliente[], int tam);

/** \brief Inicializamos el estado de los empleados
 *
 * \param cliente[] Eempleado Datos del empleado
 * \param tam int recibe la cantidad de empleados
 * \return void
 *
 */
void InicializarEstado(Eempleado cliente[], int tam);

/** \brief Buscamos un lugar libre
 *
 * \param cliente[] Eempleado Datos del empleado
 * \param tam int recibe la cantidad de empleados
 * \return int
 *
 */
int BuscarLibre(Eempleado cliente[], int tam);

/** \brief Damos de baja un empleado
 *
 * \param cliente[] Eempleado Datos del empleado
 * \param tam int recibe la cantidad de empleados
 * \return void
 *
 */
void BajaEmpleado(Eempleado cliente[], int tam);

/** \brief Mostramos el menu del programa
 *
 * \param cliente[] Eempleado Datos del empleado
 * \param tam int recibe la cantidad de empleados
 * \return void
 *
 */
void Menu(Eempleado cliente[], int tam);

/** \brief Ordenamos los clientes por apellido
 *
 * \param cliente[] Eempleado Datos del empleado
 * \param tam int recibe la cantidad de empleados
 * \return void
 *
 */
void OrdenarClientes(Eempleado cliente[], int tam);

/** \brief Calculamos el promedio de todos los salarios
 *
 * \param cliente[] Eempleado Datos del empleado
 * \param tam int recibe la cantidad de empleados
 * \return float Devuelve el promedio de todos los salarios
 *
 */
float calcularPromedioDeSalarios(Eempleado cliente[],int tam);

/** \brief Calculamos la suma de los salarios
 *
 * \param cliente[] Eempleado Datos del empleado
 * \param tam int recibe la cantidad de empleados
 * \return float Devuelve la suma de los salarios
 *
 */
float SumarSalarios(Eempleado cliente[],int tam);

/** \brief Mostramos los salarios, el promedio y el total
 *
 * \param cliente[] Eempleado Datos del empleado
 * \param tam int recibe la cantidad de empleados
 * \return void
 *
 */
void MostrarSalarios(Eempleado cliente[],int tam);

/** \brief Modificamos los datos del cliente
 *
 * \param cliente[] Eempleado  Datos del empleado
 * \param tam int recibe la cantidad de empleados
 * \return void
 *
 */
void Modificar(Eempleado cliente[],int tam);

/** \brief Calculamos la cantidad de clientes que superan el promedio de los salarios
 *
 * \param cliente[] Eempleado Datos del empleado
 * \param tam int recibe la cantidad de empleados
 * \return int devuelve la cantidad de empleados que superan el promedio de los salarios
 *
 */
int PromedioSuperado(Eempleado cliente[],int tam);

/** \brief Verificamos el estado de los empleados, si estan ocupados o libres
 *
 * \param cliente[] Eempleado Datos del empleado
 * \param tam int recibe la cantidad de empleados
 * \return int devuelve 0 , 1 , o sea libre o ocupado.
 *
 */
int EstadosEmpleados(Eempleado cliente[], int tam);

