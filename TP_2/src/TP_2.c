/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "arrayemployee.h"

int main(void) {
	setbuf(stdout, NULL);

	sEmployee arrayEmpleados[TAM];
	int opcion;
	int flagFuncion;
	//int index;

	initEmployees(arrayEmpleados, TAM);

	while(opcion != 5)
	{
		pedirEntero(&opcion, "-------------------------------------\n"
									 "1. ALTA empleado\n"
									 "2. MODIFICACION empleado\n"
									 "3. BAJA empleado\n"
									 "4. LISTADO empleado\n"
									 "5. SALIR\n"
									 "-------------------------------------\n"
									 "Ingrese una opcion: ",
									 "-------------------------------------\n"
									 "1. ALTA empleado\n"
									 "2. MODIFICACION empleado\n"
									 "3. BAJA empleado\n"
									 "4. LISTADO empleados\n"
									 "5. SALIR\n"
									 "-------------------------------------\n"
									 "Opcion invalida, reingrese: ", 1, 5);

		switch(opcion)
		{
		case 1:
			flagFuncion = addEmployee(arrayEmpleados, TAM);

			break;
		case 2:
			if(flagFuncion == 0 )
			{
				subMenuModificacion(arrayEmpleados, TAM);
			}
			else
			{
				printf("primero debe dar de alta un empleado\n");
			}
			break;
		case 3:
			if(flagFuncion == 0)
			{
				removeEmployee(arrayEmpleados, TAM);
			}
			else
			{
				printf("primero debe dar de alta un empleado\n");
			}
			break;
		case 4:
			if(flagFuncion == 0)
			{
				sortEmployees(arrayEmpleados, TAM, 0);
			}
			else
			{
				printf("Primero debe dar de alta un empleado");
			}

			break;
		case 5:
			printf("finalizando programa...\n-------------------------------------\n----programa finalizado----\n");
			break;
		default:
			printf("ingrese una opcion valida");
		}
	}

	return EXIT_SUCCESS;
}


















