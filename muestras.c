#include "stdio.h"
#include "stdlib.h"
#include "estructuras.h"
#include "muestras.h"
Muestra *crear_muestra()
{
    Muestra *unamuestra;
    unamuestra = (Muestra *)malloc(1*sizeof(Muestra));
    unamuestra->nombre=(char *)malloc(N*sizeof(char));
    unamuestra->departamento=(char *)malloc(N*sizeof(char));
    return unamuestra;

}
void llenar_datos(Muestra *unamuestra)
{
    printf("\nCual es el folio de la muestra?\n");
    scanf("%d",&unamuestra->clave);
    fflush(stdin);
    printf("\nIngrese el nombre de la muestra:\n");
    gets(unamuestra->nombre);
    fflush(stdin);
    printf("\nIngrese el nombre del departamento:\n");
    gets(unamuestra->departamento);
    fflush(stdin);
}
void listar_muestra(Muestra unamuestra)
{
    printf("\n----------------------------------------------");
    printf("\nClave: %d\nNombre: %s\nDepartamento: %s\n",unamuestra.clave,unamuestra.nombre,unamuestra.departamento);
    printf("\n----------------------------------------------");
}

