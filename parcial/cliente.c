#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "auto.h"
#include "color.h"
#include "marca.h"




void listarCliente(eCliente clientes[], int tamcliente)
{
    system("cls");
    printf("\n***** Listado de clientes *****\n\n");
    printf("     Id       Descripcion         Sexo\n");
    for (int i=0; i< tamcliente; i++)
    {
        printf("    %d    %10s            %c\n",clientes[i].id, clientes[i].nombre, clientes[i].sexo);
    }
    printf("\n\n");
}


int cargarDescripcionCliente(char nombre[20], int idCliente, eCliente clientes[], int tamcliente)
{
    int todoOk=0;
    for (int i =0; i< tamcliente; i++)
    {
        if (clientes[i].id == idCliente)
        {
            strcpy(nombre, clientes[i].nombre);
            todoOk =1;
        }
    }
    return todoOk;

}

void mostrarClientes(eAuto autos[],eCliente clientes[], int tamcliente, eColor colores[], eMarca marcas[],int tamauto, int tamcolor, int tammarca)
{
    system("cls");
    int hayAutos = 0;
    printf("\n***** Listado CLIENTES *****\n\n");
    printf("  NombresCliente      Pantente   Marca   Color     Modelo\n");

    for (int i=0; i< tamauto; i++)
    {
        if (autos[i].isEmpty == 0)
        {
            mostrarAuto(autos[i], clientes, colores, marcas, tamcliente, tamcolor, tammarca);

            hayAutos = 1;
        }
    }

    if ( hayAutos == 0)
    {
        printf("\nNo hay Autos que listar \n");
    }

}

void mostrarCliente(eAuto autos, eCliente clientes[], eColor colores[], eMarca marcas[], int tamcliente, int tamcolor, int tammarca)
{

    char descripcionColor [20];
    char descripcionMarca[20];
    char nombreCliente[20];

    cargarDescripcionColor(descripcionColor, autos.idColor, colores,  tamcolor);
    cargarDescripcionMarca(descripcionMarca, autos.idMarca, marcas, tammarca);
    cargarDescripcionCliente(nombreCliente, autos.idCliente, clientes, tamcliente);

    printf(" %10s       %10s    %10s   %10s       %d/%d/%d \n",nombreCliente, autos.patente, descripcionMarca,  descripcionColor, autos.modelo.dia,autos.modelo.mes,autos.modelo.anio);

}
