#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "fecha.h"
#include "marca.h"
#include "color.h"
#include "auto.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"
#include "FUNCIONES.h"

#define TAMMARCA 5
#define TAMCOLOR 5
#define TAMCLIENTE 5
#define TAMSERVICIO 4
#define TAMAUTO 50
#define TAMTRABAJO 100
#define CANTHARDCODE 5






int main()
{
    eCliente clientes[TAMCLIENTE]=
    {
        { 200, "Carlos" ,'M'},
        { 201, "Bruno"  ,'M'},
        { 202, "Karina" ,'F'},
        { 203, "Javier" ,'F'},
        { 204, "Walter" ,'M'}
    };
    eMarca marcas[TAMMARCA] =
    {
        { 1000, "Renault"},
        { 1001, "Fiat"},
        { 1002, "Ford"},
        { 1003, "Chevrolet"},
        { 1004, "Peugeot"}
    } ;
    eColor colores[TAMCOLOR] =
    {
        { 5000, "Negro"},
        { 5001, "Blanco"},
        { 5002, "Gris"},
        { 5003, "Rojo"},
        { 5004, "Azul"}
    };

    eServicio servicios[TAMSERVICIO] =
    {
        { 20000, "Lavado", 250},
        { 20001, "Pulido", 300},
        { 20002, "Encerado", 400},
        { 20003, "Completo", 600}
    };
    eAuto autos[TAMAUTO];
    eTrabajo trabajos[TAMTRABAJO] ;

    int proxIdAuto = 100;
    int idTrabajo = 300;
    char seguir = 's';
    char confirma;
    proxIdAuto += CANTHARDCODE;
    inicializarAuto(autos, TAMAUTO);
    inicializarTrabajo(trabajos, TAMTRABAJO);
    hardcodearAuto(autos, 5);//DEPENDE DE ESTO SI AGREGO MAS A UTOS O NO.....SI PONGO TAMAUTO NO PUEDO AGREGAR MAS


    do
    {
        switch(menu())
        {
        case 'a':
            if (altaAuto(proxIdAuto, autos, clientes, TAMCLIENTE, TAMAUTO, colores, TAMCOLOR, marcas, TAMMARCA))
            {
                printf("Se ha dado de alta el auto satisfactoriamente. \n");
            }
            else
            {
                printf("Se produjeron errores durante el dado de alta. No fue posible realizar el alta");
            }
            break;

        case 'b':

            modificarAuto(autos, clientes, TAMCLIENTE, TAMAUTO, marcas, TAMMARCA, colores, TAMCOLOR);
            break;
        case 'c':
            bajaAuto(autos, clientes, TAMCLIENTE, colores, marcas, TAMAUTO, TAMCOLOR, TAMMARCA);
            break;
        case 'd':
            ordenarAuto(autos, TAMAUTO);
            mostrarAutos(autos, clientes, TAMCLIENTE, colores, marcas, TAMAUTO, TAMCOLOR, TAMMARCA);
            break;
        case 'e':
            listarMarca(marcas, TAMMARCA);
            break;
        case 'f':
            listarColores(colores, TAMCOLOR);
            break;
        case 'g':
            listarServicio(servicios, TAMSERVICIO);
            break;
        case 'h':
            if(altaAuto(proxIdAuto, autos, clientes, TAMCLIENTE, TAMAUTO, colores, TAMCOLOR, marcas, TAMMARCA))
            {
                printf("Se ha realizado con exito el alta de trabajo.");
            }
            else
            {
                printf("Se produjeron errores durante el alta, no se realizo el alta.");
            }
            break;
        case 'i':
            mostrarTrabajos(trabajos, TAMTRABAJO,  servicios, TAMSERVICIO, autos, TAMAUTO);
            break;
            case 'j':
            mostrarClientes(autos, clientes, TAMCLIENTE, colores, marcas, TAMAUTO, TAMCOLOR, TAMMARCA);
            break;
        case 'k':

              MostrarAutoPorColor(autos, clientes, TAMCLIENTE, colores, marcas, TAMAUTO,TAMCOLOR, TAMMARCA);
        break;
        case 'l':

              MostrarAutoMarca(autos, clientes, TAMCLIENTE, colores, marcas, TAMAUTO,TAMCOLOR, TAMMARCA);
        break;
        case 'o':
  MostrarSeparadorMarca(autos, clientes, TAMCLIENTE, colores, marcas, TAMAUTO,TAMCOLOR, TAMMARCA);
          mostrarAutos(autos, clientes, TAMCLIENTE, colores, marcas, TAMAUTO, TAMCOLOR, TAMMARCA);
        break;
         case 'p':

              MostrarPorMarcayColor(autos, clientes, TAMCLIENTE, colores, marcas, TAMAUTO,TAMCOLOR, TAMMARCA);
        break;

        case 'q':
            printf("Confirma salida?  ");
            fflush(stdin);
            scanf("%c", &confirma);
            if (tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        }
        system("pause");

    }
    while( seguir == 's');
    return 0;
}





