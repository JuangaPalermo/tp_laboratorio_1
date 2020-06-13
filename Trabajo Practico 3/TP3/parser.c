#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int returnValue = 0;

    char id[20];
    char nombre[128];
    char horasTrabajadas[20];
    char sueldo[20];
    Employee* auxEmployee;
    int r;

    if(pArrayListEmployee != NULL && pFile != NULL)
    {
    	r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo); //lectura vacia por encabezados mokaroo.

    	do
    	{
    		r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);

    		if(r == 4)
    		{
    			auxEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
    			ll_add(pArrayListEmployee, auxEmployee);
    		}

    	}while(!feof(pFile));

    	returnValue = 1;
    }

	return returnValue;

}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int returnValue = 0;

	char id[20];
	char nombre[128];
	char horasTrabajadas[20];
	char sueldo[20];
	int tam;
	int r;
	int i;
	Employee auxEmployee;
	Employee* pEmployee;

	if(pArrayListEmployee != NULL && pFile != NULL)
	{
		tam = fread(&tam, sizeof(int), 1, pFile);

		for(i=0; i<tam; i++)
		{
			r = fread(&auxEmployee, sizeof(Employee), 1, pFile);

			if(r == 1)
			{
				sprintf(id, "%d", auxEmployee.id);
				sprintf(horasTrabajadas, "%d", auxEmployee.horasTrabajadas);
				sprintf(sueldo, "%d", auxEmployee.sueldo);
				strcpy(nombre, auxEmployee.nombre);

				pEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

				ll_add(pArrayListEmployee, pEmployee);
			}
		}

		returnValue = 1;
	}

    return returnValue;
}
