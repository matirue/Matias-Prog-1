#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "propietarios.h"


int prop_menu ()
{
    int opc;

    printf("::::::::::::::::::: MENU DE OPERACIONES :::::::::::::::::::");
    printf("\n\n");
    printf(" 1- AGREGAR PROPIETARIO\n");
    printf(" 2- MODIFICAR NUMERO DE TARJETA\n");
    printf(" 3- DAR DE BAJA PROPIETARIO\n");
    printf(" 4- LISTAR PROPIETARIO/S\n");
    printf(" 5- INGRESO DE VEHICULO\n");
    printf(" 6- LISTA DE VEHICULOS EN EL ESTACIONAMIENTO\n");
    printf(" 7- EGRESO DE VEHICULO\n");
    printf(" 8- RECAUDACION TOTAL DEL ESTACIONAMIENTO\n");
    printf(" 9- RECAUDACION TOTAL POR MARCA\n");
    printf("10- LISTA DE PROPIETARIO CON SU/S VEHICULO/S\n");
    printf("11- LISTA DE PROPIETARIO/S QUE POSEEN VEHICULO MARCA AUDI\n");
    printf("12- LISTA DE VEHICULOS EN EL ESTACIONAMIENTO ORDENADOS POR PATENTE\n");

    printf("\n13- ORDENADO POR MARCA\n");
    printf("14- LISTA DE AUTOS EGRESADOS\n");
    printf("15- TICKET DEL VEHICULO EGRESADO CON MAYOY IMPORTE\n");


    printf("\n20- SALIR\n");
    printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

    opc=getValidInt("\n Elija una operacion: ", "\n\n  ERROR. Operacion invalida ", 1, 20);

    return opc;
}
/********************************************************************************************/
int prop_inicializar (ePropietario* pPropietario ,int cantidad)
{
    int i, retorna=-1;
    if(pPropietario!=NULL && cantidad>0)
        {
            for(i=0;i<cantidad;i++)
                {
                   pPropietario[i].isEmpty==FREE;  //FREE=0 que esta vacio
                }

            retorna=0;
        }
    return retorna;
}
/********************************************************************************************/
void prop_hardCode (ePropietario* pPropietario)
{
    int idAux[5]={100,101,102,103,104};
    char apellidoAux[][51]={"Rueda","Gonsalez","Fernandez","Hernandez","Rodriguez"};
    char nombreAux[][51]={"Matias","Maria","Pablo","Agustina","Aldana"};
    char direccionAux [][100]={"Localidad 111","Localidad 222","Localidad 333","Localidad 444","Localidad 555"};
    int tarjetaAux[5]={10001,20002,30003,40004,50005};

    int i;
    for(i=0;i<5;i++)
        {
            pPropietario[i].idPropietario=idAux[i];
            strcpy(pPropietario[i].apellido, apellidoAux[i]);
            strcpy(pPropietario[i].nombre, nombreAux[i]);
            strcpy(pPropietario[i].direccion, direccionAux[i]);
            pPropietario[i].numTarjeta=tarjetaAux[i];

            pPropietario[i].isEmpty=FULL;
        }
}
/********************************************************************************************/
/** \brief funcion que genera un ID, iniciando en 103 para dar desde el 104 en adelante
 * \param void
 * \return int Retorna el id generado
 */
