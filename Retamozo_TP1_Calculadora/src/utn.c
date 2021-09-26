/*
 * unt.c
 *
 *  Created on: Sep 11, 2021
 *      Author: Enzo Retamozo
 */

#include <stdio.h>
#include <stdlib.h>

/* brief add: Toma dos nï¿½meros por parametro y calcula una suma de ellos.
 * param pResult: direcciï¿½n de memoria  donde se guardarï¿½ el resultado de la sumatoria de ambos nï¿½meros.
 * param firstNumber: primer nï¿½mero ingresado.
 * param secondNumber: segundo nï¿½mero ingresad por el usuario.
 * return : 0 si la operaciï¿½n fue exitosa, -1 si se produjo un error.
 * */

int suma(float *pResult, float primerNumero, float segundoNumero)
{
	int _exit = -1;
	if (pResult != NULL)
	{
		*pResult = primerNumero + segundoNumero;
		_exit = 0;
	}
	return _exit;
}

/* brief resta : Toma dos numeros por parametro y calcula una resta de ellos.
 * param pResult: direcciï¿½n de memoria (variable) donde se guardarï¿½ el resultado de la resta de ambos nï¿½meros.
 * param primerNumero: primer nï¿½mero ingresado.
 * param segundoNumero: segundo nï¿½mero ingresad por el usuario.
 * return : 0 si la operaciï¿½n fue exitosa, -1 si se produjo un error.
 * */

int resta(float *pResult, float primerNumero, float segundoNumero)
{
	int _exit = -1;
	if (pResult != NULL)
	{
		*pResult = primerNumero - segundoNumero;
		_exit = 0;
	}
	return _exit;
}

/* brief multiplicacion: Toma dos nï¿½meros por parametro y calcula una multiplicaciï¿½n de ellos.
 * param pResult: direcciï¿½n de memoria (variable) donde se guardarï¿½ el resultado de la multiplicaciï¿½n de ambos nï¿½meros.
 * param firstNumber: primer nï¿½mero ingresado.
 * param secondNumber: segundo nï¿½mero ingresad por el usuario.
 * return : 0 si la operaciï¿½n fue exitosa, -1 si se produjo un error.
 * */

int multiplicacion(float *pResult, float primerNumero, float segundoNumero)
{
	int _exit = -1;
	if (pResult != NULL)
	{
		*pResult = primerNumero * segundoNumero;
		_exit = 0;
	}
	return _exit;
}

/* \ brief factorial: realizar el factorial de un nÃºmero pedido al usuario
 * \ param pResult: es un puntero al espacio de memoria donde estÃ¡ el valor obtenido del usuario
 * \ param numero: operador por el cual se debe obtener el factoreal.
 * \ retorna 0 si fue OK, -1 si hubo un error
 */

int factorial(int *pResultado, float numero)
{
	int retornar = -1;
	int bufferInt = 1;
	if(numero >= 0 && pResultado != NULL)
	{
		for(int i = 1; i <= numero; i++)
		{
			bufferInt *= i;
		}
		*pResultado = bufferInt;
		retornar = 0;
	}
	return retornar;
}

/* \ brief division: dados un divisor y un dividendo, se realiza la operaciï¿½n de divisiï¿½n de los mismos.
 * \ param pResult: es un puntero al espacio de memoria donde estï¿½ el valor obtenido del usuario.
 * \ param divisor: es el nï¿½mero a dividir.
 * \ param dividendo: es la base por la cual se dividirï¿½ al divisor.
 * return : 0 si la operaciï¿½n fue exitosa, -1 si se produjo un error.
 */

int division(float* pResult, float divisor, float dividendo)
{
	int _exit = -1;
	if(pResult != NULL)
	{
		if (dividendo != 0) {
		*pResult = divisor / dividendo;
		_exit = 0;
		} else {
			printf("No se puede dividir por 0");
		}
	}
	return _exit;
}

/**
 * \brief Solicita un número flotante al usuario
 * \param char *mensaje: Es el mensaje a ser mostrado
 * \param char *mensajeError: Es el mensaje de error en caso de que no se haya ingresado un numero
 * \param float *pNumero: Puntero que hace referencia al espacio en memoria del numero ingresado donde se guardará el nuevo valor posteriormente
 * \return 1 si hubo error, 0 si todo esta correcto
 */

int getFloat(float *pResult, char *mensaje, char *mensajeError)
{
	float auxFloat;
	int auxScanF;
	int _exit = 1;

	if(mensaje != NULL && pResult != NULL)
	{
		printf("%s", mensaje);
		fflush(stdin);
		auxScanF = scanf("%f", &auxFloat);
		while(auxScanF == 0){
			printf("%s", mensajeError);
			fflush(stdin);
			auxScanF = scanf("%f", &auxFloat);
		}
		*pResult = auxFloat;
		_exit = 0;
	}
	return _exit;
}

// Funciones auxiliares para el TP.

/**
 * \brief Este es el menu de la calculadora. Solicita una opcion (como entero)
 * \param char *mensaje: Es el mensaje a ser mostrado
 * \param int *pOpcion: Puntero que hace referencia al espacio en memoria de la opcion elegida
 * \param intentos: valor entero que funcionará como indicador de intentos. Si los sobrepasa, el programa se dentrará.
 * \return -1 si algo salio mal, 0 si todo esta correcto
 */
