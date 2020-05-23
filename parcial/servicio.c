#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

void listarServicio(eServicio servicios[], int tamservicio)
{
    system("cls");
    printf("\n***** Listado de servicios *****\n\n");
    printf("     Id       Descripcion         Precio\n");
    for (int i=0; i< tamservicio; i++)
    {
        printf("    %d    %10s            %.2f\n",servicios[i].id, servicios[i].descripcion, servicios[i].precio);
    }
    printf("\n\n");
}


int cargarNombreServicio(char descripcion[20], int idServicio, eServicio servicios[], int tamservicio)
{
    int todoOk=0;
    for (int i =0; i< tamservicio; i++)
    {
        if (servicios[i].id == idServicio)
        {
            strcpy(descripcion, servicios[i].descripcion);
            todoOk =1;
        }
    }
    return todoOk;

}
