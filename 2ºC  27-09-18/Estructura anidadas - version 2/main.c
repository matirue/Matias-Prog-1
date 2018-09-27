#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Alumnos.h"
#include "curso.h"

#define TAM 100

/**       */
int main()
{

    int opcion,i,j;

    eAlumno listaAlumnos[TAM];
    inicializarAlumnno(listaAlumnos,TAM);
    inicializarAlumnosConDatos(listaAlumnos,TAM);

    eCurso miCurso[TAM];
    inicializarCurso(miCurso);
    mostrarListadoCurso(miCurso, 3);

    do{
        printf("\n\n*******************************************************************************\n\n");
        printf(" 1.Cargar\n 2.Mostrar\n 3.Borrar\n 4.Modificar \n 5.Mostrar listado con curso\n 6.Salir\n\n ");
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
           for(i=0;i<TAM;i++) //por cada alumno muestro los datos del aluumno
            {
                if(listaAlumnos[i].estado==1)
                    {
                        printf("%d -- %s -- %.2f -- ", listaAlumnos[i].legajo, listaAlumnos[i].nombre,listaAlumnos[i].promedio);
                    //busco los datos
                        for(j=0;j<3;j++)
                            {
                                if(listaAlumnos[i].idCurso==miCurso[j].id) //busco el id del curso q le corresponde al alumno
                                    {
                                        printf("%s",miCurso[j].nombre);
                                        break;
                                    }
                            }
                            printf("\n");
                    }
            }
            break;

       case 6:
        break;
        }
    }while(opcion!=6);

        return 0;
}
