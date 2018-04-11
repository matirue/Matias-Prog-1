#include<stdio.h>

#include<stdlib.h>

#include<ctype.h>

#include<string.h>



void strupr(char *cadena);
void strlwr(char *cadena);

void gets(char *cadena);



int main(){

	char nom[31],nom2[32];



	printf("Nombre:");

	setbuf(stdin, NULL);

	gets(nom);

	strupr(nom);



	printf("Nombre:");

	setbuf(stdin, NULL);

	gets(nom2);

	strupr(nom2);



	if(strcmp(nom,nom2)==0){

		printf("Son iguales");


	}


	if(strcmp(nom,nom2)>0){

		printf("%s Es mayor",nom);


	}


	if(strcmp(nom,nom2)<0){

		printf("%s Es menor",nom);


	}


	return 0;

}



void strupr(char *cadena){

	int i;



	for(i=0; i<strlen(cadena); i++){

		cadena[i]=toupper(cadena[i]);

	}


	return;

}

void strlwr(char *cadena){

	int i;



	for(i=0; i<strlen(cadena); i++){

		cadena[i]=tolower(cadena[i]);

	}


	return;

}



void gets(char *cadena){

	scanf("%[^\n]", cadena);

	return;
}
