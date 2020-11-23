#ifndef ESTRUCTURAS_H_INCLUDED
#define ESTRUCTURAS_H_INCLUDED
#include "muestras.h"
typedef struct nodo{
    Muestra info;
    struct nodo *sig; //APUNTADOR AL SIG NODO DE LA cola
}Nodo;

typedef struct {
   Nodo *h,*t;
} Cola;

typedef struct {
   Nodo *top;
} Pila;

//Funciones queue lineal dinamica
void insertar(Cola *cola,Muestra dato);
Nodo borrar(Cola *cola);
Cola *crearCola();
int colaVacia(Cola cola);
void inicializarCola(Cola *cola);
void Colar(Cola cola);
void listar(Cola cola);
//funciones stack
void muestras_analizar(Cola cola, int aleatorio);

#endif // ESTRUCTURAS_H_INCLUDED
