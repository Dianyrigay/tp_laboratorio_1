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
#include "Input.h"


int costo_tarjetaDebito(float precioVuelo, float *precioDebito, float descuento);
int costo_tarjetaCredito(float precioVuelo, float *precioCredito, float interes);
int costo_bitcoin(float precioVuelo,  float *precioBitcoin, float valorBitcoin);
int costo_unitario(float precioVuelo, float kmIngresados, float *precioUnitario);
int diferenciaVuelos(float precioLatam, float precioAerolineas, float *diferenciaPrecios);

int calcularCostos(float precioAerolineas, float *precioDebito, float *precioCredito, float descuento, float interes, float km, float *precioUnitario, float bitcoin, float *precioBitcoin);
void mostrarResultados(char nombreResultados[], float precioDebito, float precioCredito, float precioBitcoin, float precioUnitario, float diferenciaVuelos);

void cargaForzada(float kmForzado,float aerolineasForzado,float latamForzado, float descuento, float interes, float bitcoin, float *debitoForzado, float *creditoForzado, float *bitcoinForzado, float *unitarioForzado, float *diferenciaForzada);
#endif /* INPUT_H_ */
