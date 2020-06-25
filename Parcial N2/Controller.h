#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

/*Sirve para cargar datos a partir de un archivo en formato texto
 *param path: nombre del archivo
 *param pArrayListVuelos: lista de vuelos
 *return: (0) error o (1) OK
 */
int controller_loadFromText(char* path , LinkedList* pArrayListVuelos);

/** \brief Hardcodea la lista de pilotos
 * \param pArrayList lista a hardcodear
 * \return (0) error o (1) OK
 */
int hardcodearPilotos (LinkedList* pArrayList)


/** \brief Sirve para imprimir un listado con los datos de los vuelos, y el nombre del piloto (en lugar del ID)
 * \param pArrayListVuelos: Array que almacena los datos de los vuelos
 * \param pArrayListPilotos: Array que almadena los datos de los pilotos
 * \return: (0) error o (1) OK
 */
int controller_listVuelos(LinkedList* pArrayListVuelos, LinkedList* pArrayListPilotos);

#endif // CONTROLLER_H_INCLUDED
