#include "ArrayEmployees.h"


void CargarEmpleados(Eempleado cliente[], int tam, int indice) // CARGAMOS UN EMPLEADO DE A UNO
{
    int lugarLibre;

    lugarLibre= BuscarLibre(cliente,tam);

    if(lugarLibre==-1)
    {
        printf("\nNo hay mas espacio\n");
    }
    else
    {
        printf("Ingresar nombre: ");
        fflush(stdin);
        gets(cliente[lugarLibre].nombre);

        printf("Ingresar apellido: ");
        fflush(stdin);
        gets(cliente[lugarLibre].apellido);

        printf("Ingresar salario: ");
        scanf("%f",&cliente[lugarLibre].salario);

        printf("Ingresar sector: ");
        scanf("%d",&cliente[lugarLibre].sector);

        printf("Cliente cargado con exito !!!\n");

        cliente[lugarLibre].id= indice;


        cliente[lugarLibre].estado=OCUPADO; // CLIENTE OCUPADO

    }

}

void BajaEmpleado(Eempleado cliente[], int tam)
{
    int i;
    int indiceBaja;
    MostrarEmpleados(cliente,tam);
    printf("Escriba el ID del empleado para la baja: \n");
    scanf("%d",&indiceBaja);


    for(i=0; i<tam ; i++)
    {
        if(indiceBaja== cliente[i].id)
        {
            cliente[i].estado=LIBRE;
        }

    }

}



void MostrarEmpleados(Eempleado cliente[], int tam)
{
    int i;

    printf("\nId\t  Nombre:\t Apellido:\t Salario:\t Sector:");
    for(i=0; i<tam; i++)
    {
        if(cliente[i].estado==OCUPADO) // MUESTRA SOLO LOS QUE ESTAN OCUPADOS
        {
            printf("\n%d  %10s\t / %10s\t  / %10.2f\t  /  %10d\t\n\n ",cliente[i].id,cliente[i].nombre,cliente[i].apellido,cliente[i].salario,cliente[i].sector);

        }


    }


}


void InicializarEstado(Eempleado cliente[], int tam)
{
    int i;

    for(i=0; i< tam ; i++)
    {
        cliente[i].estado=LIBRE; // CLIENTE INICIALIZADO EN I = CERO
    }

}

int BuscarLibre(Eempleado cliente[], int tam)
{


    int indice=-1; // el -1 representa el indice
    int i;


    for(i=0; i<tam; i++)// RECORREMOS EL VECTOR
    {

        if(cliente[i].estado==LIBRE)// CUANDO ESTA LIBRE ENTRA
        {
            indice=i;
            break; // cuando se cumple la condicion se queda con ese indice y el break corta ahi
        }

    }

    return indice; // DEVUELVE ESE LUGAR LIBRE 0, -1

}



