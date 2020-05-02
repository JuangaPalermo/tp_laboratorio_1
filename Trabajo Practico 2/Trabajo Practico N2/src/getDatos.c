#include <stdio.h>
#include <stdio_ext.h>
#include "getDatos.h"
#include <string.h>
#include "ArrayEmployees.h"


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


float getFloat(int primerValor, int segundoValor)
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

int buscarLibre(Employee listado[], int tam)
{
    int i;
    int index = -1;
    for(i=0; i<tam; i++)
    {
        if(listado[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

