#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED


typedef struct
{
    int id;
    char nombre[20];
    char sexo;

} eCliente;

#endif // CLIENTE_H_INCLUDED

void listarCliente(eCliente clientes[], int tamcliente);
int cargarDescripcionCliente(char nombre[20], int idCliente, eCliente clientes[], int tamcliente);
