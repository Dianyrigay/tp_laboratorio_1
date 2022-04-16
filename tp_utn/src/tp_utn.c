/*
 ============================================================================
 Name        : tp_utn.c
 Author      : Dianyeli Yrigay
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//#include <stdio.h>
//#include <stdlib.h>

#include "Costos.h"
#include "Input.h"

#define bitcoin 4606954.55
#define	kmForzado 7090
#define	aerolineasForzado 162965
#define	latamForzado 159339

int input_getFloat(char mensaje[], int reintentos, int min, int max, char mensajeError[], float *pNumeroIngresado);
int input_opcionMenu();

int main(void) {
	setbuf(stdout, NULL);

	int opcionElegida;

	float kilometros;
	float precioAerolineas;
	float precioLatam;

	float debitoAer;
	float creditoAer;
	float bitcoinAer;
	float unitarioAer;

	float debitoLat;
	float creditoLat;
	float bitcoinLat;
	float unitarioLat;

	float diferenciaPrecios;

	float debitoForzado_Aer;
	float creditoForzado_Aer;
	float bitcoinForzado_Aer;
	float unitarioForzado_Aer;

	float debitoForzado_Lat;
	float creditoForzado_Lat;
	float bitcoinForzado_Lat;
	float unitarioForzado_Lat;

	float diferenciaForzada;

	int kmIngresados = -1;
	int preciosIngresados = -1;
	int costosCalculados = -1;

	do {
		opcionElegida = input_opcionMenu();

		switch (opcionElegida) {
		case 1:
			if ( input_getFloat("Ingrese los km (entre 1 y 5000): ", 1, 1, 5000 , "Debe ingresar entre 1 y 5000 km: ", &kilometros) == 0 ){
				kmIngresados = 0;
			}
			break;
		case 2:
			if (input_getFloat("Ingrese precio de vuelo Aerolineas: ", 1, 1, 100000, "Debe ingresar entre 1 y 5000 km: ", &precioAerolineas) == 0 &&
				input_getFloat("Ingrese precio de vuelo Latam: ", 1, 1, 100000 , "Debe ingresar entre 1 y 5000 km: ", &precioLatam) == 0)
			{
				preciosIngresados = 0;
			}
			break;
		case 3:
			if( kmIngresados == 0 && preciosIngresados == 0 ) {
				calcularCostos(precioAerolineas, &debitoAer, &creditoAer, 10, 25, kilometros, &unitarioAer, bitcoin, &bitcoinAer);
				calcularCostos(precioLatam, &debitoLat, &creditoLat, 10, 25, kilometros, &unitarioLat, bitcoin, &bitcoinLat);
				diferenciaVuelos(precioLatam, precioAerolineas, &diferenciaPrecios);

				costosCalculados = 0;
			} else {
				printf("Debe completar los primeros dos pasos para poder calcular los costos. \n");
			}
			break;
		case 4:
			if(costosCalculados == 0) {
				mostrarResultados("AEROLINEAS", debitoAer, creditoAer,  bitcoinAer,  unitarioAer,  diferenciaPrecios );
				mostrarResultados("LATAM", debitoLat, creditoLat,  bitcoinLat,  unitarioLat, diferenciaPrecios );
			} else {
				printf("Los costos deben ser calculados para poder mostrar los resultados. \n");
			}
			break;
		case 5:
			calcularCostos( aerolineasForzado, &debitoForzado_Aer, &creditoForzado_Aer, 10, 25, kmForzado, &unitarioForzado_Aer, bitcoin, &bitcoinForzado_Aer);
			calcularCostos( latamForzado, &debitoForzado_Lat, &creditoForzado_Lat, 10, 25, kmForzado, &unitarioForzado_Lat, bitcoin, &bitcoinForzado_Lat);

			diferenciaVuelos(aerolineasForzado, latamForzado, &diferenciaForzada);
			mostrarResultados("CARGA FORZADA AER", debitoForzado_Aer,  creditoForzado_Aer,  bitcoinForzado_Aer,  unitarioForzado_Aer,  diferenciaForzada);
			mostrarResultados("-", debitoForzado_Lat,  creditoForzado_Lat,  bitcoinForzado_Lat,  unitarioForzado_Lat,  diferenciaForzada);
			break;
		case 6:
			printf("\n SALISTE DEL MENÚ");
			break;
		}
	} while (opcionElegida != 6);

	return EXIT_SUCCESS;
}


