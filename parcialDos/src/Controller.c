#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "inputs.h"
#include "parser.h"


int controller_loadFromText(char* path , LinkedList* pArrayListPassenger){

	int retorno=-1;
	FILE* archivo;

	if(pArrayListPassenger!=NULL && path != NULL ){

		archivo=fopen(path,"r");

		if(archivo!=NULL){
			parser_PassengerFromText(archivo, pArrayListPassenger);
			retorno=0;
			fclose(archivo);
		}
	}

 return retorno;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger){
	int retorno=-1;
	FILE* archivoBinario;

	if(pArrayListPassenger!=NULL && path != NULL ){

		archivoBinario=fopen(path,"rb");

		if(archivoBinario!=NULL){
			//printf("Entra al if de controler\n");
			retorno=parser_PassengerFromBinary(archivoBinario, pArrayListPassenger);
			fclose(archivoBinario);
		}
	}

 return retorno;
}

int controller_addPassenger(LinkedList* pArrayListPassenger){
    int retorno= -1;
    Passenger* nuevoPasajero;

    if(pArrayListPassenger != NULL){

    	nuevoPasajero=cargarUnPax(pArrayListPassenger);

    	if(nuevoPasajero != NULL){
    		ll_add(pArrayListPassenger, nuevoPasajero);
    		retorno=0;
    	}
    }
    return retorno;
}

int controller_editPassenger(LinkedList* pArrayListPassenger){
	int retorno=-1;
	int idAbuscar;
	int validar;
	int indiceEncontrado;
	int validarIsEmpty;
	Passenger* auxPax;
	auxPax=NULL;
	validarIsEmpty= ll_isEmpty(pArrayListPassenger);
	if(validarIsEmpty== 0){

		if(pArrayListPassenger != NULL){

			validar=pedirNumero(&idAbuscar, "Ingrese el numero de id del pasajero a modifica \n", "Error! dato invalido", 1, 1000, 2);
			if(validar==0){

				indiceEncontrado=findPassengerById(pArrayListPassenger,idAbuscar);

				if(indiceEncontrado != -1){
					auxPax=(Passenger*)ll_get(pArrayListPassenger, indiceEncontrado);

					if(auxPax != NULL){

						mostrarUnPax(auxPax);

						if((validar=modificarPasajero(auxPax)) !=-1){
							printf("El pasajero se pudo modificar\n");
							mostrarUnPax(auxPax);
							retorno=0;
						}
					}
				}
			}
		}
	}else{
		printf("Primero debe cargar la lista \n");
	}
    return retorno;
}

int controller_removePassenger(LinkedList* pArrayListPassenger){
	int retorno=-1;
	int idBuscar;
	int indiceEncontrado;
	Passenger * auxPax;
	int validar;
	int opcion;
	int validarIsEmpty;

	validarIsEmpty= ll_isEmpty(pArrayListPassenger);
	if(validarIsEmpty== 0){

		if(pArrayListPassenger !=NULL){

			validar=pedirNumero(&idBuscar, "Ingrese el ID del pasajero a eliminar \n", "Error! dato invalido",1,10000000,2);
			if(validar==0){
				indiceEncontrado= findPassengerById(pArrayListPassenger,idBuscar);
				if(indiceEncontrado != -1){
					auxPax=(Passenger*)ll_get(pArrayListPassenger, indiceEncontrado);

					if(auxPax != NULL){

						mostrarUnPax(auxPax);
						validar=pedirNumero(&opcion,"Esta seguro que quiere dar de baja al pasajero, indique 1(si) o 2(no)\n", "Error! opcion invalida", 1, 2, 2);
						if(validar==0 && opcion){
						ll_remove(pArrayListPassenger,indiceEncontrado);
						Passenger_delete(auxPax);
						retorno=0;
						}
				}
			  }
			}
		}
	}else{
		printf("Primero debe cargar la lista\n");
	}
	return retorno;
}

int controller_removeList(LinkedList* pArrayListPassenger){

	int retorno=-1;
	int validar;
	int opcion;
	int validarIsEmpty;

	validarIsEmpty= ll_isEmpty(pArrayListPassenger);
	if(validarIsEmpty== 0){

		if(pArrayListPassenger != NULL){

			validar= pedirNumero(&opcion, "Esta seguro que desea eliminar la lista: indique 1(Si) o 2(No)", "Error!opcion invalida", 1, 2, 2);
			if(validar==0 && opcion ==1){
				Passenger_BorrarLista(pArrayListPassenger);
				retorno=0;
			}
		}
	}else{
		printf("Primero debe cargar la lista\n");
	}
	return retorno;
}

