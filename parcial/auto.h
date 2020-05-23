#include "marca.h"
#include "color.h"
#include "fecha.h"
#include "datawarehouse.h"
#include "cliente.h"

#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

typedef struct
{
    int id;
    char patente[20];
    int idMarca;
    int idColor;
    int idCliente;
    eFecha modelo;
    int isEmpty;

} eAuto;

#endif // AUTO_H_INCLUDED

/**
 * \brief Solicita Patente, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 1 si se obtuvo el nombre y -1 si no
 *
 */
int utn_getPatente(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);

int altaAuto(int* proxId, eAuto autos[], eCliente clientes[], int tamcliente, int tamauto, eColor colores[], int tamcolor, eMarca marcas[], int tammarca);

/** \brief
 *
 * \param autos[] eAuto
 * \param tamauto int
 * \return void
 *
 */
void inicializarAuto(eAuto autos[], int tamauto);

/** \brief
 *
 * \param autos[] eAuto
 * \param tamauto int
 * \return int
 *
 */
int buscarIndiceLibreAuto(eAuto autos[], int tamauto);

void mostrarAuto(eAuto autos, eCliente clientes[], eColor colores[], eMarca marcas[], int tamcliente, int tamcolor, int tammarca);

void modificarAuto(eAuto autos[], eCliente clientes[], int tamcliente, int tamauto, eMarca marcas[], int tammarca, eColor colores[], int tamcolor);

/** \brief
 *
 * \param id int
 * \param autos[] eAuto
 * \param tamauto int
 * \return int
 *
 */
int buscarAuto(int id, eAuto autos[], int tamauto);

/** \brief
 *
 * \return int
 *
 */
int submenuModif();

void mostrarAutos(eAuto autos[],eCliente clientes[], int tamcliente, eColor colores[], eMarca marcas[],int tamauto, int tamcolor, int tammarca);

void bajaAuto(eAuto autos[], eCliente clientes[], int tamcliente, eColor colores[], eMarca marcas[],int tamauto, int tamcolor, int tammarca);

/** \brief
 *
 * \param autos[] eAuto
 * \param tamauto int
 * \return void
 *
 */
void ordenarAuto(eAuto autos[], int tamauto);

/** \brief
 *
 * \return int
 *
 */
int elegirTipoDeOrdenamiento();

/** \brief
 *
 * \param descripcion[20] char
 * \param idAuto int
 * \param autos[] eAuto
 * \param tamauto int
 * \return void
 *
 */
void cargarNombreAuto(char descripcion[20], int idAuto, eAuto autos[], int tamauto);

/** \brief
 *
 * \param autos[] eAuto
 * \param tamauto int
 * \return void
 *
 */
void hardcodearAuto(eAuto autos[], int tamauto);

/** \brief
 *
 * \return char
 *
 */
char menu();
