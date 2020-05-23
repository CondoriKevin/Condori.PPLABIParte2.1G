#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];

} eColor;

#endif // COLOR_H_INCLUDED


int cargarDescripcionColor(char descripcion[], int idColor, eColor colores[], int tamcolor);


void listarColores(eColor colores[], int tamcolor);
