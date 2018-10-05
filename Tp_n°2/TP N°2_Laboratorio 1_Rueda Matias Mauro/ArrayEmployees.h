#include "input.h"

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;

    int isEmpty;
}eEmployee;


/** \brief Funcion menu de alta-modificacion-baja-informe
 * \param void
 * \return el valor de la opcion ingresada por el usuario
 */
int empleados_menu (void);

/** \brief Funcion que inicializa todo el arry de isEmpty en FREE (en cero)
 * \param eEmployee* puntero al primer indice del array
 * \param int Tamaño del array
 * \return return (-1) en caso de error o puntero NULL - 0 si esta bien
 */
int empleados_init (eEmployee* ,int);

/** \brief Funcion que carga datos previamente
 * \param eEmployee* puntero al primer indice del array
 * \return void
 */
void empleados_hardCode (eEmployee* );

/** \brief Funcion que recorre todo el array en busca de espacios libres ( isEmpty=FREE (0) )
 * \param eEmployee* puntero al primer indice del array
 * \param int Tamaño del array
 * \return return (-1) en caso de no encotrar un espacio libre, en caso de encontrarlo retorna el indice
 */
int empleados_findFreeSpace (eEmployee* , int );

/** \brief Funcion que recorre el array en busca de coincidencias de ID
 * \param eEmployee* puntero al primer indice del array
 * \param int Tamaño del array
 * \param int Id a comparar
 * \return retorna (-1) en caso de que no se encuentre coincidencia, en caso contrario retorna el indice de la coincidencia
 */
int empleados_findByID (eEmployee* , int , int );


/** \brief Funcion que pide datos en caso de que se encuentre un lugar libre
 * \param eEmployee* puntero al primer indice del array
 * \param int Tamaño del array
 * \return void
 */
void empleados_darDeAlta (eEmployee*, int );


/** \brief Agreaga a la lista de empleado los valores reciidos como parametros en la posicion del indice
 * \param eEmployee* puntero al primer indice del array
 * \param int Tamaño del array
 * \param int Recibe el ID
 * \param char [] recibe la cadena apellido
 * \param char [] recibe una cadena nombre
 * \param int recibe el sector
 * \param int recibe el salario
 * \param int recibe la posicion del lugar libre
 * \return retorna cero si la carga fue exitosa , -1 en caso contrario
 *
 */
int addEmployees (eEmployee* pEmployee, int cantidad, int subir_id, char subir_lastName[], char subir_name[], int subir_sector, int subir_salario, int indice)


