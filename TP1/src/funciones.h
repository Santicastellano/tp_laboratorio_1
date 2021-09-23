/*
 * funciones.h
 *
 *  Created on: 9 sept. 2021
 *      Author: santi
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#define HECHO 1
#define NO_HECHO 0


//ponerle nombre a los parametros

void LimpiarConsola();
void menu(int* opcion, float primerNumero, float segundoNumero, int flag);
float CargarNumero(char* mensaje);
float SumarNumeros(float primerNumero, float segundoNumero);
float RestarNumeros(float primerNumero, float segundoNumero);
float MultiplicarNumeros(float primerNumero, float segundoNumero);
float DividirNumeros(float primerNumero, float segundoNumero);
unsigned long factorial(float numero);


#endif /* FUNCIONES_H_ */
