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
    //char marca[51];
    int marca;

    float importe;

    int id_propietario;

    int isEmpty_auto;

}eAutos;


/** \brief Funcion menu de alta-baja-informe
 * \param void
 * \return int el valor de la opcion ingresada por el usuario
 */
//int auto_menu ();

void auto_hardCode (eAutos* );

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

/** \brief Funcion que busca vehiculo por id del propietario
 * \param eAutos* puntero al primer indice del array
 * \param int Tamaño del array
 * \param int Id a buscar
 * \return int Retorna indice del dato pedido
 *
 */
int auto_buscarPorID_delPropietario (eAutos* pAuto, int cantidad, int id);

/** \brief Funcion que muestra todos los autos con sus datos
 * \param eAutos* puntero al primer indice del array
 * \param int Tamaño del arra
 * \return int (-1) en caso de error (tamaño no valido o puntero NULL) o (0) ok
 */
int auto_mostrarTodos (eAutos* , int );

/** \brief Funcion que muesta un elemento
 * \param eAutos* puntero a estructura
 * \return void
 */
void auto_mostrarUno (eAutos);


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
void auto_darBaja (eAutos* , int , ePropietario* , int );


/** \brief Función que se encargará de determinar el tiempo
 * \param void
 * \return int Retorna el tiempo generado
 */
int devolverHorasEstadia();

/** \brief Funcion que lista los propietarios con los autos en el estacionamiento
 * \param eAuto* puntero a estructura
 * \param int tamaños del array
 * \param ePropietario* puntero a estructura
 * \param int tamaños del array
 * \return void
 *
 */
void auto_PropPorID_ConAuto (eAutos* pAuto, int cant_auto, ePropietario* pPropietario, int cant_propietario);


/** \brief Funcion que calcula la recaudacion total
 * \param eAuto* puntero a estructura
 * \param int tamaños del array
 * \return void
 */
void auto_recaudacion_total (eAutos* pAuto, int cantidad);


/** \brief Funcion que calcula la recaudacion por marca
 * \param eAuto* puntero a estructura
 * \param int tamaños del array
 * \return void
 *
 */
void auto_recaudacion_PorMarca (eAutos* pAuto, int cantidad);


/** \brief Funcion que lista los propietadios de vehiculos AUDI
 * \param ePropietario* puntero a estructura
 * \param int tamaño del array
 * \param eAuto* puntero a estructura
 * \param int tamaño del array
 * \return void
 *
 */
void auto_ListaPropietarios_Audi (ePropietario* pPropietario, int cantidad_prop, eAutos* pAuto, int cantidad_auto);

/** \brief Funcion que lista los propietadios de vehiculos ordenados por Patente
 * \param ePropietario* puntero a estructura
 * \param int tamaño del array
 * \param eAuto* puntero a estructura
 * \param int tamaño del array
 * \return void
 */
void auto_listaEstacionados_ordenPatente_conProp (ePropietario* pPropietario, int cantidad_prop, eAutos* pAuto, int cantidad_auto);


/** \brief Burbujeo por Patente
 * \param eAuto* puntero a estructura
 * \param int tamaño del array
 * \return
 *
 */
void auto_ordenPatente (eAutos* pAuto, int cantidad);

/******************************************************************************************************************/

/** \brief Funcion que pide id al usuario para darlo de baja
 * \param ePropietario* puntero al primer indice del array
 * \param int Tamaño del array
 * \param eAuto* puntero al primer indice del array
 * \param int Tamaño del array
 * \return void
 */
void prop_darBaja (ePropietario* , int ,eAutos* , int );

/** \brief Funcion que cambia el isEmpty del id a FREE
 * \param ePropietario* puntero al primer indice del array
 * \param int Tamaño del array
 * \param int Id a dar de baja
 * \param eAuto* puntero al primer indice del array
 * \param int Tamaño del array
 * \return int retorna (1) baja exitosa, (0) baja cancelada, (-1) caso de error
 */
int prop_remove (ePropietario* , int , int ,eAutos* , int );


#endif // AUTOS_H_INCLUDED

