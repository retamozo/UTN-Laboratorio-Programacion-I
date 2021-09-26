/*
 =================================================================
 Laboratorio de programación - TP1
 Calculadora.c
 Created on: Sep 7, 2021
 Author: Enzo Retamozo
 =================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utn.h"

#define INTENTOS 3
#define true 1
#define false 0

int main(void) {
	setbuf(stdout, NULL);
	float primerNumero;
	float segundoNumero;
	int opcionElegida;

	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	int resultadoFactorialNumero1;
	int resultadoFactorialNumero2;
	int banderaPrimerNumero = false;
	int banderaSegundoNumero = false;
	int banderaHandleOperaciones = false;


	if(getOpcion("Por favor, ingrese una opción", &opcionElegida, INTENTOS) == 0)
	{
		while(opcionElegida != 5)
		{
			switch(opcionElegida)
			{
			case 1 :
				if(getFloat(&primerNumero, "\nPor favor, ingrese el primer numero \n", "\n Ingrese un número válido\n") == 0)
				{
					 printf("Primer número ingresado : %2.f\n", primerNumero);
					 getOpcion("\nQue opcion desea ingresar? ", &opcionElegida, INTENTOS);
					 banderaPrimerNumero = true;
				}
			break;
			case 2:
				if(getFloat(&segundoNumero, "\nPor favor, ingrese el segundo numero \n", "\n Ingrese un número válido\n") == 0)
				{
					printf("\nPrimer número ingresado : %2.f\n", segundoNumero);
					getOpcion("\nQue opcion desea ingresar?\n", &opcionElegida, INTENTOS);
					banderaSegundoNumero = true;
				}
			break;
			case 3:
				if(banderaPrimerNumero && banderaSegundoNumero)
				{
					if(handleCalculoDeOperaciones(primerNumero, segundoNumero, &resultadoSuma,
							&resultadoResta, &resultadoMultiplicacion, &resultadoDivision,
							&resultadoFactorialNumero1, &resultadoFactorialNumero2 ) == 0)
					{
						imprimirOperaciones(primerNumero, primerNumero);
						banderaHandleOperaciones = true;
					}
				}
				else
				{
					printf("\nPara poder realizar las operaciones, debe ingresar 2 numeros\n");
				}
				getOpcion("\nPor favor, ingrese nuevamnete una opción\n", &opcionElegida, INTENTOS);
			break;
			case 4:
				if(banderaPrimerNumero && banderaSegundoNumero && banderaHandleOperaciones)
				{
					imprimirResultadosOperaciones(primerNumero, segundoNumero, resultadoSuma, resultadoResta, resultadoMultiplicacion, resultadoDivision, resultadoFactorialNumero1, resultadoFactorialNumero2);

				}
				else
				{
					printf("\n Vuelva a realizar los pasos anteriores. \n");
				}
				getOpcion("\nPor favor, ingrese nuevamnete una opción\n", &opcionElegida, INTENTOS);
			break;
			default:
				getOpcion("\nOpción no valida. \n", &opcionElegida, INTENTOS);
			break;
			}
		}
		printf("\nSaliendo del programa.\n");
	};
	return EXIT_SUCCESS;
};
