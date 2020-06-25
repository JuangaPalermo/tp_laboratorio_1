#include <stdlib.h>
#include "Aerolinea.h"
#include <string.h>

eVuelo* vuelo_new()
{
	eVuelo* auxVuelo;

	auxVuelo = (eVuelo*)malloc(sizeof(eVuelo));

	return auxVuelo;
}


ePiloto* piloto_new()
{
	ePiloto* auxPiloto;

	auxPiloto = (ePiloto*)malloc(sizeof(ePiloto));

	return auxPiloto;
}

eVuelo* vuelo_newParametros(char* idVuelo,char* idAvion,char* idPiloto,char* fecha, char* destino, char* cantPasajeros, char* horaDespegue, char* horaLlegada)
{
	eVuelo* auxVuelo;

	auxVuelo = vuelo_new();

	if(auxVuelo != NULL)
	{
		vuelo_setIdVuelo(auxVuelo, atoi(idVuelo));
		vuelo_setIdAvion(auxVuelo, atoi(idAvion));
		vuelo_setIdPiloto(auxVuelo, atoi(idPiloto));
		vuelo_setFecha(auxVuelo, fecha);
		vuelo_setDestino(auxVuelo, destino);
		vuelo_setCantPasajeros(auxVuelo, atoi(cantPasajeros));
		vuelo_setHoraDespegue(auxVuelo, atoi(horaDespegue));
		vuelo_setHoraLlegada(auxVuelo, atoi(horaLlegada));
	}

	return auxVuelo;
}

ePiloto* piloto_newParametros(char* nombre, char* idPiloto)
{
	ePiloto* auxPiloto;

	auxPiloto = piloto_new();

	if(auxPiloto != NULL)
	{
		piloto_setNombrePiloto(auxPiloto, nombre);
		piloto_setIdPiloto(auxPiloto, atoi(idPiloto));
	}

	return auxPiloto;
}

int vuelo_setIdVuelo(eVuelo* this,int idVuelo)
{
	int returnValue = 0;

	if(this != NULL)
	{
		this->idVuelo = idVuelo;
		returnValue = 1;
	}

	return returnValue;
}
int vuelo_getIdVuelo(eVuelo* this,int* idVuelo)
{
	int returnValue = 0;

	if(this != NULL)
	{
		*idVuelo = this->idVuelo;
		returnValue = 1;
	}

	return returnValue;
}

int vuelo_setIdAvion(eVuelo* this,int idAvion)
{
	int returnValue = 0;

	if(this != NULL)
	{
		this->idAvion = idAvion;
		returnValue = 1;
	}

	return returnValue;
}
int vuelo_getIdAvion(eVuelo* this,int* idAvion)
{
	int returnValue = 0;

	if(this != NULL)
	{
		*idAvion = this->idAvion;
		returnValue = 1;
	}

	return returnValue;
}


int vuelo_setIdPiloto(eVuelo* this,int idPiloto)
{
	int returnValue = 0;

	if(this != NULL)
	{
		this->idPiloto = idPiloto;
		returnValue = 1;
	}

	return returnValue;
}
int vuelo_getIdPiloto(eVuelo* this,int* idPiloto)
{
	int returnValue = 0;

	if(this != NULL)
	{
		*idPiloto = this->idPiloto;
		returnValue = 1;
	}

	return returnValue;
}


int vuelo_setFecha (eVuelo* this,char* fecha)
{
	int returnValue = 0;

	if(this != NULL)
	{
		strcpy(this->fecha, fecha);
		returnValue = 1;
	}

	return returnValue;
}
int vuelo_getFecha (eVuelo* this,char* fecha)
{
	int returnValue = 0;

	if(this != NULL)
	{
		strcpy(fecha, this->fecha);
		returnValue = 1;
	}

	return returnValue;
}


int vuelo_setDestino(eVuelo* this,char* destino)
{
	int returnValue = 0;
	int i;

	if(this != NULL)
	{
		//strlwr(destino);
		for(i=0; i<strlen(destino); i++)
		{
			if(i==0 || i-1 == ' ')
			{
				toupper(destino[i]);
			}
		}

		strcpy(this->destino, destino);
		returnValue = 1;
	}

	return returnValue;
}
int vuelo_getDestino(eVuelo* this,char* destino)
{
	int returnValue = 0;

	if(this != NULL)
	{
		strcpy(destino, this->destino);
		returnValue = 1;
	}

	return returnValue;
}


int vuelo_setCantPasajeros(eVuelo* this,int cantPasajeros)
{
	int returnValue = 0;

	if(this != NULL)
	{
		this->cantPasajeros = cantPasajeros;
		returnValue = 1;
	}

	return returnValue;
}
int vuelo_getCantPasajeros(eVuelo* this,int* cantPasajeros)
{
	int returnValue = 0;

	if(this != NULL)
	{
		*cantPasajeros = this->cantPasajeros;
		returnValue = 1;
	}

	return returnValue;
}


int vuelo_setHoraDespegue(eVuelo* this,int horaDespegue)
{
	int returnValue = 0;

	if(this != NULL)
	{
		this->horaDespegue = horaDespegue;
		returnValue = 1;
	}

	return returnValue;
}
int vuelo_getHoraDespegue(eVuelo* this,int* horaDespegue)
{
	int returnValue = 0;

	if(this != NULL)
	{
		*horaDespegue = this->horaDespegue;
		returnValue = 1;
	}

	return returnValue;
}


int vuelo_setHoraLlegada(eVuelo* this,int horaLlegada)
{
	int returnValue = 0;

	if(this != NULL)
	{
		this->horaLlegada = horaLlegada;
		returnValue = 1;
	}

	return returnValue;
}
int vuelo_getHoraLlegada(eVuelo* this,int* horaLlegada)
{
	int returnValue = 0;

	if(this != NULL)
	{
		*horaLlegada = this->horaLlegada;
		returnValue = 1;
	}

	return returnValue;
}


int piloto_setIdPiloto(ePiloto* this,int idPiloto)
{
	int returnValue = 0;

	if(this != NULL)
	{
		this->idPiloto = idPiloto;
		returnValue = 1;
	}

	return returnValue;
}
int piloto_getIdPiloto(ePiloto* this,int* idPiloto)
{
	int returnValue = 0;

	if(this != NULL)
	{
		*idPiloto = this->idPiloto;
		returnValue = 1;
	}

	return returnValue;
}


int piloto_setNombrePiloto(ePiloto* this,char* nombre)
{
	int returnValue = 0;
	int i;

	if(this != NULL)
	{
		//strlwr(nombre);
		for(i=0; i<strlen(nombre); i++)
		{
			if(i==0 || i-1 == ' ')
			{
				toupper(nombre[i]);
			}
		}

		strcpy(this->nombre, nombre);
		returnValue = 1;
	}

	return returnValue;
}
int piloto_getNombrePiloto(ePiloto* this,char* nombre)
{
	int returnValue = 0;

	if(this != NULL)
	{
		strcpy(nombre, this->nombre);
		returnValue = 1;
	}

	return returnValue;
}
