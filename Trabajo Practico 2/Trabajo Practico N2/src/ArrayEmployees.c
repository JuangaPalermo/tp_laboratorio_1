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
		printf("Ingrese el sueldo del empleado: ");
		scanf("%f", &salary);
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
	//crear funcion generate ID, porque si lo dejo asi, si da de baja un usuario le va a
	//asignar el mismo id que tenia una persona antes
	newEmployee.id = generateId();
	strcpy(newEmployee.name, name);
	strcpy(newEmployee.lastName, lastName);
	newEmployee.salary = salary;
	newEmployee.sector = sector;

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
		if(id == list[i].id)
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

int removeEmployee(Employee list [], int len, int id)
{
	int i;
	int returnValue;
	int indexFound;

	indexFound = findEmployeeById(list, len, id);

	if(indexFound != -1 && list[indexFound].isEmpty == NOTEMPTY && id == list[indexFound].id)
	{
		list[indexFound].isEmpty == EMPTY;
		returnValue = 0;
	}
	else
	{
		returnValue = -1;
		//printf("No hay ningun empleado para eliminar con ese ID");
	}


	return returnValue;
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

int generateId(void)
{
	static int generatedId = 0;

	generatedId++;

	return generatedId;
}