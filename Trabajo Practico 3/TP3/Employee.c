#include <stdlib.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{
	Employee* auxEmployee;

	auxEmployee = (Employee*)malloc(sizeof(Employee));

	return auxEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* auxEmpleado;

	auxEmpleado = employee_new();

	if(auxEmpleado != NULL)
	{
		employee_setId(auxEmpleado, atoi(idStr));
		employee_setNombre(auxEmpleado, nombreStr);
		employee_setHorasTrabajadas(auxEmpleado, atoi(horasTrabajadasStr));
		employee_setSueldo(auxEmpleado, atoi(sueldoStr));
	}

	return auxEmpleado;
}

void employee_delete(Employee* this)
{
	free(this);
}

int employee_setNombre(Employee* this,char* nombre)
{
	int returnValue = 0;
	int i;

	if(this!=NULL)
	{
		strlwr(nombre);
		for(i=0; i<strlen(nombre); i++)
		{
			if(i == 0 || nombre[i-1] == ' ')
			{
				toupper(nombre[i]);
			}
		}
		strcpy(this->nombre, nombre);
		returnValue = 1;
	}

	return returnValue;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int returnValue = 0;

	if(this != NULL)
	{
		strcpy(nombre, this->nombre);
		returnValue = 1;
	}

	return returnValue;
}


int employee_setSueldo(Employee* this,int sueldo)
{
	int returnValue = 0;

	if(this != NULL)
	{
		this->sueldo = sueldo;
		returnValue = 1;
	}

	return returnValue;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int returnValue = 0;

	if(this != NULL)
	{
		*sueldo = this->sueldo;
		returnValue = 1;
	}

	return returnValue;

}


int employee_setId(Employee* this,int id)
{
	int returnValue = 0;

	if(this != NULL)
	{
		this->id = id;
		returnValue = 1;
	}

	return returnValue;
}
int employee_getId(Employee* this,int* id)
{
	int returnValue = 0;

	if(this != NULL)
	{
		*id = this->id;
		returnValue = 1;
	}

	return returnValue;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int returnValue = 0;

	if(this != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		returnValue = 1;
	}

	return returnValue;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int returnValue = 0;

	if(this != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		returnValue = 1;
	}

	return returnValue;
}


int employee_CompareByName(void* e1, void* e2)
{
	Employee* auxE1;
	Employee* auxE2;

    //verificar nulidad
	if (e1 != NULL && e2 != NULL)
	{
		auxE1 = (Employee*) e1;
		auxE2 = (Employee*) e2;
	}

    return strcmp(auxE1->nombre, auxE2->nombre);
}

int employee_CompareById(void* e1, void* e2)
{
    int returnValue;
    Employee* auxE1;
    Employee* auxE2;

	//verificar nulidad
    if(e1 != NULL && e2 != NULL)
    {
    	auxE1 = (Employee*) e1;
    	auxE2 = (Employee*) e2;

    	if(auxE1->id > auxE2->id)
		{
			returnValue = 1;
		}
		else
		{
			if(auxE1->id < auxE2->id)
			{
				returnValue = -1;
			}
			else
			{
				returnValue = 0;
			}
		}
    }

    return returnValue;
}

int employee_CompareByHoras(void* e1, void* e2)
{
	int returnValue;
	Employee* auxE1;
	Employee* auxE2;

	//verificar nulidad
	if(e1 != NULL && e2 != NULL)
	{
		auxE1 = (Employee*) e1;
		auxE2 = (Employee*) e2;

		if(auxE1->horasTrabajadas > auxE2->horasTrabajadas)
		{
			returnValue = 1;
		}
		else
		{
			if(auxE1->horasTrabajadas < auxE2->horasTrabajadas)
			{
				returnValue = -1;
			}
			else
			{
				returnValue = 0;
			}
		}
	}

		return returnValue;
}

int employee_CompareBySueldo(void* e1, void* e2)
{
	int returnValue;
	Employee* auxE1;
	Employee* auxE2;

	//verificar nulidad
	if(e1 != NULL && e2 != NULL)
	{
		auxE1 = (Employee*) e1;
		auxE2 = (Employee*) e2;

		if(auxE1->sueldo > auxE2->sueldo)
		{
			returnValue = 1;
		}
		else
		{
			if(auxE1->sueldo < auxE2->sueldo)
			{
				returnValue = -1;
			}
			else
			{
				returnValue = 0;
			}
		}
	}

	return returnValue;
}


