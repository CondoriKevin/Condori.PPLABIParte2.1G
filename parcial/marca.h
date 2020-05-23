#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{

   int id;
   char descripcion[20] ;

}eMarca;

#endif // MARCA_H_INCLUDED

/** \brief
 *
 * \param descripcion[] char
 * \param idMarca int
 * \param marcas[] eMarca
 * \param tammarca int
 * \return int
 *
 */
int cargarDescripcionMarca(char descripcion[], int idMarca, eMarca marcas[], int tammarca);

/** \brief
 *
 * \param marcas[] eMarca
 * \param tammarca int
 * \return void
 *
 */
void listarMarca(eMarca marcas[], int tammarca);
