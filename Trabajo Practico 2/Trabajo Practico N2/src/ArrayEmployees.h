#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include "getDatos.h"

#define MAXEMPLOYEE 2
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

/* \brief add in a existing list of employees, the values received as parameters in the
 * first empty position
 * */
int addEmployees(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector);

int newEmployee (Employee list[], int len);

/* \brief find an Employee by Id, and returns the index position in array
 *
 * \param Employee list[]: array to traverse
 * \param int len: size of the array
 * \param int id: id to search
 *
 * return Return employee index position or -1 if not found.
 * */
int findEmployeeById(Employee list[], int len, int id);

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
 * return int: return (-1) uf error or  (0) or OK
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

/*brief: Recibe un array y lo recorre
 *
 *param Employee list[]: array a recorrer
 *param int tam: tamaño del array a recorrer
 *
 *return int: si encuentra un elemento vacio, devuelve el indice. Si no, devuelve -1.
 */
int buscarLibre(Employee list[], int tam);

/* \brief generador de ID ascendente, empezando desde 1
 *
 * return int: el id generado
 * */
int generateId(void);

/*/brief imprime un menu ingresado por el usuario y devuelve la opcion seleccionada
 *
 * param char opciones[]: lista de opciones
 *
 * return Retorna opcion seleccionada o -1 si error
 * */
int printMenu (char opciones []);

int askForInt (char texto []);

