#include "ArrayEmployees.h"
#define CANTIDAD 1000



int main()
{

    Eempleado cliente[CANTIDAD];


    InicializarEstado(cliente,CANTIDAD); // TODOS LOS EMPLEADOS EN 0
    Menu(cliente,CANTIDAD);
    return 0;
}
