#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"



int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
	int returnValue = 0;

	FILE* pArchivo;

	pArchivo = fopen(path, "r");

	if(pArrayListEmployee != NULL && pArchivo != NULL)
	{
		parser_EmployeeFromText(pArchivo, pArrayListEmployee);
		fclose(pArchivo);
		returnValue = 1;
	}

	return returnValue;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
	int returnValue = 0;

	FILE* pArchivo;

	pArchivo = fopen(path, "rb");

	if(pArrayListEmployee != NULL && pArchivo != NULL)
	{
		parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
		fclose(pArchivo);
		returnValue = 1;
	}

	return returnValue;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int returnValue = 0;

	int id;
	char nombre[128];
	int sueldo;
	int horasTrabajadas;

	Employee* auxEmployee;

	auxEmployee = employee_new();

	if(pArrayListEmployee != NULL && auxEmployee != NULL)
	{
		id = generateId();
		getString("Nombre del empleado: ", nombre, 128);
		sueldo = getInt("Sueldo del empleado: ", "El sueldo no puede ser negativo, reingrese: ", 0);
		horasTrabajadas = getInt("Horas del empleado: ", "Las horas no pueden ser negativas, reingrese: ", 0);

		employee_setId(auxEmployee, id);
		employee_setNombre(auxEmployee, nombre);
		employee_setSueldo(auxEmployee, sueldo);
		employee_setHorasTrabajadas(auxEmployee, horasTrabajadas);

		ll_add(pArrayListEmployee, auxEmployee);

		returnValue = 1;
	}


	return returnValue;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int returnValue = 0;
	Employee* selectedEmployee;
	int opcionSeleccionada;
	int i;
	int r;
	int idSeleccionado;
	char confirmacion;

	if(pArrayListEmployee != NULL)
	{
		r = controller_listEmployee(pArrayListEmployee);
		idSeleccionado = getInt("Ingrese el ID que desea seleccionar: ", "Los ID no pueden ser menores que 0, reingrese: ", 0);

		for(i=0; i<ll_len(pArrayListEmployee); i++)
		{
			selectedEmployee = ll_get(pArrayListEmployee, i);

			if(idSeleccionado == selectedEmployee->id)
			{
				do
				{
					opcionSeleccionada = printMenu("1. Modificar nombre\n2. Modificar horas\n3. Modificar sueldo\n4. Guardar cambios y salir\n5. Cancelar cambios y salir.", 5);

					switch(opcionSeleccionada)
					{
					case 1:
						getString("Ingrese el nuevo nombre: ", selectedEmployee->nombre, 128);
						break;
					case 2:
						selectedEmployee->horasTrabajadas = getInt("Ingrese la nueva cantidad de horas: ", "Error, las horas no pueden ser negativas. Reingrese: ", 0);
						break;
					case 3:
						selectedEmployee->sueldo = getInt("Ingrese el nuevo sueldo: ", "Error, el sueldo no puede ser negativo. Reingrese: ", 0);
						break;
					case 4:
						confirmacion = getChar("Si guarda los cambios, no podra revertirlo. Esta seguro? [s/n]: ", "Error, el caracter ingresado es invalido. Reingrese [s/n]: ", 's', 'n');
						if(confirmacion == 's')
						{
							ll_set(pArrayListEmployee, i, selectedEmployee);
							returnValue = 1;
						}
						else
						{
							printf("Cambios no guardados, puede seguir haciendo modificaciones.\n");
						}
						break;
					case 5:
						confirmacion = getChar("Si cancela los cambios, no se aplicaran los que esten sin guardar. Esta seguro? [s/n]", "Error, el caracter ingresado es invalido. Reingrese [s/n]: ", 's', 'n');
						if (confirmacion == 's')
						{
							returnValue = -1;
						}
					}

				}while(opcionSeleccionada != 4 || opcionSeleccionada != 5);

				break;
			}
		}
	}



return returnValue;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
return 1;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{

return 1;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
return 1;
}

