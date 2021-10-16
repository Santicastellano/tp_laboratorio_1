/*
 * arrayemployee.h
 *
 *  Created on: 27 sept. 2021
 *      Author: santi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#ifndef ARRAYEMPLOYEE_H_
#define ARRAYEMPLOYEE_H_
#define VACIO 0
#define OCUPADO 1
#define TAM 1000

typedef struct
{

 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;

}sEmployee;

/**
 * @fn void initEmployees(sEmployee[], int)
 * @brief  inicializa todos las posiciones del array de empleados del campo isEmpty en 0=VACIO
 *
 * @param sEmployee list
 * @param int tam
 */
void initEmployees(sEmployee list[], int tam);

/**
 * @fn int employee_buscarEspacioLibre(sEmployee[], int)
 * @brief retorna un index con la posicion de encontrada que se encuentre vacia.
 *
 * @param sEmployee list
 * @param int tam
 * @return la primer posicion libre del array en el campo isEmpty.
 */
int employee_buscarEspacioLibre(sEmployee list[], int tam);

/**
 * @fn int employee_verificarConfirmacion(char*)
 * @brief se le manda un mensaje que luego sera impreso en pantalla. Utilizado para verificar una operacion.
 *
 * @param puntero char mensaje
 * @return retorna 0 si apretas "S" o "s", sino retorna -1.
 */
int employee_verificarConfirmacion(char* mensaje);

/**
 * @fn int employee_cargarUno(sEmployee[], int)
 * @brief  completa los datos de toda la estructura sEmployee.
 *
 * @param sEmployee list
 * @param int i
 * @return retorna 0 si pudieron cargarse los datos, caso contrario retorna -1
 */
int employee_cargarUno(sEmployee list[], int i);

/**
 * @fn void employee_mostrarUno(sEmployee)
 * @brief imprime por pantalla los datos de un empleado en especifico
 *
 * @param sEmployeelist
 */
void employee_mostrarUno(sEmployee list);

/**
 * @fn int addEmployee(sEmployee[], int)
 * @brief guarda los datos de un empleado y los carga en el programa si hay espacio disponible.
 *
 * @param sEmployee list
 * @param int tam
 * @return retorna 0 si pudo cargar los datos, caso contrario retorna -1
 */
int addEmployee(sEmployee list[], int tam);

/**
 * @fn int printEmployees(sEmployee*, int)
 * @brief imprime todos los datos de los empleados que esten cargados en el sistema
 *
 * @param  sEmployee list
 * @param int tam
 * @return
 */
int printEmployees(sEmployee* list, int tam);


/**
 * @fn int findEmployeeById(sEmployee*, int, int)
 * @brief le cargas un id y busca si ese id ya existe en un empleado cargado
 *
 * @param sEmployee list
 * @param int tam
 * @param int identificador
 * @return retorna la posicion en la que se encontro el id
 */
int findEmployeeById(sEmployee* list, int tam, int identificador);


/**
 * @fn int subMenuModificacion(sEmployee*, int)
 * @brief se despliega un menu con 4 opciones para modificar los datos de los empleados.
 *
 * @param sEmployee list
 * @param int tam
 * @return retorna 0 si se pudo realizar la operacion caso contrario retorna -1
 */
int subMenuModificacion(sEmployee* list, int tam);

/**
 * @fn int removeEmployee(sEmployee*, int)
 * @brief a partir de un id ingresado, se busca al empleado correspondiente y se le da una baja logica del sistema
 *
 * @param sEmployee list
 * @param int tam
 * @return retorna 0 si se pudo realizar la operacion, caso contrario retorna -1
 */
int removeEmployee(sEmployee* list, int tam);

/**
 * @fn int sortEmployees(sEmployee*, int, int)
 * @brief genera un listado de los empleados ordenados por apellido y sector
 *
 * @param sEmployee list
 * @param int tam
 * @param int order
 * @return
 */
int sortEmployees(sEmployee* list, int tam, int order);


#endif /* ARRAYEMPLOYEE_H_ */















