/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main(void) {

	setbuf(stdout,NULL);

	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;
	unsigned long factorialA;
	unsigned long factorialB;
	float numeroA;
	float numeroB;
	int opcion;
	int banderaA;
	int banderaB;
	int bandera;
	int flagFuncion;

	numeroA=0;
	numeroB=0;
	banderaA = NO_HECHO;
	banderaB= NO_HECHO;
	flagFuncion=NO_HECHO;

	while(opcion!=5)
	{
		menu(&opcion,numeroA,numeroB, flagFuncion);
		LimpiarConsola();

		switch(opcion)
		{
		case 1:
			numeroA = CargarNumero("ingrese 1rer operando: ");
			banderaA = HECHO;
			flagFuncion = HECHO;

			break;
		case 2:
			numeroB = CargarNumero("Ingrese 2do operando: ");
			banderaB = HECHO;
			flagFuncion = HECHO;
			break;
		case 3:
			if(banderaA==HECHO && banderaB==HECHO)
			{
				resultadoSuma = SumarNumeros(numeroA , numeroB);
				resultadoResta = RestarNumeros(numeroA , numeroB);
				resultadoMultiplicacion = MultiplicarNumeros(numeroA , numeroB);
				factorialA = factorial(numeroA);
				factorialB = factorial(numeroB);

				if(numeroB != 0)
				{
					resultadoDivision = DividirNumeros(numeroA , numeroB);
				}

				bandera= HECHO;
				printf("----operaciones calculadas----\n");
			}
			else
			{
				printf("error, ingrese los operandos\n");
			}


		break;
		case 4:
			if(bandera==HECHO)
			{

				if(numeroB==0 && numeroA > 33)
				{
					printf("--RESULTADOS--\nSuma: %.2f\nResta: %.2f\nMultiplicacion: %.2f\nNo es posible dividir por CERO\nFactorial de A no se puede resolver\nFactorial de B: %ld--\a\n ", resultadoSuma, resultadoResta, resultadoMultiplicacion, factorialB );

				}
				else if(numeroB > 33 )
				{
					printf("--RESULTADOS--\nSuma: %.2f\nResta: %.2f\nMultiplicacion: %.2f\nDivision: %.3f\nFactorial de A: %ld\nFactorial de B no se puede resolver--\a\n ", resultadoSuma, resultadoResta, resultadoMultiplicacion, resultadoDivision,factorialA );
				}
				else
				{
					printf("--RESULTADOS--\nSuma: %.2f\nResta: %.2f\nMultiplicacion: %.2f\nDivision: %.3f\nFactorial de A: %ld\nFactorial de B: %ld--\a\n ", resultadoSuma, resultadoResta, resultadoMultiplicacion, resultadoDivision,factorialA, factorialB );

				}
			}else
			{
				printf("--no se calcularon las operaciones--");
			}


			break;
		case 5:
			printf("programa finalizado");
			break;
		default:
			printf("opcion invalida\n\a");
		}
	}



	return EXIT_SUCCESS;
}









