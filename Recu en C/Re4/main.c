#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1;
    int num2;
    int suma;
    float div;

    printf("Ingrese un numero: ");
    scanf("%d",&num1);

    fflush(stdin);

    printf("Ingrese otro numero: ");
    scanf("%d",&num2);

    if(num1==num2)
        {
         printf("primero: %d, segundo %d.",num1,num2);
        }
    else if(num1>num2)
        {
         div=num1/num2;
         printf("La division es: %.2f",div);
        }
    else
        {
         suma=num1+num2;
         printf("La suma es: %d.",suma);
        }


    return 0;
}
