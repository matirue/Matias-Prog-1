#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "funciones.h"
#include "input.h"

#define CANT_PROD  100
#define CANT_PROV 10
int main()
{
      int salir=0, i;

      EProveedor newProveedor[CANT_PROV];
      EProducto newProducto[CANT_PROD];

      inicializarProd(newProducto, CANT_PROD);
      inicializarProv(newProveedor, CANT_PROV);

      hardCode_prod(newProducto);
      hardCode_prov(newProveedor);



    do
    {
        system("cls");

        /**muestro el hardcodeo**/
        printf("PROVEEDORES CARGADOS\n");
        for(i=0; i<CANT_PROV; i++){
            if(newProveedor[i].estado==1)
               printf("%d - %s \n", newProveedor[i].idProveedor, newProveedor[i].descripcion);
        }
        //system("pause");
        /********************/

        printf("\n\n");

        switch(menu())
        {
            case 1:
                system("cls");
                printf("---------ALTA PROVEEDOR---------");
                printf("\n\n");
                altaProv(newProveedor, CANT_PROV);
                system("pause");
                break;

            case 2:
                system("cls");
                printf("---------ALTA PRODUCTO---------");
                printf("\n\n");
                altaProd(newProducto,CANT_PROD,newProveedor,CANT_PROV);
                system("pause");
                break;

            case 3:
                system("cls");
                printf("---------ELIMINAR PRODUCRO---------");
                printf("\n\n");
                bajaProd(newProducto, CANT_PROD);
                system("pause");
                break;

            case 4:
                system("cls");
                printf("---------ACTUALIZAR PRODUCTO---------\n");
                printf("\n\n");
                actualizar(newProducto, CANT_PROD);
                printf("\n\n");
                system("pause");
                break;

            case 5:
                system("cls");
                printf("---------MENU DE INFORMES---------\n");
                printf("\n\n");
                informar(newProducto, CANT_PROD);
                printf("\n\n");
                system("pause");
                break;

            case 6:
                system("cls");
                printf("---------MENU DE LISTAS---------");
                printf("\n");
                listar(newProducto, CANT_PROD);
                printf("\n\n");
                system("pause");
                break;

           case 7:
                salir=1;
                break;

            default:
                printf("\n\n    ERROR. Operacion invalida   \n\n");
                system("pause");

        }
    }while(salir!=1);
    return 0;
}
