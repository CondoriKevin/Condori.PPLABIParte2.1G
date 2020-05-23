#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

#endif // FECHA_H_INCLUDED

/** \brief
 *
 * \param diaAux int*
 * \param mesAux int*
 * \param anioAux int*
 * \return int
 *
 */
int obtenerFecha(int* diaAux, int * mesAux, int* anioAux);
