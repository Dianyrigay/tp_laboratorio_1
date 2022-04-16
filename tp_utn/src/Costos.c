/*
 * Input.c
 *
 *  Created on: 5 abr. 2022
 *      Author: diany
 */

#include "Costos.h"

int costo_tarjetaDebito(float precioVuelo, float *precioDebito, float descuento) {

	float descuentoTotal;
	int retorno = -1;

	if( precioDebito != NULL && descuento !=0 )
	{
		descuentoTotal = descuento * (precioVuelo/100);
		*precioDebito = precioVuelo - descuentoTotal;

		retorno = 0;
	}

	return retorno;
}


int costo_tarjetaCredito(float precioVuelo, float *precioCredito, float interes) {

	int retorno = -1;
	float interesTotal;

	if( precioCredito != NULL && interes !=0 )
	{
		interesTotal = interes * (precioVuelo/100);
		*precioCredito = precioVuelo + interesTotal;
		retorno = 0;
	}

	return retorno;
}

int costo_bitcoin(float precioVuelo, float *precioBitcoin, float valorBitcoin) {

	int retorno = -1;

	if( precioBitcoin != NULL && valorBitcoin !=0 )
	{
			*precioBitcoin = precioVuelo / valorBitcoin;
			retorno = 0;
	}

	return retorno;
}

int costo_unitario(float precioVuelo, float kmIngresados, float *precioUnitario) {

	int retorno = -1;
	if( precioUnitario != NULL && kmIngresados !=0 )
	{
		*precioUnitario = precioVuelo / kmIngresados;
		retorno = 0;
	}

	return retorno;
}

int diferenciaVuelos(float precioLatam, float precioAerolineas, float *diferenciaPrecios){

	int retorno =-1;

	if( precioLatam > precioAerolineas && diferenciaPrecios != NULL)
	{
		*diferenciaPrecios = precioLatam - precioAerolineas;
		retorno = 0;
	} else {
		*diferenciaPrecios = precioAerolineas - precioLatam;
	}

	return retorno;
}

int calcularCostos(float precioAerolineas, float *precioDebito, float *precioCredito, float descuento, float interes, float km, float *precioUnitario, float bitcoin, float *precioBitcoin) {

	int retorno = 0;
//	***********Calculo de costos para AEROLINEAS**********
	costo_tarjetaDebito(precioAerolineas, precioDebito, descuento);
	costo_tarjetaCredito(precioAerolineas, precioCredito, interes);
	costo_bitcoin(precioAerolineas, precioBitcoin, bitcoin);
	costo_unitario(precioAerolineas, km, precioUnitario);

	return retorno;
}

void mostrarResultados( char nombreResultados[], float precioDebito, float precioCredito, float precioBitcoin, float precioUnitario, float diferenciaPrecios ) {

	printf("\n------------------%s----------------", nombreResultados);
	printf("\n a) Precio con tarjeta de débito: %f", precioDebito);
	printf("\n b) Precio con tarjeta de crédito: %f", precioCredito);
	printf("\n c) Precio pagando con Bitcoin: %f", precioBitcoin);
	printf("\n d) Precio unitario: %f \n", precioUnitario);
	printf("\n d) La diferencia de precios es: %f", diferenciaPrecios);
	printf("\n------------------------------------\n");
}

