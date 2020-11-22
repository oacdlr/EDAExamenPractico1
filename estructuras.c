#include "stdio.h"
#include "stdlib.h"
#include "estructuras.h"

Cola *crearCola(){
    Cola *nuevaCola;
    //CREACIÓN DINÁMICA DE LA ESTRUCTURA COLA
    nuevaCola=(Cola *)malloc(sizeof(Cola));
    if (nuevaCola==NULL){
        printf("Error: Espacio insuficiente...");
        return NULL;
    }
    //INICIALIZANDO h y t
    nuevaCola->h=NULL;
    nuevaCola->t=NULL;

    return nuevaCola;
}

void insertar(Cola *cola,Muestra dato){
    Nodo *nuevoNodo;
    //CREA EL NODO
    nuevoNodo=(Nodo *)calloc(1,sizeof(Nodo));
    if (nuevoNodo == NULL){
       printf("Error: memoria insuficiente...");
       return;
    }
    //ASIGNA VALORES AL NODO
    nuevoNodo->info=dato;
    nuevoNodo->sig=NULL;
    //INSERTA EL NODO EN LA COLA
    if(colaVacia(*cola)){
    	cola->h=nuevoNodo;
    	cola->t=nuevoNodo;
	}
	else{
		cola->t->sig=nuevoNodo;
		cola->t=nuevoNodo;
	}
}

int colaVacia(Cola cola){
    return cola.h==NULL;
}
Nodo borrar(Cola *cola){
    Nodo dato;
	dato=*cola->h;
	dato.sig=NULL;
	cola->h=cola->h->sig;
    return dato;
}
void listar(Cola cola){
    Nodo *q=cola.h;
    if (colaVacia(cola))
        printf("\nNo hay datos en la fila...\n");
    else
	do{
		printf("%d\n",q->info.clave);
		printf("%s\n",q->info.nombre);
		printf("%s\n",q->info.departamento);		
		q=q->sig;
    }while(q!=NULL);
    printf("\n");
}
void inicializarCola(Cola *cola){
    Nodo *q=cola->h;
   //LIBERA MEMORIA
   while (q!=NULL){

   }
   //INICIALIZA APUNTADORES COLA
    printf("Cola vacía...");
}
