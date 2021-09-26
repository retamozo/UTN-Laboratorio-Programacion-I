/*
 *  utn.c
 *  Created on: Sep 8, 2021
 *  Author: Enzo Retamozo
 */

#ifndef SRC_LIB_H_
#define SRC_LIB_H_

int getFloat(float *pResult, char *mensaje, char *mensajeError);
int division(float *pResult, float divisor, float dividendo);
int factorial(int *pResultado, float numero);
int multiplicacion(float *pResult, float primerNumero, float segundoNumero);
int resta(float *pResult, float primerNumero, float segundoNumero);
int suma(float *pResult, float primerNumero, float segundoNumero);
int getOpcion(char *mensaje, int *pOpcion, int intentos);
int handleCalculoDeOperaciones(float numero1, float numero2, float *pResultadoSuma, float *pResultadoResta, float *pResultadoMultiplicacion, float *pResultadoDivision, int *pResultadoFactorial1, int *pResultadoFactorial2);
void imprimirOperaciones(float numero1, float numero2);
void imprimirResultadosOperaciones(float numero1, float numero2, float resultadoSuma, float resultadoResta, float resultadoMultiplicacion,
							float resultadoDivision, int resultadoFactorial1, int resultadoFactorial2);
#endif /* SRC_LIB_H_ */
