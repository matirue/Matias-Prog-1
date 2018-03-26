#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int nota;
    char sexo;
    int edad;

    //a)

    float promTotal;
    int acumuladorNota=0;

    //b)

    int notaBaja;
    char sexoBajo;
    int flag=0;

    //c)

    int cantVaronMas18=0;

    //d)

    int notaJoven;
    char sexoJoven;
    int edadJoven;

    //e)

    int edadMujer;
    int notaPrimeraMujer;
    int contMujer=0;



    for(int i=0; i<5; i++)
    {
        printf("Ingrese nota: ");
        scanf("%d",&nota);

        while(nota<0 || nota >10)
        {
            printf("Error. Reingrese nota: ");
            scanf("%d",&nota);
        }

        acumuladorNota+=nota;

        fflush(stdin);

        printf("Ingese Sexo ('f' para femenino, 'm' para masculino): ");
        fflush(stdin);
        scanf("%c",&sexo);
        sexo=tolower(sexo);

        while(!(sexo=='f' || sexo=='m'))
        {
            printf("Error. Reingese Sexo ('f' para femenino, 'm' para masculino):");
            fflush(stdin);
            scanf("%c",&sexo);
            sexo=tolower(sexo);
        }

        fflush(stdin);

        printf("Ingrese edad:");
        scanf("%d",&edad);

        while(edad<0)
        {
            printf("Error. Reingrese edad: ");
            scanf("%d",&edad);
        }

        if(nota<notaBaja || flag==0 )
        {
            notaBaja=nota;
            sexoBajo=sexo;
        }


        if(sexo=='m' && nota>5 && edad>17)
        {
            cantVaronMas18++;
        }

        if(edad<=edadJoven || flag==0)
        {
            edadJoven=edad;
            notaJoven=nota;
            sexoJoven=sexo;
            flag=1;

        }

        if(sexo=='f' && contMujer==0)
        {
            contMujer++;
            edadMujer=edad;
            notaPrimeraMujer=nota;
        }






    }

    promTotal=(float)acumuladorNota/5;

    printf("a) %.2f. \n",promTotal);
    printf("b) nota baja de %d  y sexo %c \n ",notaBaja,sexoBajo);
    printf("c) cantidad de varones mayores de 18 aprobados %d \n",cantVaronMas18);
    printf("d) sexo del mas joven  %c  y su nota  %d \n",sexoJoven,notaJoven);


    if(contMujer==0)
    {
        printf("no hay mujeres");
    }
    else
    {
        printf("e) edad de mujer %d y su nota %d \n",edadMujer,notaPrimeraMujer);
    }

    return 0;
}
