
#include "tp.h"
int SumarValores(int valorA,int valorB)
{
    int suma;

    suma= valorA+valorB;
    return suma;

}
int  RestarValores(int valorA, int valorB)
{
    int resta;
    resta=valorA-valorB;

    return resta;
}
int DividirValores(int valorA,int valorB)
{

    float division;
    if(valorB!=0)
    {
        division=valorA/valorB;
    }
    else
    {
        printf("no se puede dividir por CERO\n");
        system("pause");
    }


    return division;
}
int MultiplicarValores(int valorA,int valorB)
{
    long long int multiplicacion;
    multiplicacion=valorA*valorB;

    return multiplicacion;
}
long long int HacerFactorial(int valorA)
{
    long long int resultadoA;

    resultadoA=1;
    while(valorA>1)
    {

        resultadoA*=valorA;
        valorA--;

    }

}
 long long int HacerFactorialB(int valorB)
{

    long long int resultadoB;
    resultadoB=1;
    while(valorB>1)
    {

        resultadoB*=valorB;
        valorB--;

    }

    return resultadoB;
}
