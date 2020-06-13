#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "UserInteractions.h"



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
	int r;

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


int controller_editEmployee(LinkedList* pArrayListEmployee) //0 no existe, 1 guarda, -1 cancela
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
		r = controller_ListEmployee(pArrayListEmployee);
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


int controller_removeEmployee(LinkedList* pArrayListEmployee) //0 no existe, 1 confirma, -1 cancela
{
	int returnValue = 0;

	int i;
	int r;
	int idSeleccionado;
	Employee* selectedEmployee;
	char confirmacion;

	if(pArrayListEmployee != NULL)
	{
		r = controller_ListEmployee(pArrayListEmployee);
		idSeleccionado = getInt("Ingrese el ID que desea seleccionar: ", "Los ID no pueden ser menores que 0, reingrese: ", 0);

		for(i=0; i<ll_len(pArrayListEmployee); i++)
		{
			selectedEmployee = ll_get(pArrayListEmployee, i);

			if(idSeleccionado == selectedEmployee->id)
			{
				confirmacion = getChar("Usted eliminara al empleado seleccionado. Esta seguro? [s/n]: ", "Error, caracter ingresado no valido. Reingrese [s/n]: ", 's', 'n');

				if(confirmacion == 's')
				{
					ll_remove(pArrayListEmployee, i);
					returnValue = 1;
				}
				else
				{
					returnValue = -1;
				}
			}
		}
	}
return returnValue;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int returnValue = 0;
	int i;
	int cont = 0;
	Employee* auxEmployee;
	int id;
	char nombre[128];
	int sueldo;
	int horasTrabajadas;

	if(pArrayListEmployee != NULL)
	{
		printf("| %20s | %128s | %20s | %20s |\n", "ID", "NOMBRE COMPLETO", "HORAS", "SUELDO");
		for(i=0; i<ll_len(pArrayListEmployee); i++)
		{
			auxEmployee = ll_get(pArrayListEmployee, i);
			employee_getId(auxEmployee, &id);
			employee_getNombre(auxEmployee, nombre);
			employee_getHorasTrabajadas(auxEmployee, &horasTrabajadas);
			employee_getSueldo(auxEmployee, &sueldo);

			printf("| %20d | %128s | %20d | %20d |\n", id, nombre, horasTrabajadas, sueldo);

			cont++;

			if(cont%200 == 0)
			{
				system("pause");
			}
		}

		returnValue = 1;
	}

return returnValue;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int opcionSeleccionada;
	int ordenSeleccionado;
	int returnValue = 0;

	if(pArrayListEmployee != NULL)
	{
		opcionSeleccionada = printMenu("1. Ordenar por ID\n2. Ordenar por nombre\n3. Ordenar por horas\n4. Ordenar por sueldo", 4);
		ordenSeleccionado = intBetweenTwo("Ingrese el orden deseado, [0] descendente o [1] ascendente: ", "Error, opcion invalida, reingrese [0] descendente o [1] ascendente: ", 0, 1);

		switch(opcionSeleccionada)
		{
		case 1:
			ll_sort(pArrayListEmployee, employee_CompareById, ordenSeleccionado);
			break;
		case 2:
			ll_sort(pArrayListEmployee, employee_CompareByName, ordenSeleccionado);
			break;
		case 3:
			ll_sort(pArrayListEmployee, employee_CompareByHoras, ordenSeleccionado);
			break;
		case 4:
			ll_sort(pArrayListEmployee, employee_CompareBySueldo, ordenSeleccionado);
			break;
		}

		returnValue = 1;
	}
	return returnValue;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
	int returnValue = 0;

	FILE* pArchivo;
	Employee* auxEmployee;
	int i;
	int id;
	char nombre[128];
	int sueldo;
	int horasTrabajadas;

	pArchivo = fopen(path, "w");

	if(pArrayListEmployee != NULL && pArchivo != NULL)
	{
		fprintf(pArchivo, "id,nombre,horas,sueldo\n");

		for(i=0; i<ll_len(pArrayListEmployee); i++)
		{
			auxEmployee = ll_get(pArrayListEmployee, i);

			employee_getId(auxEmployee, &id);
			employee_getNombre(auxEmployee, nombre);
			employee_getHorasTrabajadas(auxEmployee, &horasTrabajadas);
			employee_getSueldo(auxEmployee, &sueldo);

			fprintf(pArchivo, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
		}

		fclose(pArchivo);
		returnValue = 1;
	}
return returnValue;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
	int returnValue = 0;
	FILE* pArchivo;
	Employee* auxEmployee;
	int i;

	pArchivo = fopen(path, "wb");

	if(pArrayListEmployee != NULL && pArchivo != NULL)
	{
		for (i=0; i<ll_len(pArrayListEmployee); i++)
		{
			auxEmployee = ll_get(pArrayListEmployee, i);

			fwrite(auxEmployee, sizeof(Employee), 1, pArchivo);
		}
		fclose(pArchivo);
		returnValue = 1;
	}


return returnValue;
}

