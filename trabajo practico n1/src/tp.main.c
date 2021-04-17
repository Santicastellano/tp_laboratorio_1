#include <stdio.h>
#include <stdlib.h>
#include "tp.h"

/*
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

int SumarValores(int valorA, int valorB);
int RestarValores(int valorA, int valorB);
int DividirValores(int valorA, int valorB);
int MultiplicarValores(int valorA, int valorB);
long long int HacerFactorial(int valorB);
long long int HacerFactorialB(int valorA);

int main()
{

    int valorA;
    int valorB;
    int opcion;
    long long int resultadoSuma;
    long long int resultadoResta;
    float resultadoDivision;
    long long int resultadoMultiplicacion;
    long long int resultadoFactorial;
    long long int resultadoFactorialB;


        printf("1. ingrese el primer operando\n");
        scanf("%d", &valorA);
        printf("2. ingrese el segundo operando\n");
        scanf("%d", &valorB);
    do
    {


    //Calcular la suma (A+B)

        printf("3. Calcular todas las operaciones\n");
        /*printf(" a- Calcular la suma (A+B)\n");
        printf(" b- Calcular la resta (A-B)\n");
        printf(" c- Calcular la division (A/B)\n");
        printf(" d- Calcular la multiplicacion (A*B)\n");
        printf(" e-Calcular la multiplicacion (A*B)\n");*/
        printf("4. Informar resultados\n");
        printf("5. SALIR\n");
        scanf("%d", &opcion);


        switch(opcion)
        {

        case 3://suma
            resultadoSuma= SumarValores(valorA, valorB);
            resultadoResta=  RestarValores(valorA, valorB);
            resultadoDivision= DividirValores(valorA, valorB);
            resultadoMultiplicacion= MultiplicarValores(valorA, valorB);
            resultadoFactorial= HacerFactorial(valorA);
            resultadoFactorialB= HacerFactorialB(valorB);
            //4 * 3 * 2 * 1, que es igual a 24.

        break;
        case 4://resta
            printf("los reesultados son: ");
            printf("suma= %lld\n", resultadoSuma);
            printf("resta= %lld\n", resultadoResta);
            printf("division= %f\n", resultadoDivision);
            printf("multiplicacion= %lld\n", resultadoMultiplicacion);
            printf("el factorial de A es= %lld el factorial de B es= %lld\n",resultadoFactorial,resultadoFactorialB );

        break;

        }



    }while(opcion!=5);
}
