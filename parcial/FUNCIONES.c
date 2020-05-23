#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"
#include "auto.h"
#include "cliente.h"



////////////////////////////*************************************////////////////////////////
/*void mostrarAuto(eAuto autos, eCliente clientes[], eColor colores[], eMarca marcas[], int tamcliente, int tamcolor, int tammarca)
{

    char descripcionColor [20];
    char descripcionMarca[20];
    char nombreCliente[20];

    cargarDescripcionColor(descripcionColor, autos.idColor, colores,  tamcolor);
    cargarDescripcionMarca(descripcionMarca, autos.idMarca, marcas, tammarca);
    cargarDescripcionCliente(nombreCliente, autos.idCliente, clientes, tamcliente);

    printf("%d   %10s      %d    %10s    %d  %10s   %d %10s       %d/%d/%d \n",autos.idCliente,nombreCliente,  autos.id, autos.patente, autos.idMarca, descripcionMarca, autos.idColor, descripcionColor, autos.modelo.dia,autos.modelo.mes,autos.modelo.anio);

}*/

void MostrarAutoPorColor(eAuto autos[],eCliente clientes[], int tamcliente, eColor colores[], eMarca marcas[],int tamauto, int tamcolor, int tammarca)
{
    //eAuto auxAuto;
    int idAuxColor;
    int hayColor = 0;
    system("cls");
    printf("**** Listado autos POR COLOR****\n\n");
    listarColores(colores, tamcolor);

    utn_getNumero(&idAuxColor, "Ingrese id del color elegico: [Entre...5000 - 5004]\n", "Error. El color debe ser uno de los mostrados en la pantalla.", 5000, 5004, 3);


    printf("IdCliente    NombreCliente    idauto  Patente    id marca     marca    id color     color    modelo\n");

    for (int i=0; i< tamauto; i++)
    {
        if (autos[i].isEmpty == 0 && autos[i].idColor== idAuxColor)
        {

            mostrarAuto(autos[i], clientes, colores, marcas,tamcliente,tamcolor,tammarca );
            hayColor = 1;
        }
    }
    if ( hayColor == 0)
    {
        printf("\nNo hay autos con ese color. \n");
    }


}

void MostrarAutoMarca(eAuto autos[],eCliente clientes[], int tamcliente, eColor colores[], eMarca marcas[],int tamauto, int tamcolor, int tammarca)
{
    //eAuto auxAuto;
    int idAuxMarca;
    int hayMarca = 0;
    system("cls");
    printf("**** Listado autos POR Marca****\n\n");
    listarMarca(marcas, tammarca);

    utn_getNumero(&idAuxMarca, "Ingrese marca: ", "\nError, debe estar comprendido entre 1000 y 1004. \n", 1000, 1004, 3);


    printf("IdCliente    NombreCliente    idauto  Patente    id marca     MARCA    id color     color    modelo\n");

    for (int i=0; i< tamauto; i++)
    {
        if (autos[i].isEmpty == 0 && autos[i].idMarca== idAuxMarca)
        {

            mostrarAuto(autos[i], clientes, colores, marcas,tamcliente,tamcolor,tammarca );
            hayMarca = 1;
        }
    }
    if ( hayMarca == 0)
    {
        printf("\nNo hay autos con esa MARCA. \n");
    }


}

void MostrarSeparadorMarca(eAuto autos[],eCliente clientes[], int tamcliente, eColor colores[], eMarca marcas[],int tamauto, int tamcolor, int tammarca)
{

    eAuto auxAuto;
    for (int i = 0; i< tamauto-1; i++)
    {
        for (int j= i+1;  j< tamauto;  j++)
        {
            if (autos[i].idMarca > autos[j].idMarca)

            {
                auxAuto = autos[i];
                autos[i] = autos[j];
                autos[j] = auxAuto;
            }
        }
    }
}

void MostrarPorMarcayColor(eAuto autos[],eCliente clientes[], int tamcliente, eColor colores[], eMarca marcas[],int tamauto, int tamcolor, int tammarca){

int hayCombinacion =0;
int idAuxColor;
int idAuxMarca;
int contador =0;
    int hayColor = 0;
    system("cls");
    printf("**** Listado autos POR COLOR y MARCA****\n\n");
    listarColores(colores, tamcolor);


    utn_getNumero(&idAuxColor, "Ingrese id del color elegico: [Entre...5000 - 5004]\n", "Error. El color debe ser uno de los mostrados en la pantalla.", 5000, 5004, 3);
  listarMarca(marcas, tammarca);
utn_getNumero(&idAuxMarca, "Ingrese marca: ", "\nError, debe estar comprendido entre 1000 y 1004. \n", 1000, 1004, 3);

    printf("IdCliente    NombreCliente    idauto  Patente    id marca     marca    id color     color    modelo\n");

    for (int i=0; i< tamauto; i++)
    {
        if (autos[i].isEmpty == 0 && autos[i].idColor== idAuxColor && autos[i].idMarca== idAuxMarca)
        {

            mostrarAuto(autos[i], clientes, colores, marcas,tamcliente,tamcolor,tammarca );
            contador = contador + 1;
        }
    }
    if ( hayCombinacion == 0)
    {
        printf("\nNo hay autos con ese color y esa marca. \n");
    }

printf ("Hay %d con ese color y esa marca", contador);


}
