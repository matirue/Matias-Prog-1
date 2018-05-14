#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vec[5]={5, 9, 10, 3 ,1};

    /*
    printf("%d\n", *vec); //muestra el dato del primer elemento del array
    printf("%d\n", *(vec+1));  //el mas i me indica q array muesto, el +1 es el sizeof
    printf("%d\n", *(vec+2));
    printf("%d\n", *(vec+3));
    printf("%d\n", *(vec+4));
    */
    int i;
    for(i=0;i<5;i++)
        {
            printf("Ingrese numero: ");
            scanf("%d", vec+i);
        }
   for(i=0;i<5;i++)
    {
        printf("%d \n", *(vec+i));
    }



    return 0;
}
