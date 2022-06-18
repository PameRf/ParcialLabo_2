#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "inputs.h"


int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	Passenger* unPasajero;

	char id[200];
	char nombre[200];
	char apellido[200];
	char precio[200];
	char codigoVuelo[200];
	char tipoPasajero[200];
	char estadoVuelo[200];

	if(pFile!=NULL && pArrayListPassenger !=NULL){

		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
		do{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
			unPasajero=Passenger_newParametros(id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
			if(unPasajero !=NULL){
			ll_add(pArrayListPassenger, unPasajero);
			retorno=0;
			}
		}while(!feof(pFile));
	}

    return retorno;
}

int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	Passenger* auxPax;

	if(pFile !=NULL && pArrayListPassenger !=NULL){


		while(!feof(pFile)){
				auxPax=Passenger_new();
				if(auxPax !=NULL && fread(auxPax,sizeof(Passenger),1,pFile)==1){

				ll_add(pArrayListPassenger, auxPax);
				retorno=0;
				}
				else{
					Passenger_delete(auxPax);
				}
			}
	}

    return retorno;
}
