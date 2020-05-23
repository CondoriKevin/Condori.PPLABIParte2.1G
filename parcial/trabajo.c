#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"
#include "servicio.h"
#include "cliente.h"



void inicializarTrabajo(eTrabajo trabajos[], int tamtrabajo)
{
    for (int i =0; i < tamtrabajo; i++)
    {
        trabajos[i].isEmpty = 1;
    }
}

int buscarIndiceLibreTrabajo(eTrabajo trabajos[], int tamtrabajo)
{
    int indiceLibre = -1;
    for (int i =0 ; i< tamtrabajo; i++)
    {
        if (trabajos[i].isEmpty)
        {
            indiceLibre = i;
            break;
        }
    }
    return indiceLibre;
}


int altaTrabajo(int* proxId,eTrabajo trabajos[], eCliente clientes[], int tamcliente,  int tamtrabajo, eAuto autos[], int tamauto, eColor colores[], int tamcolor, eMarca marcas[], int tammarca, eServicio servicios[], int tamservicio)
{
    int idAuto;
    int fechaOk;
    int todoOk = -1;
    int servicioOk;
    int indiceAuto;
    int id;
    int indiceLibre;
    eTrabajo auxTrabajo;

    indiceLibre = buscarIndiceLibreTrabajo(trabajos, tamtrabajo);
    if (indiceLibre == -1)
    {
        printf("No hay lugar para nuevos trabajos. \n");

    }
    else
    {
        id = *proxId;
        auxTrabajo.id = id;

        mostrarAutos(autos, clientes, tamcliente, colores, marcas, tamauto, tamcolor, tammarca);
        printf("Ingrese el del auto a la que quiere asignarle un trabajo. \n");
        scanf("%d",&idAuto);
        indiceAuto = buscarAuto(idAuto, autos, tamauto);

        if (indiceAuto == -1)
        {
            printf("No existe auto con el id ingresado. \n");

        }
        else
        {
            auxTrabajo.idAuto  = idAuto;
            printf("Usted esta a punto de contratar un servicio para el sigueinte auto: \n");
            printf("  Id       Patente   IdMarca    desc Marca   idColor  Desc Color  modelos\n");

            mostrarAuto(autos[indiceAuto], clientes, colores, marcas, tamcliente, tamcolor, tammarca);
            system("pause");
            listarServicio(servicios, tamservicio);

            servicioOk =utn_getNumero(&auxTrabajo.idServicio, "Ingrese el servicio que desea solicitar: ", "Error, debe elegir uno de los servicios listados anteriormente. \n", 20000, 20003, 3);
            if (servicioOk)
            {
                fechaOk = obtenerFecha(&auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);
                while(fechaOk != 1)
                {
                    system("cls");
                    printf("Fecha invalida. \n");
                    fechaOk = obtenerFecha(&auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);
                }
                todoOk = 1;
                auxTrabajo.isEmpty = 0;
                trabajos[indiceLibre] = auxTrabajo;
                system("cls");
                printf("  Id       IdAuto PatenteAuto  IdServicio   NombreServicio  FechaParaElServicio\n");
                mostrarTrabajo(trabajos[indiceLibre], servicios, tamservicio, autos, tamauto);
            }

        }

    }
    return todoOk;

}



void mostrarTrabajo(eTrabajo trabajos, eServicio servicios[], int tamservicio, eAuto autos[], int tamauto)
{
    char patenteAuto [20];
    char nombreServicio [20];

    cargarNombreAuto(patenteAuto, trabajos.idAuto, autos, tamauto);
    cargarNombreServicio(nombreServicio, trabajos.idServicio, servicios, tamservicio);

    printf("\n%d    %d    %10s      %d     %10s    %d/%d/%d   \n", trabajos.id, trabajos.idAuto, patenteAuto, trabajos.idServicio,  nombreServicio, trabajos.fecha.dia, trabajos.fecha.mes, trabajos.fecha.anio);

}
void mostrarTrabajos(eTrabajo trabajos[],int tamtrabajo, eServicio servicios[], int tamservicio, eAuto autos[], int tamautos)
{
    system("cls");
    int hayTrabajo = 0;
    printf("\n***** Listado Trabajos *****\n\n");
    printf("  Id       IdAuto Patene Auto  IdServicio   NombreServicio  Fecha\n");

    for (int i=0; i< tamtrabajo; i++)
    {
        if (trabajos[i].isEmpty == 0)
        {
            mostrarTrabajo(trabajos[i], servicios, tamservicio, autos, tamautos);
            hayTrabajo = 1;
        }
    }

    if ( hayTrabajo == 0)
    {
        printf("\nNo hay trabajos que listar \n");
    }


}


int obtenerModelo(int* diaAux, int * mesAux, int* anioAux)
{

    int dia, mes, anio, fecha_correcta;
    printf("Ingrese Fecha del modelo (dd/mm/aaaa): ");
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

    if ( fecha_correcta )
    {

        *diaAux  = dia;
        *mesAux  = mes;
        *anioAux  = anio;
    }

    return fecha_correcta;
}
