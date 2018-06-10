#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "input.h"

/**
* \brief Solicita una leta al usuario y la devuelve.
* \param algo Es el mensaje a mostrar.
* \return Devuelve la letra ingresada.
**/
char getChar(char algo[])
{
    char dato;
    printf("%s",algo);
    fflush(stdin);
    scanf("%c",&dato);
    dato=tolower(dato);
    return dato;
}

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param sms Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char sms[])
{
    float aux;
    printf("%s",sms);
    scanf("%f",&aux);
    return aux;
}

/**
* \brief Le pide un numero al ususario y devuelve un resultado.
* \param sms Es el mensaje a ser mostrado.
* \return Devuelve el numero (x) ingresado por el usuario.
**/
int getInt(char sms[])
{
    int x;
    printf("%s",sms);
    scanf("%d",&x);
    return x;
}

 /** \brief Verifica si el valor recibido contiene solo letras
  * \param dato Array con la cadena a ser analizada
  * \return 1 si contiene solo ' ' y 0 si no lo es
  */
  int esSoloLetra(char dato[])
  {
      int i=0;
      while(dato[i] != '\0')
        {
            if ((dato[i]!=' ') && (dato[i]<'a' || dato[i]>'z') && (dato[i]<'A' || dato[i]>'Z'))
                {
                    return 0;
                }
             i++;
        }
        return 1;
  }

/** VERIFICAR NUMERO
 * \brief verifica si el valor recibido es numerico
 * \param  x Array  con la cadena a ser analizado
 * \return 1 si es numerico y 0 si no lo es.
 */

 int esNumerico(char x[])
 {
     int i=0;
     while(x[i]!='\0') //recorre la cadena de caracteres hasta que encuentre el \0
        {
            if (x[i]<'0' || x[i]>'9')
                {
                    return 0;
                }
              i++;
        }
     return 1;
 }

 /**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param x Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int esNumericoFlotante(char x[])
{
   int i=0;
   int cantidadPuntos=0;
   while(x[i] != '\0')
   {
       if (x[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(x[i] < '0' || x[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
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

/** FC PEDIR TEXTO
 * \brief Pide un texto al usuario y lo devuelve
 * \param sms Es el texto a ser mostrado
 * \param input Es el Array donde se cargara el texto pedido
 * \return void
 */
 void getString(char sms[], char a[])
 {
    printf("%s", sms);
    //scanf("%s", a);
    gets(a);
 }

/**
* \brief Pide un texto numerico al usuario y lo devuelve
* \param sms Es el texto a ser mostrado
* \param num Es el Array donde se cargara el texto pedido
* \return 1 si el texto contiene solo numeros, 0 caso contrario
*/
int getStringNumeros(char sms[], char num[])
{
    char aux[256];
    getString(sms, aux);
    if(esNumerico(aux))
      {
         strcpy(num,aux);
         return 1;
      }
    return 0;
 }

/** VALIDA SI ES TODO LETRA
* \brief Pide un texto solo letras al usuario y lo devuelve
* \param sms Es el texto a ser mostrado
* \param a Es el Arrat donde se cargara el texto pedido
* \return 1 si el texto contiene solo letras
*/
int getStringLetras(char sms[], char a[])
{
     char aux[256];
     getString(sms, aux);
     if(esSoloLetra(aux))
       {
          strcpy(a,aux);
          return 1;
       }
  return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
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


 /**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param mensaje Es el mensaje a ser mostrado para solicitar el dato
 * \param mensajeError Es el mensaje a ser mostrado en caso de error
 * \param minimo y maximo Rango
 * \return El número ingresado por el usuario
 *
 */
int getValidInt(char mensaje[],char mensajeError[],int minimo,int maximo)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(mensaje,auxStr))
        {
            printf ("%s\n",mensajeError);
            system("pause");
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

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

/**
 * \brief Solicita un string
 * \param mensaje Es el mensaje a ser mostrado para solicitar el dato
 * \param mensajeError Es el mensaje a ser mostrado en caso de error
 * \param dato Array donde se cargará el texto ingresado
 * \return -
 *
 */
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

/**
 * \brief Detiene la ejecucion y muestra un mensaje
 * \param message Mensaje
 * \return -
 *
 */
void pause(char message[])
{
    getChar(message);
    clean_stdin();
}



