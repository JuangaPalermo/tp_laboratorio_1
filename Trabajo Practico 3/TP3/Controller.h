/*Sirve para cargar datos a partir de un archivo en formato texto
 *param path: nombre del archivo
 *param pArrayListEmployee: lista de empleados
 *return: (0) error o (1) OK
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/*Sirve para cargar datos a partir de un archivo en formato texto
 *param path: nombre del archivo
 *param pArrayListEmployee: lista de empleados
 *return: (0) error o (1) OK
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/*Sirve para agregar un empleado a la lista que le paso como parametro
 *param pArrayListEmployee: lista donde se agregara el empleado
 *return: (0) error o (1) OK.
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/*Sirve para editar un empleado de la lista que le paso como parametro
 *param pArrayListEmployee: lista donde se encuentra el empleado a editar
 *return: (0) error, (1) OK, (-1) cancela.
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/*Sirve para eliminar un empleado de la lista que le paso como parametro
 *param pArrayListEmployee: lista donde se encuentra el empleado a eliminar
 *return: (0) error, (1) OK, (-1) cancela.
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/*Sirve para imprimir la lista de empleados que le paso como parametro
 *param pArrayListEmployee: listado a imprimir
 *return: (0) error o (1) OK.
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/*Sirve para ordenar la lista de empleados que le paso como parametro
 *(el criterio de ordenamiento lo selecciona el usuario en un submenu dentro del controller)
 *param pArrayListEmployee: listado a ordenar
 *return: (0) error o (1) OK.
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/*Sirve para guardar la lista que le paso como parametro en un archivo de formato texto
 *param path: nombre del archivo
 *param pArrayListEmployee: listado a almacenar
 *return: (0) error o (1) OK.*/
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/*Sirve para guardar la lista que le paso como parametro en un archivo de formato binario
 *param path: nombre del archivo
 *param pArrayListEmployee: listado a almacenar
 *return: (0) error o (1) OK.*/
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


