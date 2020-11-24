#ifndef COLA_C_DIN_H_INCLUDED
#define COLA_C_DIN_H_INCLUDED
#include "estructuras.h"
#include "muestras.h"

typedef struct {
   Nodo *h,*t;
} Colac;

//FUNCIONES
void insertarc(Colac *cola,Muestra dato);
Muestra *borrarc(Colac *cola);
//FUNCIONES AUXILIARES
Colac *crearColac();
int colaVaciac(Colac cola);
void inicializarColac(Colac *cola);
void listarc(Colac cola);

#endif // COLA_C_DIN_H_INCLUDED
