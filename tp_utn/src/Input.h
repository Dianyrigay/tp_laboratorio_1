/*
 * Input.h
 *
 *  Created on: 5 abr. 2022
 *      Author: diany
 */

#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include "Costos.h"

int input_getInt(char mensaje[], int reintentos, int min, int max, char mensajeError[], int *pNumeroIngresado);
int input_getFloat(char mensaje[], int reintentos, int min, int max, char mensajeError[], float *pNumeroIngresado);
int input_opcionMenu();

#endif /* INPUT_H_ */
