#include <stdio.h>
#include <stdlib.h>
#include "EstructuraGenerica.h"
//#include "susFunciones.h"
#define CANTIDAD 10

/**     COMPLETAR CON TODAS LAS VALIDACIONES  **/
int main()
{
    eAlumno listadoGenerico[CANTIDAD];
    eAlumno_init(listadoGenerico,CANTIDAD);

    printf( "\n \t muestro el array... esta vacio");
    eAlumno_mostrarListado(listadoGenerico,CANTIDAD);
    getchar();

    printf( "\n \t muestro el array con los borrados y vacios");
    eAlumno_mostrarListadoConBorrados(listadoGenerico,CANTIDAD);
    getchar();

    eAlumno_alta(listadoGenerico,CANTIDAD);
    eAlumno_alta(listadoGenerico,CANTIDAD);
    printf( "\n \t cargo dos elementos y muestro el array");
    eAlumno_mostrarListado(listadoGenerico,CANTIDAD);
    getchar();

    printf( "\n \t muestro el array con los borrados y vacios");
    eAlumno_mostrarListadoConBorrados(listadoGenerico,CANTIDAD);
    getchar();


    return 0;
}