void Menu(Eempleado cliente[], int tam)
{
    int opcion;
    int opcion2;
    int indice=100;

    do
    {
        system("cls");
        printf("\t\t ****** A --- B --- M --- ****** \t\t\n");



        printf("\n1- Alta            --> Ingreso de cliente ");
        printf("\n2- Baja            --> Baja de cliente ");
        printf("\n3- Modificar       --> Modificar cliente ");
        printf("\n4- Mostrar Listado --> clientes ");
        printf("\n5- Salir           --> Finalizar programa ");
        printf("\nIngrese una opcion --> 1/2/3/4/5 = ");
        scanf("%d",&opcion);

        // VALIDAMOS PARA OPCION PARA QUE EL USUARIO NO INGRESE LETRAS NI NUMEROS MENORES A 1 , NI MAYORES A 5

       while(opcion < 1 || opcion > 5)
        {
            printf("\nError...Reingrese opcion 1/2/3/4/5 --> ");
            fflush(stdin);
            scanf("%d", &opcion);
        }


        switch (opcion)
        {
        case 1:
            CargarEmpleados(cliente,tam, indice); // CUANDO ESTOY EN EL MAIN PASO SOLO EL NOMBRE DEL ARRAY Y EL TAMAÑO
            indice++;
            break;

        case 2:
            if(EstadosEmpleados(cliente,tam)==OCUPADO)
            {
                BajaEmpleado(cliente, tam);
            }
            else
            {
                printf("\nNo hay Empleados\n");
            }

            break;

        case 3:
            if(EstadosEmpleados(cliente,tam)==OCUPADO)
            {
                Modificar(cliente,tam);
            }
            else
            {
                printf("\nNo hay Empleados\n");
            }

            break;

        case 4: // SEGUNDO MENU

            if(EstadosEmpleados(cliente,tam)==OCUPADO)
            {

                do
                {
                    system("pause");
                    system("cls");

                    printf("\n1- Listado de los empleados");
                    printf("\n2- Total y promedio de los salarios");
                    printf("\n3- Volver al Menu Principal");
                    printf("\nIngrese una opcion --> 1/2/3 = ");
                    scanf("%d",&opcion2);

                    switch(opcion2)
                    {
                    case 1:
                        OrdenarClientes(cliente,tam);
                        MostrarEmpleados(cliente,tam);
                        break;

                    case 2:
                        MostrarSalarios(cliente,tam);
                        break;
                    case 3:
                        printf("Usted esta volviendo al Menu Principal");
                        break;
                    }

                }
                while(opcion2!=3);


            }
            else
            {
                printf("\nNo hay Empleados\n");
            }
            break;

        case 5:
            printf(" ***Programa finalizado***\n");
            break;
        }
        system("pause");
        system("cls");

    }
    while(opcion!=5);
}

void OrdenarClientes(Eempleado cliente[], int tam)
{
    int i;
    int j;
    Eempleado auxCliente;

    for(i=0 ; i<tam-1 ; i++)// TIENE QUE RECORRER HASTA EL ANTE ULTIMO, I <TAM-1
    {
        for(j=i+1 ; j<tam ; j++)// RECORRE HASTA EL FINAL, I+1 PARA COMPARAR CON EL SIGUIENTE DE I
        {
            if(strcmp(cliente[i].apellido,cliente[j].apellido) > 0)
            {
                auxCliente=cliente[i];         //PRIMERO DESTINO,Y DESPUES ORIGEN
                cliente[i]=cliente[j];
                cliente[j]=auxCliente;

            }
        }
    }
}

float calcularPromedioDeSalarios(Eempleado cliente[],int tam)  // promedio , sumas
{

    int i;
    int suma=0; // es acumulador por eso se inicializa en 0
    float promedio;
    int contadorDeSalarios=0;

    for(i=0; i<tam; i++)
    {

        // suma los numeros cargados y no la basura(-1)

        if(cliente[i].salario!=OCUPADO)
        {
            suma=suma + cliente[i].salario; // suma el contenido del vector, seria 0 + lo que este cargado
            contadorDeSalarios++;
        }
    }

    promedio= (float)suma/contadorDeSalarios;

    return promedio;

}

void MostrarSalarios(Eempleado cliente[],int tam)
{

    float promedio;
    float suma;
    int contadorEmpleados;

    printf("\t***SALARIOS***\n");
    printf("Total:\t Promedio: \t Cantidad de Empleados que superan promedio\n");

    promedio= calcularPromedioDeSalarios(cliente,tam);
    suma= SumarSalarios(cliente, tam);
    contadorEmpleados= PromedioSuperado(cliente,tam);
    printf("%3.f\t%3.f\t %d ",suma,promedio,contadorEmpleados);


}

float SumarSalarios(Eempleado cliente[],int tam)
{

    int i;
    int suma=0; // es acumulador por eso se inicializa en 0

    for(i=0; i<tam; i++)
    {

        // suma los numeros cargados y no la basura(-1)

        if(cliente[i].salario!=OCUPADO)
        {
            suma=suma + cliente[i].salario; // suma el contenido del vector, seria 0 + lo que este cargado

        }
    }

    return suma;

}

