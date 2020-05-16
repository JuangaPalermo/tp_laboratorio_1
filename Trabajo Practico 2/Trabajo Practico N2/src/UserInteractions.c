#include "UserInteractions.h"

int printMenu (char opciones [], int cantidadOpciones)
{
	int returnValue;

	printf("%s\n", opciones);
	printf("Ingrese la opcion que desee: ");
	scanf("%d", &returnValue);

	while (returnValue > cantidadOpciones || returnValue < 1)
	{
		printf("Error, opcion invalida. Por favor, reingrese la opcion que desea: ");
		scanf("%d", &returnValue);
	}

	return returnValue;
}

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

float getFloat(char mensaje[])
{
	float returnValue;
	float numeroCargado;

	printf("%s", mensaje);
	scanf("%f", &numeroCargado);

	returnValue = numeroCargado;

	return returnValue;
}

char getChar (char mensaje[], char error[], char letraUno, char letraDos)
{
    char opcionSeleccionada;
    int returnValue;

    printf("%s", mensaje);
    __fpurge(stdin);
    scanf("%c", &opcionSeleccionada);
    returnValue = tolower(opcionSeleccionada);

    while(returnValue != letraUno && returnValue != letraDos)
    {
        printf("%s", error);
        __fpurge(stdin);
        scanf("%c", &opcionSeleccionada);
        returnValue = tolower(opcionSeleccionada);
    }

    return returnValue;
}

int askForInt (char texto [])
{
	int returnValue;

	printf("%s", texto);
	scanf("%d", &returnValue);

	return returnValue;
}

