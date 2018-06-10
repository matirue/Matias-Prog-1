#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "input.h"
/**************************************MENU************************************************************/
int menu()
{
    int opc;
    printf("---------MERCADO---------");
    printf("\n\n");
    printf("1-AGREGAR PROVEEDOR\n");
    printf("2-AGREGAR PRODUCTO\n");
    printf("3-ELIMINAR PRODUCTO\n");
    printf("4-ACTUALIZAR PRODUCTO\n");
    printf("5-INFORME\n");
    printf("6-TIPO DE LISTAS\n");
    printf("7-SALIR\n");
    printf("\n\n");
    opc=getValidInt("\n Elija una operacion: ", "\n\n  ERROR. Operacion invalida ", 0, 8);
    return opc;
}
/**************************************FIN DE MENU*****************************************************/

/** \brief Inicializa el estado de un array de productos
 * \param producto[] Es el array en el cual buscar
 * \param cantidad Es el largo del array
 * \return void
 */

void inicializarProd(EProducto producto[],int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        producto[i].estadoProducto = 0;  /**< 0 para inactivo, 1 para activo */
    }
}

/** \brief Inicializa el estado de un array de proveedor
 * \param proveedor[] Es el array en el cual buscar
 * \param cantidad Es el largo del array
 * \return void
 */

void inicializarProv(EProveedor proveedor[],int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        proveedor[i].estado = 0;  /**< 0 para inactivo, 1 para activo */
    }
}

/******************************************************************************************************/
/**
 * \brief Busca el primer lugar no utilizado en el array.
 * \param producto el array  que se pasa como parametro.
 * \param cantidad Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 **/

int buscarEspacioLibreProd (EProducto producto[],int cantidad)
{
    int i, indice=-1;
    for(i=0;i<cantidad;i++)
        {
            if(producto[i].estadoProducto==0)    //recordar q estado=0 es inactivo
            {
                indice=i;
                break;
            }
        }
        return indice;
}

/**
 * \brief Busca el primer lugar no utilizado en el array.
 * \param proveedor el array que se pasa como parametro.
 * \param cantidad Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 **/

int buscarEspacioLibreProv (EProveedor proveedor[],int cantidad)
{
    int i, indice=-1;
    for(i=0;i<cantidad;i++)
        {
            if(proveedor[i].estado==0)    //recordar q estado=0 es inactivo
            {
                indice=i;
                break;
            }
        }
        return indice;
}

/******************************************************************************************************/
void altaProv (EProveedor proveedor[],int cantidad)
{
    int  existe, lugar;
    int idAux;
    char descripcionAux[51];

    lugar=buscarEspacioLibreProv(proveedor, cantidad);

    if(lugar==-1)
        {
            printf("\n\n Sistema completo. No se puede seguir cargando nuevos proveedores.\n\n");
            system("pause");
        }
    else
        {
            idAux=getValidInt("\n\n Ingrese ID el proveedor: ", "\n\n ERROR. ID invalido.  \n\n", 0, 99);

            if(buscarPorIdProv(proveedor, cantidad, proveedor[lugar].idProveedor)!=-1)
                {
                    printf("\n\n El codigo %d ya existe en el sistema \n", proveedor[lugar].idProveedor);
                    mostrarProveedor (proveedor[existe]);
                }

            getValidString("\n Ingrese descripcion del proveedor: ", "\n\n ERROR. Descripcion invalida...\n\n", descripcionAux);


            setProveedor(proveedor, lugar, idAux, descripcionAux);

            printf("\n\n\n  ALTA EXITOSA   \n\n\n");

        }
}

void altaProd(EProducto producto[],int cantidad,EProveedor proveedor[],int tamanio)
{
    int  existe, lugar;
    int idProvAux, idProv;
    int codeAux, cargarCode, cantidadAux, precioAux;
    char descripcionAux[51], importeAux[10000];

    lugar=buscarEspacioLibreProd(producto,cantidad);

    if(lugar==-1)
        {
            printf("\n\n Sistema completo. No se puede seguir cargando productos.\n\n");
        }
    else
        {
            idProvAux=getValidInt("\n\n Ingrese el Id del proveedor: ", "\n\n ERROR Id invalido\n\n", 0, 99);
            idProv=idProvAux;
            if(buscarPorIdProv(proveedor, tamanio, idProv)==-1)
                {
                    printf("\n\n El proveedor de id: %d   No existe en el sistema \n", idProv);
                    system("pause");
                }
            else
                {
                    codeAux=getValidInt("\n\n Ingrese codigo del producto: ", "\n\n ERROR. Codigo invalido.  \n\n",0,999);
                    cargarCode=codeAux;
                    if(buscarPorCodigoProd(producto,cantidad,cargarCode)!=-1)
                    {
                        printf("\n\n El codigo %d ya existe en el sistema \n", cargarCode);
                        mostrarProductoPorCodigo(producto[existe]);
                    }
                    else
                    {
                        getValidString("\n Ingrese descripcion del producto: ", "\n\n ERROR. Descripcion invalida...\n\n",descripcionAux);

                        cantidadAux=getValidInt("\n Cantidad entrante: ","\n\n ERROR. Cantidad invalida: \n",1,1000);

                        while(getStringNumerosFlotantes("\n Ingrese Importe del producto: ", importeAux)==0 || ( (atoi(importeAux))<0 || (atoi(importeAux))>9999.99 ) )
                        {
                           printf("\n\n Error. Importe invalido: \n");
                           printf("\n - DEbe ser numerico.");
                           printf("\n - Fuera de rango \n\n");
                        }
                        precioAux=atoi(importeAux);

                        setProducto(producto,lugar,cargarCode,descripcionAux,precioAux,cantidadAux);
                    }
                }
        }
        printf("\n\n\n  ALTA EXITOSA   \n\n\n");
}

