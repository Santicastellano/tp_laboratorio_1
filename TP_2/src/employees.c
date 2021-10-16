/*
 * employees.c
 *
 *  Created on: 27 sept. 2021
 *      Author: santi
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayemployee.h"
#include "Inputs.h"


void initEmployees(sEmployee list[], int tam)
{
	int i;
	int contadorId=0;

	for(i=0; i<tam; i++)
	{
		list[i].isEmpty = VACIO;
		list[i].id = contadorId++;
	}

}

int employee_buscarEspacioLibre(sEmployee list[], int tam)
{
	int i;
	int index = -1;

	for(i=0; i<tam; i++)
	{
		if(list[i].isEmpty == VACIO)
		{
			index = i;
			break;
		}
	}

	return index;
}

int employee_verificarConfirmacion(char* mensaje)
{
	int retorno = -1;
	char respuesta;

	pedirCaracter(&respuesta, mensaje);
	if(respuesta == 's' || respuesta == 'S')
	{
		retorno = 0;
	}

	return retorno;
}

int employee_cargarUno(sEmployee list[], int i)
{
	int retorno = -1;

	pedirCadena(list[i].name, "Ingrese nombre: ", "nombre invalido, hasta 50 caracteres, reingrese: ", 51);
	pedirCadena(list[i].lastName, "Ingrese apellido: ", "apellido invalido, hasta 50 caracteres, reingrese: ", 51);
	pedirFlotante(&list[i].salary, "Ingrese el salario del empleado (entre 1 y 5000000): ", "Ingrese un salario valido (entre 1 y 5000000): ", 1, 5000000);
	pedirEntero(&list[i].sector, "Ingrese el sector(entre 1-5): ", "Ingrese un sector valido (entre 1-5): ", 1, 5);

	printf("\nEmpleado a agregar:\n\n%-5s %-20s %-15s %-20s %-20s\n", "ID", "name", "last name", "salary", "sector");
	employee_mostrarUno(list[i]);

	if(!employee_verificarConfirmacion("\nIngrese 's' para confirmar el alta del empleado: "))
	{
		list[i].isEmpty = OCUPADO;
		retorno = 0;
	}

	return retorno;
}

void employee_mostrarUno(sEmployee list)
{
	printf("%-5d %-20s %-15s %-20f %-20d\n", list.id, list.name, list.lastName, list.salary, list.sector);
}

int addEmployee(sEmployee list[], int tam)
{
	int index;
	int retorno=-1;
	index = employee_buscarEspacioLibre(list,  tam);

	if(index != -1)
	{
		printf("\nDando de alta un empleado...\n\n");
			if(!employee_cargarUno(list, index))
			{
				printf("\nSe dio de alta el empleado!\n\n\a");
			}
			else
			{
				printf("\nSe cancelo el alta del empleado.\n\n");
			}
			retorno = 0;
	}
	else
	{
			printf("\nError. No hay espacio disponible.\n\n");
	}
	return retorno;
}

int printEmployees(sEmployee* list, int tam)
{
	int i;

	for(i=0; i<tam; i++)
		{
			if(list[i].isEmpty == OCUPADO)
			{
				employee_mostrarUno(list[i]);
			}
		}
	return 0;
}

int findEmployeeById(sEmployee* list, int tam, int identificador)
{
	int i;
	int index;


	printEmployees(list, tam);

	printf("ingrese el id a buscar: ");
	scanf("%d" , &identificador);

	index= -1;

	for(i=0; i<tam; i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].id == identificador)
		{
			printf("buscando empleado...\n");
			employee_mostrarUno(list[i]);

			index = i;
			break;
		}
	}


	return index;
}

int subMenuModificacion(sEmployee* list, int tam)//: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
                                                 //  o Salario o Sector
{
	int retorno = -1;
	int index;
	int idIngresado;
	int opcion=0;
	sEmployee auxEmpleado;

	pedirEntero(&idIngresado, "Ingrese el ID del empleado (0-1000): ", "Reingrese el ID del empleado  (0-1000): ", 0, 1000);
	index = findEmployeeById(list, tam, idIngresado);

	if(index != -1)
	{
		printf("\empleado a modificar:\n\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "name", "last name", "salary", "sector");
		employee_mostrarUno(list[index]);
		printf("\n");

		while(opcion != 3)
		{
			auxEmpleado = list[index];
			pedirEntero(&opcion, "-------------------------------------\n"
										 "1. MODIFICAR nombre\n"
										 "2. MODIFICAR apellido\n"
					                   	 "3. MODIFICAR salario\n"
										 "4. MODIFICAR sector\n"
										 "5. ATRAS\n"
										 "-------------------------------------\n"
										 "Ingrese una opcion: ",
										 "-------------------------------------\n"
										 "1. MODIFICAR nombre\n"
										 "2. MODIFICAR apellido\n"
										 "3. MODIFICAR salario\n"
										 "4. MODIFICAR sector\n"
										 "5. ATRAS\n"
										 "-------------------------------------\n"
										 "Opcion invalida, reingrese: ", 1, 5);

			switch(opcion)
			{
			case 1:
				printf("\nEmpleado a modificar:\n\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "name", "last name", "salary", "sector");
				employee_mostrarUno(list[index]);
				pedirCadena(auxEmpleado.name, "Ingrese nuevo nombre: ", "nombre invalido, hasta 50 caracteres, reingrese: ", 51);

				if(!employee_verificarConfirmacion("\nIngrese 's' para confirmar la modificacion del empleado: "))
				{
					strcpy(list[index].name , auxEmpleado.name);
					printf("\nEmpleado %s modificado correctamente!\n\n\a", list[index].lastName);
					retorno = 0;
				}
				else
			    {
					printf("\nSe cancelo la modificacion del empleado.\n\n");
			    }

				break;
			case 2:
				printf("\nEmpleado a modificar:\n\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "name", "last name", "salary", "sector");
				employee_mostrarUno(list[index]);
				pedirCadena(auxEmpleado.lastName, "Ingrese nuevo apellido: ", "apellido invalido, hasta 50 caracteres, reingrese: ", 51);

				if(!employee_verificarConfirmacion("\nIngrese 's' para confirmar la modificacion del empleado: "))
				{
					strcpy(list[index].lastName , auxEmpleado.lastName);
					printf("\nEmpleado %s modificado correctamente!\n\n\a", list[index].lastName);
					retorno = 0;
				}
				else
			    {
					printf("\nSe cancelo la modificacion del empleado.\n\n");
			    }


				break;
			case 3:
				printf("\nEmpleado a modificar:\n\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "name", "last name", "salary", "sector");
				employee_mostrarUno(list[index]);
				pedirFlotante(&auxEmpleado.salary, "Ingrese el nuevo salario del empleado (entre 1 y 5000000): ", "Ingrese un salario valido (entre 1 y 5000000): ", 1, 5000000);

				if(!employee_verificarConfirmacion("\nIngrese 's' para confirmar la modificacion del empleado: "))
				{
					list[index].salary = auxEmpleado.salary;
					printf("\nEmpleado %s modificado correctamente!\n\n\a", list[index].lastName);
					retorno = 0;
				}
				else
			    {
					printf("\nSe cancelo la modificacion del empleado.\n\n");
				}

				break;
			case 4:
				printf("\nEmpleado a modificar:\n\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "name", "last name", "salary", "sector");
				employee_mostrarUno(list[index]);
				pedirEntero(&auxEmpleado.sector, "Ingrese el nuevo sector del empleado (entre 1 y 5000000): ", "Ingrese un sector valido (entre 1 y 5): ", 1, 5);

				if(!employee_verificarConfirmacion("\nIngrese 's' para confirmar la modificacion del empleado: "))
				{
					list[index].sector = auxEmpleado.sector;
					printf("\nEmpleado %s modificado correctamente!\n\n\a", list[index].lastName);
					retorno = 0;
				}
				else
				{
					printf("\nSe cancelo la modificacion del empleado.\n\n");
				}

				break;
			case 5:
				printf("volviendo...\n");
				break;
			default:
				printf("\nopcion invalida");

			}

		}

	}

	return retorno;
}

int removeEmployee(sEmployee* list, int tam)
{
	int retorno = -1;
	int index;
	int idIngresado;

	pedirEntero(&idIngresado, "Ingrese el ID del empleado a borrar (0-1000): ", "Reingrese el ID del empleado a borrar (0-1000): ", 0, 1000);
	index = findEmployeeById(list, tam, idIngresado);

	if(index != -1)
	{
		printf("\nempleado a borrar:\n\n%-5s %-20s %-20s %-20s %-20s\n", "ID", "name", "last name", "salary", "sector");
		employee_mostrarUno(list[index]);

		if(!employee_verificarConfirmacion("\nIngrese 's' para confirmar la baja del empleado: "))
		{
			list[index].isEmpty = VACIO;
			printf("\nempleado %s dado de baja correctamente!\n\n", list[index].lastName);
			retorno = 0;
		}
		else
		{
			printf("\nSe cancelo la baja del empleado.\n\n");
		}
	}
	else
	{
		printf("\nError. empleado no encontrado...\n\n");
	}
	return retorno;

}

int sortEmployees(sEmployee* list, int len, int order)
{
	int i;
	int j;
	int retorno =-1;
	sEmployee auxEmpleado;

	for(i=0;i<len-1;i++)
		{
			for(j=i+1 ; j<len ; j++)
			{
				if(list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
				{
					if(list[i].sector > list[j].sector || (list[i].sector == list[j].sector && strcmp(list[i].name, list[j].name)>order))
					{
						auxEmpleado = list[i];
						list[i] = list[j];
						list[j] = auxEmpleado;
						retorno = 0;
					}
				}
			}
		}
	printEmployees( list,  len);

	return retorno;
}












