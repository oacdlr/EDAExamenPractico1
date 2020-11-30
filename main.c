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
     printf("Desea ver el estado de cada contenedor?\n\t1)Si\t2)No");
        scanf("%d",&respuesta);
        if(respuesta==1){

            mostrar_contenedores(cola,colac,pila);

        }
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
                printf("Numero de muestras:%d\n",nmuestras);
            }
    	}
        else
        	printf("No se genero la muestra(aleatorio = %d)\n",aleatorio);
    }while(respuesta !=4);
    //FASE DE PROCESADO Y ANALISIS
    printf("Desea ver el estado de cada contenedor?\n\t1)Si\t2)No");
    scanf("%d",&respuesta);
    if(respuesta==1){

        mostrar_contenedores(cola,colac,pila);

    }
    i=0;
    nanaliz=0;
    aleatorio = rand() % nmuestras+1;
    aleatorio=3;
    printf("Numero de muestras a analizar y procesar: %d\n",aleatorio);
    do
    {
        printf("\n*******************************\n");
        printf("\nMuestras por analizar:\n");
        muestras_analizar(*cola,aleatorio+1-i);
        aux = borrar(cola);
        Sleep(1000);
        printf("\nAnalizando muestra : %d...\n",aux.info.clave);
        insertarc(colac,aux.info);
        printf("\nMuestras analizadas\n");
        listarc(*colac);
        printf("\nMuestras por analizar:\n");
        muestras_analizar(*cola,aleatorio-i);
        nanaliz++;
        i++;
    }while(i!=aleatorio);
    //FASE DE REPORTE Y ENTREGA
        printf("Desea ver el estado de cada contenedor?\n\t1)Si\t2)No");
    scanf("%d",&respuesta);
    if(respuesta==1){

        mostrar_contenedores(cola,colac,pila);

    }
    aleatorio=rand() % nanaliz+1;
    printf("\ngggg\n");
    Sleep(2500);
    printf("\nApilando %d pruebas...\n",aleatorio);
	for(i=0;i<aleatorio;i++){
    	unamuestra=borrarc(colac);
    	printf("\nApilando muestra : %d...\n",unamuestra->clave);
		printf("La muestra:");
		listar_muestra(*unamuestra);
		printf("\nEsta lista para entregar(esta en el contenedor para entregarse)\n");
		Sleep(1000);
		pushPila(*unamuestra,pila);
	}


	printf("\n//////////////////////////////////////////////////////////\n");
	printf("\nMuestras Listas para Entregar...\n");
	listarPila(pila);
	printf("\nSe entregaran %d muestras...\n",aleatorio);
	Sleep(1000);
	for(i=0;i<aleatorio;i++){
		*unamuestra=popPila(pila);
    	printf("\nEntregando la muestra:%d de nombre %s al departamento %s\n",unamuestra->clave,unamuestra->nombre,unamuestra->departamento);
		Sleep(1000);
		printf("Muestras restantes:\n");
		listarPila(pila);
		printf("\n//////////////////////////////////////////////////////////\n");
	}
}

	return 0;
}
