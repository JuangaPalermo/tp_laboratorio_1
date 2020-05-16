#include "ArrayEmployees.h"


int initEmployees(Employee list[], int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		list[i].isEmpty = EMPTY;
	}

	return 0;
}

int newEmployee (Employee list[], int len)
{
	int returnValue;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int id;
	int index;

	index = buscarLibre(list, len);

	if (index != -1)
	{

		getString("Ingrese el nombre del empleado: ", name, 51);
		getString("Ingrese el apellido del empleado: ", lastName, 51);
		salary = getFloat("Ingrede el sueldo del empleado: ");
		printf("Ingrese el numero de sector del empleado: ");
		scanf("%d", &sector);
		id = index;

		returnValue = addEmployees(list, len, id, name, lastName, salary, sector);
	}
	else
	{
		returnValue = index;
	}

	return returnValue;
}


int addEmployees(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector)
{
	Employee newEmployee;
	newEmployee.id = generateId();
	strcpy(newEmployee.name, name);
	strcpy(newEmployee.lastName, lastName);
	newEmployee.salary = salary;
	newEmployee.sector = sector;
	newEmployee.isEmpty = NOTEMPTY;

	list[id] = newEmployee;

	printf("El ID asignado es: %d\n", newEmployee.id);

	return 0;
}

int findEmployeeById(Employee list[], int len, int id)
{
	int i;
	int returnValue;

	for (i=0; i<len; i++)
	{
		if(id == list[i].id && list[i].isEmpty == NOTEMPTY)
		{
			returnValue = i;
			break;
		}
		else
		{
			returnValue = -1;
		}
	}

	return returnValue;
}