/******************************************************************************************************/
void bajaProd (EProducto producto[],int cantidad)
{
    int existe, codeAux, stop;
    char confirmar;

    printf("\n\n Productos registrados:  ");
    listar_productoPorDescripcion(producto, cantidad);

    codeAux=getValidInt("\n\n Ingrese el codigo del producto a eliminar: ", "\n\n ERROR. Codigo invalido\n\n", 0, 999);
    existe=buscarPorCodigoProd(producto, cantidad, codeAux);

    if(existe==-1)
        {
            printf("\n\n Codigo inexistente en el sistema\n\n");
        }
    else
        {
            printf("\n\n");
            mostrarProductoPorCodigo(producto[existe]);

            do{
                    confirmar=getChar("\n\n Confirmar baja? (s/n):  ");

                    if(confirmar=='s')
                        {
                            producto[existe].estadoProducto=0;
                            printf("\n\n BAJA EXITOSA\n\n");
                            stop=1;
                        }
                    else if(confirmar=='n')
                        {
                            printf("\n\n Baja cancelada\n\n");
                            stop=1;
                        }
                    else
                        {
                           printf("\n\n Respuesta invalida\n\n");
                           stop=0;
                        }
            }while(stop!=1);
        }
}

/******************************************************************************************************/


/**
 * \brief Busca la primer ocurrencia de un producto mediante su codigo
 * \param producto Es el array en el cual buscar
 * \param cantidad Indica la logitud del array
 * \param codeAux Es el codigo que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 */

int buscarPorCodigoProd (EProducto producto[],int cantidad,int codeAux)
{
    int i, indice=-1;
    for(i=0;i<cantidad;i++)
        {
            if(producto[i].estadoProducto==1 && producto[i].codigo==codeAux)
                {
                    indice=i;
                    break;
                }
        }
    return indice;
}

/**
 * \brief Busca la primer ocurrencia de un proveedor mediante su id
 * \param proveedor Es el array en el cual buscar
 * \param cantidad Indica la logitud del array
 * \param id Es el codigo que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 */

int buscarPorIdProv (EProveedor proveedor[],int cantidad,int id)
{
    int i, indice=-1;
    for(i=0;i<cantidad;i++)
        {
            if(proveedor[i].estado==1 && proveedor[i].idProveedor==id)
                {
                    indice=i;
                    break;
                }
        }
    return indice;
}

/******************************************************************************************************/

void hardCode_prov(EProveedor nuevoProveedor[])
{
    nuevoProveedor[0].idProveedor=1;
    strcpy(nuevoProveedor[0].descripcion, "AAAAA");
    nuevoProveedor[0].estado=1;

    nuevoProveedor[1].idProveedor=2;
    strcpy(nuevoProveedor[1].descripcion, "BBBBB");
    nuevoProveedor[1].estado=1;

    nuevoProveedor[2].idProveedor=3;
    strcpy(nuevoProveedor[2].descripcion, "CCCCC");
    nuevoProveedor[2].estado=1;

}

void hardCode_prod(EProducto nuevoProducto[])
{
    nuevoProducto[0].codigo=1;
    strcpy(nuevoProducto[0].descProducto, "ABCD");
    nuevoProducto[0].cantidad=10;
    nuevoProducto[0].importe=50;
    nuevoProducto[0].idProveedor=0;
    nuevoProducto[0].estadoProducto=1;

    nuevoProducto[1].codigo=2;
    strcpy(nuevoProducto[1].descProducto, "EFGH");
    nuevoProducto[1].cantidad=20;
    nuevoProducto[1].importe=100;
    nuevoProducto[1].idProveedor=1;
    nuevoProducto[1].estadoProducto=1;

    nuevoProducto[2].codigo=3;
    strcpy(nuevoProducto[0].descProducto, "IJKL");
    nuevoProducto[2].cantidad=30;
    nuevoProducto[2].importe=150;
    nuevoProducto[2].idProveedor=2;
    nuevoProducto[2].estadoProducto=1;

}
/********************************************************************************************************/
/**
 * \brief Carga dato a la estructura de EProveedor
 * \param proveedor Es el array de autores
 * \param lugar Indica la posicion a cargar
 * \param idAux Codigo del producto
 * \param descripAux Descripcion del proveedor
 * \return -
 */
void setProveedor(EProveedor proveedor[],int lugar,int idAux,char descripAux[])
{

    proveedor[lugar].idProveedor = idAux;             //id del proveedor
    strcpy(proveedor[lugar].descripcion,descripAux);  //descripcion
    proveedor[lugar].estado = 1;                      //cambio su estado

}

/**
 * \brief Carga dato a la estructura de EProductos
 * \param producto Es el array de autores
 * \param lugar Indica la posicion a cargar
 * \param productCode Codigo del producto
 * \param descripAux Descripcion del producto
 * \param importeProduct Importe del producto
 * \param cantProduct Cantidad del producto
 * \return -
 */
void setProducto(EProducto producto[],int lugar,int productCode,char descripAux[],float importeProduct,int cantProduct)
{

    producto[lugar].codigo = productCode;             //codigo
    strcpy(producto[lugar].descProducto,descripAux);  //descripcion
    producto[lugar].importe = importeProduct;         //importe
    producto[lugar].cantidad = cantProduct;           //stock
    producto[lugar].estadoProducto = 1;                       //cambio su estado

}




/******************************************************************************************************/
void listarProveedor (EProveedor proveedor[],int cantidad)
{
    int i;
    printf("\n\n  ID PROVEEDOR   \t   DESCRIPCION   \t  \n");
    proveedor_OedenarDescripcion(proveedor, cantidad);
    for(i=0;i<cantidad;i++)
        {
            if(proveedor[i].estado==1)
                {
                     mostrarProveedor(proveedor[i]);
                }
        }
}

void mostrarProveedor (EProveedor proveedor)
{
    printf("\n  %d   \t   %s   \n", proveedor.idProveedor, proveedor.descripcion);
}

/** \brief ordeno por Descripcion
 * \param proveedor El array a recoorer
 * \param cantidad Largo del array
 * \return void
 */
