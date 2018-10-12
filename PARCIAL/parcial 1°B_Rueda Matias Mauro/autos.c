#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "autos.h"

int auto_menu ()
{
    int opc;

    printf("::::::::::::::::::: MENU DE ESTACIONAMIENTO :::::::::::::::::::");
    printf("\n\n");
    printf("1-INGRESO\n");
    printf("2-LISTADO DE VEHICULOS ESCTACIONADOS\n");
    printf("3-EGRESO\n");
    printf("4-REGRESAR\n");;
    printf("\n\n");

    opc=getValidInt("\n Elija una operacion: ", "\n\n  ERROR. Operacion invalida ", 1, 4);

    return opc;
}
/********************************************************************************************/
int auto_inicializar (eAutos* pAuto ,int cantidad)
{
    int i, retorna=-1;
    if(pAuto!=NULL && cantidad>0)
        {
            for(i=0;i<cantidad;i++)
                {
                   pAuto[i].isEmpty_auto==NOESTACIONADO;  //FREE=0 que esta vacio
                }

            retorna=0;
        }
    return retorna;
}
/********************************************************************************************/
int auto_buscarEspacioLibre (eAutos* pAuto, int cantidad)
{
    int i, space=-1; //devuelve -1 en caso de no encontrar espacio libre

    for(i=0;i<cantidad;i++)
        {
            if(pAuto[i].isEmpty_auto==NOESTACIONADO)
                {
                    space=i;
                    break;
                }
        }
    return space;
}
/********************************************************************************************/
int auto_creatId ()
{
    static int contar=999;
    contar++;
    return contar;
}
/********************************************************************************************/
int auto_buscarPorID (eAutos* pAuto, int cantidad, int id)
{
    int i, indice=-1;
    if(pAuto!=NULL)
        {
            for(i=0;i<cantidad;i++)
            {
                if( pAuto[i].id_auto==id && pAuto[i].isEmpty_auto==ESTACIONADO)
                {
                    indice=i;
                    break;
                }
            }
        }
    return indice;
}
/********************************************************************************************/
int auto_mostrarTodos (eAutos* pAuto, int cantidad)
{
    int i;

    printf("\n ID VEHICULO   \t   ID PROPIETARIO   \t   PATENTE   \t   MODELO  ");
    for(i=0;i<cantidad;i++)
        {
            if(pAuto!=NULL && pAuto[i].isEmpty_auto==ESTACIONADO)
                {
                    printf("\n %3d   \t   %5d   \t   %15s   \t   %15s   ",pAuto[i].id_auto,pAuto[i].id_propietario,pAuto[i].patente,pAuto[i].marca);
                }
        }
}
/********************************************************************************************/
void auto_darAlta (eAutos* pAuto, int cantidad, ePropietario* pPropietario, int tam)
{
    int i, lugar, aux_idAuto;
    char aux_patente[51];
    int aux_marca;

    int aux_idPropietario;

    lugar=auto_buscarEspacioLibre(pAuto,cantidad);

    if(lugar==-1)
        {
            printf("\n :::::::::::::::::::::::::::::::::::::::::::::::::\n");
            printf(" ::  Memoria llena, imposible seguir operando.  ::\n");
            printf(" :::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
        }
    else
        {

            printf("\n PATENTE: ");
            setbuf(stdin,NULL);
            scanf("%[^\n]", aux_patente);
            while(esAlfaNumerico(aux_patente)==0)
                {
                    printf("\n\n ERROR, Patente invalidad\n DIRECCION: ");
                    setbuf(stdin,NULL);
                    scanf("%[^\n]", aux_patente);
                }
            for(i=0;i<cantidad;i++) //verifica coincidencia o no
                {
                    if(pAuto!=NULL && pAuto[i].isEmpty_auto==ESTACIONADO)
                        {
                            while(stricmp(pAuto[i].patente,aux_patente)==0 || esAlfaNumerico(aux_patente)==0)
                                {
                                    printf("\n\n La patenete ingresada ya existe en el sistema.\n Reingrese patente: ");
                                    setbuf(stdin,NULL);
                                    scanf("%[^\n]", aux_patente);
                                }
                        }
                }
            strcpy(pAuto[lugar].patente,aux_patente);  //subo la patente

            /**************/

            aux_marca=getValidInt("\n\n Opcion de marca:\n 1-ALPHA ROMEO\n 2-FERRARI\n 3-AUDI\n 4-OTRO\n\n MARCA: ","\n\n ERROR, Opcion invaila.\n\n",1,4);
            switch(aux_marca) //lo subo segun la opcion elegida
            {
            case 1:
                strcpy(pAuto[lugar].marca,"ALPHA ROMEO");
                break;

            case 2:
                 strcpy(pAuto[lugar].marca,"FERRARI");
                 break;

            case 3:
                 strcpy(pAuto[lugar].marca,"AUDI");
                 break;

            case 4:
                strcpy(pAuto[lugar].marca,"OTRO");
                break;

            default:
                printf("\n\n ERROR, Opcion invaila.\n\n");
            }

            /**************/

            aux_idAuto=auto_creatId();
            printf("\n Id del vehiculo generado: %d ", aux_idAuto);
            pAuto[lugar].id_auto=aux_idAuto; //subo el id del auto

            /**************/

            printf("\n\n Propietarios cargados en el sistema: \n");
            prop_print(pPropietario, tam);
            aux_idPropietario=getValidInt("\n\n Id del propietario: ","\n\n ERROR, Id invalido\n\n",100,200);
            pAuto[lugar].id_propietario=aux_idPropietario;  //subo el id del propietario dueño del auto

            /**************/

            pAuto[lugar].isEmpty_auto=ESTACIONADO;
        }
}
/********************************************************************************************/
void auto_darBaja (eAutos* pAuto, int cantidad)
{
    int i, lugar, horas, stop=-1;
    int aux_idAuto;
    char confirmar;
    float precio=0;

    printf("\n Vehiculos en el estacionamiento: ");
    auto_mostrarTodos(pAuto,cantidad);
    aux_idAuto=getValidInt("\n\n Ingrese el ID del vehiculo que se retira del estacionamientos: ","\n\n ERROR. Id invalido\n\n",1000,1020);

    lugar=auto_buscarPorID(pAuto,cantidad,aux_idAuto);

    if(lugar==-1)
        {
            printf("\n\n Vehiculo inexistente en el sistema \n\n");
        }
    else
        {
            if(aux_idAuto==pAuto[lugar].id_auto)
                {
                   do{
                    confirmar=getChar("\n\n El vehiculo se esta retirando del estacionamiento? (s/n):  ");

                    if (confirmar=='s' || confirmar=='S')
                        {
                            pAuto[lugar].id_auto=0;

                            horas=devolverHorasEstadia();
                            printf("\n\n Tiempo de estadia: %d hs\n\n");

                            if(stricmp(pAuto[lugar].marca,"ALPHA ROMEO")==0)
                                {
                                    precio=horas*150;
                                }
                            if(stricmp(pAuto[lugar].marca,"FERRARI")==0)
                                {
                                    precio=horas*175;
                                }
                            if(stricmp(pAuto[lugar].marca,"AUDI")==0)
                                {
                                    precio=horas*200;
                                }
                            if(stricmp(pAuto[lugar].marca,"OTRO")==0)
                                {
                                    precio=horas*250;
                                }

                            printf("\n\n TICKET\n");
                            printf("\n :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
                            printf("\n :: MODELO: %s                                                      ",pAuto[lugar].marca);
                            printf("\n :: PRECIO: $ %.1f                                                ",precio);
                            printf("\n :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

                            stop=1;
                        }
                    else if(confirmar=='n' || confirmar=='N')
                        {
                            printf("\n\n Proceso cancelado\n\n");
                            stop=1;
                        }
                    else
                        {
                            printf("\n\n Respuesta invalida\n");
                            stop=-1;
                        }
                   }while(stop!=1);
                }
        }

}

int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}
