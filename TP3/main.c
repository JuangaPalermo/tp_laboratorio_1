#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    LinkedList* listaEmpleados;
    int len;
    int opcionSeleccionada;
    int retornoFuncion;
    int archivoCreado = 0; //0 si no hay archivo creado, 1 si el archivo se creo.

    listaEmpleados = ll_newLinkedList();

    do
    {
    	opcionSeleccionada = printmenu("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n2. Cargar los datos de los empleados desde el archivo data.dat (modo binario)\n3. Dar de alta un empleado\n4. Modificar datos de un empleado\n5. Dar de baja un empleado\n6. Listar a los empleados\n7. Ordenar a los empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n9. Guardar los datos de los empleados en el archivo data.dat (modo binario)\n10. Salir", 10);

    	switch(opcionSeleccionada)
    	{
    		case 1:
    			retornoFuncion =

    	}

    }while(opcionSeleccionada != 10);


    return 0;
}
