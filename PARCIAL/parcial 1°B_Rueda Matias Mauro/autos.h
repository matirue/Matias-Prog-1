#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED

#include "propietarios.h"



#define NOESTACIONADO 0
#define ESTACIONADO 1

#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4

typedef struct
{
    int id_auto;
    char patente[51];
    char marca[51];
    int id_propietario;

    int isEmpty_auto;

}eAutos;


/** \brief Funcion menu de alta-baja-informe
 * \param void
 * \return int el valor de la opcion ingresada por el usuario
 */
int auto_menu ();

/** \brief Funcion que inicializa todo el arry [ isEmpty en FREE (en cero) ]
 * \param eAutos* puntero al primer indice del array
 * \param int Tamaño del array
 * \return return int (-1) en caso de error o puntero NULL - 0 si esta bien
 */
int auto_inicializar (eAutos*  ,int );

/** \brief Funcion que recorre todo el array en busca de espacios libres ( isEmpty=FREE (0) )
 * \param eAutos* puntero al primer indice del array
 * \param int Tamaño del array
 * \return return int (-1) en caso de no encotrar un espacio libre, en caso de encontrarlo retorna el indice
 */
int auto_buscarEspacioLibre (eAutos* , int );

/** \brief funcion que genera un ID, iniciando en 999 para dar desde el 1000 en adelante
 * \param void
 * \return int Retorna el id generado
 */
int auto_creatId ();

/** \brief Funcion que recorre el array en busca de coincidencias de ID
 * \param eAutos* puntero al primer indice del array
 * \param int Tamaño del array
 * \param int Id a comparar
 * \return int retorna (-1) en caso de que no se encuentre coincidencia, en caso contrario retorna el indice de la coincidencia
 */
int auto_buscarPorID (eAutos* , int , int );

/** \brief Funcion que muestra todos los autos con sus datos
 * \param eAutos* puntero al primer indice del array
 * \param int Tamaño del arra
 * \return int (-1) en caso de error (tamaño no valido o puntero NULL) o (0) ok
 */
int auto_mostrarTodos (eAutos* , int );

/** \brief Funcion que pide datos en caso de que se encuentre un lugar libre
 * \param eAutos* puntero al primer indice del array
 * \param int Tamaño del array
 * \param ePropietario* puntero al primer indice del array
 * \param int Tamaño del array
 * \return void
 */
void auto_darAlta (eAutos* , int , ePropietario* , int );

/** \brief Funcion que pide id al usuario para darlo de baja
 * \param eAutos* puntero al primer indice del array
 * \param int Tamaño del array
 * \return void
 */
void auto_darBaja (eAutos* , int );


/** \brief Función que se encargará de determinar el tiempo
 * \param void
 * \return int Retorna el tiempo generado
 */
int devolverHorasEstadia();


#endif // AUTOS_H_INCLUDED

