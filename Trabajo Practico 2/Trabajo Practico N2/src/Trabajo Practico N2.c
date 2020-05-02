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
		printf ("4. Listar empleados");
		printf ("5. Salir");
		scanf ("%d", opcion);

		switch (opcion)
		{
		case 1:
			//retornoFuncion = addEmployees()
		}

	}while (opcion != 5);
	//necesito un menu con: Alta, Baja, Modif, Listar


	return EXIT_SUCCESS;
}
