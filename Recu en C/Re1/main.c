#include <stdio.h>
#include <stdlib.h>

int main()
{
    int base;
    int altura;
    int perimetro;
    float sup;

    printf("Ingrese la base: ");
    scanf("%d", &base);

    printf("Ingrese una altura: ");
    scanf("%d", &altura);

    perimetro=base*3;

    sup=base*altura/2;

    printf("Perimetro: %d y superficie de: %.2f " , perimetro , sup);



    return 0;
}