int prop_creatId ()
{
    static int contar=104;
    contar++;
    return contar;
}
/********************************************************************************************/
int prop_buscarEspacioLibre (ePropietario* pPropietario, int cantidad)
{
    int i, space=-1; //devuelve -1 en caso de no encontrar espacio libre

    for(i=0;i<cantidad;i++)
        {
            if(pPropietario[i].isEmpty==FREE)
                {
                    space=i;
                    break;
                }
        }
    return space;
}
/********************************************************************************************/
int prop_buscarPorID (ePropietario* pPropietario, int cantidad, int id)
{
    int i, indice=-1;
    if(pPropietario!=NULL)
        {
            for(i=0;i<cantidad;i++)
            {
                if( pPropietario[i].idPropietario==id && pPropietario[i].isEmpty==FULL)
                {
                    indice=i;
                    break;
                }
            }
        }
    return indice;
}
/********************************************************************************************/
void prop_darDeAlta (ePropietario* pPropietario, int cantidad)
{
    int lugar, i;
    int aux_id, aux_tarjeta;
    char aux_name[51], aux_lastName[51], aux_direccion[100];

    lugar=prop_buscarEspacioLibre(pPropietario,cantidad);

    if(lugar == -1)
        {
            printf("\n :::::::::::::::::::::::::::::::::::::::::::::::::\n");
            printf(" ::  Memoria llena, imposible seguir operando.  ::\n");
            printf(" :::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
        }
    else
        {
            getValidString("\n APELLIDO: ","\n\n ERROR, apellido invalido\n",aux_lastName);
            for(i=0;i<strlen(aux_lastName);i++)
                {
                    if(i==0)
                        {
                            aux_lastName[i]=toupper(aux_lastName[i]);
                        }
                }

            getValidString("\n NOMBRE: ","\n\n ERROR, nombre invalido\n",aux_name);
            for(i=0;i<strlen(aux_name);i++)
                {
                    if(i==0)
                        {
                            aux_name[i]=toupper(aux_name[i]);
                        }
                }

            printf("\n DIRECCION: ");
            setbuf(stdin,NULL);
            scanf("%[^\n]", aux_direccion);
            while(esAlfaNumerico(aux_direccion)==0)
                {
                    printf("\n\n ERROR, direccion invalidad\n DIRECCION: ");
                    setbuf(stdin,NULL);
                    scanf("%[^\n]", aux_direccion);

                }
            for(i=0;i<strlen(aux_direccion);i++)
                {
                    if(i==0)
                        {
                            aux_direccion[i]=toupper(aux_direccion[i]);
                        }
                }

            aux_tarjeta=getValidInt("\n TARJETA DE CREDITO (5 NUMEROS) : ","ERROR, numero invalido \n\n",00000,99999);

            aux_id=prop_creatId();

            printf("\n\n Id generado: %d",aux_id);

            prop_setDatos(pPropietario, lugar, aux_id, aux_lastName,aux_name,aux_direccion,aux_tarjeta);

            printf("\n\n Alta exitosa!!!!!\n\n");
        }
}
/********************************************************************************************/
 void prop_setDatos (ePropietario* pPropietario, int lugar, int id, char apellido[], char nombre[], char direccion[], int tarjeta )
 {
     pPropietario[lugar].idPropietario=id;
     strcpy(pPropietario[lugar].apellido, apellido);
     strcpy(pPropietario[lugar].nombre, nombre);
     strcpy(pPropietario[lugar].direccion, direccion);
     pPropietario[lugar].numTarjeta=tarjeta;

     pPropietario[lugar].isEmpty=FULL;

 }
 /********************************************************************************************/

/********************************************************************************************/
int prop_print (ePropietario* pPropietario, int cantidad)
{
    int retorna=-1, i;

    for(i=0;i<cantidad;i++)
        {
            if(pPropietario!=NULL && cantidad>0)
                {
                    printf("\n ID  \t APELLIDO  \t  NOMBRE  \t   DIRECCION  \t    TARJETA DE CREDITO");

                    for(i=0;i<cantidad;i++)
                        {
                            if(pPropietario[i].isEmpty==FULL)
                                {
                                    printf("\n  %d  \t  %5s  \t  %5s  \t  %5s \t %10d  ",pPropietario[i].idPropietario,pPropietario[i].apellido,pPropietario[i].nombre,pPropietario[i].direccion,pPropietario[i].numTarjeta);
                                    retorna=0;
                                }
                        }
                }
        }
    return retorna;
}

void prop_ordenar_apelidoNombre (ePropietario* pPropietario, int cantidad)
{
    ePropietario auxiliar;
    int i,j, noOrdenado=-1;
    if(pPropietario!=NULL && cantidad>0)
        {
            while(noOrdenado==-1)
            {
                noOrdenado=0;

                for(i=0;i<cantidad-1;i++)
                    {
                        for(j=i+1;j<cantidad;j++)
                            {
                                if(strcmp(pPropietario[j].apellido, pPropietario[i].apellido)<0)
                                    {
                                        auxiliar=pPropietario[i];
                                        pPropietario[i]=pPropietario[j];
                                        pPropietario[j]=auxiliar;

                                        noOrdenado=-1;
                                    }
                                else if(strcmp(pPropietario[j].apellido, pPropietario[i].apellido)==0 && strcmp(pPropietario[j].nombre, pPropietario[i].nombre)<0)
                                    {
                                        auxiliar=pPropietario[i];
                                        pPropietario[i]=pPropietario[j];
                                        pPropietario[j]=auxiliar;

                                        noOrdenado=-1;
                                    }

                            }
                    }
            }
        }
}

int prop_print_ordenCrecienteNombreApellido (ePropietario* pPropietario, int cantidad)
{
    int retorna=-1, i;

    prop_ordenar_apelidoNombre(pPropietario,cantidad);

    for(i=0;i<cantidad;i++)
        {
            if(pPropietario!=NULL && cantidad>0)
                {
                    printf("\n ID  \t APELLIDO  \t  NOMBRE  \t   DIRECCION  \t    TARJETA DE CREDITO");

                    for(i=0;i<cantidad;i++)
                        {
                            if(pPropietario[i].isEmpty==FULL)
                                {
                                    printf("\n  %d  \t  %5s  \t  %5s  \t  %5s \t %10d  ",pPropietario[i].idPropietario,pPropietario[i].apellido,pPropietario[i].nombre,pPropietario[i].direccion,pPropietario[i].numTarjeta);
                                    retorna=0;
                                }
                        }
                }
        }
    return retorna;
}
/********************************************************************************************/

void prop_actualizar (ePropietario* pPropietario, int cantidad)
{
    int i, aux_id, lugar;
    int aux_tarjeta;
    //char aux_lastName[51], aux_name[51], aux_direccion[100];
    int stop=-1;
    char confirmar;

    aux_id=getValidInt("\n ID del propietario a actulizar: ","\n ERROR, id invalido\n\n ", 100,120);


    lugar=prop_buscarPorID(pPropietario,cantidad,aux_id);

    if(pPropietario!=NULL)
        {
            if(lugar>=0)
                {
                        system("cls");
                        printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
                        printf("\ Propietario a renovar: \nID: %d \n APELLIDO: %s \n NOMBRE: %s \n DIRECCION: %s \n NUMERO TARJETA: %d \n",pPropietario[lugar].idPropietario,pPropietario[lugar].apellido,pPropietario[lugar].nombre,pPropietario[lugar].direccion,pPropietario[lugar].numTarjeta);
                        printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

                        confirmar=getChar("\n Desea actualizar? (s/n):  ");

            do{
                if(confirmar=='s')
                {
                    aux_tarjeta=getValidInt("\n\n NUEVO NUMERO DE TARJETA : ","ERROR, numero invalido \n\n",00000,99999);
                    pPropietario[lugar].numTarjeta=aux_tarjeta;
                    stop=1;
                }
                else if(confirmar=='n')
                {
                    printf("\n\n Actualizacion cancelada\n\n");
                    stop=1;
                }
                else
                {
                    printf("\n Respuesta invalida\n");
                    stop=-1;
                }
            }while(stop!=1);

                }
                else
                {
                        printf("\n :::::::::::::::::::::::::::::::::::::::::::::::::\n");
                        printf(" ::  Id: %d no existe en el sistema.             ::\n",aux_id);
                        printf(" :::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
                }
        }
}