int controller_ListPassenger(LinkedList* pArrayListPassenger){

	int retorno=-1;
	Passenger* auxPax;
	int size;
	int validarIsEmpty;

	validarIsEmpty= ll_isEmpty(pArrayListPassenger);
	if(validarIsEmpty== 0){

		if(pArrayListPassenger!=NULL){
			size=ll_len(pArrayListPassenger);
			printf("--id---Nombre---Apellido---Precio---Codigo de vuelo---Tipo de pasajero---Estado de vuelo--\n");
			for(int i=0;i<size;i++){
				auxPax=(Passenger*)ll_get(pArrayListPassenger, i);
				mostrarUnPax(auxPax);

				retorno=0;
			}
		}
	}else{
		printf("Primero debe cargar la lista\n");
	}
	return retorno;
}

int controller_sortPassenger(LinkedList* pArrayListPassenger){

	int retorno=-1;
	int opcion;
	int validar;
	int orden;
	int validarIsEmpty;

	validarIsEmpty= ll_isEmpty(pArrayListPassenger);
	if(validarIsEmpty== 0){
		if(pArrayListPassenger != NULL){
		menuSort();
		validar= pedirNumero(&opcion,"Ingrese la opcion\n","Error opcion incorrecta \n",1,5,2);
		if(validar==0){

			pedirNumero(&orden,"Desea ordenar de manera  descendente (ingrese 0) o ascendente (ingrese 1)\n","Error orden incorrecto \n",0,1,2);

			switch(opcion)
			{
				case 1:
					ll_sort(pArrayListPassenger, Passenger_compararXNombre, orden);
					retorno=0;
					break;
				case 2:
					ll_sort(pArrayListPassenger, Passenger_compararXapellido, orden);
					retorno=0;
					break;
				case 3:
					ll_sort(pArrayListPassenger, Passenger_compararXPrecio, orden);
					retorno=0;
					break;
				case 4:
					ll_sort(pArrayListPassenger, Passenger_compararXtipo, orden);
					retorno=0;
					break;
				case 5:
					ll_sort(pArrayListPassenger, Passenger_compararXtipo, orden);
					retorno=0;
					break;
			}
		  }
		}
	}else{
			printf("Primero debe cargar la lista\n");
		}
    return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	Passenger* auxPax=NULL;
	FILE* archivo;
	int size;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[7];
	int tipoPasajero;
	int estadoVuelo;
	char auxTipo[50];
	char auxEstado[50];

	if(path != NULL && pArrayListPassenger!= NULL){

		size=ll_len(pArrayListPassenger);

		archivo=fopen(path,"w");
		if(archivo !=NULL){

			fprintf(archivo,"id,Nombre,apellido,precio,codigo de vuelo,tipo de pasajero,estado de vuelo\n");

			for(int i=0;i<size;i++){

				auxPax=(Passenger*)ll_get(pArrayListPassenger, i);
				if(Passenger_getId(auxPax, &id) == 0 &&	Passenger_getNombre(auxPax,nombre)== 0 &&
				Passenger_getApellido(auxPax, apellido)==0 && Passenger_getPrecio(auxPax, &precio)==0 &&
				Passenger_getCodigoVuelo(auxPax, codigoVuelo)== 0 && Passenger_getTipoPasajero(auxPax, &tipoPasajero)== 0 &&
				Passenger_getEstadoVuelo(auxPax,&estadoVuelo) == 0){

					if(convertirTipoAcaracteres(tipoPasajero, auxTipo)==0 && convertirEstadoAcaracteres(estadoVuelo, auxEstado)==0){

						fprintf(archivo,"%d,%s,%s,%f,%s,%s,%s\n",id,nombre,apellido,precio,codigoVuelo,auxTipo,auxEstado);
						retorno=0;
					}
				}
			  }
			}
		fclose(archivo);
		}
   return retorno;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	Passenger* auxPax;
	FILE* archivo;
	int size;

	if(path != NULL && pArrayListPassenger!= NULL){

		size=ll_len(pArrayListPassenger);

		archivo=fopen(path,"wb");
		if(archivo != NULL){

			for(int i=0;i<size;i++){

			auxPax=(Passenger*)ll_get(pArrayListPassenger, i);
			fwrite(auxPax,sizeof(Passenger),1,archivo);
			retorno=0;

			}
			fclose(archivo);
		}
	}
    return retorno;
}


