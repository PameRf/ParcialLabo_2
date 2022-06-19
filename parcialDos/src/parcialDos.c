/*
 ============================================================================
 Name        : parcialDos.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "inputs.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
/////ultimo///


int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    int validarMenu;
    int flagMenu=0;
    int confirmaSalir=0;


    LinkedList* listaPasajeros = ll_newLinkedList();


    do{
    	printf(".............................MENU.............................................\n");
    	printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n ");
        printf("2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n");
    	printf("3. Alta de pasajero\n");
    	printf("4. Modificar datos de pasajero\n");
    	printf("5. Baja de pasajero\n");
    	printf("6. Listar pasajeros\n");
    	printf("7. Ordenar pasajeros\n");
    	printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
    	printf("9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n");
    	printf("10.Salir\n");


    	validarMenu=pedirNumero(&option, "Ingrese una opcion \n","Error! opcion invalida\n", 1, 10,2);

    	if(validarMenu==0){
			switch(option)
			{
				case 1:
				    if(flagMenu==0){
						if(controller_loadFromText("data.csv",listaPasajeros)==0){
							printf("Se cargo el archivo de pasajeros\n");
							flagMenu=1;
						}
						else{
							printf("No se pudo cargar el archivo \n");
						}
				    }
				    else{
							printf("No puede cargar dos veces la lista\n");
						}
					break;
				case 2:
					if(flagMenu==0){
						if(controller_loadFromBinary("data.bin",listaPasajeros)==0){
							printf("Se cargo el archivo en binario\n");
							flagMenu=1;
						}
						else{
							printf("No se pudo cargar el archivo en binario\n");
						}
					}
				  else{
						   printf("No puede cargar dos veces la lista\n");
					  }
					break;
				case 3:
					if(controller_addPassenger(listaPasajeros)==0){
						printf("El pasajero se cargo correctamente\n");

					}
					else{

						printf("No se pudo cargar pasajero\n");
					}
					break;
				case 4:

					if(controller_editPassenger(listaPasajeros)==0){
						printf("El pasajero se modifico correctamente\n");

					}
					else{
						printf("El pasajero no se modifico\n");
					}
					break;
				case 5:
					if(controller_removePassenger(listaPasajeros)==0){

							printf("El pasajero se dio de baja correctamente\n");

						}
						else{
							printf("El pasajero no se pudo dar de baja\n");
						}
					break;
				case 6:
						if(listaPasajeros != NULL){
						controller_ListPassenger(listaPasajeros);
						}
						else{
							printf("Debe cargar el archivo primero\n");
							}

					break;
				case 7:

						if(controller_sortPassenger(listaPasajeros)==0){
							printf("Pasajeros ordenados\n");
							controller_ListPassenger(listaPasajeros);
													}
						else{
							printf("No se pudo ordenar los pasajeros\n");
						}

					break;
				case 8:
					if(flagMenu==1){
						if(controller_saveAsText("data.csv",listaPasajeros)==0 &&
							controller_saveAsBinary("data.bin", listaPasajeros)==0){

							printf("El archivo se guardo exitosamente\n");

							flagMenu=2;
						}
						else{
							printf("No se pudo guard\n");
						}
					}
					else{
						printf("Primero debe cargar la lista\n");

					}
					break;
				case 9:
					if(flagMenu== 1){
						if(controller_saveAsBinary("data.bin", listaPasajeros)==0
							&& controller_saveAsText("data.csv",listaPasajeros)==0){
							printf("El archivo se guardo en binario correctamente\n");
							flagMenu=3;
						}
						else{
							printf("No se pudo cargar el archivo dos veces \n");
						}
					}
					break;
				case 10:
					if(flagMenu== 2 || flagMenu== 3){
					pedirNumero(&confirmaSalir, "Desea salir del programa?\n 1.si\n 2.no \n", "Opcion incorrecta!\n", 1, 2, 3);
					if(confirmaSalir ==1){

						ll_deleteLinkedList(listaPasajeros);
						printf("Gracias por usar Smart Travel");
					}
					}else{
						printf("Primero debe guardar los cambios\n");
					}
					break;


			}
    	}
    }while(confirmaSalir != 1);
    return 0;
}

