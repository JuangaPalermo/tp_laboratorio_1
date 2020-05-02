/*brief: pide al usuario que ingrese un entero, lo valida, y lo devuelve
 *
 *param char mensaje[]: Mensaje al usuario pidiendole el int
 *param char error[]: Mensaje de error si el int no cumple los criterios de max/min
 *param int min: Valor minimo permitido a ingresar
 *param int max: Valor maximo permitido a ingresar
 *
 *return: int ingresado por el usuario y validado por la funcion
 */
int getInt (char mensaje[], char error[], int min, int max);

/*brief: recibe dos numeros y devuelve el promedio entre ambos
 *
 *param int primervalor: primer numero a sumar para calcular el promedio
 *param int segundovalor: segundo numero a sumar para calcular el promedio
 *
 *return: float obtenido de dividir la suma de los dos numeros
 */
float getFloat(int primerValor, int segundoValor);

/*brief: pide un string y lo carga en la direccion indicada
 *
 *param char mensaje[]: Mensaje al usuario pidiendole el string
 *param char texto[]: Direccion donde se carga el string ingresado por el usuario
 *param int largo: Largo maximo permitido por el string
 *
 */
void getString (char mensaje[], char texto[], int largo);

/*brief: Recibe un array y lo recorre
 *
 *param Employee listado[]: array a recorrer
 *param int tam: tamaño del array a recorrer
 *
 *return int: si encuentra un elemento vacio, devuelve el indice. Si no, devuelve -1.
 */
int buscarLibre(Employee listado[], int tam);

