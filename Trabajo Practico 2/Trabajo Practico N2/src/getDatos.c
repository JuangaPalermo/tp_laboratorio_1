#include "getDatos.h"


int getInt (char mensaje[], char error[], int min, int max)
{
    int valor;

    printf ("%s", mensaje);
    scanf ("%d", &valor);

    while (valor < min || valor > max)
    {
        printf ("%s", error);
        scanf ("%d", &valor);
    }

  return valor;
}


float getPromedio(int primerValor, int segundoValor)
{
    return ((float) primerValor + segundoValor) / 2;
}


void getString (char mensaje[], char texto[], int largo)
{
    printf("%s", mensaje);
    __fpurge(stdin);
    fgets(texto, largo, stdin);
    texto[strlen(texto)-1]='\0';
}

float getFloat(char mensaje[], char error[])
{
	float returnValue;
	float numeroCargado;

	printf("%s", mensaje);
	scanf("%f", &numeroCargado);

	returnValue = numeroCargado;

	return returnValue;
}



