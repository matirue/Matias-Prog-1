#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "ArrayEmployees.h"

#define FREE 0
#define FULL 1

int empleadosCreatId (void);

/********************************************************************************************/
int empleados_menu ()
{
    int opc;

    printf("::::::::::::::::::: MENU DE OPERACIONES :::::::::::::::::::");
    printf("\n\n");
    printf("1-AGREGAR EMPLEADO\n");
    printf("2-MODIFICAR EMPLEADO\n");
    printf("3-DAR DE BAJA EMPLEADO\n");
    printf("4-INFORMES\n");
    printf("5-SALIR\n");
    printf("\n\n");

    opc=getValidInt("\n Elija una operacion: ", "\n\n  ERROR. Operacion invalida ", 1, 5);

    return opc;
}
/********************************************************************************************/
int empleados_init (eEmployee* pEmployee ,int cantidad)
{
    int i, retorna=-1;
    if(pEmployee!=NULL &&cantidad>0)
        {
            for(i=0;i<cantidad;i++)
                {
                   pEmployee[i].isEmpty==FREE;  //FREE=0 que esta vacio
                }

            retorna=0;
        }
    return retorna;
}
/********************************************************************************************/
void empleados_hardCode (eEmployee* pEmployee)
{
    int idAux[3]={100,101,102};
    char nameAux[][51]={"Matias","Maria","Pablo"};
    char lastNameAux[][51]={"Rueda","Gonsalez","Fernandez"};
    float salaryAux[3]={1000,2000,3000};
    int sectorAux[3]={1,2,3};
    int i;
    for(i=0;i<3;i++)
        {
            pEmployee[i].id=idAux[i];
            pEmployee[i].salary=salaryAux[i];
            pEmployee[i].sector=sectorAux[i];
            strcpy(pEmployee[i].lastName, lastNameAux[i]);
            strcpy(pEmployee[i].name, nameAux[i]);
            pEmployee[i].isEmpty=FULL;
        }
}
/********************************************************************************************/
/** \brief funcion que genera un ID, iniciando en 103 para dar desde el 104 en adelante
 * \param void
 * \return int Retorna el id generado
 */
int empleadoscreatId ()
{
    static int contar=103;
    contar++;
    return contar;
}
/********************************************************************************************/
int empleados_findFreeSpace (eEmployee* pEmployee, int cantidad)
{
    int i, space=-1; //devuelve -1 en caso de no encontrar espacio libre

    for(i=0;i<cantidad;i++)
        {
            if(pEmployee[i].isEmpty==FREE)
                {
                    space=i;
                    break;
                }
        }
    return space;
}
/********************************************************************************************/
int empleados_findByID (eEmployee* pEmployee, int cantidad, int id)
{
    int i, indice=-1;
    for(i=0;i<cantidad;i++)
        {
            if(pEmployee[i].isEmpty==FULL && pEmployee[i].id=id)
                {
                    indice=i;
                    break;
                }
        }
    return indice;
}
/********************************************************************************************/
void empleados_darDeAlta (eEmployee* pEmployee, int cantidad)
{
    int lugar, i;
    int aux_id, aux_sector;
    char aux_name[51], aux_lastName[51];
    float aux_salario;
    char verificarSalario[999999];

    lugar=empleados_findFreeSpace(pEmployed, cantidad);

    if(lugar == -1)
        {
            printf("\n :::::::::::::::::::::::::::::::::::::::::::::::::\n");
            printf(" ::  Memoria llena, imposible seguir operando.  ::\n");
            printf(" :::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
        }
    else
        {
            getValidString("\n\n APELLIDO: ","\n\n ERROR, apellido invalido\n",aux_lastName);
            for(i=0;i<strlen(aux_lastName);i++)
                {
                    if(i==0)
                        {
                            aux_lastName[i]=toupper(aux_lastName[i]);
                        }
                }

            getValidString("\n\n NOMBRE: ","\n\n ERROR, nombre invalido\n",aux_name);
            for(i=0;i<strlen(aux_name);i++)
                {
                    if(i==0)
                        {
                            aux_name[i]=toupper(aux_name[i]);
                        }
                }

            while(getStringNumerosFlotantes("\n SUELDO: ", verificarSalario)==0 || ( (atoi(verificarSalario))<0 || (atoi(verificarSalario))>9999.99 ) )
                        {
                           printf("\n\n Error. Importe invalido: \n");
                           printf("\n - Debe ser numerico.");
                           printf("\n - Fuera de rango \n\n");
                        }
            aux_salario=atoi(verificarSalario);

            aux_sector=getValidInt("\n\n SECTOR : ","ERROR, sector incorrecto\n Sectores:\n 1-cobranzas\n 2-Atencion al cliente\n 3-Envios \n\n",1,3);

            aux_id=empleadoscreatId();

            printf("\n ID generado: %d \n\n", aux_id );

            if(addEmployees(pEmployee, cantidad,aux_id,aux_lastName,aux_name,aux_sector,aux_salario,lugar) == -1)
                {
                    printf("\n\n ERROR en la carga de datos \n");
                }
            else
                {
                    printf("\n\n Alta exitosa!  \n");
                }
        }
}
/********************************************************************************************/

int addEmployees (eEmployee* pEmployee, int cantidad, int subir_id, char subir_lastName[], char subir_name[], int subir_sector, int subir_salario, int indice)
{
    int retorna=-1;
    if(pEmployee!=NULL && subir_lastName!=NULL && subir_name!=NULL && subir_id!=NULL )
        {
            pEmployee[indice].id=subir_id;
            strcpy(pEmployee[indice].lastName, subir_lastName);
            strcpy(pEmployee[indice].name, subir_name);
            pEmployee[indice].salary=subir_salario;
            pEmployee[indice].sector=subir_sector;
            pEmployee[indice].isEmpty=FULL;

            retorna=0;
        }
    return retorna;
}
