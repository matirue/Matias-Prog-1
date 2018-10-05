#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "input.h"

char getChar(char message[])
{
    char dato;
    printf("%s",message);
    //fflush(stdin);
    setbuf(stdin,NULL);
    scanf("%c",&dato);
    dato=tolower(dato);
    return dato;
}

int esSoloLetra(char message[])
  {
      int i=0;
      while(message[i] != '\0')
        {
            if ((message[i]!=' ') && (message[i]<'a' || message[i]>'z') && (message[i]<'A' || message[i]>'Z'))
                {
                    return 0;
                }
             i++;
        }
        return 1;
  }


int getStringLetras(char message[], char text[])
{
     char aux[256];
     getString(message, aux);
     if(esSoloLetra(aux))
       {
          strcpy(text,aux);
          return 1;
       }
  return 0;
}

/*********************************************************************************************************************/

float getFloat(char message[])
{
    float aux;
    printf("%s",message);
    scanf("%f",&aux);
    return aux;
}

int esNumericoFlotante(char dato[])
{
   int i=0;
   int cantidadPuntos=0;
   while(dato[i] != '\0')
   {
       if (dato[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(dato[i] < '0' || dato[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
/*********************************************************************************************************************/

int getInt(char message[])
{
    int numero;
    printf("%s",message);
    scanf("%d",&numero);
    return numero;
}

 int esNumerico(char num[])
 {
     int i=0;
     while(num[i]!='\0') //recorre la cadena de caracteres hasta que encuentre el \0
        {
            if (num[i]<'0' || num[i]>'9')
                {
                    return 0;
                }
              i++;
        }
     return 1;
 }

 int getStringNumeros(char message[], char num[])
{
    char aux[256];
    getString(message, aux);
    if(esNumerico(aux))
      {
         strcpy(num,aux);
         return 1;
      }
    return 0;
 }

int getValidInt(char mensaje[],char mensajeError[],int minimo,int maximo)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(mensaje,auxStr))
        {
            printf ("\n %s\n",mensajeError);
            system("pause");
            //pause_Linux();
            continue;
        }
        auxInt = atoi(auxStr);
        if(auxInt < minimo || auxInt > maximo)
        {
            printf ("\n\n El numero del debe ser mayor a %d y menor a %d\n",minimo,maximo);
            continue;
        }
        return auxInt;
    }
}

/*********************************************************************************************************************/

 void getString(char message[], char text[])
 {
    printf("%s", message);
    setbuf(stdin,NULL);
    scanf("%[^\n]", text);

 }

 int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}

void getValidString(char mensaje[],char mensajeError[], char dato[])
{

    while(1)
    {
        if (!getStringLetras(mensaje,dato))
        {
            printf ("%s\n",mensajeError);
            continue;
        }
        clean_stdin();
        break;
    }

}

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

