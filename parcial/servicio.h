#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{

   int id;
   char descripcion[20];
   float precio;

} eServicio;

#endif // SERVICIO_H_INCLUDED

/** \brief
 *
 * \param servicios[] eServicio
 * \param tamservicio int
 * \return void
 *
 */
void listarServicio(eServicio servicios[], int tamservicio);

/** \brief
 *
 * \param descripcion[20] char
 * \param idServicio int
 * \param servicios[] eServicio
 * \param tamservicio int
 * \return int
 *
 */
int cargarDescripcionServicio(char descripcion[20], int idServicio, eServicio servicios[], int tamservicio);
