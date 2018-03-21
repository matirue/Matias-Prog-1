#include <stdio.h>
#include <limits.h>
void main(void)
{
int i;
int suma = 0;
int max = INT_MIN; // constante definida en limits.h
int min = INT_MAX; // constante definida en limits.h

   for(i=0; i<10;i++)
      {
         int aux;
         scanf("%d",&aux);
         suma=suma+aux;

           if(aux>max)
            {
              max = aux;
            }

           if(aux<min)
            {
              min = aux;
            }

       }

printf("la suma es:%d\n",suma);
printf("El maximo es:%d\n",max);
printf("El minimo es:%d\n",min);

}
