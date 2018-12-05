#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "autos.h"
/*
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
}*/

void auto_hardCode(eAutos* pAuto)
{
    int id[5]={1000,1001,1002,1003,1004};
    char patente[5][51]={"aaa111","bbb222","ccc333","ddd444","eee555"};
    int marca[5]={4,2,3,1,2};
    int idDelProp[5]={100,101,102,100,104};
    int i;
    for(i=0;i<5;i++)
        {
            pAuto[i].id_auto=id[i];
            strcpy(pAuto[i].patente, patente[i]);
            pAuto[i].marca=marca[i];
            pAuto[i].id_propietario=idDelProp[i];

            pAuto[i].isEmpty_auto=ESTACIONADO;
        }

}


/********************************************************************************************/
int auto_inicializar (eAutos* pAuto ,int cantidad)
{
    int i, retorna=-1;
    if(pAuto!=NULL && cantidad>0)
        {
            for(i=0;i<cantidad;i++)
                {
                   pAuto[i].isEmpty_auto=NOESTACIONADO;  //FREE=0 que esta vacio
                   pAuto[i].importe=0;
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
    static int contar=1004;
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

int auto_buscarPorID_delPropietario (eAutos* pAuto, int cantidad, int id)
{
    int i, indice=-1;
    if(pAuto!=NULL)
        {
            for(i=0;i<cantidad;i++)
            {
                if( pAuto[i].id_propietario==id && pAuto[i].isEmpty_auto==ESTACIONADO)
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

    printf("\n ID VEHICULO   \t   ID PROPIETARIO   \t   PATENTE   \t        MARCA  ");
    for(i=0;i<cantidad;i++)
        {
            if(pAuto!=NULL && pAuto[i].isEmpty_auto==ESTACIONADO)
                {
                    //printf("\n %3d   \t   %5d   \t   %15s   \t   %15s   ",pAuto[i].id_auto,pAuto[i].id_propietario,pAuto[i].patente,pAuto[i].marca);
                    auto_mostrarUno (pAuto[i]);
                }
        }
}

void auto_mostrarUno (eAutos pAuto)
{
    char marca[51];

    if(pAuto.marca==1)
        {
            strcpy(marca, "ALPHA_ROMEO");
        }

    if(pAuto.marca==2)
        {
           strcpy(marca, "FERRARI");
        }

    if(pAuto.marca==3)
        {
            strcpy(marca, "AUDI");
        }

    if(pAuto.marca==4)
        {
            strcpy(marca, "OTRO");
        }



    printf("\n %3d   \t   %5d   \t   %15s   \t   %15s   ",pAuto.id_auto,pAuto.id_propietario,pAuto.patente,marca);
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
            pAuto[lugar].marca=aux_marca;

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
void auto_darBaja (eAutos* pAuto, int cantidad, ePropietario* pPropietario, int tam)
{
    int i, lugar, horas, stop=-1;
    int indiceProp;
    int aux_idAuto;
    char confirmar, marca[51];
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
                   indiceProp=prop_buscarPorID(pPropietario,tam,pAuto[lugar].id_propietario);

                   do{
                    confirmar=getChar("\n\n El vehiculo se esta retirando del estacionamiento? (s/n):  ");

                    if (confirmar=='s' || confirmar=='S')
                        {

                            horas=devolverHorasEstadia();
                            printf("\n\n Tiempo de estadia: %d hs\n\n", horas);


                            if(pAuto[lugar].marca==1)///alpha romeo
                                {
                                    precio=horas*150;
                                    strcpy(marca,"ALPHA_ROMEO");
                                }
                            if(pAuto[lugar].marca==2) ///Ferrari
                                {
                                    precio=horas*175;
                                    strcpy(marca,"FERRARI");
                                }
                            if(pAuto[lugar].marca==3) ///audi
                                {
                                    precio=horas*200;
                                    strcpy(marca,"AUDI");
                                }
                            if(pAuto[lugar].marca==4)///otro
                                {
                                    precio=horas*250;
                                    strcpy(marca,"OTRO");
                                }

                            pAuto[lugar].importe=precio;
                            pAuto[lugar].isEmpty_auto=EGRESO;

                            printf("\n TICKET\n");
                            printf("\n :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
                            printf("\n :: PROPIRTARIO: %s %s                                                   ",pPropietario[indiceProp].nombre,pPropietario[indiceProp].apellido);
                            printf("\n :: PATENTE: %s                                                      ",pAuto[lugar].patente);
                            printf("\n :: MARCA: %s                                                      ",marca);
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
/********************************************************************************************/
void auto_PropPorID_ConAuto (eAutos* pAuto, int cant_auto, ePropietario* pPropietario, int cant_propietario)
{
    int auxID, existe, i;
    char marca[51];

    if(pAuto!=NULL && pPropietario!=NULL)
        {
            printf("\n Propietarios cargados: \n\n");
            prop_print(pPropietario, cant_propietario);

            auxID=getValidInt("\n Ingrese ID del propietario: ","ERROR. Id invalido", 1,1000);

            existe=prop_buscarPorID(pPropietario,cant_propietario,auxID);

            if(existe!=-1)
                {
                    printf("\n NOMBRE    \t   PATENTE   \t        MARCA  \n");

                    for(i=0;i<cant_auto;i++)
                        {
                            if(pPropietario[existe].idPropietario==pAuto[i].id_propietario && pPropietario[existe].isEmpty==FULL && pAuto[i].isEmpty_auto==ESTACIONADO)
                                {
                                    if(pAuto[i].marca==1)
                                      {
                                          strcpy(marca, "ALPHA_ROMEO");
                                      }
                                    if(pAuto[i].marca==2)
                                      {
                                          strcpy(marca, "FERRARI");
                                      }
                                    if(pAuto[i].marca==3)
                                      {
                                          strcpy(marca, "AUDI");
                                      }
                                    if(pAuto[i].marca==4)
                                      {
                                          strcpy(marca, "OTRO");
                                      }

                                      printf(" %s    \t   %4s    \t    %10s   \n",pPropietario[existe].nombre,pAuto[i].patente,marca);
                                }
                        }
                }
           else
            {
                printf("\n\n ID IINEXISTENTE \n\n");
            }
        }
}
/********************************************************************************************/

void auto_recaudacion_total (eAutos* pAuto, int cantidad)
{
    int i;
    float total=0;

    if(pAuto!=NULL)
        {
           for(i=0;i<cantidad;i++)
             {
                total+=pAuto[i].importe;
             }
             printf("\n\n------------------------------------------------\n");
             printf("   Se registro una recaudacion de:  $ %.2f  \n",total);
             printf("------------------------------------------------\n\n");
        }
}
/********************************************************************************************/

void auto_recaudacion_PorMarca (eAutos* pAuto, int cantidad)
{
    int i;
    float total_Alpha=0, total_Ferrari=0, total_Audi=0, total_Otro=0;

    if(pAuto!=NULL)
        {
            for(i=0;i<cantidad;i++)
                {
                    if(pAuto[i].marca==1)
                        {
                            total_Alpha+=pAuto[i].importe;
                        }
                    if(pAuto[i].marca==2)
                        {
                            total_Ferrari+=pAuto[i].importe;
                        }
                    if(pAuto[i].marca==3)
                        {
                            total_Audi+=pAuto[i].importe;
                        }
                    if(pAuto[i].marca==4)
                        {
                            total_Otro+=pAuto[i].importe;
                        }
                }

             printf("\n\n------------------------------------------------\n");
             printf("   Se registro una recaudacion de:          \n");
             printf("   ALPHA ROMEO: $ % .2f          \n",total_Alpha);
             printf("   FERRARI: $ % .2f          \n",total_Ferrari);
             printf("   AUDI: $ % .2f          \n",total_Audi);
             printf("   OTRO: $ % .2f          \n",total_Otro);
             printf("------------------------------------------------\n\n");
        }

}

/********************************************************************************************/

void auto_ListaPropietarios_Audi (ePropietario* pPropietario, int cantidad_prop, eAutos* pAuto, int cantidad_auto)
{
    int indiceAuto, indiceProp;

    if(pPropietario!=NULL && pAuto!=NULL)
        {
            printf("\n ID PROPIETARIO \t    NOMBRE     \t    APELLIDO    \t      DIRECCION      \t    TARJETA   \n");

            for(indiceAuto=0;indiceAuto<cantidad_auto;indiceAuto++)
                {
                    if(pAuto[indiceAuto].marca==3 && pAuto[indiceAuto].isEmpty_auto==ESTACIONADO)
                        {
                            for(indiceProp=0;indiceProp<cantidad_prop;indiceProp++)
                                {
                                    if(pAuto[indiceAuto].id_propietario==pPropietario[indiceProp].idPropietario)
                                        {
                                            printf(" %8d  \t    %13s     \t    %5s    \t      %10s      \t    %5d   \n",pPropietario[indiceProp].idPropietario,pPropietario[indiceProp].nombre,pPropietario[indiceProp].apellido,pPropietario[indiceProp].direccion,pPropietario[indiceProp].direccion);
                                        }
                                }
                        }
                }
        }
}
/********************************************************************************************/

void auto_listaEstacionados_ordenPatente_conProp (ePropietario* pPropietario, int cantidad_prop, eAutos* pAuto, int cantidad_auto)
{
    int indiceProp, indiceAuto;
    int i,j;
    char marca[51];

    if(pAuto!=NULL && pPropietario!=NULL)
        {

            auto_ordenPatente(pAuto,cantidad_auto);

             printf("\n PATENTE    --     MARCA     --  ID VEHICULO  -- ID PROPIETARIO --   NOMBRE   --    APELLIDO    --     DIRECCION     --    TARJETA   \n");
             for(i=0;i<cantidad_auto;i++)
                {
                    if(pAuto[i].isEmpty_auto==ESTACIONADO)
                        {
                            for(j=0;j<cantidad_prop;j++)
                                {
                                    if(pPropietario[j].isEmpty==FULL && pAuto[i].id_propietario==pPropietario[j].idPropietario)
                                        {
                                            if(pAuto[i].marca==1)
                                                {
                                                    strcpy(marca,"ALPHA_ROMEO");
                                                }
                                            if(pAuto[i].marca==2)
                                                {
                                                    strcpy(marca,"FERRARI");
                                                }
                                            if(pAuto[i].marca==3)
                                                {
                                                    strcpy(marca,"AUDI");
                                                }
                                            if(pAuto[i].marca==4)
                                                {
                                                    strcpy(marca,"OTRO");
                                                }
                                           // printf(" %s  \t  %3s    \t    %5d    \t     %5d    \t    %10s    \t    %7s    \t    %7s    \t   %d   \n",pAuto[i].patente,marca,pAuto[i].id_auto,pPropietario[j].idPropietario,pPropietario[j].nombre,pPropietario[j].apellido,pPropietario[j].direccion,pPropietario[j].numTarjeta);
                                            printf(" %s    %12s        %5d         %10d         %10s           %7s           %7s            %d   \n",pAuto[i].patente,marca,pAuto[i].id_auto,pPropietario[j].idPropietario,pPropietario[j].nombre,pPropietario[j].apellido,pPropietario[j].direccion,pPropietario[j].numTarjeta);
                                        }
                                }
                        }
                }
        }



}

void auto_ordenPatente (eAutos* pAuto, int cantidad)
{
    eAutos aux;
    int i,j;

    for(i=0;i<cantidad-1;i++)
        {
            if(pAuto[i].isEmpty_auto==ESTACIONADO)
            {
               for(j=i+1;j<cantidad;j++)
                {
                    if(pAuto[j].isEmpty_auto==ESTACIONADO && stricmp(pAuto[i].patente,pAuto[j].patente)>0 )
                        {
                            aux=pAuto[i];
                            pAuto[i]=pAuto[j];
                            pAuto[j]=aux;
                        }
                }

            }
        }
}

/********************************************************************************************/

void prop_darBaja (ePropietario* pPropietario, int cantidad, eAutos* pAuto, int tam)
{
    int aux_id, stop=-1, baja;
    char confirmar;

    aux_id=getValidInt("\n\n Ingrese el ID del propietario a dar de baja del sistema: ","ERROR. Id invalido", 1,1000);

    baja=prop_remove(pPropietario,cantidad,aux_id,pAuto,tam);

    if(baja==1)
        {
            printf("\n Baja de propietario exitosa. \n");
        }
    else if(baja==0)
        {
            printf("\n\n Baja cancelada \n\n");
        }
    else{
            printf("\n\n ERROR en la baja \n\n");
        }

}
/********************************************************************************************/
int prop_remove (ePropietario* pPropietario, int cantidad, int bajaID, eAutos* pAuto, int tam)
{
    int existe, indiceAuto, i, confirmar, stop = -1, retorna=-1;

    existe=prop_buscarPorID(pPropietario,cantidad,bajaID);

    if(existe== -1)
        {
            printf("\n :::::::::::::::::::::::::::::::::::::::::::::::::\n");
            printf(" ::  Id: %d no existe en el sistema.             ::\n",bajaID);
            printf(" :::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
        }
    else
        {

            printf("\n\n Se encontro: \n ID: %d \n APELLIDO: %s \n NOMBRE: %s \n DIRECCION: %s \n NUMERO TARJETA: %d \n",pPropietario[existe].idPropietario,pPropietario[existe].apellido,pPropietario[existe].nombre,pPropietario[existe].direccion,pPropietario[existe].numTarjeta);

            confirmar=getChar("\n Confirmar baja? (s/n):  ");

            do{
                if(confirmar=='s'||confirmar=='S')
                {
                    pPropietario[existe].isEmpty=FREE;
                    for(i=0;i<tam;i++)
                        {
                            indiceAuto=auto_buscarPorID_delPropietario(pAuto,tam,bajaID);
                            pAuto[indiceAuto].isEmpty_auto=NOESTACIONADO;
                        }

                    stop=1;
                    retorna=1;
                }
                else if(confirmar=='n'||confirmar=='N')
                {
                    stop=1;
                    retorna=0;
                }
                else
                {
                    printf("\n Respuesta invalida\n");
                    stop=-1;
                }
            }while(stop!=1);


        }
        return retorna;
}
/********************************************************************************************/
/********************************************************************************************/
void auto_lista_ordenarPorMarca (ePropietario* pPropietario, int cantidad_prop, eAutos* pAuto, int cantidad_auto)
{
    int indiceProp, indiceAuto;
    int i,j;
    char marca[51];

    if(pAuto!=NULL && pPropietario!=NULL)
        {

            auto_ordenMarca(pAuto,cantidad_auto);

             printf("\n PATENTE    --     MARCA     --  ID VEHICULO  -- ID PROPIETARIO --   NOMBRE   --    APELLIDO    --     DIRECCION     --    TARJETA   \n");
             for(i=0;i<cantidad_auto;i++)
                {
                    if(pAuto[i].isEmpty_auto==ESTACIONADO)
                        {
                            for(j=0;j<cantidad_prop;j++)
                                {
                                    if(pPropietario[j].isEmpty==FULL && pAuto[i].id_propietario==pPropietario[j].idPropietario)
                                        {
                                            if(pAuto[i].marca==1)
                                                {
                                                    strcpy(marca,"ALPHA_ROMEO");
                                                }
                                            if(pAuto[i].marca==2)
                                                {
                                                    strcpy(marca,"FERRARI");
                                                }
                                            if(pAuto[i].marca==3)
                                                {
                                                    strcpy(marca,"AUDI");
                                                }
                                            if(pAuto[i].marca==4)
                                                {
                                                    strcpy(marca,"OTRO");
                                                }
                                           // printf(" %s  \t  %3s    \t    %5d    \t     %5d    \t    %10s    \t    %7s    \t    %7s    \t   %d   \n",pAuto[i].patente,marca,pAuto[i].id_auto,pPropietario[j].idPropietario,pPropietario[j].nombre,pPropietario[j].apellido,pPropietario[j].direccion,pPropietario[j].numTarjeta);
                                            printf(" %s    %12s        %5d         %10d         %10s           %7s           %7s            %d   \n",pAuto[i].patente,marca,pAuto[i].id_auto,pPropietario[j].idPropietario,pPropietario[j].nombre,pPropietario[j].apellido,pPropietario[j].direccion,pPropietario[j].numTarjeta);
                                        }
                                }
                        }
                }
        }
}

void auto_ordenMarca (eAutos* pAuto, int cantidad)
{
    eAutos aux;
    int i,j;

    for(i=0;i<cantidad-1;i++)
        {
            if(pAuto[i].isEmpty_auto==ESTACIONADO)
            {
               for(j=i+1;j<cantidad;j++)
                {
                    if(pAuto[j].isEmpty_auto==ESTACIONADO && (pAuto[i].marca>pAuto[j].marca) )
                        {
                            aux=pAuto[i];
                            pAuto[i]=pAuto[j];
                            pAuto[j]=aux;
                        }
                }

            }
        }
}
/********************************************************************************************/
void auto_hardCodeEgreso(eAutos* pAuto)
{
    int id[3]={999,998,997};
    char patente[3][51]={"zzz999","xxx888","sss777"};
    int marca[3]={3,1,2};
    int idDelProp[3]={102,103,104};
    float importe[3]={52.2,3897.9,4.1};
    int i;
    for(i=0;i<3;i++)
        {
            pAuto[i].id_auto=id[i];
            strcpy(pAuto[i].patente, patente[i]);
            pAuto[i].marca=marca[i];
            pAuto[i].id_propietario=idDelProp[i];
            pAuto[i].importe=importe[i];

            pAuto[i].isEmpty_auto=EGRESO;
        }

}

void auto_lista_autosEgresados (eAutos* pAuto, int cantidad)
{
    int i;
    char marca[51];

    if(pAuto!=NULL)
        {
            printf("\n ID VEHICULO \t ID PROPIETARIO \t PATENTE \t MARCA   \t     IMPORTE   \n");

            auto_ordenIDauto(pAuto,cantidad);
            for(i=0;i<cantidad;i++)
                {
                    if(pAuto[i].isEmpty_auto==EGRESO)
                        {
                                            if(pAuto[i].marca==1)
                                                {
                                                    strcpy(marca,"ALPHA_ROMEO");
                                                }
                                            if(pAuto[i].marca==2)
                                                {
                                                    strcpy(marca,"FERRARI");
                                                }
                                            if(pAuto[i].marca==3)
                                                {
                                                    strcpy(marca,"AUDI");
                                                }
                                            if(pAuto[i].marca==4)
                                                {
                                                    strcpy(marca,"OTRO");
                                                }
                            printf(" %6d \t %9d \t %14s \t %3s  \t  $ %2.2f  \n",pAuto[i].id_auto,pAuto[i].id_propietario,pAuto[i].patente,marca,pAuto[i].importe);
                        }
                }


        }
}

void auto_ordenIDauto (eAutos* pAuto, int cantidad)
{
    eAutos aux;
    int i,j;

    for(i=0;i<cantidad-1;i++)
        {
            if(pAuto[i].isEmpty_auto==EGRESO)
            {
               for(j=i+1;j<cantidad;j++)
                {
                    if(pAuto[j].isEmpty_auto==EGRESO && (pAuto[i].id_auto>pAuto[j].id_auto) )
                        {
                            aux=pAuto[i];
                            pAuto[i]=pAuto[j];
                            pAuto[j]=aux;
                        }
                }

            }
        }
}
/********************************************************************************************/
void auto_ticketMayorImporte (eAutos* pAuto, int cantidad, ePropietario* pPropietario, int cantidadProp)
{
    int i, j, k, indice, indicemax, flag=-1;
    float auxMayorImporte;
    char marca[51];

    if(pAuto!=NULL && pPropietario!=NULL)
        {
            for(i=0;i<cantidad-1;i++)
                {
                    if(pAuto[i].isEmpty_auto==EGRESO)
                        {
                            for(j=i+1;j<cantidad;j++)
                                {
                                    if(pAuto[j].isEmpty_auto==EGRESO)
                                        {
                                            if(pAuto[i].importe<pAuto[j].importe)
                                                {
                                                    indicemax=j;

                                                    flag=0;
                                                }
                                                else
                                                    {
                                                        indicemax=i;
                                                        flag=0;
                                                    }

                                        }
                                }
                        }

                }

            if(flag==0)
                {
                    indice=prop_buscarPorID(pPropietario,cantidadProp,pAuto[indicemax].id_propietario);

                    if(indice!=-1)
                        {
                                            if(pAuto[indicemax].marca==1)
                                                {
                                                    strcpy(marca,"ALPHA_ROMEO");
                                                }
                                            if(pAuto[indicemax].marca==2)
                                                {
                                                    strcpy(marca,"FERRARI");
                                                }
                                            if(pAuto[indicemax].marca==3)
                                                {
                                                    strcpy(marca,"AUDI");
                                                }
                                            if(pAuto[indicemax].marca==4)
                                                {
                                                    strcpy(marca,"OTRO");
                                                }

                            printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
                            printf("\n::: PROPIETARIO: %s %s                   \n",pPropietario[indice].nombre, pPropietario[indice].apellido);
                            printf("\n::: PATENTE: %s                 \n",pAuto[indicemax].patente);
                            printf("\n::: MARCA: %s                    \n",marca);
                            printf("\n::: IMPORTE: $ %.2f              \n",pAuto[indicemax].importe);
                            printf("\n:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
                        }
                }
            else
                {
                    printf("\n\n NO HAY AUTOS EGRESADOS\n\n");
                }
        }

}


/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/
/********************************************************************************************/

