#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

int main(void) {

	Employee listEmployees[MAXEMPLOYEE]; //defino un array de empleados, con 1000 maximo.

	int opcion;
	int retornoFuncion;

	initEmployees(listEmployees, MAXEMPLOYEE);

	do
	{
		printf ("1. Cargar un empleado\n");
		printf ("2. Modificar un empleado\n");
		printf ("3. Dar de baja un empleado\n");
		printf ("4. Listar empleados\n");
		printf ("5. Salir\n");
		printf("Ingrese la opcion que desee: ");
		scanf ("%d", &opcion);

		switch(opcion)
		{
		case 1:
			retornoFuncion = newEmployee(listEmployees, MAXEMPLOYEE);
			switch(retornoFuncion)
			{
			case 0:
				printf("Se han ingresado los datos del empleado.\n");
				break;
			case -1:
				printf("No hay espacio disponible para agregar a este empleado\n");
				break;
			}

			break;
		case 2:
			//funcion para modificar empleados
			break;
		case 3:
			//funcion para dar de baja empleados
			break;
		case 4:
			//ordenamiento de empleados
			break;
		case 5:
			//mensaje de salida
			break;
		//default:
			//verificacion de que haya ingresado una opcion correcta.
		}

	}while (opcion != 5);
	//necesito un menu con: Alta, Baja, Modif, Listar


	return EXIT_SUCCESS;
}