void proveedor_OedenarDescripcion (EProveedor proveedor[],int cantidad)
{
    EProveedor proveedorAux;
    int i,j;

    for(i=0;i<cantidad-1;i++)
        {
            for(j=i+1;j<cantidad;j++)
                {
                    if(strcmp(proveedor[i].descripcion, proveedor[j].descripcion)>0)
                        {
                            proveedorAux=proveedor[i];
                            proveedor[i]=proveedor[j];
                            proveedor[j]=proveedorAux;
                        }
                }
        }
}


void listarproducto (EProducto producto[],int cantidad)
{
    int i;
    printf("\n\n  CODIGO   \t   DESCRIPCION   \t   IMPORTE($)   \t   STOCK   \n");
    producto_OedenarDescripcion(producto, cantidad);
    for(i=0;i<cantidad;i++)
        {
            if(producto[i].estadoProducto==1)
                {
                     mostrarProductoPorCodigo(producto[i]);
                }
        }
}

void mostrarProductoPorCodigo(EProducto producto)
{
    printf("\n %5d \t  %-35s  \t  %4.2f  \t %4d  ", producto.codigo, producto.descProducto, producto.importe, producto.cantidad);
}

/** \brief ordeno por Descripcion
 * \param producto El array a recoorer
 * \param cantidad Largo del array
 * \return void
 */

void producto_OedenarDescripcion (EProducto producto[],int cantidad)
{
    EProducto productoAux;
    int i,j;

    for(i=0;i<cantidad-1;i++)
        {
            for(j=i+1;j<cantidad;j++)
                {
                    if(strcmp(producto[i].descProducto,producto[j].descProducto)>0)
                        {
                            productoAux=producto[i];
                            producto[i]=producto[j];
                            producto[j]=productoAux;
                        }
                }
        }
}

void listar_productoPorDescripcion (EProducto producto[],int cantidad)
{
    int i;
    producto_OedenarDescripcion(producto, cantidad);

    printf("\n -----------------LISTA DE PRODUCTOS----------------- ");
    printf("\n    CODIGO    \t      DESCRIPCION      \t    IMPORTE($)    \t    STOCK      ");

    for(i=0;i<cantidad;i++)
        {
            if(producto[i].estadoProducto==1)
                {
                    printf("\n %5d \t  %-35s  \t  %4.2f  \t %4d  ", producto[i].codigo, producto[i].descProducto, producto[i].importe, producto[i].cantidad);
                }
        }
}
/******************************************************************************************************/





/**************************************MODIFICAR************************************************************/
int menuModi()
{
    int opc;

    printf("---------ACTUALIZAR:---------");
    printf("\n\n");
    printf("1-DESCRIPCION\n");
    printf("2-STOCK\n");
    printf("3-IMPORTE\n");
    printf("4-REGRESAR\n");
    printf("\n\n");

    opc=getValidInt("\n Elija una operacion: ","\n\n  ERROR. Operacion invalida ",0,5);

    return opc;
}



void actualizar(EProducto producto[], int cantidad)
{
    int  existe, codeAux, stop, stockAux, precioAux;

    char confirmar;
    char descripcionAux[51];
    char importeAux[10000];

    printf("\n\n Productos registrados:  ");
    listar_productoPorDescripcion(producto, cantidad);

    codeAux=getValidInt("\n\n Ingrese el codigo del producto a modificar: ", "\n\n ERROR. Codigo invalido\n\n", 0, 999);
    existe=buscarPorCodigoProd(producto, cantidad, codeAux);

    if(existe==-1)
        {
            printf("\n\n Codigo inexistente en el sistema\n\n");
        }
    else
        {
            printf("\n");
            mostrarProductoPorCodigo(producto[existe]);

            do{
                    confirmar=getChar("\n\n CONTINUAR CON LA ACTUALIZACION? (s/n):  ");

                    if(confirmar=='s')
                        {
                            system("cls");

                            switch(menuModi())
                            {
                               case 1:
                                   getValidString("\n Ingrese descripcion del producto: ", "\n\n ERROR. Descripcion invalida...\n\n", descripcionAux);
                                   strcpy(producto[existe].descProducto,descripcionAux);
                                   break;
                               case 2:
                                   stockAux=getValidInt("\n Stock: ", "\n\n ERROR. Cantidad invalida: \n", 1, 1000);
                                   producto[existe].cantidad = stockAux;
                                   break;
                               case 3:
                                   while(getStringNumerosFlotantes("\n Ingrese Importe del producto: ", importeAux)==0 || ( (atoi(importeAux))<0 || (atoi(importeAux))>9999.99 ) )
                                     {
                                         printf("\n\n Error. Importe invalido: \n");
                                         printf("\n - DEbe ser numerico.");
                                         printf("\n - Fuera de rango \n\n");
                                     }
                                   precioAux=atoi(importeAux);
                                   producto[existe].importe = precioAux;
                                   break;
                               case 4:
                                   stop=1;
                                   break;

                               default:
                                   printf("\n\n    OPCION INEXISTENTE   \n\n");
                                   system("pause");

                            }


                        }
                    else if(confirmar=='n')
                        {
                            printf("\n\n OPERACION CANCELADA \n\n");
                            system("pause");
                            stop=1;
                        }
                    else
                        {
                           printf("\n\n RESPUESTA INVALIDA\n\n");

                           system("pause");
                           stop=0;
                        }

            }while(stop!=1);

        }
}

/************************************************************************************************************/
int menuInformes ()
{
    int opc;

    printf("---------MENU INFORME:---------");
    printf("\n\n");
    printf("1- TOTAL Y RPOMEDIO DE LOS IMPORTES, Y CUANTOS NO SUPERAN ESE PROMEDIO:\n");
    printf("2- TOTAL Y RPOMEDIO DE LOS IMPORTES, Y CUANTOS SUPERAN ESE PROMEDIO:\n");
    printf("3- CANTIDAD DE PRODUCTOS CON STOCK MENOR E IGUAL A DIEZ:\n");
    printf("4- CNATIDAD DE PRODUCTOS CON STOCK MAYOR A DIEZ:\n");
    printf("5- PARA REGRESAR");
    printf("\n\n");

    opc=getValidInt("\n Tipo de informe: ","\n\n  ERROR. Operacion invalida ",0,6);

    return opc;
}

