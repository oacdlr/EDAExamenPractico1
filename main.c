#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "estructuras.h"
#include "muestras.h"
#include "cola_c_din.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define maxstack 20
int main() {
    int aleatorio,respuesta,nmuestras,nanaliz,i;
    Nodo aux;
    Muestra *unamuestra;
    unamuestra=crear_muestra();
    Cola *cola;
    cola = crearCola();
    Colac *colac;
	colac = crearColac();
	stack *pila;
	pila=crearPila(maxstack);
	//FASE DE RECEPCI?N DE MUESTRAS
	nmuestras=nanaliz=0;
	srand (time(NULL));
while(1){
    do{
    	aleatorio = rand() % 101;
    	if(aleatorio <=50){
            printf("\nDesea llenar los datos de las muestras?Si no, presione el numero 4,\nEn caso contrario, digite cualquier otro numero\n");
            scanf("%d",&respuesta);
            if(respuesta != 4){
                unamuestra=crear_muestra();
				llenar_datos(unamuestra);
                insertar(cola,*unamuestra);
                listar(*cola);
                nmuestras++;
            }
    	}
        else
        	printf("No se genero la muestra(aleatorio = %d)\n",aleatorio);
    }while(respuesta !=4);
    printf("Desea ver el estado de cada contenedor?\n\t1)Si\t2)No");
    scanf("%d",&respuesta);
    if(respuesta==1){
    	printf("Recibidos\n");
    	listar(*cola);
    	printf("Analizando\n");
    	listarc(*colac);
    	printf("Listos para entregar\n");
    	listarPila(pila);
		Sleep(2000);
	}
	    //FASE DE PROCESADO Y ANALISIS
	printf("Muestras Recibidas:");
    listar(*cola);
    if(nmuestras!=0){
    aleatorio=rand()%nmuestras+1;
    printf("Numero de muestras a analizar y procesar: %d\n",aleatorio);
    Sleep(1000);
    for(i=0;i<aleatorio;i++){
	aux=borrar(cola);
	insertarc(colac,aux.info);
	nmuestras--;
	nanaliz++;
	}
	printf("\nMuestras en Recepcion\n");
	listar(*cola);
    printf("\n*******************************\n");
    printf("\nMuestras por analizar:\n");
    listarc(*colac);
    aleatorio=rand()%nanaliz+1;
    Sleep(2500);
    printf("\nAnalizando %d pruebas...\n",aleatorio);
	for(i=0;i<aleatorio;i++){
    	unamuestra=borrarc(colac);
    	printf("\nAnalizando muestra : %d...\n",unamuestra->clave);
		printf("La muestra:");
		listar_muestra(*unamuestra);
		printf("Esta lista para entregar");
		Sleep(1500);
		pushPila(*unamuestra,pila);
	}
	}
	//FASE DE REPORTE Y ENTREGA
	Sleep(1000);
	printf("\nMuestras Listas para Entregar...");
	listarPila(pila);
	aleatorio=rand()%((pila->tope)+2);
	printf("Entregando %d muestras...\n",aleatorio);
	Sleep(1000);
	for(i=0;i<aleatorio;i++){
		*unamuestra=popPila(pila);
    	printf("\nEntregando la muestra:%d de nombre %s al departamento %s\n",unamuestra->clave,unamuestra->nombre,unamuestra->departamento);
		Sleep(1000);
		printf("Muestras restantes:\n");
		listarPila(pila);
	}
}
	return 0;
}
