#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char dia[128];

    printf("Ingrese un  dia de la semana: ");
    scanf("%s",dia);

    switch(dia[128])
     {
        case 'lunes':
        case 'martes':
        case 'miercoles':
        case 'jueves':
        case 'viernes':
            printf("A trabajar.\n");
            break;

        case 'sabado':
        case 'domingo':
            printf("Buen finde.\n");
            break;

        default:
            printf("Lo ingresado no corresponde a un dia de la semana.\n");

     }
    return 0;
}
