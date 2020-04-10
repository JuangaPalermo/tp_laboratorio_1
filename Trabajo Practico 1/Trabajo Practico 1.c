/*TRABAJO PRACTICO 1
 *
 * Consigna: Hacer una calculadora. Para ello, el programa iniciara y contara con un menu
 * de opciones:
 * 1. Ingresar el 1er operando (A=x)
 * 2. Ingresar el 2do operando (B=y)
 * 3. Calcular TODAS las operaciones
 * 		a) Suma de A+B
 * 		b) Resta de A-B
 * 		c) Division de A/B
 * 		d) Multiplicacion de A*B
 * 		e) Factorial de A y de B (validar si es decimal o negativo, en ese caso no se puede)
 * 4. Informar resultados:
 * 		a) "El resultado de A+B es: r"
 * 		b) "El resultado de A-B es: r"
 * 		c) "El resultado de A/B es: r" o "No es posible dividir por cero"
 * 		d) "El resultado de A*B es: r"
 * 		e) "El factorial de A es: r1 y el factorial de B es: r2"
 * 5. Salir
 *
 * ACLARACIONES:
 *
 * Todas las funciones matematicas del menu se deberan realizar en una bilioteca aparte, que
 * contenga las funciones para realizar las 5 operaciones.
 *
 * En el menu, deberan aparecer los valores actuales cargados en los operandos A y B (donde
 * dice "x" e "y" en el ejemplo, se debe mostrar el numero cargado)
 *
 * Deberan contemplarse los casos de error
 *
 * Documentar todas las funciones
 */

#include <stdio.h>
#include <stdlib.h>

int menu (void);
float solicitudNumero (void);
float suma (float primerNumero, float segundoNumero);
float resta (float primerNumero, float segundoNumero);
float multiplicacion (float primerNumero, float segundoNumero);
float division (float primerNumero, float segundoNumero);



int main(void) {

	int opcionElegida;
	float numero1;
	float numero2;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;


	do
	{
	    opcionElegida = menu();

    	switch (opcionElegida)
    	{
    		case 1:
    		{
    			numero1 = solicitudNumero();
    			break;
    		}
    		case 2:
    		{
    			numero2 = solicitudNumero();
    			break;
    		}
    		case 3:
    		{
    			resultadoSuma = suma(numero1, numero2);
    			resultadoResta = resta(numero1, numero2);
    			resultadoMultiplicacion = multiplicacion(numero1, numero2);
    			resultadoDivision = division(numero1, numero2);
    			//resultadoFactorialPrimero = factorial(numero1);
    			//resultadoFactorialSegundo = factorial(numero2);
    			break;
    		}
    		case 4:
    		{
    			printf("\nEl resultado de %f mas %f es: %f\n", numero1, numero2, resultadoSuma);
    			printf("El resultado de %f menos %f es: %f\n", numero1, numero2, resultadoResta);
    			printf("El resultado de %f por %f es: %f\n", numero1, numero2, resultadoMultiplicacion);
    			printf("El resultado de %f dividido %f es: %f\n", numero1, numero2, resultadoDivision);
    			break;
    		}
    		case 5:
    			printf("\nMuchas gracias por usar este programa!");
    			break;
    	}
	} while (opcionElegida != 5);

	return EXIT_SUCCESS;
}

int menu (void)
{
	int opcion;

	printf("1. Ingresar primer operando\n");
	printf("2. Ingresar segundo operando\n");
	printf("3. Calcular operaciones (suma, resta, producto, division y factorial)\n");
	printf("4. Informar resultados de las operaciones\n");
	printf("5. Salir\n");
	printf("Seleccione la opcion que desee: ");
	scanf("%d", &opcion);

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

	while (segundoNumero == 0){
		printf("El divisor no puede ser 0, por favor, reingrese un numero: ");
		scanf("%f", &segundoNumero);
	}

	resultadoDivision = primerNumero / segundoNumero;

	return resultadoDivision;
}

