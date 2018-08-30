#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//menu
int main()
{
    char opcion;

    do{
        printf("\n A-Alata ");
        printf("\n B-Baja ");
        printf("\n C-Modificar ");
        printf("\n D-Salir ");
        printf("\n\n ELIJA UNA OPCION: ");

        setbuf(stdin, NULL);
        scanf("%c", &opcion);
        opcion=toupper(opcion);



        switch(opcion)
    {
        case 'A':
        printf("\n\n----AAAAAAAAAAAAAAA----\n");
        break;

        case 'B':
        printf("\n\n----BBBBBBBBBBBBBB----\n");
        break;

        case 'C':
        printf("\n\n----CCCCCCCCCCCCCC----\n");
        break;

    }

    system("pause");
    system("cls");

    }while(opcion!='D');



    return 0;
}
