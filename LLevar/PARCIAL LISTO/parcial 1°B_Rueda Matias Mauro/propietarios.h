#ifndef PROPIETARIOS_H_INCLUDED
#define PROPIETARIOS_H_INCLUDED

#include "Input.h"


#define FREE 0
#define FULL 1

typedef struct
{
    int idPropietario;
    char apellido[51];
    char nombre[51];
    char direccion[100];
    int numTarjeta;

    int isEmpty;
}ePropietario;



/** \brief Funcion menu de alta-modificacion-baja-informe
 * \param void
 * \return int el valor de la opcion ingresada por el usuario
 */
int prop_menu (void);

/** \brief Funcion que inicializa todo el arry [ isEmpty en FREE (en cero) ]
 * \param ePropietario* puntero al primer indice del array
 * \param int Tamaño del array
 * \return return int (-1) en caso de error o puntero NULL - 0 si esta bien
 */
int prop_inicializar (ePropietario*  ,int );

/** \brief Funcion que carga datos previamente
 * \param ePropietario* puntero al primer indice del array
 * \return void
 */
void prop_hardCode (ePropietario* );

/** \brief funcion que genera un ID, iniciando en 102 para dar desde el 103 en adelante
 * \param void
 * \return int Retorna el id generado
 */
int prop_creatId ();

/** \brief Funcion que recorre todo el array en busca de espacios libres ( isEmpty=FREE (0) )
 * \param ePropietario* puntero al primer indice del array
 * \param int Tamaño del array
 * \return return int (-1) en caso de no encotrar un espacio libre, en caso de encontrarlo retorna el indice
 */
int prop_buscarEspacioLibre (ePropietario* , int );

/** \brief Funcion que recorre el array en busca de coincidencias de ID
 * \param ePropietario* puntero al primer indice del array
 * \param int Tamaño del array
 * \param int Id a comparar
 * \return int retorna (-1) en caso de que no se encuentre coincidencia, en caso contrario retorna el indice de la coincidencia
 */
int prop_buscarPorID (ePropietario* , int , int );

/** \brief Funcion que pide datos en caso de que se encuentre un lugar libre
 * \param ePropietario* puntero al primer indice del array
 * \param int Tamaño del array
 * \return void
 */
void prop_darDeAlta (ePropietario* , int );

/** \brief Agreaga a la lista de empleado los valores reciidos como parametros en la posicion del indice
 * \param ePropietario* puntero al primer indice del array
 * \param int indice a cargar del array
 * \param int Recibe el ID
 * \param char [] recibe la cadena apellido
 * \param char [] recibe una cadena nombre
 * \param char [] recibe una cadena direccion
 * \param int recibe el tarjeta
 * \return void
 *
 */
void prop_setDatos (ePropietario* , int , int , char [], char [], char [], int  );



 /** \brief Funcion que muestra todos los propietarios con sus datos
 * \param ePropietario* puntero al primer indice del array
 * \param int Tamaño del arra
 * \return int (-1) en caso de error (tamaño no valido o puntero NULL) o (0) ok
 */
int prop_print (ePropietario* , int );


/** \brief Funcion que permite ingresar un ID a modificar sus datos
 * \param ePropietario* puntero al primer indice del array
 * \param int Tamaño del array
 * \return void
 */
void prop_actualizar (ePropietario* , int );

/** \brief Funcion que ordena por apellido y nombre
 * \param ePropietario* puntero al primer indice del array
 * \param int Tamaño del array
 * \return void
 */
void prop_ordenar_apelidoNombre (ePropietario* , int );


/** \brief Funcion que muestra los propietarios ordenados por apellido y nombre
 * \param ePropietario* puntero al primer indice del array
 * \param int Tamaño del array
 * \return int (-1) en caso de error (tamaño no valido o puntero NULL) o (0) ok
 *
 */
int prop_print_ordenCrecienteNombreApellido (ePropietario* , int );

#endif // PROPIETARIOS_H_INCLUDED

