#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include "UserInteractions.h"


#define EMPTY 1
#define NOTEMPTY 0

typedef struct
{

	int id;
	char name [51];
	char lastName [51];
	float salary;
	int sector;
	int isEmpty;

}Employee;


/*brief To indicate that all position in the array are empty. this function
 * 		put the flag (isEmpty) in TRUE in all position of the array.
 *
 * \param Employee list[] = array of employees to initialize
 * \param int len = length of the array of employees
 */
int initEmployees(Employee list[], int len);

/*brief le pide al usuario cada uno de los datos que componen a un dato de tipo Employee
 * 		en caso de que encuentre un espacio libre en el array. Devuelve (index) si OK, o (-1) si
 * 		no hay espacio
 * \param Employee list[] = array of employees to initialize
 * \param int len = length of the array of employees
 *
 *return: retorna el indice encontrado, o -1 si no lo encuentra
 */
int newEmployee (Employee list[], int len);

/* \brief add in a existing list of employees, the values received as parameters in the
 * first empty position
 *
 * return Return employee index position or -1 if not found.
 * */
int addEmployees(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector);


/* \brief find an Employee by Id, and returns the index position in array
 *
 * \param Employee list[]: array to traverse
 * \param int len: size of the array
 * \param int id: id to search
 *
 * return Return employee index position or -1 if not found.
 * */
int findEmployeeById(Employee list[], int len, int id);

/* \brief permite al usuario modificar todos los datos de un empleado manualmente (salvo
 * 		  el ID y el campo isEmpty) y aplicarlos
 *
 * return (1)si no se guardaron las modificaciones, (0) si se guardaron las modificaciones
 * 		   o (-1) si no hay ningun empleado con el ID declarado por el usuario
 * */

int modifyEmployee(Employee list[], int len, int id);


/* \brief Remove a Employee by Id (put isEmpty Flag in EMPTY)
 *
 * \param Employee list[]: array to traverse
 * \param int len: size of the array
 * \param int id: id to search
 *
 * return Return (-1) if error or (0) if OK
 * */
int removeEmployee(Employee list [], int len, int id);


/* \brief Sort the elements in the array of employees, the argument order
 * indicates UP or DOWN
 *
 * \param Employee list[]: array to traverse
 * \param int len: size of the array
 * \param int order: [1] indicate UP - [0] indicate DOWN
 *
 * return int: return (-1) if error or  (0) or OK
 * */
int sortEmployees (Employee list[], int len, int order);


/* \brief print the content of employees array
 *
 * \param Employee list[]: array to traverse
 * \param int length: size of the array
 *
 * return int
 * */
int printEmployees(Employee list[], int length);


/* \brief print the content of one employee
 *
 * \param Employee unEmpleado: Employee to print
 *
 * */
void printOneEmployee(Employee unEmpleado);


/*brief recorre todo el array de empleados sumando sus campo salary, y luego retorna
 * 		esa suma
 *
 * \param Employee list[]: array to traverse
 * \param int length: size of the array
 *
 * return suma de todos los salarios de los empleados
 * */
float calcularTotalSalarios (Employee list[], int len);


/*brief suma todos los salarios de los empleados, y luego saca el promedio entre todos
 *
 * \param Employee list[]: array to traverse
 * \param int length: size of the array
 *
 * return el promedio entre todos los salarios
 * */
float calcularPromedioSalarios (Employee list[], int len);


/*brief recorre todos los empleados, y almacena en un contador cuantos superan el promedio
 *
 * \param Employee list[]: array to traverse
 * \param int length: size of the array
 * \param float promedioSalarios: promedio de los salarios de los empleados (calculado con la
 * 		  funcion promedioSalarios)
 *
 * return cantidad de empleados que superan el promedio de salarios.
 * */
int calcularEmpleadosQueSuperanPromedio  (Employee list[], int len, float promedioSalarios);


/*brief: Recibe un array y lo recorre
 *
 *param Employee list[]: array a recorrer
 *param int tam: tamaño del array a recorrer
 *
 *return int: si encuentra un elemento vacio, devuelve el indice. Si no, devuelve -1.
 */
int buscarLibre(Employee list[], int tam);


/*brief: Recibe un array y lo recorre
 *
 *param Employee list[]: array a recorrer
 *param int tam: tamaño del array a recorrer
 *
 *return int: si encuentra un elemento ocupado, devuelve (0). Si no, devuelve -1.
 */
int buscarOcupado(Employee list[], int tam);


/* \brief generador de ID ascendente, empezando desde 1
 *
 * return int: el id generado
 * */
int generateId(void);
