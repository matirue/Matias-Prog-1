#include <stdio.h>
#include <stdlib.h>

#define C 3
int main()
{
    int leg[C], i;
    char nom[C][31];
    float salario[C];

    for(i=0;i<C;i++)
        {
            //printf("\n Legajo: ");
            leg[i]=i+1;


''
            printf("\n Nombre: ");
            setbuf(stdin,NULL);//fflush(stdin);
            scanf("%[^\n]", nom[i]);


            printf("\n Salario: ");
            scanf("%f",&salario[i]);
        }

        printf("\nLegajo\t\tNombre\t\tSalario");

        for(i=0;i<C;i++)
            {
                printf("\n%d\t\t%s\t\t$%.2f ",leg[i],nom[i],salario[i]);
            }
    return 0;
}