void informar (EProducto producto[],int cantidad)
{
    int salir=0, cantidadImporte, dato;
    float sumaImporte;

    do{
        switch(menuInformes())
        {
        case 1:
            cantidadImporte=inf_contarImporte(producto, cantidad);
            sumaImporte=inf_sumarImportes(producto, cantidad);

            printf("\n\n Se registro un total de: $ %.2f  con un promedio de: $ %.2f \n", sumaImporte, sumaImporte/cantidadImporte);
            dato=inf_cantidadMenor_Promedio(producto, cantidad);
            printf("\n La cantidad de productos que no supera el promedio es de: %d \n", dato);
            system("pause");
            break;

        case 2:
            cantidadImporte=inf_contarImporte(producto, cantidad);
            sumaImporte=inf_sumarImportes(producto, cantidad);

            printf("\n\n Se registro un total de: $ %.2f  con un promedio de: $ %.2f \n", sumaImporte, sumaImporte/cantidadImporte);
            dato=inf_cantidadMayor_Promedio(producto, cantidad);
            printf("\n La cantidad de productos que superan el promedio es de: %d \n", dato);
            system("pause");
            break;

        case 3:
            inf_stockMenorDiez(producto, cantidad);
            system("pause");
            break;

        case 4:
            inf_stockMayorDiez(producto, cantidad);
            system("pause");
            break;

        case 5:
            salir=1;
            break;

        default:
            printf("\n\n    OPCION INEXISTENTE   \n\n");
            system("pause");
        }
    }while(salir!=1);

}

/** \brief Funcion que cuenta la cantidad de productos activos
 * \param producto Es la estructura a recorrer
 * \param cantidad Es el tamaño del array
 * \return cont Retorna la cantidad de producto registrados
 *
 */
int inf_contarImporte (EProducto producto[],int cantidad)
{
    int i, cont=0;

    for(i=0;i<cantidad;i++)
        {
            if(producto[i].estadoProducto==1)
                {
                    cont++;
                }
        }
    return cont;
}

/** \brief Funcion que suma el total de los importes de productos
 * \param productos Es la estructura a recorrer
 * \param cantidad El tamaño de la estructura
 * \return cont Retorna la suma total de los importes
 */
float inf_sumarImportes (EProducto producto[],int cantidad)
{
    int i;
    float cont=0;

    for(i=0;i<cantidad;i++)
        {
            if(producto[i].estadoProducto==1)
                {
                    cont=cont+producto[i].importe;
                }
        }

    return cont;
}

/** \brief Funcion que cuenta la cantidad de productos registrado cuyo stock sea mayor  a 10
 * \param productos Es la estructura a recorrer
 * \param cantidad El tamaño de la estructura
 * \return -
 *
 */
void inf_stockMayorDiez (EProducto producto[],int cantidad)
{
    int i, cant=0;

    producto_OedenarDescripcion(producto, cantidad);

    for(i=0;i<cantidad;i++)
        {
            if(producto[i].estadoProducto==1 && producto[i].cantidad>10)
                {
                    cant++;
                }
        }
    printf("\n\n Cantidad de productos de los cuales su stock en mayor a diez: %d", cant);
}


/** \brief Funcion que cuenta la cantidad de productos registrado cuyo stock sea menor e igual a 10
 * \param productos Es la estructura a recorrer
 * \param cantidad El tamaño de la estructura
 * \return -
 *
 */
void inf_stockMenorDiez (EProducto producto[],int cantidad)
{
    int i, cant=0;

    producto_OedenarDescripcion(producto, cantidad);

    for(i=0;i<cantidad;i++)
        {
            if(producto[i].estadoProducto==1 && producto[i].cantidad<11)
                {
                    cant++;
                }
        }
    printf("\n\n Cantidad de productos de los cuales su stock en menor e igual a diez: %d", cant);
}

/** \brief Funcion que cuenta la cantidad de productos con importe menor al promedio
 * \param productos Es la estructura a recorrer
 * \param cantidad El tamaño de la estructura
 * \return cant Retorna la cantidad de productos con importe menor al promedio
 */
int inf_cantidadMenor_Promedio(EProducto producto[],int cantidad)
{
    int i, cant=0;
    float promedio;

    promedio=( inf_sumarImportes(producto, cantidad)/inf_cantidadMenor_Promedio(producto, cantidad) );
    for(i=0;i<cantidad;i++)
        {
            if(producto[i].estadoProducto==1 && producto[i].importe<promedio)
                {
                    cant++;
                }
        }
    return cant;
}

/** \brief Funcion que cuenta la cantidad de productos con importe mayor al promedio
 * \param productos Es la estructura a recorrer
 * \param cantidad El tamaño de la estructura
 * \return cant Retorna la cantidad de productos con importe mayor al promedio
 */
