#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Alumnos.h"
#include "curso.h"

#define OCUPADO 1
#define LIBRE 0
#define ELIMINADO -1

void inicializarAlumnosConDatos(eAlumno listado[], int tam) //no es necesario el tam
{
    int legajo[5]={1,2,3,4,5};
    char nombre[5][50]={"aaa", "bbb", "ccc", "ddd", "eee"};
    char direccion[5][50]={"abc", "def","ghi","jkl","mno"};
    float promedio[5]={5,4,9,10,6};
    int curso[5]={100,102,101,100,101};
    int i;

    for(i=0;i<5;i++)//solo i<5 xq cargo 5 dato y seria inecesario q corra todo el TAM
        {
            listado[i].legajo=legajo[i];
            listado[i].promedio=promedio[i];
            strcpy(listado[i].nombre, nombre[i]);
            strcpy(listado[i].direccion, direccion[i]);
            listado[i].idCurso=curso[i];
            listado[i].estado=OCUPADO;
        }
}

eAlumno cargarAlumno()
{
    eAlumno miAlumno;

    printf("Ingrese el legajo: ");
    scanf("%d", &miAlumno.legajo);

    printf("Ingrese su nombre: ");
    fflush(stdin);
    gets(miAlumno.nombre);

    printf("Ingrese su direccion: ");
    fflush(stdin);
    gets(miAlumno.direccion);

    printf("Ingrese el promedio: ");
    scanf("%f", &miAlumno.promedio);

    return miAlumno;

}



void mostrarAlumno (eAlumno alumnoParametro)
{
    printf("%d -- %s -- %s -- %.2f -- %d  \n", alumnoParametro.legajo, alumnoParametro.nombre, alumnoParametro.direccion, alumnoParametro.promedio, alumnoParametro.idCurso);
}



int cargarListado(eAlumno listado[], int tam)
{
    int retorno=0;
    int indice;
    indice=buscarLibre(listado,tam);
    if(indice!=-1){
    listado[indice] = cargarAlumno();
    listado[indice].estado= OCUPADO;
    retorno=1;
    }
    return retorno;

}



void mostrarListado(eAlumno listado[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(listado[i].estado==1)
            {
               mostrarAlumno(listado[i]);
            }
    }
}
 void inicializarAlumnno (eAlumno lista[], int tam){
    int i;
    for (i=0;i<tam;i++){

        lista[i].estado=LIBRE;
    }
 }
int buscarLibre (eAlumno listado[], int tam){

    int indice=-1;
    int i;
    for(i=0;i<tam;i++){
        listado[i].estado== LIBRE;
        indice=i;
        break;
    }
    return indice;
}
int borrarAlumno(eAlumno listado[], int tam)
{
//1) pido legajo 2) busco el legajo en el array ---no : no existe----si cambio el estado
    int legajo;
    int retorno=0;

    printf(" Ingrese legajo:");
    scanf("%d", &legajo);
    int i;

    for(i=0;i<tam;i++)
        {
           if (legajo==listado[i].legajo && listado[i].legajo==OCUPADO )
           {
             listado[i].estado=ELIMINADO;
             retorno=1;
             break;
          }
        }
    return retorno;
}

int modificarAlumno(eAlumno listado[], int tam) //poner todas las validaciones, etc
{

    int legajo;
    int retorno=0;
    int i;

    printf(" Ingrese legajo a buscar:");
    scanf("%d", &legajo);


    for(i=0;i<tam;i++)
        {
           if (legajo==listado[i].legajo && listado[i].legajo==OCUPADO )
           {
             printf("\n Ingrese el nuevo promedio: ");
             scanf("%f", &listado[i].promedio);

             retorno=1;
             break;
          }
        }
    return retorno;
}
