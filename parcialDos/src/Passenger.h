/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */


#ifndef PASSENGER_H_
#define PASSENGER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "inputs.h"
#define FIRST_CLASS "1"
#define EXECUTIVE_CLASS "2"
#define ECONOMY_CLASS "3"
#define ATERRIZADO "4"
#define EN_HORARIO "5"
#define EN_VUELO "6"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[7];
	int tipoPasajero;
	int estadoVuelo;

}Passenger;
/// @fn Passenger constructor para cargar un pasajero en memoria dinamica inicializando en 0 o vacio cada atributo
/// @brief
///
/// @return
Passenger* Passenger_new();
/// @fn Passenger constructor que carga un pasajero con los atributos de la estructura y a los que corresponde lo convierte en float o int
/// @brief
///
/// @param idStr
/// @param nombreStr
/// @param apellidoStr
/// @param precioStr
/// @param tipoPasajeroStr
/// @param codigoVueloStr
/// @param estadoVueloStr
/// @return
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr);
/// @fn Passenger constructor que carga un pasajero con los atributos de la estructura del tipo que corresponde cada uno
/// para carga desde el usuario
/// @brief
///
/// @param idStr
/// @param nombreStr
/// @param apellidoStr
/// @param precioStr
/// @param codigoVueloStr
/// @param tipoPasajeroStr
/// @param estadoVueloStr
/// @return
Passenger* Passenger_newParametrosUsuario(int idStr, char *nombreStr,char *apellidoStr, float precioStr, char* codigoVueloStr,int tipoPasajeroStr, int estadoVueloStr);
/// @fn void borra un pasajero que recibe como parametro
/// @brief
///
/// @param this
void Passenger_delete(Passenger* this);
/// @fn int borra la lista
/// @brief
///
/// @param pArrayListPassenger
/// @return
int Passenger_BorrarLista(LinkedList* pArrayListPassenger);
/////////////setter y getter//////////////
int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo);
/// @fn int convertirTipoAentero convierto el dato strig a un define de char numerico
/// @brief
///
/// @param tipoPasajero
/// @return
int convertirTipoAentero(char* tipoPasajero);
/// @fn int convierto el dato strig a un define de char numerico
/// @brief
///
/// @param estadoVuelo
/// @return
int convertirEstadoAentero(char* estadoVuelo);
//
int convertirTipoAcaracteres(int tipoPasajero, char* tipoPasajeroStr);
int convertirEstadoAcaracteres(int estadoVuelo, char* estadoVueloStr);

/// @fn int buscar el id mayor de la lista
/// @brief
///
/// @param pArrayListPassenger
/// @return
int buscarUltimoID(LinkedList* pArrayListPassenger);
/// @fn int generar el proximo id a asignar al nuevo pax
/// esta funcion llama a buscarUltimoID
///
/// /// @brief
///
/// @param pArrayListPassenger
/// @return
int ObtenerUltimoId(char* path, char* idUltimo);
int GuardarUltimoId(char* path, char* idUltimo);
int generarNuevoId(LinkedList* pArrayListPassenger);
/// @fn carga un nuevo pasajero con todos sus atributos
/// @brief
///
/// @param pArrayListPassenger
/// @return
Passenger* cargarUnPax(LinkedList* pArrayListPassenger);
/// @fn busca el pasajero con el id que se paso como parametro y devuelve el indice si lo encuentra
/// @brief
///
/// @param pArrayListPassenger
/// @param id
/// @return
int findPassengerById(LinkedList* pArrayListPassenger,int id);
/// @fn int recibe el pasajero a modificar y con un submenu pide al usuario que elija el atributo que desea modificar
/// @brief
///
/// @param pPasajero
/// @return
int modificarPasajero(Passenger* pPasajero);
/// @fn void muestra todos los atributos del pasajero que recibio como paramero
/// @brief
///
/// @param pPasajero
void mostrarUnPax(Passenger* pPasajero);
/// @fn int funcion retorna el valor de ordenamiento  por nombre de manera descendente o ascendete
/// @brief
///
/// @param paxUno
/// @param paxDos
/// @return
int Passenger_compararXNombre(void* paxUno, void* paxDos);
/// @fn int funcion retorna el valor de ordenamiento por apellido de manera descendente o ascendete
/// @brief
///
/// @param paxUno
/// @param paxDos
/// @return
int Passenger_compararXapellido(void* paxUno, void* paxDos);
/// @fn int funcion retorna el valor de ordenamiento por precio de manera descendente o ascendete
/// @brief
///
/// @param paxUno
/// @param paxDos
/// @return
int Passenger_compararXPrecio(void* paxUno, void* paxDos);
/// @fn int funcion retorna el valor de ordenamiento por tipo de manera descendente o ascendete
/// @brief
///
/// @param paxUno
/// @param paxDos
/// @return
int Passenger_compararXtipo(void* paxUno, void* paxDos);
/// @fn int funcion retorna el valor de ordenamiento por estado de vuelo de manera descendente o ascendete
/// @brief
///
/// @param paxUno
/// @param paxDos
/// @return
int Passenger_compararXestado(void* paxUno, void* paxDos);
/// @fn void menuSort()
/// @brief
///
int Passenger_compararXid(void* paxUno, void* paxDos);
void menuSort();

#endif /* PASSENGER_H_ */
