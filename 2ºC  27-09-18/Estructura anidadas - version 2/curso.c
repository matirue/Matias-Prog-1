#include "curso.h"
void inicializarCurso (eCurso* cursos)
{
    int id[3]={100,101,102};
    char nombre[3][30]={"php", "c#", "VB"};
    int duracion[3]={3,4,5};
    char profesor[3][30]={"qwe","asd","zxc"};

    int i;

    for(i=0;i<3;i++)
    {
        cursos[i].id=id[i];
        cursos[i].duracion=duracion[i];
        strcpy(cursos[i].nombre, nombre[i]);
        strcpy(cursos[i].profesor, profesor[i]);
    }
}

void mostrarCurso(eCurso curso)
{
    printf("%s -- %s -- %d \n",curso.nombre,curso.profesor,curso.duracion);
}
void mostrarListadoCurso(eCurso* curso, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
       mostrarCurso(curso[i]);
    }
}
