/*
 * Input.c
 *
 *  Created on: 5 abr. 2022
 *      Author: diany
 */

#include "Input.h"

int input_getInt(char mensaje[], int reintentos, int min, int max, char mensajeError[], int *pNumeroIngresado) {

	int retorno = -1;
	int auxiliarInt;
	int retornoScanf;

	if (mensaje != NULL && min < max && mensajeError != NULL && pNumeroIngresado != NULL && reintentos > 0)
	{
		printf("%s", mensaje);
		retornoScanf = scanf("%d", &auxiliarInt);

		do {
			if (retornoScanf != 1 || auxiliarInt > max || auxiliarInt < min)
			{
				printf("%s", mensajeError);
				retornoScanf = scanf("%d", &auxiliarInt);
				reintentos--;
			} else {
				reintentos = 0;
				*pNumeroIngresado = auxiliarInt;
				retorno = 0;
			}

		} while (reintentos>0);
	}
	return retorno;
}

int input_getFloat(char mensaje[], int reintentos, int min, int max, char mensajeError[], float *pNumeroIngresado) {

	int retorno = -1;
	float auxiliarFloat;
	int retornoScanf;

	if (mensaje != NULL && min < max && mensajeError != NULL && pNumeroIngresado != NULL && reintentos > 0)
	{
		printf("%s", mensaje);
		retornoScanf = scanf("%f", &auxiliarFloat);
		do {

			if (retornoScanf != 1 || auxiliarFloat > max || auxiliarFloat < min)
			{
				printf("%s ERROR: \n", mensajeError);
				retornoScanf = scanf("%f", &auxiliarFloat);
				reintentos--;
			} else {
				reintentos = 0;
				*pNumeroIngresado = auxiliarFloat;
				retorno = 0;
			}

		} while (reintentos>0);
	}
	return retorno;
}

int input_getCharacter(char *pCaracterIngresado, char mensaje[], char mensajeError[], char min, char max, int reintentos) {

	int retorno = -1;
	char buffer;

	if( pCaracterIngresado != NULL && mensajeError != NULL && min <= max && reintentos >= 0)
	{
		do {
			printf("%s", mensaje);
			scanf("%c", &buffer);

			if( buffer >= min && buffer <= max )
			{
				*pCaracterIngresado = buffer;
				retorno = 0;
			} else {
				printf("%s \n", mensajeError);
				reintentos--;
			}
		} while(reintentos>=0);
	}

	return retorno;
}

int input_opcionMenu() {

	int opcionElegida;

	printf("\n************-MENU-***********\n");
	printf("\n 1) Ingresar Kilómetros");
	printf("\n 2) Ingresar precio de Vuelos");
	printf("\n 3) Calcular todos los costos");
	printf("\n 4) Informar Resultados");
	printf("\n 5) Carga forzada de datos");
	printf("\n 6) Salir");
	printf("\n****************************\n");

	input_getInt("\n Ingrese una opción del menú (entre 1 y 6): ",1, 1, 6, "ERROR! Debe ingresar un número entre 1 y 6: ", &opcionElegida);

	return opcionElegida;
}