void Modificar(Eempleado cliente[],int tam)
{

    int id;
    int opcion;
    char respuesta;
    char auxNombre[20];
    char auxApellido[20];
    float auxSalario;
    int auxSector;
    int i;


    MostrarEmpleados(cliente,tam);
    printf("\nIngrese el Id a Modificar");
    scanf("%d",&id);

    for(i=0; i<tam ; i++)
    {
        if(id== cliente[i].id && cliente[i].estado==OCUPADO)//  FILTRAMOS POR ESTADO PARA SABER SI ESTA DADO DE ALTA
        {
            do      // MENU DE MODIFICACIONES
            {
                printf("\n1- Modificar Nombre");
                printf("\n2- Modificar Apellido");
                printf("\n3- Modificar Salario");
                printf("\n4- Modificar Sector");
                printf("\n5- Volver al Menu Principal");
                printf("\nIngrese una opcion: 1/2/3/4/5");
                scanf("%d",&opcion);

                switch(opcion)
                {
                case 1:
                    printf("\nIngrese el Nuevo Nombre: ");
                    fflush(stdin);
                    gets(auxNombre);
                    printf("\nEl nuevo Nombre es : %s",auxNombre);
                    printf("\nEsta seguro que desea realizar el cambio? s/n: ");
                    fflush(stdin);
                    scanf("%c",&respuesta);

                    if(respuesta=='s')
                    {
                        strcpy(cliente[i].nombre,auxNombre);
                        printf("\nCambio Realizado con Exito !!!");

                    }
                    else
                    {
                        printf("\nOperacion Cancelada!!!");
                    }
                    break;

                case 2:
                    printf("\nIngrese el Nuevo Apellido: ");
                    fflush(stdin);
                    gets(auxApellido);
                    printf("\nEl nuevo Apellido es : %s",auxApellido);
                    printf("\nEsta seguro que desea realizar el cambio? s/n: ");
                    fflush(stdin);
                    scanf("%c",&respuesta);

                    if(respuesta=='s')
                    {
                        strcpy(cliente[i].apellido,auxApellido);
                        printf("\nCambio Realizado con Exito !!!");

                    }
                    else
                    {
                        printf("\nOperacion Cancelada!!!");
                    }
                    break;

                case 3:
                    printf("\nIngrese el Nuevo Salario: ");
                    scanf("%f",&auxSalario);

                    printf("\nEl nuevo Salario es : %f",auxSalario);
                    printf("\nEsta seguro que desea realizar el cambio? s/n: ");
                    fflush(stdin);
                    scanf("%c",&respuesta);

                    if(respuesta=='s')
                    {
                        cliente[i].salario= auxSalario;
                        printf("\nCambio Realizado con Exito !!!");

                    }
                    else
                    {
                        printf("\nOperacion Cancelada!!!");
                    }
                    break;

                case 4:
                    printf("\nIngrese el Nuevo Sector: ");
                    scanf("%d",&auxSector);
                    printf("\nEl nuevo Sector es : %d",auxSector);
                    printf("\nEsta seguro que desea realizar el cambio? s/n: ");
                    fflush(stdin);
                    scanf("%c",&respuesta);

                    if(respuesta=='s')
                    {
                        cliente[i].sector=auxSector;
                        printf("\nCambio Realizado con Exito !!!");

                    }
                    else
                    {
                        printf("\nOperacion Cancelada!!!");
                    }
                    break;
                }
            }
            while(opcion!=5);
        }

    }

}


int PromedioSuperado(Eempleado cliente[],int tam)
{
    float promedio;
    int i;
    int contadorEmpleados=0;

    promedio=calcularPromedioDeSalarios(cliente,tam);

    for(i=0 ; i< tam ; i++)
    {
        if(cliente[i].salario > promedio && cliente[i].estado==OCUPADO) // SIEMPRE FILTRAMOS POR ESTADO
        {
            contadorEmpleados++;
        }
    }

    return contadorEmpleados;

}

int EstadosEmpleados(Eempleado cliente[], int tam)
{
    int i;
    int estado= LIBRE;


    for(i=0; i<tam; i++)
    {
        if(cliente[i].estado==OCUPADO) // MUESTRA SOLO LOS QUE ESTAN OCUPADOS
        {
            estado=OCUPADO;
            break; // EL PRIMERO QUE BUSCA, CORTA
        }


    }

    return estado;

}





