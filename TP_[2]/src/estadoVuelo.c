/*
 * estadoVuelo.c
 *
 *  Created on: 6 may. 2022
 *      Author: Hernan
 */

#include "estadoVuelo.h"
#include <string.h>

int cargarDescripcionVuelo(eEstadoVuelo vuelo[], int tam, int id, char desc[])
{

    int todoOk = 0;
    if(vuelo != NULL && tam > 0 && desc != NULL)
    {

         for(int i= 0; i < tam; i++)
         {

            if( vuelo[i].id == id)
            {
                strcpy( desc, vuelo[i].descripcion);
                todoOk = 1;
                break;
            }

         }
    }
    return todoOk;
}
