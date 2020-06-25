#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Aerolinea.h"
#include "parser.h"
#include "UserInteractions.h"


int controller_loadFromText(char* path , LinkedList* pArrayListVuelos)
{
	int returnValue = 0;

	FILE* pArchivo;

	pArchivo = fopen(path, "r");

	if(pArrayListVuelos != NULL && pArchivo != NULL)
	{
		parser_VueloFromText(pArchivo, pArrayListVuelos);
		fclose(pArchivo);
		returnValue = 1;
	}

	return returnValue;
}

/*int hardcodearPilotos (LinkedList* pArrayList)
{
	int retorno = 0;
	int idPiloto[5]={1,2,3,4,5};
	char nombre[5][128]={"Alex Lifeson", "Richard Bach", "John Kerry", "Erwin Rommel", "Stephen Coonts"};
	int i;
	ePiloto* auxPiloto;

	if(pArrayList != NULL)
	{
		for(i=0; i<5; i++)
		{
			auxPiloto = piloto_newParametros(idPiloto[i], nombre[i]);
			ll_add(pArrayList, auxPiloto);
			retorno = 1;
		}
	}

	return retorno;
}*/

int controller_listVuelos(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos)
{
    int returnValue = 0;
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[15];
    char destino[30];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    char nombre[128];
    int idPiloto2;

    int i;
    int j;
    int lenVuelos;
    int lenPilotos;
    eVuelo* auxVuelo;
    ePiloto* auxPiloto;

    if(pArrayListVuelos != NULL && pArrayListPilotos != NULL)
    {
        lenVuelos = ll_len(pArrayListVuelos);
        lenPilotos = ll_len(pArrayListPilotos);

        printf("| %5s | %5s | %60s | %15s | %30s | %5s | %5s | %5s |\n", "IDvue", "IDavi", "Nombre Piloto", "Fecha", "Destino", "Pasaj", "Hdesp", "Hlleg");
        for(i = 0; i<lenVuelos; i++)
        {
            auxVuelo = ll_get(pArrayListVuelos, i);
            vuelo_getIdVuelo(auxVuelo, &idVuelo);
            vuelo_getIdAvion(auxVuelo, &idAvion);
            vuelo_getIdPiloto(auxVuelo, &idPiloto);
            vuelo_getFecha(auxVuelo, fecha);
            vuelo_getDestino(auxVuelo, destino);
            vuelo_getCantPasajeros(auxVuelo, &cantPasajeros);
            vuelo_getHoraDespegue(auxVuelo, &horaDespegue);
            vuelo_getHoraLlegada(auxVuelo, &horaLlegada);
            for(j = 0; j<lenPilotos; j++)
            {
                auxPiloto = ll_get(pArrayListPilotos, j);
                piloto_getIdPiloto(auxPiloto, &idPiloto2);
                piloto_getNombrePiloto(auxPiloto, nombre);
                if(idPiloto == idPiloto2)
                {
                    break;
                }
            }

            printf("| %5d | %5d | %60s | %15s | %30s | %5d | %5d | %5d |\n", idVuelo, idAvion, nombre, fecha, destino, cantPasajeros, horaDespegue, horaLlegada);
        }

        returnValue = 1;
    }

    return returnValue;
}
