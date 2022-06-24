/*
 * Passenger.c
 *
 *  Created on: 9 jun. 2022
 *      Author: pamel
 */

#include "Passenger.h"

Passenger* Passenger_new() {

	Passenger *espacioParaPasajero;

	espacioParaPasajero = (Passenger*) malloc(sizeof(Passenger));

	if (espacioParaPasajero != NULL) {
		Passenger_setId(espacioParaPasajero, 0);
		Passenger_setNombre(espacioParaPasajero, " ");
		Passenger_setApellido(espacioParaPasajero, " ");
		Passenger_setPrecio(espacioParaPasajero, 0);
		Passenger_setCodigoVuelo(espacioParaPasajero, " ");
		Passenger_setTipoPasajero(espacioParaPasajero, 0);
		Passenger_setEstadoVuelo(espacioParaPasajero, 0);

	}
	return espacioParaPasajero;
}

Passenger* Passenger_newParametros(char *idStr, char *nombreStr,
		char *apellidoStr, char *precioStr, char *codigoVueloStr,
		char *tipoPasajeroStr, char *estadoVueloStr) {

	Passenger *nuevoPasajero;

	nuevoPasajero = Passenger_new();
	int validarretorno;

	if (idStr != NULL && nombreStr != NULL && apellidoStr != NULL
			&& precioStr != NULL && tipoPasajeroStr != NULL
			&& codigoVueloStr != NULL && estadoVueloStr != NULL) {
		if (nuevoPasajero != NULL) {
			Passenger_setId(nuevoPasajero, atoi(idStr));
			Passenger_setNombre(nuevoPasajero, nombreStr);
			Passenger_setApellido(nuevoPasajero, apellidoStr);
			Passenger_setPrecio(nuevoPasajero, atof(precioStr));
			Passenger_setCodigoVuelo(nuevoPasajero, codigoVueloStr);
			validarretorno = convertirTipoAentero(tipoPasajeroStr);
			if (validarretorno == 0) {
				Passenger_setTipoPasajero(nuevoPasajero, atoi(tipoPasajeroStr));
			}
			validarretorno = convertirEstadoAentero(estadoVueloStr);
			if (validarretorno == 0) {
				Passenger_setEstadoVuelo(nuevoPasajero, atoi(estadoVueloStr));
			}
		}
	}
	return nuevoPasajero;
}

