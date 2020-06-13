/*parseo de un archivo de texto
 *param pFile: puntero al archivo
 *param pArrayListEmployee: lista de empleados
 *return: (0) error o (1) OK.
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/*parseo de un archivo de binario
 *param pFile: puntero al archivo
 *param pArrayListEmployee: lista de empleados
 *return: (0) error o (1) OK.
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
