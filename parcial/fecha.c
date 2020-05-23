#include <stdio.h>
#include <stdlib.h>
#include "fecha.h"

int obtenerFecha(int* diaAux, int * mesAux, int* anioAux)
{

    int dia, mes, anio, fecha_correcta;
    printf("Ingrese fecha: ");
    scanf("%d/%d/%d", &dia, &mes, &anio);

    fecha_correcta = 0;

    if ( mes >= 1 && mes <= 12 )
    {
        switch ( mes )
        {
        case  1 :
        case  3 :
        case  5 :
        case  7 :
        case  8 :
        case 10 :
        case 12 :
            if ( dia >= 1 && dia <= 31 )
                fecha_correcta = 1;
            break;

        case  4 :
        case  6 :
        case  9 :
        case 11 :
            if ( dia >= 1 && dia <= 30 )
                fecha_correcta = 1;
            break;

        case  2 :
            if ( (anio % 4 == 0 && anio % 100 != 0)|| anio % 400 == 0 )
            {
                if ( dia >= 1 && dia <= 29 )
                    fecha_correcta = 1;
            }
            else if ( dia >= 1 && dia <= 28 )
                fecha_correcta = 1;
        }
    }

    /* Llegados a este punto, según el valor de fecha_correcta,
       por pantalla se mostrará un mensaje u otro. */

    if ( fecha_correcta )
    {

        *diaAux  = dia;
        *mesAux  = mes;
        *anioAux  = anio;
    }

    return fecha_correcta;
}