Passenger* Passenger_newParametrosUsuario(int idStr, char *nombreStr,
		char *apellidoStr, float precioStr, char *codigoVueloStr,
		int tipoPasajeroStr, int estadoVueloStr){

	Passenger *nuevoPasajero;

	nuevoPasajero = Passenger_new();

	if (idStr >0 && nombreStr != NULL && apellidoStr != NULL
			&& precioStr >0 && tipoPasajeroStr >0
			&& codigoVueloStr != NULL && estadoVueloStr >0){
		if (nuevoPasajero != NULL) {
			Passenger_setId(nuevoPasajero, idStr);
			Passenger_setNombre(nuevoPasajero, nombreStr);
			Passenger_setApellido(nuevoPasajero, apellidoStr);
			Passenger_setPrecio(nuevoPasajero, precioStr);
			Passenger_setCodigoVuelo(nuevoPasajero, codigoVueloStr);
			Passenger_setTipoPasajero(nuevoPasajero, tipoPasajeroStr);
			Passenger_setEstadoVuelo(nuevoPasajero, estadoVueloStr);
			}
	}
	return nuevoPasajero;
}
void Passenger_delete(Passenger *this) {

	if (this != NULL) {
		free(this);
	}
}
int Passenger_BorrarLista(LinkedList* pArrayListPassenger){

	int retorno=-1;
	Passenger* auxPax;
	int size;

	if (pArrayListPassenger != NULL){

		size = ll_len(pArrayListPassenger);

		for (int i = 0; i < size; i++) {
			auxPax = (Passenger*) ll_get(pArrayListPassenger, i);
			Passenger_delete(auxPax);
			retorno=0;
		}
	}
	return retorno;
}
int Passenger_setId(Passenger *this, int id) {

	int retorno;
	retorno = -1;

	if (this != NULL && id > 0) {
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int Passenger_getId(Passenger *this, int *id) {

	int retorno;
	retorno = -1;

	if (this != NULL && id != NULL) {
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setNombre(Passenger *this, char *nombre) {
	int retorno;
	retorno = -1;

	if (this != NULL && nombre != NULL) {
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}

int Passenger_getNombre(Passenger *this, char *nombre) {

	int retorno;
	retorno = -1;

	if (this != NULL && nombre != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setApellido(Passenger *this, char *apellido) {

	int retorno;
	retorno = -1;

	if (this != NULL && apellido != NULL) {
		strcpy(this->apellido, apellido);
		retorno = 0;
	}
	return retorno;
}

int Passenger_getApellido(Passenger *this, char *apellido) {

	int retorno;
	retorno = -1;

	if (this != NULL && apellido != NULL) {
		strcpy(apellido, this->apellido);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger *this, char *codigoVuelo) {

	int retorno;
	retorno = -1;

	if (this != NULL && codigoVuelo != NULL) {
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 0;
	}
	return retorno;
}

int Passenger_getCodigoVuelo(Passenger *this, char *codigoVuelo) {

	int retorno;
	retorno = -1;

	if (this != NULL && codigoVuelo != NULL) {
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 0;
	}
	return retorno;

}

int Passenger_setTipoPasajero(Passenger *this, int tipoPasajero) {

	int retorno;
	retorno = -1;

	if (this != NULL && tipoPasajero > 0) {
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger *this, int *tipoPasajero) {

	int retorno;
	retorno = -1;

	if (this != NULL && tipoPasajero > 0) {
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger *this, float precio) {

	int retorno;
	retorno = -1;

	if (this != NULL && precio > 0) {
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger *this, float *precio) {

	int retorno;
	retorno = -1;

	if (this != NULL && precio > 0) {
		*precio = this->precio ;
		;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setEstadoVuelo(Passenger *this, int estadoVuelo) {

	int retorno;
	retorno = -1;

	if (this != NULL && estadoVuelo > 0) {
		this->estadoVuelo = estadoVuelo;
		retorno = 0;
	}
	return retorno;
}

int Passenger_getEstadoVuelo(Passenger *this, int *estadoVuelo) {

	int retorno;
	retorno = -1;

	if (this != NULL && estadoVuelo != NULL) {
		*estadoVuelo = this->estadoVuelo;
		retorno = 0;
	}
	return retorno;
}

int convertirTipoAentero(char *tipoPasajero) {

	int retorno = -1;
	if (tipoPasajero != NULL) {

		if (strcmp(tipoPasajero, "FirstClass") == 0) {

			strcpy(tipoPasajero, FIRST_CLASS);
			retorno = 0;
		}
		if (strcmp(tipoPasajero, "ExecutiveClass") == 0) {
			strcpy(tipoPasajero, EXECUTIVE_CLASS);
			retorno = 0;
		}
		if (strcmp(tipoPasajero, "EconomyClass") == 0) {
			strcpy(tipoPasajero, ECONOMY_CLASS);
			retorno = 0;
		}

	}
	return retorno;
}
int convertirEstadoAentero(char *estadoVuelo) {

	int retorno = -1;
	if (estadoVuelo != NULL) {

		if (strcmp(estadoVuelo, "Aterrizado") == 0) {
			strcpy(estadoVuelo, ATERRIZADO);
			retorno = 0;
		}
		if (strcmp(estadoVuelo, "En Horario") == 0) {
			strcpy(estadoVuelo, EN_HORARIO);
			retorno = 0;
		}
		if (strcmp(estadoVuelo, "En Vuelo") == 0) {
			strcpy(estadoVuelo, EN_VUELO);
			retorno = 0;
		}
	}
	return retorno;
}

int convertirTipoAcaracteres(int tipoPasajero, char* tipoPasajeroStr){

	int retorno = -1;
	if (tipoPasajero > 0  && tipoPasajero <4) {

		switch(tipoPasajero){
		case 1:
			strcpy(tipoPasajeroStr,"FirstClass");
			break;
		case 2:
			strcpy(tipoPasajeroStr,"ExecutiveClass");
			break;
		case 3:
			strcpy(tipoPasajeroStr, "EconomyClass");
			break;
		}
		retorno=0;
	}
	return retorno;
}
int convertirEstadoAcaracteres(int estadoVuelo, char* estadoVueloStr){

	int retorno = -1;
	if (estadoVuelo > 3  && estadoVuelo <7) {

		switch(estadoVuelo){
		case 4:
			strcpy(estadoVueloStr,"Aterrizado");
			break;
		case 5:
			strcpy(estadoVueloStr,"En Horario");
			break;
		case 6:
			strcpy(estadoVueloStr, "En Vuelo");
			break;
		}
		retorno=0;
	}
	return retorno;
}
int buscarUltimoID(LinkedList* pArrayListPassenger){

	int retorno=-1;
	int size;
	Passenger* auxPax;
	int id;
	int idMayor=0;
	int flagId=0;
	if(pArrayListPassenger !=NULL){
		size=ll_len(pArrayListPassenger);

		for(int i=0;i<size;i++){
				auxPax=(Passenger*)ll_get(pArrayListPassenger, i);
				Passenger_getId(auxPax, &id);
				if(flagId==0 || idMayor<id){
					idMayor=id;
					retorno=idMayor;
				}
		}
	}
	return retorno;
}
int ObtenerUltimoId(char* path,char* idUltimo){

	int retorno=-1;

	FILE* archivo;

	archivo=fopen(path,"r");

	if(archivo != NULL && idUltimo > 0){
		fscanf(archivo,"%[^\n]\n",idUltimo);
		retorno=0;
	}
	fclose(archivo);
	return retorno;

}

int GuardarUltimoId(char* path, char* idUltimo){

	int retorno=-1;

	FILE* archivo;

	archivo=fopen(path,"w");

	if(archivo != NULL && idUltimo != NULL){
		fprintf(archivo,"%s",idUltimo);
		retorno=0;
	}
	fclose(archivo);
	return retorno;

}

int generarNuevoId(LinkedList* pArrayListPassenger){

	int idPasajero = 0;
	char auxId[10];
	int validar;
	int idborrado;

	if(pArrayListPassenger !=NULL){
		idPasajero=buscarUltimoID(pArrayListPassenger);
		//printf("id encontrado en mayor %d \n",idPasajero);
		validar=ObtenerUltimoId("ultimoId.csv", auxId);
		//printf("id char %s\n",auxId);
		if(validar ==0){
		 idborrado=atoi(auxId);
		 if(idborrado > idPasajero){
			 idPasajero=idborrado;
		 }
		}

		if(idPasajero > 0){
	    idPasajero++;
	    //printf("valor de id num %d'n",idPasajero);
		}

		else{
			idPasajero=1001;
		}
	}
	return idPasajero;
}

Passenger* cargarUnPax(LinkedList* pArrayListPassenger){

	Passenger* unPasajero;
	int id;
	char nombre[200];
	char apellido[200];
	float precio;
	char codigoVuelo[50];
	int tipoPasajero;
	int estadoVuelo;

	int flagCarga;
	flagCarga=0;
	unPasajero=NULL;

	if(pArrayListPassenger != NULL){
		id=generarNuevoId(pArrayListPassenger);

		if(pedirCaracteres(nombre,"Ingrese el nombre: \n",200)== 0){

			flagCarga=1;
		}
		else{

			printf("Error no se pudo cargar nombre invalido");
		}
		if(pedirCaracteres(apellido,"Ingrese el apellido: \n",200)== 0 && flagCarga==1){

			flagCarga=2;
		}
		else{
			printf("Error no se pudo cargar apellido invalido");
		}
		if(pedirPrecio(&precio,"Ingrese el precio del vuelo: \n", "Error! el precio es incorrecto: \n", 9000, 4700000, 2)== 0 && flagCarga==2){

			flagCarga=3;
		}
		else{
			printf("Error no se pudo cargar Precio");
		}
		if(pedirLetrasYnumeros(codigoVuelo, "Ingrese su codigo de vuelo: \n", 50)== 0  && flagCarga==3){

			flagCarga=4;
		}
		else{
			printf("Error no se pudo cargar Fly code");
		}
		if(pedirNumero(&tipoPasajero, "Ingrese tipo de pasajero 1 (FirstClass), 2 (ExecutiveClass) y 3 (EconomyClass) \n", "Error! Tipo de pasajero invalido", 1, 3,2)== 0 && flagCarga==4){

			flagCarga=5;
		}
		else{
			printf("Error no se pudo cargar tipo de pax");
		}
		if(pedirNumero(&estadoVuelo, "Ingrese estado de vuelo 4 (Aterrizado), 5 (En Horario) y 6 (En Vuelo) \n", "Error! Estado de vuelos invalido", 4, 6,2)== 0 && flagCarga==5){

			flagCarga=6;
		}
		else{
			printf("Error no se pudo cargar estado de vuelo");
		}

		if(flagCarga== 6){


			unPasajero=Passenger_newParametrosUsuario(id,nombre,
				apellido, precio, codigoVuelo,tipoPasajero,estadoVuelo);
      }
	}


return unPasajero;

}

int modificarPasajero(Passenger* pPasajero){

	int retorno=-1;
	char nombre[200];
	char apellido[200];
	float precio;
	char codigoVuelo[50];
	int tipoPasajero;
	int estadoVuelo;
	int opcion;


	if (pPasajero != NULL){


	 mostrarSubMenu();

	 pedirNumero(&opcion, "Ingrese la opcion que desea modificar\n", "Error! la opcion ingresada es incorrecta \n",1, 6, 2);

		 switch(opcion){

		 case 1:
			 if(pedirCaracteres(nombre,"Ingrese el nuevo nombre: \n",200)== 0){

				 Passenger_setNombre(pPasajero,nombre);
				 retorno=1;

			 }
			 else{

				 printf("Error! no se pudo cargar nombre invalido \n");
			 }
		 break;
		 case 2:
			if(pedirCaracteres(apellido,"Ingrese el nuevo apellido: \n",200)== 0){

				Passenger_setApellido(pPasajero, apellido);
				retorno=2;
			}
			else{
				printf("Error! no se pudo cargar apellido invalido");
			}
		 break;
		 case 3:
			if(pedirPrecio(&precio,"Ingrese el nuevo precio del vuelo: \n", "Error! el precio es incorrecto: \n", 9000, 600000000, 2)== 0){

				Passenger_setPrecio(pPasajero,precio);
				retorno=3;
			}
			else{
				printf("Error! no se pudo cargar Precio\n");
			}
		 break;
		 case 4:
			if(pedirNumero(&tipoPasajero, "Ingrese nuevo tipo de pasajero 1 (FirstClass), 2 (ExecutiveClass) y 3 (EconomyClass) \n", "Error! Tipo de pasajero invalido", 1, 3,2)== 0){

				Passenger_setTipoPasajero(pPasajero,tipoPasajero);
				retorno=4;
			}
			else{
				printf("Error no se pudo cargar tipo de pasajero\n");
			}
		 break;
		 case 5:
			if(pedirLetrasYnumeros(codigoVuelo, "Ingrese su codigo de vuelo: \n", 10)== 0){

				Passenger_setCodigoVuelo(pPasajero,codigoVuelo);
				retorno=5;
			}
			else{
				printf("Error no se pudo cargar el codigo de vuelo\n");
			}
		 break;
		 case 6:
			if(pedirNumero(&estadoVuelo, "Ingrese Ingrese estado de vuelo 4 (Aterrizado), 5 (En Horario) y 6 (En Vuelo) \n","Error estado invalido",4,6,2)== 0){

				Passenger_setEstadoVuelo(pPasajero,estadoVuelo);
				retorno=6;
			}
			else{
				printf("Error no se pudo cargar el codigo de vuelo");
			}
		 break;
		 }
	}
 return retorno;
}



int findPassengerById(LinkedList* pArrayListPassenger,int id){

	int retorno=-1;
	int size;
	Passenger* auxPasajero;
	int idAux;


	if (pArrayListPassenger != NULL && id > 0){

		size=ll_len(pArrayListPassenger);

		for (int i = 0; i < size; i++){

			auxPasajero= (Passenger*)ll_get(pArrayListPassenger, i);

			if (Passenger_getId(auxPasajero,&idAux)==0 &&  idAux== id){

      		  retorno = i;
			}
		}
	}
	return retorno;
}

void mostrarUnPax(Passenger* pPasajero){


	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[7];
	int tipoPasajero;
	int estadoVuelo;
	char auxTipo[50];
	char auxEstado[50];

	if(Passenger_getId(pPasajero, &id)==0 && Passenger_getNombre(pPasajero, nombre)==0 &&
	Passenger_getApellido(pPasajero, apellido)==0 && Passenger_getPrecio(pPasajero, &precio)==0 &&
	Passenger_getCodigoVuelo(pPasajero, codigoVuelo)== 0 && Passenger_getTipoPasajero(pPasajero,&tipoPasajero) ==0 &&
	Passenger_getEstadoVuelo(pPasajero, &estadoVuelo)==0){

		if (convertirTipoAcaracteres(tipoPasajero, auxTipo)== 0 &&	convertirEstadoAcaracteres(estadoVuelo, auxEstado)==0){

		printf("%-4d %-10s %-15s %-19.2f %-12s %-19s %-10s \n",id, nombre, apellido, precio, codigoVuelo, auxTipo, auxEstado);
		}
	}
}

int Passenger_compararXNombre(void* paxUno, void* paxDos) {

	int retorno=0;
	Passenger* primerPax;
	Passenger* segundoPax;
	char nombreUno[100];
	char nombreDos[100];


	if (paxUno != NULL && paxDos != NULL) {
		primerPax = (Passenger*) paxUno;
		segundoPax = (Passenger*) paxDos;

		Passenger_getNombre(primerPax, nombreUno);
		Passenger_getNombre(segundoPax, nombreDos);

		retorno = strcmp(nombreUno, nombreDos);
	}

	return retorno;
}

int Passenger_compararXapellido(void* paxUno, void* paxDos) {

	int retorno=0;
	Passenger* primerPax;
	Passenger* segundoPax;
	char apellidoUno[100];
	char apellidoDos[100];


	if (paxUno != NULL && paxDos != NULL) {
		primerPax = (Passenger*) paxUno;
		segundoPax = (Passenger*) paxDos;

		Passenger_getApellido(primerPax, apellidoUno);
		Passenger_getApellido(segundoPax, apellidoDos);

		retorno = strcmp(apellidoUno, apellidoDos);
	}

	return retorno;
}

int Passenger_compararXPrecio(void* paxUno, void* paxDos){

	int retorno=0;
	Passenger* primerPax;
	Passenger* segundoPax;
	float primerPrecio;
	float segundoPrecio;

	if (paxUno != NULL && paxDos != NULL) {
			primerPax = (Passenger*) paxUno;
			segundoPax = (Passenger*) paxDos;
			Passenger_getPrecio(primerPax,&primerPrecio);
			Passenger_getPrecio(segundoPax,&segundoPrecio);
			if(primerPrecio > segundoPrecio){
					retorno=1;
				}
			else if(primerPrecio < segundoPrecio){

					retorno=-1;
				}
		}
	return retorno;
}



int Passenger_compararXtipo(void* paxUno, void* paxDos){

	int retorno=0;
	Passenger* primerPax;
	Passenger* segundoPax;
	int primerTipo;
	int segundoTipo;


	if (paxUno != NULL && paxDos != NULL){
			primerPax = (Passenger*) paxUno;
			segundoPax = (Passenger*) paxDos;
			Passenger_getTipoPasajero(primerPax,&primerTipo);
			Passenger_getTipoPasajero(segundoPax,&segundoTipo);
			if(primerTipo > segundoTipo){
				retorno=1;
			}
			else if(primerTipo < segundoTipo){

				retorno=-1;
			}
		}
  return retorno;
}

int Passenger_compararXestado(void* paxUno, void* paxDos){

	int retorno=0;
	Passenger* primerPax;
	Passenger* segundoPax;
	int primerEstado;
	int segundoEstado;


	if (paxUno != NULL && paxDos != NULL) {
			primerPax = (Passenger*) paxUno;
			segundoPax = (Passenger*) paxDos;
			Passenger_getEstadoVuelo(primerPax,&primerEstado);
			Passenger_getEstadoVuelo(segundoPax,&segundoEstado);
			if(primerEstado > segundoEstado){
				retorno=1;
			}
			else if(primerEstado < segundoEstado){

				retorno=-1;
			}
		}
  return retorno;
}
int Passenger_compararXid(void* paxUno, void* paxDos){

	int retorno=0;
	Passenger* primerPax;
	Passenger* segundoPax;
	int primerID;
	int segundoID;

	if (paxUno != NULL && paxDos != NULL) {
			primerPax = (Passenger*) paxUno;
			segundoPax = (Passenger*) paxDos;
			Passenger_getId(primerPax,&primerID);
			Passenger_getId(segundoPax,&segundoID);
			if(primerID > segundoID){
					retorno=1;
				}
			else if(primerID < segundoID){

					retorno=-1;
				}
		}
	return retorno;
}

int buscarPaxXTipo(void* this){

	int retorno=0;
	Passenger* AuxPax=NULL;
	int auxTipo;



	if(this !=NULL){

			AuxPax=(Passenger*)this;
		if(Passenger_getTipoPasajero(AuxPax, &auxTipo)==0 && auxTipo== 1){

			retorno=1;
		}
   	}
	return retorno;
}

int BuscarFirstClass(void* this){

	int retorno=0;
	Passenger* AuxPax=NULL;
	int tipoFirst;


	if(this !=NULL){

		AuxPax=(Passenger*)this;

		if(Passenger_getTipoPasajero(AuxPax, &tipoFirst)==0 && tipoFirst== 1){

			retorno=1;
		}
   	}
	return retorno;
}

int BuscarExecutiveClass(void* this){

	int retorno=0;
	Passenger* AuxPax=NULL;
	int Executive;


	if(this !=NULL){

		AuxPax=(Passenger*)this;

		if(Passenger_getTipoPasajero(AuxPax, &Executive)==0 && Executive== 2){

			retorno=1;
		}
   	}
	return retorno;
}

int BuscarEconomyClass(void* this){

	int retorno=0;
	Passenger* AuxPax=NULL;
	int Economy;


	if(this !=NULL){

		AuxPax=(Passenger*)this;

		if(Passenger_getTipoPasajero(AuxPax, &Economy)==0 && Economy== 3){

			retorno=1;
		}
   	}
	return retorno;
}



void menuSort(){

	printf("Elija la opcion que desea ordenar: \n"
				"1. Nombre \n"
				"2. Apellido \n"
				"3. Precio \n"
				"4. Tipo de pasajero\n"
				"5. Estado de vuelo\n"
				"6. Id\n");
}

void menuInformes(){

	printf("Elija la opcion que desea informar: \n"
				"1. Pasajeros por clase \n"
				"2. Generar archivo de vuelos \n"
				"3. Calcular millas acumuladas \n");
}