int getOpcion(char *mensaje, int *pOpcion, int intentos)
{
	setbuf(stdout, NULL);
	int auxScanf;
	int bufferInt;
	int _exit = -1;

	if(mensaje!=NULL && pOpcion!=NULL && intentos > 0)
	{
		do
		{
			printf("%s", mensaje);
			printf("\n 1) Ingrese el primer numero."
				   "\n 2) Ingrese el segundo numero."
	     	       "\n 3) Calcular todas las operaciones."
				   "\n 4) Informar los resultados."
				   "\n 5) Salir.\n");
		    fflush(stdin);
			auxScanf = scanf("%d", &bufferInt);
			if(auxScanf == 1)
			{
				*pOpcion = bufferInt;
				_exit = 0;
				break;
			}
			else
			{
				intentos--;
				fflush(stdin);
			}
		} while(intentos > 0);
	}
	return _exit;
}

/**
 * \brief Calculo de todas las operaciones
 * \param float primerOperando: Recibe el primer numero ingresado
 * \param float segundoOperando: Recibe el segundo numero ingresado
 * \param float *pResultadoSuma: Puntero al resultado de la suma
 * \param float *pResultadoResta: Puntero al resultado de la resta
 * \param float *pResultadoMultiplicacion: Puntero al resultado de la multiplicacion
 * \param float *pResultadoDivision: Puntero al resultado de la division
 * \param int *pResultadoFactorial1: Puntero al resultado del factorial del primer numero
 * \param int *pResultadoFactorial2: Puntero al resultado del factorial del segundo numero
 * \return si fue OK, 0. Si no, -1.
 */
int handleCalculoDeOperaciones(float numero1, float numero2, float *pResultadoSuma, float *pResultadoResta, float *pResultadoMultiplicacion, float *pResultadoDivision, int *pResultadoFactorial1, int *pResultadoFactorial2)
{
	int _exit =-1;
	float sumaResult;
	float restaResult;
	float multiplicacionResult;
	float divisionResult;
	int primerFactorialResult;
	int segundoFactorialResult;

	if(suma(&sumaResult, numero1, numero2) == 0 &&
	   resta(&restaResult, numero1, numero2) == 0 &&
	   multiplicacion(&multiplicacionResult, numero1, numero2) == 0 &&
	   pResultadoSuma!=NULL &&
	   pResultadoResta!=NULL &&
	   pResultadoMultiplicacion!=NULL)
	{
		*pResultadoSuma = sumaResult;
		*pResultadoResta = restaResult;
		*pResultadoMultiplicacion = multiplicacionResult;
	}
	if(division(&divisionResult, numero1, numero2) == 0 && pResultadoDivision!=NULL)
	{
		*pResultadoDivision = divisionResult;
	}
	if(factorial(&primerFactorialResult, numero1) == 0 && pResultadoFactorial1!=NULL)
	{
		*pResultadoFactorial1 = primerFactorialResult;
	}
	if(factorial(&segundoFactorialResult, numero2) == 0 && pResultadoFactorial2!=NULL)
	{
		*pResultadoFactorial2 = segundoFactorialResult;
	}
	_exit = 0;
	return _exit;
}

/**
 * \brief Esta funcion hace un print rápido para los cálculos.
 * \param float numero1: Recibe el primer numero y lo muestra en mensaje
 * \param float numero2: Recibe el segundo numero y lo muestra en mensaje
 */
void imprimirOperaciones(float numero1, float numero2)
{
	printf("\n Resultado de la suma %.2f + %.2f \n", numero1, numero2);
	printf("\n Resultado de la resta %.2f - %.2f \n", numero1, numero2);
	printf("\n Resultado de la multiplicacion %.2f * %.2f \n", numero1, numero2);
	printf("\n Resultado de la division %.2f / %.2f \n", numero1, numero2);
	printf("\n Resultado del factorial de %.2f y %.2f\n", numero1, numero2);
}



/**
 * \brief Imprime el resultado de la suma, resta y multiplicacion
 * \param float numero1: Recibe el primer numero
 * \param float numero2: Recibe el segundo numero
 * \param float resultadoSuma: Recibe el resultado de la suma
 * \param float resultadoResta: Recibe el resultado de la resta
 * \param float resultadoMultiplicacion: Recibe el resultado de la multiplicacion
 * \param float resultadoDivision: Recibe el resultado de la division
 * \param float resultadoFactorial1: Recibe el resultado del factorial del ENTERO del primer numero
 * \param float resultadoFactorial2: Recibe el resultado del factorial del ENTERO del segundo numero
 */
void imprimirResultadosOperaciones(float numero1, float numero2, float resultadoSuma, float resultadoResta, float resultadoMultiplicacion,
							float resultadoDivision, int resultadoFactorial1, int resultadoFactorial2)
{
	printf("\nEl resultado de %.2f + %.2f es: %.2f", numero1, numero2, resultadoSuma);
	printf("\nEl resultado de %.2f - %.2f es: %.2f", numero1, numero2, resultadoResta);
	printf("\nEl resultado de %.2f * %.2f es: %.2f", numero1, numero2, resultadoMultiplicacion);
	if(numero2 != 0)
	{
		printf("\nEl resultado de %.2f / %.2f es: %.2f", numero1, numero2, resultadoDivision);
	}
	else
	{
		printf("\nNo se puede dividir por 0");
	}
	if(numero1 >= 0)
	{
		printf("\nEl factorial del entero de %.2f es: %d", numero1, resultadoFactorial1);
	}
	else
	{
		printf("\nNo se puede hacer el factorial de un numero negativo");
	}
	if(numero2 >= 0)
	{
		printf("\nEl factorial del entero de %.2f es: %d", numero2, resultadoFactorial2);
	}
	else
	{
		printf("\nNo se puede hacer el factorial de un numero negativo");
	}
};
