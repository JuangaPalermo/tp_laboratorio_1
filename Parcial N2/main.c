/*
 PARCIAL N2	DE PROGRAMACION - UTN
 Juan Gabriel Palermo - 1 'F'.
 */

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"
#include "Aerolinea.h"
#include "UserInteractions.h"

int main()
{
    LinkedList* listVuelos;
	LinkedList* listPilotos;

	int opcionSeleccionada;
	int retornoFuncion;

	listVuelos = ll_newLinkedList();
	listPilotos = ll_newLinkedList();

	hardcodearPilotos(listPilotos);



	do
	{
		opcionSeleccionada = printMenu("1.Cargar archivo\n2.Imprimir vuelos\n3.Cantidad de pasajeros\n4.Cantidad de pasajeros a Irlanda\n5.Filtrar vuelos cortos\n6.Listar vuelos a Portugal\n7.Filtrar a Alex Lifeson\n8.Guardar archivo\n9.Salir", 9);

		switch(opcionSeleccionada)
		{
		case 1:
			retornoFuncion = controller_loadFromText("Vuelos.csv", listVuelos);
			if(retornoFuncion == 1)
			{
				printf("Archivo cargado con exito.\n");
			}
			else
			{
				printf("Error al cargar archivo.\n");
			}
			break;
		case 2:
		    retornoFuncion = controller_listVuelos(listVuelos, listPilotos);
		    if(retornoFuncion == 1)
            {
                printf("Lista Impresa.\n");
            }
            else
            {
                printf("Error.\n");
            }
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		}
	}while(opcionSeleccionada != 9);

    return 0;
}
