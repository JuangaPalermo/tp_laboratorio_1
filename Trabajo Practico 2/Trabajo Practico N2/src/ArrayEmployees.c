#include "ArrayEmployees.h"

initEmployees(Employee list[], int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		list[i].isEmpty = EMPTY;
	}
}

Employee newEmployee (void)
{
	Employee newEmployee;

	//crear funcion generate ID
	getString("Ingrese el nombre del empleado: ", newEmployee.name, 51);
	getString("Ingrese el apellido del empleado: ", newEmployee.lastName, 51);
	printf("Ingrese el sueldo del empleado: ");
	scanf("%f", &newEmployee.salary);
	printf("Ingrese el numero de sector del empleado: ");
	scanf("%d", &newEmployee.sector);
	newEmployee.isEmpty = NOTEMPTY;

	return newEmployee;
}


int addEmployees(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector)
{
	int returnValue;
	int freeSpace;
	Employee newEmployee;

	freeSpace = buscarLibre(list, len);

	if(freeSpace!=-1)
	{


		list[freeSpace] = newEmployee;

		returnValue = 0;
	}
	else
	{
		returnValue = -1;
	}

	return returnValue;
}
