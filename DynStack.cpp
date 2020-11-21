#include<stdio.h>
#include<stdlib.h>
#include <time.h>
typedef struct nodo{
    int info;
    struct nodo *sig; //APUNTADOR AL SIG NODO DE LA pila
}Nodo;

typedef struct {
   Nodo *top;
} Pila;

//FUNCIONES
void insertar(Pila *pila,int dato);
Nodo borrar(Pila *pila);
//FUNCIONES AUXILIARES
Pila *crearPila();
int pilaVacia(Pila pila);
void inicializarPila(Pila *pila);
void Pilar(Pila pila);
void listar(Pila pila);


int main(){
 int dato;
    int n=50,i;
	Pila *pila;
	pila=crearPila();
	listar(*pila);
    for (i=0; i<10; i++){
        scanf("%d",&n);
        insertar(pila,n);
        listar(*pila);
        if((i+1)%3==0)
        	borrar(pila);
    }
  return 0;
}

Pila *crearPila(){
    Pila *nuevaPila;
    //CREACIÓN DINÁMICA DE LA ESTRUCTURA COLA
    nuevaPila=(Pila *)malloc(sizeof(Pila));
    if (nuevaPila==NULL){
        printf("Error: Espacio insuficiente...");
        return NULL;
    }
    //INICIALIZANDO h y t
    nuevaPila->top=NULL;

    return nuevaPila;
}

void insertar(Pila *pila,int dato){
    Nodo *nuevoNodo;
    //CREA EL NODO
    nuevoNodo=(Nodo *)calloc(1,sizeof(Nodo));
    if (nuevoNodo == NULL){
       printf("Error: memoria insuficiente...");
       return;
    }
    nuevoNodo->info=dato;
    if(pilaVacia(*pila)){
    	pila->top=nuevoNodo;
	}
	else{
		nuevoNodo->sig=pila->top;
		pila->top=nuevoNodo;
	}
	/*
    //ASIGNA VALORES AL NODO
    nuevoNodo->info=dato;
    nuevoNodo->sig=NULL;
    //INSERTA EL NODO EN LA COLA
    if(pilaVacia(*pila)){
    	pila->h=nuevoNodo;
    	pila->t=nuevoNodo;
	}
	else{
		pila->t->sig=nuevoNodo;
		pila->t=nuevoNodo;
	}
	*/	
}

int pilaVacia(Pila pila){
    return pila.top==NULL;
}
Nodo borrar(Pila *pila){
    Nodo dato;
	dato=*pila->top;
	dato.sig=NULL;
	pila->top=pila->top->sig;
    return dato;
}
void listar(Pila pila){
    Nodo *q=pila.top;
    if (pilaVacia(pila))
        printf("\nNo hay datos en la fila...\n");
    else
	do{
		printf("%d\n",q->info);
		q=q->sig;
    }while(q!=NULL);
    printf("\n");
}
void inicializarPila(Pila *pila){
    Nodo *q=pila->top;
   //LIBERA MEMORIA
   while (q!=NULL){

   }
   //INICIALIZA APUNTADORES COLA


    printf("Pila vacía...");
}
