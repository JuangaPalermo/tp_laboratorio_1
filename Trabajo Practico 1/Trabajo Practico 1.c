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
#include "micalculadora.h"


int main(void) {

	int opcionElegida;
	float numero1 = 0;
	float numero2 = 0;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	long long int resultadoFactorialPrimero;
	long long int resultadoFactorialSegundo;


	do
	{
	    opcionElegida = menu(numero1, numero2);

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
    			resultadoFactorialPrimero = factorial(numero1);
    			resultadoFactorialSegundo = factorial(numero2);
    			printf("\nSe han calculado todas las operaciones!\n");
    			break;
    		}
    		case 4:
    		{
    			printf("\nEl resultado de %g mas %g es: %g\n", numero1, numero2, resultadoSuma);
    			printf("El resultado de %g menos %g es: %g\n", numero1, numero2, resultadoResta);
    			printf("El resultado de %g por %g es: %g\n", numero1, numero2, resultadoMultiplicacion);

    			if (resultadoDivision == 0)
    			{
    				printf("No se puede dividir por cero!\n");
    			}
    			else
    			{
    				printf("El resultado de %g dividido %g es: %g\n", numero1, numero2, resultadoDivision);
    			}

    			if (resultadoFactorialPrimero == 0)
    			{
    				printf("No se puede calcular el factorial de los decimales!\n");
    			}
    			else
    			{
    			    if (resultadoFactorialPrimero == -1)
    			    {
    			        printf("No se puede calcular el factorial de los negativos!\n");
    			    }
    			    else
    			    {
    			    	if(resultadoFactorialPrimero == -2)
    			    	{
    			    		printf("El numero %g es muy grande para calcular el factorial en esta aplicacion.\n", numero1);
    			    	}
    			    	else
    			    	{
    			    		printf("El factorial de %g es: %llu\n", numero1, resultadoFactorialPrimero);
    			    	}

    			    }

    			}

    			if (resultadoFactorialSegundo == 0)
				{
					printf("No se puede calcular el factorial de los decimales!\n");
				}
				else
				{
				    if (resultadoFactorialSegundo == -1)
				    {
				        printf("No se puede calcular el factorial de los negativos!\n");
				    }
				    else
					{
						if(resultadoFactorialSegundo == -2)
						{
							printf("El numero %g es muy grande para calcular el factorial en esta aplicacion.\n", numero2);
						}
						else
						{
							printf("El factorial de %g es: %llu\n", numero2, resultadoFactorialSegundo);
						}

					}
				}
    			break;
    		}
    		case 5:
    		{
    			printf("\nMuchas gracias por usar este programa!");
    			break;
    		}
    	}

	} while (opcionElegida != 5);

	return EXIT_SUCCESS;
}



