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

typedef struct{
	int max;
	int tope;
	Muestra *arr;//tambien jala como int arr[tammax] pero este es para que sea dinamica
}stack;

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

stack *crearPila(int n);
int pilaLLena(stack *pila);
void pushPila(Muestra dato,stack *pila);
void listarPila(stack *pila);
int pilaVacia(stack *pila);
Muestra popPila(stack *pila);
void inicializarPila(stack *pila);
void liberaMamoriaCola(stack *pila);
#endif // ESTRUCTURAS_H_INCLUDED
