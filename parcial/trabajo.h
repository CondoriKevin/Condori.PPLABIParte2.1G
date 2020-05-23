#include "fecha.h"
#include "auto.h"
#include "color.h"
#include "servicio.h"
#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{

   int id;
   int idAuto;//CAMBIAR POR PATENTE
   int idServicio;
   eFecha fecha;
   int isEmpty;

}eTrabajo;



#endif // TRABAJO_H_INCLUDED

int altaTrabajo(int* proxId,eTrabajo trabajos[], eCliente clientes[], int tamcliente,  int tamtrabajo, eAuto autos[], int tamauto, eColor colores[], int tamcolor, eMarca marcas[], int tammarca, eServicio servicios[], int tamservicio);

/** \brief
 *
 * \param trabajo[] eTrabajo
 * \param tamtrabajo int
 * \return void
 *
 */
void inicializarTrabajo(eTrabajo trabajo[], int tamtrabajo);

/** \brief
 *
 * \param trabajos[] eTrabajo
 * \param tamtrabajo int
 * \return int
 *
 */
int buscarIndiceLibreTrabajo(eTrabajo trabajos[], int tamtrabajo);

/** \brief
 *
 * \param trabajos eTrabajo
 * \param servicios[] eServicio
 * \param tamservicio int
 * \param autos[] eAuto
 * \param tamauto int
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo trabajos, eServicio servicios[], int tamservicio, eAuto autos[], int tamauto);

/** \brief
 *
 * \param trabajos[] eTrabajo
 * \param tamtrabajo int
 * \param servicios[] eServicio
 * \param tamservicio int
 * \param autos[] eAuto
 * \param tamautos int
 * \return void
 *
 */
void mostrarTrabajos(eTrabajo trabajos[],int tamtrabajo, eServicio servicios[], int tamservicio, eAuto autos[], int tamautos);

/** \brief
 *
 * \param diaAux int*
 * \param mesAux int*
 * \param anioAux int*
 * \return int
 *
 */
int obtenerModelo(int* diaAux, int * mesAux, int* anioAux);
