#define MAXEMPLOYEE 1000
#define EMPTY 0
#define NOTEMPTY -1

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
initEmployees(Employee list[], int len);

/* \brief add in a existing list of employees, the values received as parameters in the
 * first empty position
 * */
int addEmployees(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector);
