#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEmployees.h"

#define FREE 0
#define FULL 1

#define TAM_EMPLOYEE 1000


int main()
{
    int salir=0;
    int i;

    eEmployee employee[TAM_EMPLOYEE]; //inicializo los estados

    if(empleados_init(employee, TAM_EMPLOYEE)==-1)
    {
        printf("\n :::::::::::::::::::: ALERTA! ::::::::::::::::::::\n");
        printf(" ::  Memoria llena, imposible seguir operando.  ::\n");
        printf(" :::::::::::::::::::::::::::::::::::::::::::::::::\n\n\n");
    }
    else
    {
        empleados_hardCode(employee); //carga dato al sistema

        printf("\n APELLIDO-NOMBRE- ID - SECTOR -  SUELDO ");
        for(i=0;i<TAM_EMPLOYEE;i++){
            if(employee[i].isEmpty==FULL && employee!=NULL){
                printf("\n %s  %s  %d  %d  $%.2f ",employee[i].lastName,employee[i].name,employee[i].id,employee[i].sector,employee[i].salary);
            }
        }
        system("pause");

        do
        {
            system("cls");

            switch(empleados_menu())
            {
            case 1:
                system("cls");
                printf("::::::::::::::ALTA::::::::::::::\n");
                empleados_darDeAlta(employee, TAM_EMPLOYEE);
                system("pause");
                break;

            case 2:
                system("cls");
                printf("::::::::::::::MODIFICAR::::::::::::::");
                system("pause");
                break;

            case 3:
                system("cls");
                printf("::::::::::::::ELIMINAR ::::::::::::::\n");
                system("pause");
                break;

            case 4:
                system("cls");
                printf(":::::::::::::::INFORMES:::::::::::::::\n");

                system("pause");
                break;

            case 5:
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
