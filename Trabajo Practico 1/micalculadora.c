#include "micalculadora.h"
#include <stdio.h>

int menu (float numero1, float numero2)
{
	int opcion;

	printf("\n1. Ingresar primer operando, (actualmente A = %g):\n", numero1);
	printf("2. Ingresar segundo operando, (actualmente B = %g):\n", numero2);
	printf("3. Calcular operaciones (suma, resta, producto, division y factorial)\n");
	printf("4. Informar resultados de las operaciones\n");
	printf("5. Salir\n");
	printf("Seleccione la opcion que desee: ");
	scanf("%d", &opcion);

	while (opcion > 5)
	{
		printf("\nLa opcion que selecciono no es valida, ingrese un numero de opcion del menu: ");
		scanf("%d", &opcion);
	}

	return opcion;
}

float solicitudNumero (void)
{
	float numero;

	printf("\nIngrese el numero que desea: ");
	scanf("%f", &numero);

	return numero;
}

float suma (float primerNumero, float segundoNumero)
{
	float resultadoSuma;

	resultadoSuma = primerNumero + segundoNumero;

	return resultadoSuma;
}

float resta (float primerNumero, float segundoNumero)
{
	float resultadoResta;

	resultadoResta = primerNumero - segundoNumero;

	return resultadoResta;
}

float multiplicacion (float primerNumero, float segundoNumero)
{
	float resultadoMultiplicacion;

	resultadoMultiplicacion = primerNumero * segundoNumero;

	return resultadoMultiplicacion;
}

float division (float primerNumero, float segundoNumero)
{
	float resultadoDivision;

	if (segundoNumero == 0)
	{
		resultadoDivision = 0;
	}
	else
	{
		resultadoDivision = primerNumero / segundoNumero;
	}

	return resultadoDivision;
}

long long int factorial (float numero)
{
	long long int resultadoFactorial;

	int numeroEntero = (int) numero;

	if (numero - numeroEntero)
	{
		resultadoFactorial = 0;
		return resultadoFactorial;
	}
	else
	{
	    if (numero < 0)
	    {
	        resultadoFactorial = -1;
	        return resultadoFactorial;
	    }
	    else
	    {
	    	if (numero > 20)
	    	{
	    		resultadoFactorial = -2;
	    	}
	    	else
	    	{
	    		resultadoFactorial = 1;

				for (numero; numero > 1; numero--)
					{
						resultadoFactorial *= numero;
					}
	    	}

    		return resultadoFactorial;
	    }
	}
}
