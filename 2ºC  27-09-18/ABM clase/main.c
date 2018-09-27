#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Alumnos.h"

#define TAM 100


int main()
{
    int opcion;
    eAlumno listaAlumnos[TAM];

    inicializarAlumnno(listaAlumnos,TAM);
    inicializarAlumnosConDatos(listaAlumnos,TAM);

    do{
        printf("\n\n*******************************************************************************\n\n");
        printf(" 1.Cargar\n 2.Mostrar\n 3.Borrar\n 4.Modificar \n 5.Salir\n\n ");
        scanf("%d", &opcion);

        switch (opcion)
        {

        case 1:
            printf("\n\n*******************************************************************************\n\n");
            if (cargarListado(listaAlumnos, TAM))
            {

                printf("Has dado de alta\n");
            }
            else
            {
                printf("No hay espacio\n");
            }
            break;

        case 2:
            printf("\n\n*******************************************************************************\n\n");
            mostrarListado(listaAlumnos, TAM);
            break;

        case 3:
            printf("\n\n*******************************************************************************\n\n");
            borrarAlumno(listaAlumnos, TAM);
            break;

       case 4:
           printf("\n\n*******************************************************************************\n\n");
            if (modificarAlumno(listaAlumnos, TAM))
            {

                printf("Has Modificado\n");
            }
            else
            {
                printf("No hay espacio\n");
            }
            break;

       case 5:
            break;
        }
    }while(opcion!=5);
        return 0;
}
