#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/*Crea en memoria dinamica espacio para una variable de tipo Employee
 *return: la direccion de memoria dinamica*/
Employee* employee_new();

/*Constructor por parametros para Employee (recibe todos los parametros en formato tipo char*, despues convierte)
 *param idStr: ID empleado
 *param nombreStr: nombre empleado
 *param horasTrabajadasStr: horas empleado
 *param sueldoStr: sueldo empleado
 *return: Employee**/
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/*Elimina el empleado que le paso como parametro
 *esta funcion se encontraba vacia, se le cambian los parametros para su utilizacion.
 */
void employee_delete(Employee* this);

/*Setter ID
 *param this: puntero del empleado
 *param id: ID a asignar
 *return: (0) error o (1) OK.*/
int employee_setId(Employee* this,int id);
/*Getter ID
 *param this: puntero del empleado
 *param id: puntero del ID
 *return: (0) error o (1) OK.*/
int employee_getId(Employee* this,int* id);

/*Setter nombre
 *param this: puntero del empleado
 *param nombre: nombre a asignar
 *return: (0) error o (1) OK.*/
int employee_setNombre(Employee* this,char* nombre);
/*Getter nombre
 *param this: puntero del empleado
 *param nombre: puntero del nombre
 *return: (0) error o (1) OK.*/
int employee_getNombre(Employee* this,char* nombre);

/*Setter horasTrabajadas
 *param this: puntero del empleado
 *param horasTrabajadas: horasTrabajadas a asignar
 *return: (0) error o (1) OK.*/
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/*Getter horasTrabajadas
 *param this: puntero del empleado
 *param horasTrabajadas: puntero del horasTrabajadas
 *return: (0) error o (1) OK.*/
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/*Setter sueldo
 *param this: puntero del empleado
 *param sueldo: sueldo a asignar
 *return: (0) error o (1) OK.*/
int employee_setSueldo(Employee* this,int sueldo);
/*Getter sueldo
 *param this: puntero del empleado
 *param sueldo: puntero del sueldo
 *return: (0) error o (1) OK.*/
int employee_getSueldo(Employee* this,int* sueldo);

/*Esta firma es igual a la de LL sort. Aca tengo que agregar los criterios de ordenamiento*/
int employee_CompareByName(Employee* e1, Employee* e2);
int employee_CompareById(Employee* e1, Employee* e2);
int employee_CompareByHoras(Employee* e1, Employee* e2);
int employee_CompareBySueldo(Employee* e1, Employee* e2);

#endif // employee_H_INCLUDED
