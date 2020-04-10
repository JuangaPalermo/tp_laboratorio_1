/* Brief: Funcion menu, que pide un numero de las opciones y lo devuleve al main
 *
 * return: Int - Validado entre las opciones impresas.
 */

int menu (void);


/* Brief: Solicita un numero al usuario
 *
 * return: float - El numero ingresado por el usuario
 */

float solicitudNumero (void);


/* Brief: Suma los dos numeros ingresados como parametros
 *
 * param: float - Recibe el primer numero ingresado por el usuario
 *
 * param: float - Recibe el segundo numero ingresado por el usuario
 *
 * return: float - La suma de ambos numeros
 */

float suma (float primerNumero, float segundoNumero);

/* Brief: Resta los dos numeros ingresados como parametros
 *
 * param: float - Recibe el primer numero ingresado por el usuario
 *
 * param: float - Recibe el segundo numero ingresado por el usuario
 *
 * return: float - La resta de ambos numeros
 */

float resta (float primerNumero, float segundoNumero);


/* Brief: Multiplica los dos numeros ingresados como parametros
 *
 * param: float - Recibe el primer numero ingresado por el usuario
 *
 * param: float - Recibe el segundo numero ingresado por el usuario
 *
 * return: float - La multiplicacion de ambos numeros
 */

float multiplicacion (float primerNumero, float segundoNumero);

/* Brief: Divide los dos numeros ingresados como parametros. Valida que el valor del divisor
 *
 * param: float - Recibe el primer numero ingresado por el usuario
 *
 * param: float - Recibe el segundo numero ingresado por el usuario
 *
 * return: float - La division de ambos numeros, o si el divisor es cero, devuelve 0.
 */

float division (float primerNumero, float segundoNumero);


/* Brief: Calcula el factorial del numero ingresado por el usuario, valida que no sea ni cero ni negativo.
 *
 * param: float - Recibe el primer numero ingresado por el usuario
 *
 * return: float - El factorial del numero ingresado. Si es negativo devuelve -1. Si es decimal devuelve 0.
 */

long long int factorial (float numero);

