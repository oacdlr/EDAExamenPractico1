#ifndef MUESTRAS_H_INCLUDED
#define MUESTRAS_H_INCLUDED
#include "estructuras.h"

#define N 30
typedef struct{
	int clave;
	char *nombre;
	char *departamento;
}Muestra;

Muestra *crear_muestra();
void llenar_datos(Muestra *unamuestra);
void listar_muestra(Muestra unamuestra);


#endif // MUESTRAS_H_INCLUDED
