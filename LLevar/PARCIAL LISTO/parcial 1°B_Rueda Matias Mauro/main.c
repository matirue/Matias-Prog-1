#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "propietarios.h"
#include "autos.h"

#define CANT_PROP 100
#define CANT_VEHICULO 20

int main()
{

    int salir=0; //salir_estacionamiento=0;
    int i;

    ePropietario miPropietario[CANT_PROP];
    eAutos miAuto[CANT_VEHICULO];



    if(prop_inicializar(miPropietario, CANT_PROP)==-1)
    {
        printf("\n :::::::::::::::::::: ALERTA! ::::::::::::::::::::\n");
        printf(" ::  Memoria llena, imposible seguir operando.  ::\n");
        printf(" :::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
    }
    else
    {
        //empleados_hardCode(employee); //carga dato al sistema
        prop_hardCode(miPropietario);
        auto_hardCode(miAuto);

        do
        {
            system("cls");

            switch(prop_menu())
            {
            case 1:
                system("cls");
                printf("::::::::::::::   DAR DE ALTA PROPIETARIO   ::::::::::::::\n");
                prop_darDeAlta(miPropietario,CANT_PROP);
                system("pause");
                break;

            case 2:
                system("cls");
                printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");

                printf(" Lista de empleados cargados\n");
                prop_print(miPropietario, CANT_PROP);

                printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
                printf("::::::::::::::   ACTUALIZAR   ::::::::::::::\n");

                prop_actualizar(miPropietario, CANT_PROP);

                system("pause");
                break;

            case 3:
                system("cls");
                printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");

                printf(" Lista de propietarios cargados\n");
                prop_print(miPropietario, CANT_PROP);

                printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
                printf("\n:::::::::::::           DAR DE BAJA           ::::::::::::::\n");
                prop_darBaja(miPropietario,CANT_PROP,miAuto,CANT_VEHICULO);

                system("pause");
                break;

            case 4:
                system("cls");
                printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
                //printf("\n:::::::::::::::      LISTAR      :::::::::::::::\n");
                //prop_print(miPropietario,CANT_PROP);

               // printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
                printf("\n:::::::::::::::      LISTAR POR APELLIDO Y NOMBRE      :::::::::::::::\n");
                prop_print_ordenCrecienteNombreApellido(miPropietario,CANT_PROP);
                printf("\n\n");
                system("pause");
                break;

            case 5:
                system("cls");
                printf("::::::::::::::   VEHICULO INGRESANTE   ::::::::::::::\n");
                auto_darAlta(miAuto,CANT_VEHICULO,miPropietario,CANT_PROP);
                system("pause");
                break;

           case 6:
                system("cls");
                printf("\n:::::::::::::::      LISTA DE VEHICULOS EN EL ESTACIONAMIENTO      :::::::::::::::\n");
                auto_mostrarTodos(miAuto,CANT_VEHICULO);
                printf("\n\n");
                system("pause");
                break;

           case 7:
               system("cls");
               printf("::::::::::::::   EGRESO VEHICULO    ::::::::::::::\n");
               auto_darBaja(miAuto,CANT_VEHICULO,miPropietario,CANT_PROP);
               system("pause");
               break;

          case 8:
               system("cls");
               printf("::::::::::::::   RECAUDACION    ::::::::::::::\n");
               auto_recaudacion_total(miAuto,CANT_VEHICULO);
               system("pause");
               break;

          case 9:
               system("cls");
               printf("::::::::::::::   RECAUDACION  POR MARCA  ::::::::::::::\n");
               auto_recaudacion_PorMarca(miAuto,CANT_VEHICULO);
               system("pause");
               break;

           case 10:
               system("cls");
               printf("::::::::::::::   LISTA DE PROPIETARIO CON SUS VEHICULOS    ::::::::::::::\n");
               auto_PropPorID_ConAuto(miAuto,CANT_VEHICULO,miPropietario,CANT_PROP);
               system("pause");
               break;

           case 11:
               system("cls");
               printf("::::::::::::::   LISTA DE PROPIETARIO CON SUS VEHICULOS DE MARCA AUDI    ::::::::::::::\n");
               auto_ListaPropietarios_Audi(miPropietario,CANT_PROP,miAuto,CANT_VEHICULO);
               system("pause");
               break;

           case 12:
               system("cls");
               printf("::::::::::::::   LISTA DE VEHICULOS CON LOS DATOS DE PROPIETARIOS   ::::::::::::::\n");
               auto_listaEstacionados_ordenPatente_conProp(miPropietario,CANT_PROP,miAuto,CANT_VEHICULO);
               system("pause");
               break;

            case 13:
                salir=1;
                break;

            default:
                printf("\n\n    ERROR. Operacion invalida   \n\n");
                system("pause");

            }
        }
        while(salir!=1);
    }

    return 0;
}
