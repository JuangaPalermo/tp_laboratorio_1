#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

int main(void) {

	Employee listEmployees[MAXEMPLOYEE] = {{1,"a","a",1.1,1, 0}, {2,"b","b", 2.2,2,0}}; //defino un array de empleados, con 1000 maximo.

	int opcion;
	int retornoFuncion;
	int i;
	int IdSeleccionado;

	//initEmployees(listEmployees, MAXEMPLOYEE);

	do
	{
		opcion = printMenu("1. Cargar un empleado\n2. Modificar un empleado\n3. Dar de baja un empleado\n4. Listar empleados\n5. Salir");

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
			IdSeleccionado = askForInt("Ingrese el ID que desea: ");
			retornoFuncion = modifyEmployee(listEmployees, MAXEMPLOYEE, IdSeleccionado);
			switch (retornoFuncion)
			{
			case 1:
				printf("No se han guardado las modificaciones.\n");
				break;
			case 0:
				printf("Las modificaciones se han guardado correctamente.\n");
				break;
			case -1:
				printf("No hay ningun empleado activo con ese numero de ID.\n");
				break;
			}
			break;
		case 3:
			//funcion para dar de baja empleados
			break;
		case 4:
			//ordenamiento de empleados
			for (i=0;i<MAXEMPLOYEE; i++)
			{
				printf("%8d - %51s - %51s - %10f - %8d - %8d\n", listEmployees[i].id, listEmployees[i].name, listEmployees[i].lastName, listEmployees[i].salary, listEmployees[i].sector, listEmployees[i].isEmpty);
			}
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

