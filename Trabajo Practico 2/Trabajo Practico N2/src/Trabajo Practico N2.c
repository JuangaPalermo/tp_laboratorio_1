#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

#define MAXEMPLOYEE 1000

int main(void) {

	Employee listEmployees[MAXEMPLOYEE];

	int opcion;
	int opcionInformes;
	int retornoFuncion;
	int IdSeleccionado;
	float totalSalarios;
	float promedioSalarios;
	int superanElPromedio;


	initEmployees(listEmployees, MAXEMPLOYEE);

	do
	{
		opcion = printMenu("1. Cargar un empleado\n2. Modificar un empleado\n3. Dar de baja un empleado\n4. Informes\n5. Salir", 5);

		switch(opcion)
		{
		case 1:
			//cargar un nuevo usuario
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
			//modificar empleados
			retornoFuncion = buscarOcupado(listEmployees, MAXEMPLOYEE);
			if(retornoFuncion != -1)
			{
				retornoFuncion = printEmployees(listEmployees, MAXEMPLOYEE);
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
			}
			else
			{
				printf("Aun no hay ningun empleado cargado, no puede ejecutar esta opcion.\n");
			}
			break;
		case 3:
			//eliminacion de empleados
			retornoFuncion = buscarOcupado(listEmployees, MAXEMPLOYEE);
			if(retornoFuncion != -1)
			{
				retornoFuncion = printEmployees(listEmployees, MAXEMPLOYEE);
				IdSeleccionado = askForInt("Ingrese el ID que desea: ");
				retornoFuncion = removeEmployee(listEmployees, MAXEMPLOYEE, IdSeleccionado);
				switch(retornoFuncion)
				{
				case 1:
					printf("Usted ha cancelado la eliminacion del empleado.\n");
					break;
				case 0:
					printf("Usted ha eliminado al empleado correctamente.\n");
					break;
				case -1:
					printf("No hay ningun empleado para eliminar con ese ID.\n");
					break;
				}
			}
			else
			{
				printf("Aun no hay ningun empleado cargado, no puede ejecutar esta opcion.\n");
			}
			break;
		case 4:
			//reportes
			retornoFuncion = buscarOcupado(listEmployees, MAXEMPLOYEE);
			if(retornoFuncion != -1)
			{
				do
				{
					opcionInformes = printMenu("1. Listado de empleados\n2. Informe salarial\n3. Salir de informes", 3);
					switch (opcionInformes)
					{
					case 1:
						retornoFuncion = getInt("Se ordenaran por Apellido y Sector. Ingrese [1] para ascendente y [0] para descendente: ", "Error, parametro no valido. Ingrese [1] para ascendente y [0] para descendente: ", 0,1);
						retornoFuncion = sortEmployees(listEmployees, MAXEMPLOYEE, retornoFuncion);
						break;
					case 2:
						totalSalarios = calcularTotalSalarios(listEmployees, MAXEMPLOYEE);
						printf("El total de los salarios es: %f\n", totalSalarios);
						promedioSalarios = calcularPromedioSalarios(listEmployees, MAXEMPLOYEE);
						printf("El promedio de los salarios es: %f\n", promedioSalarios);
						superanElPromedio = calcularEmpleadosQueSuperanPromedio(listEmployees, MAXEMPLOYEE, promedioSalarios);
						printf("La cantidad de empleados que superan el promedio de salarios es: %d\n", superanElPromedio);
						break;
					}
				}while(opcionInformes != 3);
			}
			else
			{
				printf("Aun no hay ningun empleado cargado, no puede ejecutar esta opcion.\n");
			}
			break;
		case 5:
			printf("\n\n---------------Gracias por utilizar el progama. Hasta la proxima.---------------\n\n");
			break;
		}

	}while (opcion != 5);


	return EXIT_SUCCESS;
}

