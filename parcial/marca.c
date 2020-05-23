#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "marca.h"


int cargarDescripcionMarca(char descripcion[], int idMarca, eMarca marcas[], int tammarca)
{
    int todoOk=0;
    for (int i =0; i< tammarca; i++)
    {
        if (marcas[i].id == idMarca)
        {
            strcpy(descripcion, marcas[i].descripcion);
            todoOk =1;
        }
    }
    return todoOk;

}

void listarMarca(eMarca marcas[], int tammarca)
{
    system("cls");
    printf("\n***** Listado de Marcas *****\n\n");
    printf("     Id       Descripcion Marcas\n");
    for (int i=0; i< tammarca; i++)
    {
        printf("    %d    %10s\n",marcas[i].id, marcas[i].descripcion);
    }
    printf("\n\n");
}