int inf_cantidadMayor_Promedio(EProducto producto[],int cantidad)
{
    int i, cant=0;
    float promedio;

    promedio=( inf_sumarImportes(producto, cantidad)/inf_cantidadMenor_Promedio(producto, cantidad) );
    for(i=0;i<cantidad;i++)
        {
            if(producto[i].estadoProducto==1 && producto[i].importe>promedio)
                {
                    cant++;
                }
        }
    return cant;
}
/************************************************************************************************************/
int menuListas()
{
    int opc;

    printf("---------MENU LISTAS:---------");
    printf("\n\n");
    printf(" 1- PRODUCTOS ORDENADOS POR IMPORTE DE MANERA DESCENDENTE Y POR DESCRIPCION DE MANERA ASCENDENTE: ");
    printf("\n 2- PRODUCTOS CON CANTIDAD MENOR E IGUAL A DIEZ: ");
    printf("\n 3- PRODUCTOD CON CANTIDAD MAYOR A DIEZ: ");
    printf("\n 4- PRODUCTOS QUE SUPERAN EL PROMEDIO DE LOS IMPORTES: ");
    printf("\n 5- PRODUCTOS QUE NO SUPERAN EL PROMEDIO DE LOS IMPORTES: ");
    printf("\n 6- PROVEEDORES CUYA CANTIDAD DE PRODUCTOS ES MENOR E IGUAL A DIEZ: ");
    printf("\n 7- PRODUCTOS PROVISTOS POR CADA PROVEEDOR: ");
    printf("\n 8- PRODUCTOS PROVISTOS POR UN PROVEEDOR DETERMINADO: ");
    printf("\n 9- PROVEEDOR QUE PROVEE MAS PRODUCTOS, MOSTRANDO LOS PRODUCTOS: ");
    printf("\n 10- PROVEEDOR QUE PROVEE MENOS PRODUCTOS, MOSTRANDO LOS PRODUCTOS:");
    printf("\n 11- PROVEEDOR QUE PROVEE EL PRODUCTO MAS CARO, MOSTRANDO ESE PRODUCTO:");
    printf("\n 12- PROVEEDOR QUE PROVEE EL PRODUCTO MAS BARATO, MOSTRANDO ESE PRODUCTO:");
    printf("\n 13-PARA REGRESAR");
    printf("\n\n");

    opc=getValidInt("\n LISTAR POR: ","\n\n  ERROR. Operacion invalida ",0,14);

    return opc;
}

void listar(EProducto producto[],int cantidad,EProveedor proveedor[],int tamanio)
{
    int salir=0;

    do{
        switch(menuListas())
        {
        case 1:
            system("cls");
            printf("\n----------LISTA DE PRODUCTOS SEGUN SU IMPORTE DESCENDENTE----------\n");
            listar_producto_importe(producto, cantidad);

            printf("\n\n\n----------LISTA DE PRODUCTOS SEGUN SU DESCRIPCION----------\n");
            listar_producto_descripcion(producto, cantidad);
            system("pause");
            break;

        case 2:
             system("cls");
             printf("\n----------LISTA DE PRODUCTOS CON STOCK MENOR E IGUAL A DIEZ----------\n");
             printf("\n  CODIGO   \t   DESCRIPCION   \t   IMPORTE($)   \t   STOCK   \n");
             listar_producto_menorDiez(producto, cantidad);
             system("pause");
             break;

        case 3:
            system("cls");
            printf("\n----------LISTA DE PRODUCTOS CON STOCK MAYOR A DIEZ----------\n");
            printf("\n  CODIGO   \t   DESCRIPCION   \t   IMPORTE($)   \t   STOCK   \n");
            listar_producto_mayorDiez(producto, cantidad);
            system("pause");
            break;

        case 4:
            system("cls");
            printf("\n----------LISTA DE PRODUCTOS CON IMPORTE MAYOR AL PROMEDIO----------\n");
            listar_producto_mayorPromedio(producto, cantidad);
            system("pause");
            break;

        case 5:
            system("cls");
            printf("\n----------LISTA DE PRODUCTOS CON IMPORTE MENOR AL PROMEDIO----------\n");
            listar_producto_menorPromedio(producto, cantidad);
            system("pause");
            break;

        case 6:
            system("cls");
            printf("\n----------LISTA DE PROVEEDORES CUYA CANTIDAD DE PRODUCTOS ES MENOR E IGUAL A DIEZ----------\n");
            listar_proveedor_stockMenorIgDiez(proveedor, tamanio, producto, cantidad);
            system("pause");
            break;

        case 7:
            system("cls");
            printf("\n----------LISTA DE PRODUCTOS POR PROVEEDOR----------\n");
            listar_proveedor_productos(proveedor, tamanio, producto, cantidad);
            system("pause");
            break;

        case 8:
            system("cls");
            printf("\n----------LISTA DE PRODUCTOS PROVISTOS POR UN PROVEEDOR DETERMINADO----------\n");
            listar_proveedor_conSusProductos(proveedor, tamanio, producto, cantidad);
            system("pause");
            break;

        case 9:
            system("cls");
            printf("\n----------LISTA DE PROVEEDOR QUE PROVEE MAS PRODUCTOS, MOSTRANDO LOS PRODUCTOS----------\n");
            listar_proveedor_conMasProductos(proveedor, tamanio, producto, cantidad);
            system("pause");
            break;

        case 10:
            system("cls");
            printf("\n----------LISTA DE PROVEEDOR QUE PROVEE MENOS PRODUCTOS, MOSTRANDO LOS PRODUCTOS----------\n");
            listar_proveedor_conMenorProductos(proveedor, tamanio, producto, cantidad);
            system("pause");
            break;

        case 11:
            system("cls");
            printf("\n----------LISTA DE PROVEEDOR QUE PROVEE EL PRODUCTO MAS CARO, MOSTRANDO ESE PRODUCTO----------\n");
            listar_producto_caro(proveedor, tamanio, producto, cantidad);
            system("pause");
            break;

        case 12:
            system("cls");
            printf("\n----------LISTA DE PROVEEDOR QUE PROVEE EL PRODUCTO MAS BARATO, MOSTRANDO ESE PRODUCTO----------\n");
            listar_producto_barato(proveedor, tamanio, producto, cantidad);
            system("pause");
            break;

        case 13:
            salir=1;
            break;

        default:
                printf("\n\n    OPCION INEXISTENTE   \n\n");
                system("pause");

        }
    }while(salir!=1);

}

