#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "estructuras.h"
#include "muestras.h"
#include "cola_c_din.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    int aleatorio,respuesta,nmuestras,i;
    Nodo aux;
    Muestra *unamuestra;
    Cola *cola;
    cola = crearCola();
    Colac *colac;



	//FASE DE RECEPCIÓN DE MUESTRAS
	nmuestras=0;
	srand (time(NULL));
	aleatorio = rand() % 101;
	if(aleatorio <=50)
    {
        do
        {
            printf("\nDesea llenar los datos de las muestras?Si no, presione el numero 4,\nencaso contrario, digite cualquier otro numero\n");
            scanf("%d",&respuesta);
            if(respuesta != 4)
            {
                unamuestra=crear_muestra();
                llenar_datos(unamuestra);
                insertar(cola,*unamuestra);
                listar(*cola);
                nmuestras++;
            }
        }while(respuesta !=4);
        //FASE DE PROCESADO Y ANALISIS
    colac = crearColac();
    i=0;
    //aleatorio = rand() % nmuestras+1;
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
        listarc(*colac);
        printf("\nMuestras por analizar:\n");
        muestras_analizar(*cola,aleatorio-i);
        i++;
    }while(i!=aleatorio);
listarc(*colac);
    }
    else
        printf("No se genero la muestra(aleatorio = %d)",aleatorio);
    return 0;

}
