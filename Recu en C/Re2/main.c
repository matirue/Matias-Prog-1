#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nom[128];
    char loc[128];

    printf("Ingrese su nombre: ");
    scanf("%s",nom);

    fflush(stdin);


    printf("Ingrese su localidad: ");
    scanf("%s",loc);

    printf("Se llama %s y vive en %s.",nom,loc);



    return 0;
}
