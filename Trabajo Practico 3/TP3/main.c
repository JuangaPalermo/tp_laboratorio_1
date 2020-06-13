#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "UserInteractions.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    LinkedList* listEmployees;
    int opcionSeleccionada;
    int retornoFuncion;
    int archivoCreado = 0; //0 si no hay archivo creado, 1 si el archivo se creo.

    listEmployees = ll_newLinkedList();

    do
    {
    	opcionSeleccionada = printMenu("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n2. Cargar los datos de los empleados desde el archivo data.dat (modo binario)\n3. Dar de alta un empleado\n4. Modificar datos de un empleado\n5. Dar de baja un empleado\n6. Listar a los empleados\n7. Ordenar a los empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n9. Guardar los datos de los empleados en el archivo data.dat (modo binario)\n10. Salir", 10);

    	switch(opcionSeleccionada)
    	{
    		case 1:
    			if (archivoCreado == 0)
    			{
    				retornoFuncion = controller_loadFromText("data.csv", listEmployees);
    				if(retornoFuncion == 1)
    				{
    					printf("Archivo cargado.\n");
    				}
    				else
    				{
    					printf("Error.\n");
    				}
    			}
    			else
    			{
    				printf("Ya hay un archivo creado.\n");
    			}
    			break;
    		case 2:
    			if (archivoCreado == 0)
				{
					retornoFuncion = controller_loadFromBinary("data.csv", listEmployees);
					if(retornoFuncion == 1)
					{
						printf("Archivo cargado.\n");
					}
					else
					{
						printf("Error.\n");
					}
				}
				else
				{
					printf("Ya hay un archivo creado.\n");
				}
				break;
    		case 3:
    			retornoFuncion = controller_addEmployee(listEmployees);
    			if(retornoFuncion == 1)
    			{
    				printf("Empleado cargado.\n");
    			}
    			else
    			{
    				printf("Error. Empleado no cargado\n");
    			}
    			break;
    		case 4:
    			retornoFuncion = controller_editEmployee(listEmployees);
    			switch(retornoFuncion)
    			{
    			case 1:
    				printf("Cambios guardados.\n");
    				break;
    			case -1:
    				printf("Cambios cancelados.\n");
    				break;
    			case 0:
    				printf("Error, no se encuentra al empleado.\n");
    				break;
    			}
    			break;
			case 5:
				retornoFuncion = controller_removeEmployee(listEmployees);
				switch(retornoFuncion)
				{
				case 1:
					printf("Empleado eliminado.\n");
					break;
				case -1:
					printf("Cancelo la eliminacion.\n");
					break;
				case 0:
					printf("Error, no se encuentra al empleado.\n");
					break;
				}
				break;
			case 6:
				retornoFuncion = controller_ListEmployee(listEmployees);
				if(retornoFuncion == 1)
				{
					printf("Lista impresa.\n");
				}
				else
				{
					printf("Error.\n");
				}
				break;
			case 7:
				retornoFuncion = controller_sortEmployee(listEmployees);
				if(retornoFuncion == 1)
				{
					printf("Lista ordenada.\n");
				}
				else
				{
					printf("Error.\n");
				}
				break;
			case 8:
				retornoFuncion = controller_saveAsText("data.csv", listEmployees);
				if(retornoFuncion == 1)
				{
					printf("Archivo guardado.\n");
				}
				else
				{
					printf("No se pudo guardar el archivo.\n");
				}
				break;
			case 9:
				retornoFuncion = controller_saveAsBinary("data.csv", listEmployees);
				if(retornoFuncion == 1)
				{
					printf("Archivo guardado.\n");
				}
				else
				{
					printf("No se pudo guardar el archivo.\n");
				}
				break;
			case 10:
				printf("\n\nGracias por usar el programa.\n");
				break;
		}

    }while(opcionSeleccionada != 10);


    return 0;
}
