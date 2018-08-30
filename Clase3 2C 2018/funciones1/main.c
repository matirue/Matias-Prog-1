#include <stdio.h>
#include <stdlib.h>


//caso1 de funcion
void suma_caso1(void);

//caso2 de funcion
void suma_caso2(int, int);

//caso3 de funcion
int suma_caso3(void);

//caso4 de funcion
int suma_caso4(int, int);



int main()
{
    int num1, num2;
    int numUno, numDos;
    int solucionCaso3;
    int solucionCaso4;

    printf("\n---------CASO 1 DE FUN-----------\n\n");
    suma_caso1();
    printf("\n\n---------------------------------\n\n");




    printf("\n---------CASO 2 DE FUN-----------\n\n");

    printf("\n INGRESE NUM A: ");
    scanf("%d",&num1);

    printf("\n INGRESE NUM B: ");
    scanf("%d", &num2);

    suma_caso2(num1, num2);
    printf("\n\n---------------------------------\n\n");






    printf("\n---------CASO 3 DE FUN-----------\n\n");

    solucionCaso3=suma_caso3();

    printf("\n------Suma caso 3: %d", solucionCaso3);

    printf("\n\n---------------------------------\n\n");






    printf("\n---------CASO 4 DE FUN-----------\n\n");

    printf("\n INGRESE NUM A: ");
    scanf("%d",&numUno);

    printf("\n INGRESE NUM B: ");
    scanf("%d", &numDos);

    solucionCaso4=suma_caso4(numUno, numDos);

    printf("\n------Suma caso 4: %d", solucionCaso4);

    printf("\n\n---------------------------------\n\n");



    return 0;
}

//caso1
void suma_caso1 (void)
{
    int num1, num2, sumar;

    printf("\n INGRESE NUM A: ");
    scanf("%d",&num1);

    printf("\n INGRESE NUM B: ");
    scanf("%d", &num2);

    sumar=num1+num2;

    printf("\n------Suma caso 1: %d", sumar);
}

//caso2
void suma_caso2(int a, int b)
{
    int suma;
    suma=a+b;
    printf("\n------Suma caso 2: %d",suma);
}

//caso3
int suma_caso3(void)
{
    int num1, num2, sumar;

    printf("\n INGRESE NUM A: ");
    scanf("%d",&num1);

    printf("\n INGRESE NUM B: ");
    scanf("%d", &num2);

    sumar=num1+num2;

    return sumar;
}

//caso4
int suma_caso4(int a, int b)
{
    int suma;
    suma=a+b;

    return suma;
}
