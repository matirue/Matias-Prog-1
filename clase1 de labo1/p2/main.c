#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    int i;

    int max;
    int min;
    int suma=0;
    float prom;
    int flag=0;

    for(i=0;i<10;i++)
        {
            printf("Ingrese un nmero: \n");
            scanf("%d", &i);
            suma++;

            if(i==0 || flag==0)
             {
                 max=i;
                 min=i;
                 flag=1;
             }
            if(i>max)
             {
                 max=i;
             }
            if(i<min)
             {
                 min=i;
             }

             prom=(float)suma/i;


        }

        printf("El maximo es %d \n",max);
        printf("El minimo es %d \n",min);
        printf("El promedio es de %.2f \n",prom);
    return 0;
}