int modifyEmployee(Employee list[], int len, int id)
{
	int indexFound;
	int returnValue = 1;
	int opcion;
	Employee auxEmployee;

	indexFound = findEmployeeById(list, len, id);

	auxEmployee = list[indexFound];

	if (indexFound != -1)
	{
		do
		{
			opcion = printMenu("1. Modificar nombre\n2. Modificar apellido\n3. Modificar salario\n4. Modificar sector\n5. Previsualizar cambios\n6. Cancelar modificaciones\n7. Guardar cambios\n8. Salir", 8);

			switch(opcion)
			{
			case 1:
				getString("Ingrese nuevo nombre: ", auxEmployee.name, 51);
				break;
			case 2:
				getString("Ingrese nuevo apellido: ", auxEmployee.lastName, 51);
				break;
			case 3:
				auxEmployee.salary = getFloat("Ingrese nuevo salario: ");
				break;
			case 4:
				printf("Ingrese nuevo sector: ");
				scanf("%d", &auxEmployee.sector);
				break;
			case 5:
				printf("Previsualizacion de cambios (1er fila = sin cambios | 2da fila = cambios aplicados):\n");
				printf("%4s | %40s | %40s | %15s | %10s |\n","ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
				printOneEmployee(list[indexFound]);
				printOneEmployee(auxEmployee);
				break;
			case 6:
				printf("Se han cancelado las modificaciones! \n");
				auxEmployee = list[indexFound];
				returnValue = 1;
				break;
			case 7:
				printf("Se han guardado las modificaciones! \n");
				list[indexFound] = auxEmployee;
				returnValue = 0;
				break;
			}

		}while (opcion != 8);

	}
	else
	{
		returnValue = -1;
	}

	return returnValue;

}

int removeEmployee(Employee list [], int len, int id)
{
	int returnValue;
	int indexFound;
	char confirmacion;

	indexFound = findEmployeeById(list, len, id);

	if(indexFound != -1)
	{
		printf("Usted selecciono al empleado %s %s, ID %d\n", list[indexFound].name, list[indexFound].lastName, list[indexFound].id);
		confirmacion = getChar("Desea realmente eliminar al empleado? [s/n]: ", "Error, caracter invalido. Reingrese [s/n]: ", 's', 'n');

		if (confirmacion == 's')
		{
			list[indexFound].isEmpty = EMPTY;
			returnValue = 0;
		}
		else
		{
			returnValue = 1;
		}
	}
	else
	{
		returnValue = -1;
		//printf("No hay ningun empleado para eliminar con ese ID");
	}


	return returnValue;
}

int sortEmployees (Employee list[], int len, int order)
{
	int i;
	int j;
	Employee auxEmployee;
	int listado;

	if (order == 0) //descendente
	{
		for(i=0; i<len-1; i++)
		{
			for(j=i+1; j<len; j++)
			{
				if(strcmp(list[i].lastName, list[j].lastName)<0)
				{
					auxEmployee = list[i];
					list[i] = list [j];
					list[j] = auxEmployee;
				}
				else
				{
					if(strcmp(list[i].lastName, list[j].lastName)==0)
					{
						if(list[i].salary < list[j].salary)
						{
							auxEmployee = list[i];
							list[i] = list [j];
							list[j] = auxEmployee;
						}
					}
				}
			}
		}
	}
	else //ascendente
	{
		for(i=0; i<len-1; i++)
		{
			for(j=i+1; j<len; j++)
			{
				if(strcmp(list[i].lastName, list[j].lastName)>0)
				{
					auxEmployee = list[i];
					list[i] = list [j];
					list[j] = auxEmployee;
				}
				else
				{
					if(strcmp(list[i].lastName, list[j].lastName)==0)
					{
						if(list[i].salary > list[j].salary)
						{
							auxEmployee = list[i];
							list[i] = list [j];
							list[j] = auxEmployee;
						}
					}
				}
			}
		}
	}

	listado = printEmployees(list, len);

	return 0;
}


int printEmployees(Employee list[], int length)
{
	int i;

	printf("%4s | %40s | %40s | %15s | %10s |\n","ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
	for (i=0; i<length; i++)
	{
		if(list[i].isEmpty == NOTEMPTY)
		{
			printf("%4d | %40s | %40s | %15f | %10d |\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
		}
	}
	return 0;
}

void printOneEmployee(Employee unEmpleado)
{
	printf("%4d | %40s | %40s | %15f | %10d |\n", unEmpleado.id, unEmpleado.name, unEmpleado.lastName, unEmpleado.salary, unEmpleado.sector);
}

float calcularTotalSalarios (Employee list[], int len)
{
	float totalSalarios;
	int i;

	totalSalarios = 0;

	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == NOTEMPTY)
		{
			totalSalarios += list[i].salary;
		}
	}


	return totalSalarios;
}

float calcularPromedioSalarios (Employee list[], int len)
{
	float promedioSalarios;
	int contadorEmpleados;
	float acumuladorSalarios;
	int i;

	contadorEmpleados = 0;
	acumuladorSalarios = 0;

	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == NOTEMPTY)
		{
			contadorEmpleados++;
			acumuladorSalarios += list[i].salary;
		}
	}

	promedioSalarios = (float) acumuladorSalarios / contadorEmpleados;

	return promedioSalarios;
}

int calcularEmpleadosQueSuperanPromedio  (Employee list[], int len, float promedioSalarios)
{
	int i;
	int contadorSuperadores;

	contadorSuperadores = 0;

	for (i=0; i<len; i++)
	{
		if (list[i].isEmpty == NOTEMPTY && list[i].salary > promedioSalarios)
		{
			contadorSuperadores++;
		}
	}

	return contadorSuperadores;
}

int buscarLibre(Employee list[], int tam)
{
    int i;
    int index = -1;
    for(i=0; i<tam; i++)
    {
        if(list[i].isEmpty == EMPTY)
        {
            index = i;
            break;
        }
    }
    return index;
}

int buscarOcupado(Employee list[], int tam)
{
	int i;
	int returnValue;

	returnValue = -1;

	for(i=0; i<tam; i++)
	{
		if(list[i].isEmpty == NOTEMPTY)
		{
			returnValue = 0;
			break;
		}
	}

	return returnValue;
}

int generateId(void)
{
	static int generatedId = 0;

	generatedId++;

	return generatedId;
}



