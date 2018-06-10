#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define MAX 51

typedef struct{
    char descripcion[MAX];
    int idProveedor;
    int estado;
}EProveedor;

typedef struct{
    int codigo;
    char descProducto[MAX];
    float importe;
    int cantidad;
    int estadoProducto;
    int idProveedor;
}EProducto;


int menu();


void hardCode_prov(EProveedor []);
void hardCode_prod(EProducto []);



void inicializarProd(EProducto [],int);
void inicializarProv(EProveedor [],int);


int buscarEspacioLibreProd(EProducto [],int);
int buscarEspacioLibreProv(EProveedor [],int);

int buscarPorCodigoProd(EProducto [],int,int);
int buscarPorIdProv(EProveedor [],int,int);

void mostrarProveedor(EProveedor );
void listarProveedor(EProveedor [],int);

void producto_OedenarDescripcion(EProducto [],int);
void proveedor_OedenarDescripcion(EProveedor [],int);

void mostrarProductoPorCodigo(EProducto );
void listarproducto(EProducto [],int);

void altaProv(EProveedor [],int);
void altaProd(EProducto [],int,EProveedor [],int);

void bajaProd(EProducto [],int);

void setProducto(EProducto [],int,int,char [],float,int);
void setProveedor(EProveedor [],int,int,char []);

int menuModi();
void actualizar(EProducto [],int);

int menuInformes();
void informar(EProducto [],int);
float inf_sumarImportes(EProducto [],int);
int inf_contarImporte(EProducto [],int);
void inf_stockMayorDiez(EProducto [],int);
void inf_stockMenorDiez(EProducto [],int);
int inf_cantidadMenor_Promedio(EProducto [],int);
int inf_cantidadMayor_Promedio(EProducto [],int);

int menuListas ();

void listar_productoPorDescripcion(EProducto [],int);
void listar_producto_importe(EProducto [],int );
void producto_OedenarImporte(EProducto [],int );
void listar_producto_descripcion(EProducto [],int);
void listar_producto_menorDiez(EProducto [],int);
void listar_producto_mayorDiez(EProducto [],int);
void listar_producto_mayorPromedio(EProducto [],int);
void listar_producto_menorPromedio(EProducto [],int);
void listar_proveedor_stockMenorIgDiez(EProveedor [],int,EProducto [],int);
void listar_proveedor_productos(EProveedor [], int,EProducto [],int);
void listar_proveedor_conSusProductos(EProveedor [],int,EProducto [],int);
int cantidad_productos(EProducto [], int , int );
int max_productos(EProveedor [],int,EProducto [],int);
int min_productos(EProveedor [],int,EProducto [],int);
void listar_proveedor_conMasProductos(EProveedor [],int,EProducto [],int);
void listar_proveedor_conMenorProductos(EProveedor [],int,EProducto [],int);
float importeMayor(EProducto [],int);
float importeMenor(EProducto [],int);
void listar_producto_caro(EProveedor [],int,EProducto [],int);
void listar_producto_barato(EProveedor [],int,EProducto [],int);





#endif // FUNCIONES_H_INCLUDED

