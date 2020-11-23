#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"
#include "muestras.h"
#include "cola_c_din.h"
Colac *crearColac(){
    Colac *nuevaCola;
    //CREACIÓN DINÁMICA DE LA ESTRUCTURA COLA
    nuevaCola=(Colac *)malloc(sizeof(Colac));
    if (nuevaCola==NULL){
        printf("Error: Espacio insuficiente...");
        return NULL;
    }
    //INICIALIZANDO h y t
    nuevaCola->h=NULL;
    nuevaCola->t=NULL;
    return nuevaCola;
}
void insertarc(Colac *cola,Muestra dato){
    Nodo2 *nuevoNodo;
    //CREA EL NODO
    nuevoNodo=(Nodo *)malloc(1*sizeof(Nodo));
    if (nuevoNodo == NULL){
       printf("Error: memoria insuficiente...");
       return;
    }
    //ASIGNA VALORES AL NODO
    nuevoNodo->info=dato;
    nuevoNodo->sig=NULL;
    //INSERTA EL NODO EN LA COLA
    if(cola->h == NULL){
        cola->h =nuevoNodo;
        cola->t=nuevoNodo;
    }
    else{
        cola->t->sig = nuevoNodo;
        cola->t =nuevoNodo;
    }
      cola->t->sig=cola->h;//se hace la liga
}

int colaVaciac(Colac cola){
    return cola.h==NULL;
}
Muestra *borrarc(Colac *cola){
    Muestra *dato;
    dato =(Muestra *)malloc(1*sizeof(Muestra));
    Nodo2 *q;
    q=cola->h;
    //BORRA EL ELEMENTO DE LA COLA
    if(!colaVaciac(*cola)){
        if(cola->h==cola->t)
            cola->h = cola->t = NULL;
        else
        cola->h =cola->h->sig;
        cola->t->sig=cola->h;//actualiza la ligadura con H
        *dato = q->info;//EXTRAE LA INFORMACIÓN
        free(q);  //LIBERA LA MEMORIA
        q=NULL;
    }
    return dato;
}
void listarc(Colac cola){
   Nodo2 *q;//se crea la variable
    if (colaVaciac(cola))
    printf("\nNo hay datos en la fila...\n");
    else{
            q=cola.h;//Se inicializa la variable q es punto por que se recibe una copia
            printf("\nMuestras analizadas :\n");
            do
            {
            listar_muestra(q->info);
            q=q->sig;
            }while(q!= cola.h);
        }
    printf("\n");

}
void inicializarColac(Colac *cola){
    Nodo2 *q=cola->h;
   //LIBERA MEMORIA
   if(!colaVaciac(*cola)){
       cola->t->sig= NULL;
   while(q!= NULL){
    cola->h = cola->h->sig;
    free(q);
    q=cola->h;
   }
   }
   //INICIALIZA APUNTADORES COLA
    printf("Cola vacia...");
}
