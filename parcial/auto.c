#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "auto.h"
#include "datawarehouse.h"
#include "cliente.h"

char menu()
{
    char opcion;

    system("cls");
    printf("**** Gestion de Autos **** \n\n");
    printf("A.  Alta Autos. \n");
    printf("B.  Modificar Autos. \n");
    printf("C.  Baja Autos.\n");
    printf("D.  Listar Autos.\n");
    printf("E.  Listar marcas.\n");
    printf("F.  Listar colores.\n");
    printf("G.  Listar servicios.\n");
    printf("H.  Alta trabajo\n");
    printf("I.  Listar trabajos\n");
    printf("J.  Listar Clientes con Sus Autos\n");
    printf("K.  MOSTRAR AUTOS POR COLOR\n");
    printf("L.  MOSTRAR AUTOS POR MARCA\n");
    printf("O.  MOSTRAR AUTOS SEPARADOS X MARCA\n");
    printf("P.  MOSTRAR AUTOS POR MARCA Y COLOR\n");
    printf("Q.  Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);

    return tolower(opcion);

}

void inicializarAuto(eAuto autos[], int tamauto)
{
    for (int i =0; i < tamauto; i++)
    {
        autos[i].isEmpty = 1;
    }
}

void hardcodearAuto(eAuto autos[], int tamauto)
{
    for(int i = 0; i < tamauto; i++)
    {

        int idsAutos[] = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
        char patentes[][20] = {"XCVFSD", "CDDSUI", "WAGEQL", "YJKUER", "UKLLGY", "CFSELO", "ZSERMJ", "ZASSPA", "MAGTPA", "MZMJKI"};
        int idsMarcas[] =  { 1000, 1001, 1002, 1003, 1002, 1003, 1001, 1005, 1003, 1002};
        int idsColores[] = { 5000, 5001, 5002, 5003, 5004, 5001, 5003, 5002, 5001, 5005};
        int idsClientes [] = { 200, 201, 202, 203, 204, 205, 206, 207, 208, 209};
        eFechaa modelos[]  =
        {
            { 02, 03, 2000},
            { 01, 10, 2001},
            { 20, 01, 2004},
            { 15, 11, 2004},
            { 30, 12, 2001}
        };
        autos[i].idCliente = idsClientes [i];
        autos[i].id = idsAutos[i];
        strcpy(autos[i].patente, patentes[i]);
        autos[i].idMarca = idsMarcas[i];
        autos[i].idColor = idsColores[i];
        autos[i].modelo.dia = modelos[i].dia;
        autos[i].modelo.mes = modelos[i].mes;
        autos[i].modelo.anio = modelos[i].anio;
        autos[i].isEmpty = 0;

    }
}


int buscarIndiceLibreAuto(eAuto autos[], int tamauto)
{
    int indiceLibre = -1;
    for (int i =0 ; i< tamauto; i++)
    {
        if (autos[i].isEmpty)
        {
            indiceLibre = i;
            break;
        }
    }
    return indiceLibre;
}

int altaAuto(int* proxId, eAuto autos[], eCliente clientes[], int tamcliente, int tamauto, eColor colores[], int tamcolor, eMarca marcas[], int tammarca)
{
    int indice = buscarIndiceLibreAuto(autos, tamauto);
    eAuto auxAuto;
    int todoOk =-1;
    int patenteOk;
    int marcaOk;
    int modeloOk;
    int clienteOk;
    int colorOk;
    int id;

    system("cls");

    printf("***** Alta Auto ***** \n \n");

    if( indice == -1 )
    {
        printf("Sistema completo. No hay lugar para nuevos ingresos. \n\n");

    }
    else
    {

        id = *proxId;
        auxAuto.id = id;

        patenteOk = utn_getPatente(auxAuto.patente, 7, "Ingrese Patente(Combinacion de 6 letras): ", "\nError, la patente debe contener 6 letras(solo letras).\n", 3);

        listarCliente(clientes, tamcliente);
        clienteOk = utn_getNumero(&auxAuto.idCliente, "Ingrese id cliente: ", "\nError, debe estar comprendido entre 200 y 204. \n", 200, 2004, 3);

        listarMarca(marcas, tammarca);
        marcaOk = utn_getNumero(&auxAuto.idMarca, "Ingrese marca: ", "\nError, debe estar comprendido entre 1000 y 1004. \n", 1000, 1004, 3);

        listarColores(colores, tamcolor);
        colorOk = utn_getNumero(&auxAuto.idColor, "Ingrese color : ", "\n Error, el id de color debe estar comprendido entre 5000 y 5004\n", 5000, 5004, 3);

        modeloOk = obtenerModelo(&auxAuto.modelo.dia, &auxAuto.modelo.mes, &auxAuto.modelo.anio);
        while(modeloOk != 1)
        {
            system("cls");
            printf("Modelo invalido (dd/mm/aaaa). \n");
            modeloOk = obtenerModelo(&auxAuto.modelo.dia, &auxAuto.modelo.mes, &auxAuto.modelo.anio);
        }

        auxAuto.isEmpty = 0;

        if (patenteOk && clienteOk && marcaOk && colorOk && modeloOk )
        {
            autos[indice] = auxAuto;
            system("cls");
            printf(" Id cliente   nombreCliente     Idauto    Patente    Id marca    Desc.Marca  Id Color  Color     Modelo\n");

            mostrarAuto(autos[indice],clientes , colores, marcas, tamcliente, tamcolor, tammarca);
            (*proxId)++;
            todoOk =1;
        }
        else
        {
            printf("Surgieron problemas durante el alta del auto. Por favor intentelo de nuevo.\n");
        }


    }
    return todoOk;
}





void mostrarAuto(eAuto autos, eCliente clientes[], eColor colores[], eMarca marcas[], int tamcliente, int tamcolor, int tammarca)
{

    char descripcionColor [20];
    char descripcionMarca[20];
    char nombreCliente[20];

    cargarDescripcionColor(descripcionColor, autos.idColor, colores,  tamcolor);
    cargarDescripcionMarca(descripcionMarca, autos.idMarca, marcas, tammarca);
    cargarDescripcionCliente(nombreCliente, autos.idCliente, clientes, tamcliente);

    printf("%d   %10s      %d    %10s    %d  %10s   %d %10s       %d/%d/%d \n",autos.idCliente,nombreCliente,  autos.id, autos.patente, autos.idMarca, descripcionMarca, autos.idColor, descripcionColor, autos.modelo.dia,autos.modelo.mes,autos.modelo.anio);

}
///////////////////////////////////////MODIFICAR AUTOS//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void modificarAuto(eAuto autos[], eCliente clientes[], int tamcliente, int tamauto, eMarca marcas[], int tammarca, eColor colores[], int tamcolor)
{
    int id;
    int idAux = 0;
    char patente[20];
    int indice;
    int obtenerColorOk;
    int obtenerModeloOk;
    eAuto auxAuto;


    system("cls");

    mostrarAutos(autos,clientes, tamcliente, colores, marcas, tamauto, tamcolor, tammarca);

    utn_getPatente(patente, 7, "Ingrese Patente(Combinacion de 6 letras): ", "\nError, la patente debe contener 6 letras(solo letras).\n", 3);
    for(int i = 0; i < tamauto; i++)
    {
        if(strcmp(autos[i].patente, patente) == 0 && autos[i].isEmpty ==0)
        {
            idAux = autos[i].id;

        }
    }
    id = idAux;

    indice = buscarAuto(id, autos, tamauto);
    if (indice == -1)
    {
        printf("No hay registro de un auto con la patente: %s. \n", patente);
    }
    else
    {
        printf("Usted está a punto de modificar el siguiente auto: \n");
        printf(" Idcliente  NOmbre    Id auto      Patente   IdMARCA      Marca   Id Color  Color     Modelo\n");

        mostrarAuto(autos[indice], clientes, colores, marcas, tamcliente, tamcolor, tammarca);
        switch(submenuModif())
        {
        case 1:
            listarColores(colores, tamcolor);

            obtenerColorOk = utn_getNumero(&auxAuto.idColor, "Ingrese id del color elegico: [Entre...5000 - 5004]", "Error. El color debe ser uno de los mostrados en la pantalla.", 5000, 5004, 3);
            if (obtenerColorOk)
            {
                autos[indice].idColor = auxAuto.idColor;
                printf("Se ha modificado el color del auto con éxito.");
            }
            else
            {
                printf("No se realizo la modificacion. Vuelva a intentarlo. \n");
            }

            break;
        case 2:
            printf("\nIngrese el nuvo modelo del auto: ");
            obtenerModeloOk = obtenerModelo(&auxAuto.modelo.dia, &auxAuto.modelo.mes, &auxAuto.modelo.anio);
            if (obtenerModeloOk)
            {
                autos[indice].modelo = auxAuto.modelo;
                printf("Se ha modificado el modelo del auto con éxito.");
            }
            else
            {
                printf("No se ingreso un modelo de auto  valida. Vuelva a intentarlo. \n");
            }

            break;

        }
    }
}

void mostrarAutos(eAuto autos[],eCliente clientes[], int tamcliente, eColor colores[], eMarca marcas[],int tamauto, int tamcolor, int tammarca)
{
    system("cls");
    int hayAutos = 0;
    printf("\n***** Listado Autos *****\n\n");
    printf(" Idcliente  Nombres  Idauto    Pantente    Id Marca Desc. Marca  Id Color  Color     Modelo\n");

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

int submenuModif()
{
    int opcion;
    printf("***** Modificar Autos ***** \n \n");
    printf("1. Modificar Color.\n");
    printf("2. Modificar Modelo.\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

int buscarAuto(int id, eAuto autos[], int tamauto)
{
    int indiceBuscado = -1;
    for (int i =0; i< tamauto; i++)
    {
        if (autos[i].id == id && autos[i].isEmpty ==0)
        {
            indiceBuscado = i;
            break;
        }
    }
    return indiceBuscado;
}

/////////////////////////BAJA DE AUTO////////////////////////////

void bajaAuto(eAuto autos[], eCliente clientes[], int tamcliente, eColor colores[], eMarca marcas[],int tamauto, int tamcolor, int tammarca)
{

    char patente[20];
    int id;
    int idAux = 0;
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja Auto ***** \n \n");

    mostrarAutos(autos,clientes, tamcliente, colores, marcas, tamauto, tamcolor, tammarca);
    utn_getPatente(patente, 7, "Ingrese Patente(Combinacion de 6 letras): ", "\nError, la patente debe contener 6 letras(solo letras).\n", 3);
    for(int i = 0; i < tamauto; i++)
    {
        if(strcmp(autos[i].patente, patente) == 0 && autos[i].isEmpty ==0)
        {
            idAux = autos[i].id;

        }
    }
    id = idAux;

    indice = buscarAuto(id, autos, tamauto);
    if (indice == -1)
    {
        printf("No hay registro de una Auto con la patente: %s. \n", patente);
    }
    else
    {
        mostrarAuto(autos[indice], clientes,  colores, marcas, tamcliente, tamcolor, tammarca);
        printf("Confirma la baja de la Auto mostrado?  ");
        fflush(stdin);
        scanf("%c", &confirma);
        if (tolower(confirma)== 's')
        {
            autos[indice].isEmpty = 1;
            printf("Se realizo la baja de la Auto solicitada. \n");
        }
        else
        {
            printf("Se ha cancelado la operacion. \n");
        }

    }

}

/////////////////listar ORDENANDO////////////////////////////////////////////////////////

void ordenarAuto(eAuto autos[], int tamauto)
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
            else if (autos[i].idMarca == autos[j].idMarca && strcmp(autos[i].patente, autos[j].patente) > 0 )
            {
                auxAuto = autos[i];
                autos[i] = autos[j];
                autos[j] = auxAuto;
            }
        }
    }




}


void cargarNombreAuto(char descripcion[20], int idAuto, eAuto autos[], int tamauto)
{

    for (int i =0; i< tamauto; i++)
    {
        if (autos[i].id == idAuto)
        {
            strcpy(descripcion, autos[i].patente);
        }
    }

}

int utn_getPatente(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
    char bufferString[4096];
    int retorno = -1;
    while(reintentos>=0)
    {
        reintentos--;
        printf("%s",mensaje);
        if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) == longitud - 1 )
        {
            strncpy(pResultado,bufferString,longitud);
            retorno = 1;
            break;
        }
        printf("%s",mensajeError);
    }
    return retorno;
}