/** \brief Lista los producto de manera descendente por su importe
 * \param productos Es la estructura a recorrer
 * \param cantidad El tamaño de la estructura
 * \return -
 */
 void listar_producto_importe (EProducto producto[],int cantidad)
 {
     int i;

     producto_OedenarImporte(producto, cantidad);

     printf("\n\n   IMPORTE($)   \t    CODIGO    \t     DESCRIPCION     \t   STOCK   \n");

     for(i=0;i<cantidad-1;i++)
        {
            if(producto[i].estadoProducto==1)
                {
                    printf("\n   %.2f   \t    %4d    \t    %-35s    \t   %4d   \n", producto[i].importe, producto[i].codigo, producto[i].descProducto, producto[i].cantidad);
                }
        }


 }

 void producto_OedenarImporte(EProducto producto[],int cantidad)
 {
     int i, j;
     EProducto prodAux;

     for(i=0;i<cantidad-1;i++)
        {
            for(j=i+1;j<cantidad;j++)
                {
                    if(producto[i].importe<producto[j].importe)
                        {
                            prodAux=producto[i];
                            producto[i]=producto[j];
                            producto[j]=prodAux;
                        }
                }
        }
 }

 /** \brief Lista los producto de manera ascendente por su descripcion
 * \param productos Es la estructura a recorrer
 * \param cantidad El tamaño de la estructura
 * \return -
 */
 void listar_producto_descripcion (EProducto producto[],int cantidad)
 {
     int i;
     producto_OedenarDescripcion(producto, cantidad);

     printf("\n\n   DESCRIPCION   \t    CODIGO    \t     IMPORTE($)     \t   STOCK   \n");

     for(i=0;i<cantidad-1;i++)
        {
            if(producto[i].estadoProducto==1)
                {
                    printf("\n   %-35s   \t    %4d    \t    %.2f    \t   %4d   \n", producto[i].descProducto, producto[i].codigo, producto[i].importe, producto[i].cantidad);
                }
        }


 }


 /** \brief Lista los productos menor e igual a diez
  * \param productos Es la estructura a recorrer
  * \param cantidad El tamaño de la estructura
  * \return -
  */
  void listar_producto_menorDiez (EProducto producto[],int cantidad)
  {
      int i;

      producto_OedenarDescripcion(producto, cantidad);

      printf("\n\n  CODIGO   \t   DESCRIPCION   \t   IMPORTE($)   \t   STOCK   \n");

      for(i=0;i<cantidad;i++)
        {
            if(producto[i].estadoProducto==1 && producto[i].cantidad<11)
                {
                    mostrarProductoPorCodigo(producto[i]);
                }
        }
  }

   /** \brief Lista los productos mayor a diez
  * \param productos Es la estructura a recorrer
  * \param cantidad El tamaño de la estructura
  * \return -
  */
  void listar_producto_mayorDiez (EProducto producto[],int cantidad)
  {
      int i;
      producto_OedenarDescripcion(producto, cantidad);

      printf("\n\n  CODIGO   \t   DESCRIPCION   \t   IMPORTE($)   \t   STOCK   \n");

      for(i=0;i<cantidad;i++)
        {
            if(producto[i].estadoProducto==1 && producto[i].cantidad>10)
                {
                    mostrarProductoPorCodigo(producto[i]);
                }
        }
  }

  /** \brief Lista los productos que supera los promedios
   * \param productos Es la estructura a recorrer
   * \param cantidad El tamaño de la estructura
   * \return -
   */
  void listar_producto_mayorPromedio (EProducto producto[],int cantidad)
  {
      int i;
      float promedio;

      promedio=(inf_sumarImportes(producto, cantidad)/inf_contarImporte(producto, cantidad));

      printf("\n\n  CODIGO   \t   DESCRIPCION   \t   IMPORTE($)   \t   STOCK   \n");

      for(i=0;i<cantidad;i++)
        {
            if(producto[i].estadoProducto==1 && producto[i].importe>promedio)
                {
                    mostrarProductoPorCodigo(producto[i]);
                }
        }
  }


  /** \brief Lista los productos que sean menor a los promedios
   * \param productos Es la estructura a recorrer
   * \param cantidad El tamaño de la estructura
   * \return -
   */
  void listar_producto_menorPromedio (EProducto producto[],int cantidad)
  {
      int i;
      float promedio;

      promedio=(inf_sumarImportes(producto, cantidad)/inf_contarImporte(producto, cantidad));

      printf("\n\n  CODIGO   \t   DESCRIPCION   \t   IMPORTE($)   \t   STOCK   \n");

      for(i=0;i<cantidad;i++)
        {
            if(producto[i].estadoProducto==1 && producto[i].importe<promedio)
                {
                    mostrarProductoPorCodigo(producto[i]);
                }
        }
  }


  /** \brief lista al proveedor cuyo stock sea menor a 10
   * \param proveedor Estructura a recorrer
   * \param cantidadProv El tamaño de la estructura
   * \param producto Estructura a recorrer
   * \param cantidadProd El tamaño de la estructura
   * \return -
   */
   void listar_proveedor_stockMenorIgDiez (EProveedor proveedor[], int cantidadProv, EProducto producto[], int cantidadProd)
   {
       int i, j, menor, flag=0;
       char provAux[51];

       for(i=0;i<cantidadProd;i++)
        {
            for(j=0;j<cantidadProv;j++)
                {
                    if(producto[i].estadoProducto==1 && proveedor[j].idProveedor==producto[i].idProveedor && producto[i].cantidad<11)
                        {
                            strcpy(provAux, proveedor[j].descripcion);

                            printf("\n\n    PROVEEDOR    \t       PRODUCTO       \t     CODIGO PRODUCTO    \t   STOCK   \t   IMPORTE($)    \n");
                            printf("    %5s    \t       %-35S       \t     %6d     \t    %4d    \t     %.2f     \n", provAux, producto[i].descProducto, producto[i].codigo, producto[i].cantidad, producto[i].importe);

                            flag=1;

                            break;
                        }
                }
        }
        if(flag==0)
            {
                printf("\n\n No se ecnuentra ningun proveedor con stock menor a 10 \n");
            }
   }

   /** \brief lista al proveedor con el stock q provee
   * \param proveedor Estructura a recorrer
   * \param cantidadProv El tamaño de la estructura
   * \param producto Estructura a recorrer
   * \param cantidadProd El tamaño de la estructura
   * \return -
   */
 void listar_proveedor_productos (EProveedor proveedor[], int cantidadProv, EProducto producto[], int cantidadProd)
 {
     proveedor_OedenarDescripcion(producto, cantidadProd);

     int i, j, existe, existeProveedor;
     char provAux[51];

     printf("\n\n    PROVEEDOR    \t       PRODUCTO       \t     CODIGO PRODUCTO    \t   STOCK   \t   IMPORTE($)    \n");

     for(i=0;i<cantidadProd;i++)
        {
            for(j=0;j<cantidadProv;j++)
                {
                    if(proveedor[j].estado==1 && producto[i].idProveedor==proveedor[j].idProveedor)
                        {
                            strcpy(provAux, proveedor[j].descripcion);
                        }

                    if(producto[i].estadoProducto==1 && producto[i].idProveedor==proveedor[j].idProveedor)
                        {
                            printf("    %5s    \t       %-35S       \t     %6d     \t    %4d    \t     %.2f     \n", provAux, producto[i].descProducto, producto[i].codigo, producto[i].cantidad, producto[i].importe);

                            break;
                        }
                }
        }
 }


 /** \brief lista al proveedor con su stock
   * \param proveedor Estructura a recorrer
   * \param cantidadProv El tamaño de la estructura
   * \param producto Estructura a recorrer
   * \param cantidadProd El tamaño de la estructura
   * \return -
   */
   void listar_proveedor_conSusProductos (EProveedor proveedor[], int cantidadProv, EProducto producto[], int cantidadProd)
   {
       proveedor_OedenarDescripcion(producto, cantidadProd);

       int i, j, existe, existeProveedor, mostrar;
       //char provAux[51];

       listarProveedor(proveedor, cantidadProv);

       mostrar=getValidInt("\n\n Ingrese ID el proveedor a mostrar: ", "\n\n ERROR. ID invalido.  \n\n", 0, 99);

       printf("\n\n       PRODUCTO       \t     CODIGO PRODUCTO    \t   STOCK   \t   IMPORTE($)    \n\n");

       for(i=0;i<cantidadProd;i++)
        {
            for(j=0;j<cantidadProv;j++)
                {
                   /* if(proveedor[j].estado==1 && mostrar==proveedor[j].idProveedor)
                        {
                            strcpy(provAux, proveedor[j].descripcion);
                        }
                    */
                    if(producto[i].estadoProducto==1 && mostrar==proveedor[j].idProveedor)
                        {
                            printf("        %-35S       \t     %6d     \t    %4d    \t     %.2f     \n", producto[i].descProducto, producto[i].codigo, producto[i].cantidad, producto[i].importe);

                            break;
                        }
                }
        }

   }


   /** \brief Cuenta la cantidad de productos
   * \param proveedor Estructura a recorrer
   * \param cantidadProv El tamaño de la estructura
   * \param producto Estructura a recorrer
   * \param cantidadProd El tamaño de la estructura
   * \return cont Retorna la cantidad de productos
   */
   int cantidad_productos (EProducto producto[], int proveedor, int cantidad)
   {
       int i, cont=0;

       for(i=0;i<cantidad;i++)
        {
            if(producto[i].estadoProducto==1 && proveedor==producto[i].idProveedor)
                {
                    cont++;
                }
        }
      return cont;
   }

   /** \brief Cuenta la cantidad de productos
   * \param proveedor Estructura a recorrer
   * \param cantidadProv El tamaño de la estructura
   * \param producto Estructura a recorrer
   * \param cantidadProd El tamaño de la estructura
   * \return mayor Retorna la cantidad de productos
   */
   int max_productos (EProveedor proveedor[], int cantidadProv, EProducto producto[], int cantidadProd)
   {
       int i, mayor=0, acum, flag=0;

       for(i=0;i<cantidadProv;i++)
        {
            acum=cantidad_productos(producto, proveedor[i].idProveedor, cantidadProd);

            if(acum>mayor || flag==0)
                {
                    mayor=acum;
                    flag=1;
                }
        }
       return mayor;
   }

   /** \brief Cuenta la cantidad de productos
   * \param proveedor Estructura a recorrer
   * \param cantidadProv El tamaño de la estructura
   * \param producto Estructura a recorrer
   * \param cantidadProd El tamaño de la estructura
   * \return menor Retorna la cantidad de productos
   */
   int min_productos (EProveedor proveedor[], int cantidadProv, EProducto producto[], int cantidadProd)
   {
       int i, menor=0, acum, flag=0;

       for(i=0;i<cantidadProv;i++)
        {
            acum=cantidad_productos(producto, proveedor[i].idProveedor, cantidadProd);

            if(acum<menor || flag==0)
                {
                    menor=acum;
                    flag=1;
                }
        }
       return menor;
   }

   /** \brief lista al proveedor que provee mayor stock
   * \param proveedor Estructura a recorrer
   * \param cantidadProv El tamaño de la estructura
   * \param producto Estructura a recorrer
   * \param cantidadProd El tamaño de la estructura
   * \return -
   */
   void listar_proveedor_conMasProductos (EProveedor proveedor[], int cantidadProv, EProducto producto[], int cantidadProd)
   {
       int i, j, mostrar, acum;

       acum=max_productos(proveedor, cantidadProv, producto, cantidadProd);

        printf("\n\n    PROVEEDOR    \t       PRODUCTO       \t     CODIGO PRODUCTO    \t   STOCK   \t   IMPORTE($)    \n");

        for(i=0;i<cantidadProv;i++)
            {
                if(acum==cantidad_productos(producto, proveedor[i].idProveedor, cantidadProd))
                    {
                        mostrar=proveedor[i].idProveedor;

                        for(j=0;j<cantidadProd;j++)
                            {
                                if(producto[j].estadoProducto==1 && producto[j].idProveedor==mostrar)
                                    {
                                        printf("    %5s    \t       %-35S       \t     %6d     \t    %4d    \t     %.2f     \n", proveedor[j].descripcion, producto[j].descProducto, producto[j].codigo, producto[j].cantidad, producto[j].importe);
                                    }
                            }
                    }
            }
   }


   /** \brief lista al proveedor que provee menor stock
   * \param proveedor Estructura a recorrer
   * \param cantidadProv El tamaño de la estructura
   * \param producto Estructura a recorrer
   * \param cantidadProd El tamaño de la estructura
   * \return -
   */
   void listar_proveedor_conMenorProductos (EProveedor proveedor[], int cantidadProv, EProducto producto[], int cantidadProd)
   {
       int i, j, mostrar, acum;

       acum=min_productos(proveedor, cantidadProv, producto, cantidadProd);

        printf("\n\n    PROVEEDOR    \t       PRODUCTO       \t     CODIGO PRODUCTO    \t   STOCK   \t   IMPORTE($)    \n");

        for(i=0;i<cantidadProv;i++)
            {
                if(acum==cantidad_productos(producto, proveedor[i].idProveedor, cantidadProd))
                    {
                        mostrar=proveedor[i].idProveedor;

                        for(j=0;j<cantidadProd;j++)
                            {
                                if(producto[j].estadoProducto==1 && producto[j].idProveedor==mostrar)
                                    {
                                        printf("    %5s    \t       %-35S       \t     %6d     \t    %4d    \t     %.2f     \n", proveedor[j].descripcion, producto[j].descProducto, producto[j].codigo, producto[j].cantidad, producto[j].importe);
                                    }
                            }
                    }
            }
   }

   /** \brief Busca el mayor importe
    * \param producto Estructura a recorrer
    * \param cantidad Tamaño de la estructura
    * \return impMayor Retotna el mayor valor si es encontrado, -1 si no existe
    */
    float importeMayor (EProducto producto[], int cantidad)
    {
        int i;
        float impMayor=-1;

        for(i=0;i<cantidad;i++)
            {
                if(producto[i].estadoProducto==1)
                    {
                        impMayor=producto[i].importe;
                        break;
                    }
            }

         if(impMayor==-1)
            {
                return -1;
            }

         for(i=0;i<cantidad;i++)
            {
                if(producto[i].estadoProducto==1 && impMayor<producto[i].importe)
                    {
                        impMayor=producto[i].importe;
                    }
            }
       return impMayor;
    }

   /** \brief lista el producto mas caro
   * \param proveedor Estructura a recorrer
   * \param cantidadProv El tamaño de la estructura
   * \param producto Estructura a recorrer
   * \param cantidadProd El tamaño de la estructura
   * \return -
   */
   void listar_producto_caro (EProveedor proveedor[], int cantidadProv, EProducto producto[], int cantidadProd)
   {
       int i, j, mostrar;
       char provAux[51];
       float impMayor;

       producto_OedenarDescripcion(producto, cantidadProd);
       impMayor=importeMayor(producto, cantidadProd);

       printf("\n\n    PROVEEDOR    \t       PRODUCTO       \t     CODIGO PRODUCTO    \t   STOCK   \t   IMPORTE($)    \n");

       for(i=0;i<cantidadProd;i++)
        {
            for(j=0;j<cantidadProv;j++)
                {
                    if(producto[i].estadoProducto==1 && proveedor[j].idProveedor==producto[i].idProveedor && impMayor==producto[i].importe)
                        {
                            strcpy(provAux, proveedor[j].descripcion);
                            printf("    %5s    \t       %-35S       \t     %6d     \t    %4d    \t     %.2f     \n", provAux, producto[i].descProducto, producto[i].codigo, producto[i].cantidad, producto[i].importe);
                            break;
                        }
                }
        }

   }


      /** \brief Busca el menor importe
    * \param producto Estructura a recorrer
    * \param cantidad Tamaño de la estructura
    * \return impMenor Retotna el mayor valor si es encontrado, -1 si no existe
    */
    float importeMenor (EProducto producto[], int cantidad)
    {
        int i;
        float impMenor=-1;

        for(i=0;i<cantidad;i++)
            {
                if(producto[i].estadoProducto==1)
                    {
                        impMenor=producto[i].importe;
                        break;
                    }
            }

         if(impMenor==-1)
            {
                return -1;
            }

         for(i=0;i<cantidad;i++)
            {
                if(producto[i].estadoProducto==1 && impMenor>producto[i].importe)
                    {
                        impMenor=producto[i].importe;
                    }
            }
       return impMenor;
    }

    /** \brief lista el producto mas barato
   * \param proveedor Estructura a recorrer
   * \param cantidadProv El tamaño de la estructura
   * \param producto Estructura a recorrer
   * \param cantidadProd El tamaño de la estructura
   * \return -
   */
   void listar_producto_barato (EProveedor proveedor[], int cantidadProv, EProducto producto[], int cantidadProd)
   {
       int i, j, mostrar;
       char provAux[51];
       float impMenor;

       producto_OedenarDescripcion(producto, cantidadProd);
       impMenor=importeMenor(producto, cantidadProd);

       printf("\n\n    PROVEEDOR    \t       PRODUCTO       \t     CODIGO PRODUCTO    \t   STOCK   \t   IMPORTE($)    \n");

       for(i=0;i<cantidadProd;i++)
        {
            for(j=0;j<cantidadProv;j++)
                {
                    if(producto[i].estadoProducto==1 && proveedor[j].idProveedor==producto[i].idProveedor && impMenor==producto[i].importe)
                        {
                            strcpy(provAux, proveedor[j].descripcion);
                            printf("    %5s    \t       %-35S       \t     %6d     \t    %4d    \t     %.2f     \n", provAux, producto[i].descProducto, producto[i].codigo, producto[i].cantidad, producto[i].importe);
                            break;
                        }
                }
        }

   }
/************************************************************************************************************/

