/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int 0 si pudo y -1 sino
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int  0 si pudo y -1 sino
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int 0 si pudo y -1 sino
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger);
/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int  0 si pudo y -1 sino
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger);
/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int 0 si pudo y -1 sino
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger);
/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int 0 si pudo y -1 sino
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger);
/** \brief Ordenar pasajeros de manera descendente o ascendente
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int 0 si pudo y -1 sino
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);
/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int 0 si pudo y -1 sino
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int 0 si pudo y -1 sino
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);
/// @fn int elimina la lista de pasajeros
/// @brief
///
/// @param pArrayListPassenger
/// @return
int controller_removeList(LinkedList* pArrayListPassenger);

int controller_filter(LinkedList* pArrayListPassenger);
int controller_ContadorClase(LinkedList* this);

