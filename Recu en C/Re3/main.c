#include <stdio.h>
#include <stdlib.h>

int main()
{
    float precio;
    float descuento;
    float iva=.25;
    float precioIva;
    float descDin;
    float precioDesc;
    float precioFinal;

    printf("Ingrese el precio: ");
    scanf("%f", &precio);

    fflush(stdin);

    printf("Ingrese el descuento: ");
    scanf("%f", &descuento);

    descDin=precio*(descuento/100);

    precioDesc=precio-descDin;

    precioIva=precio*iva;

    precioFinal=precioDesc+precioIva;

    printf("El descuento en monto: $%.2f. El iva es de %.2f . El precio con descuento es de $%.2f . El precio final es de $%.2f .",descDin,iva,precioDesc,precioFinal);

    /* printf("El descuento en monto: $%.2f." ,descDin);
    printf("El iva es de %.2f./n",iva);
    printf("El precio con descuento es de $%.2f./n",precioDesc);
    printf("El precio final es de $%.2f./n",precioFinal); */
    return 0;
}
