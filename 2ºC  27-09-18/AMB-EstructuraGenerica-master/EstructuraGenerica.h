#ifndef ESTRUCTURAGENERICA_H_INCLUDED
#define ESTRUCTURAGENERICA_H_INCLUDED

typedef struct
{
    char nombre[50];
    //------------
    int idGenerica;
    int estado;
}eAlumno;

#endif // ESTRUCTURAGENERICA_H_INCLUDED

int eAlumno_init(eAlumno[],int limite);
int eAlumno_buscarPorId(eAlumno[] ,int limite, int id);
int eAlumno_siguienteId(eAlumno[] ,int limite);
int eAlumno_buscarLugarLibre(eAlumno listado[],int limite);

int eAlumno_mostrarUno(eAlumno parametro);
int eAlumno_mostrarListado(eAlumno[] ,int limite);
int eAlumno_mostrarListadoConBorrados(eAlumno[] ,int limite);

int eAlumno_alta(eAlumno[] ,int limite);
int eAlumno_baja(eAlumno[] ,int limite, int id);
int eAlumno_modificacion(eAlumno[] ,int limite, int id);

int eAlumno_ordenar(eAlumno[] ,int limite, int orden);
