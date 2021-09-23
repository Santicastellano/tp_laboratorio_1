/*
 * funciones.c
 *
 *  Created on: 9 sept. 2021
 *      Author: santi
 */
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @fn void LimpiarConsola()
 * @brief
 * la funcion ejecuta 13 saltos de linea.
 */
void LimpiarConsola()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

/**
 * @fn void menu(int*, float, float, int)
 * @brief
 * la funcion muestra el menu que va a aparecer cuando se inicia el programa.
 * @param opcion
 * @param primerNumero
 * @param segundoNumero
 * @param flag
 */
void menu(int* opcion, float primerNumero, float segundoNumero, int flag)
{
	if(!flag)
	{
		printf("\n-------------------------------\n");
		printf("Elija una opcion:\n1. Ingresar primer operando(A=x)\n2. Ingresar segundo operando(B=y)\n3. Calcular todas las operaciones\n4. informar resultados\n5. SALIR\nopcion: ");
		scanf("%d", opcion);
		printf("\n-------------------------------\n");
	}
	else
	{
		printf("\n-------------------------------\n");
		printf("Elija una opcion:\n1. Ingresar primer operando(A=%.2f)\n2. Ingresar segundo operando(B=%.2f)\n3. Calcular todas las operaciones\n4. informar resultados\n5. SALIR\nopcion: ",primerNumero, segundoNumero);
		scanf("%d", opcion);
		printf("\n-------------------------------\n");

	}

}

/**
 * @fn float CargarNumero(char*)
 * @brief
 * la funcion carga un numero flotante y lo retorna.
 * @param mensaje
 * @return float
 */
float CargarNumero(char* mensaje )
{
	float numero;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%f", &numero);

	return numero;
}

/**
 * @fn float SumarNumeros(float, float)
 * @brief
 * la funcion recibe 2 numeros flotantes, los suma y retorna el resultado.
 * @param primerNumero
 * @param segundoNumero
 * @return float
 */
float SumarNumeros(float primerNumero , float segundoNumero)
{
	float resultado;
	resultado = primerNumero+segundoNumero;

	return resultado;
}

/**
 * @fn float RestarNumeros(float, float)
 * @brief
 * la funcion recibe 2 numeros flotantes, los resta y retorna el resultado.
 * @param primerNumero
 * @param segundoNumero
 * @return float
 */
float RestarNumeros(float primerNumero, float segundoNumero)
{
	float resultado;
	resultado = primerNumero-segundoNumero;

	return resultado;


}

/**
 * @fn float MultiplicarNumeros(float, float)
 * @brief
 * la funcion recibe 2 numeros flotantes, los multiplica y retorna el resultado.
 * @param primerNumero
 * @param segundoNumero
 * @return float
 */
float MultiplicarNumeros(float primerNumero, float segundoNumero)
{
	float resultado;
	resultado = primerNumero*segundoNumero;

	return resultado;

}

/**
 * @fn float DividirNumeros(float, float)
 * @brief
 * la funcion recibe 2 numeros flotantes, los divide y retorna el resultado.
 * @param primerNumero
 * @param segundoNumero
 * @return float
 */
float DividirNumeros(float primerNumero, float segundoNumero)
{
	float resultado;

	resultado = primerNumero/segundoNumero;

	return resultado;
}

/**
 * @fn unsigned long factorial(float)
 * @brief
 * la funcion recibe 1 numero flotante, y en caso de que el numero sea distinto de 0 o 1 calcula el factorial y retorna un long.
 * @param numero
 * @return unsigned long
 */
unsigned long factorial(float numero)
{
	unsigned long fact;


	if(numero == 0 || numero == 1)
	{
		fact=1;
	}
	else
	{
		fact = numero * factorial(numero-1);
	}
	if(numero>33)
	{
		fact=0;
	}


	return fact;
}






