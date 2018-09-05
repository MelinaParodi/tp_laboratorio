#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"



void printMenu(int x, int y);
void readNumber(int* number);
void printResults(int resultAddition, int resultSubstraction, float resultDivision, int resultMultiplication, int resultFactorialA, int resultFactorialB, int flagDivisionZero );


int main(void)
{
    int x=0; // se declara la variable x
    int y=0; // se declara la variable y
    int resultAddition=0; // guarda el resultado de la suma
    int resultSubstraction=0; // guarda el resultado de la resta
    float resultDivision=0; // guarda el resultado de la division
    int resultMultiplication=0; // guarda el resultado de la multipliacion
    int resultFactorialA=0; // guarda el resultado de factorial A
    int resultFactorialB=0;// guarda el resultado de factorial B
    int flagEnd=0; // guarda para 0 = seguir, 1=salir
    int flagDivisionZero=1;// representa con un 0
    do
    {

        int option; //Variable que representa opcion que eligio el usuario


        printMenu(x, y);


        printf("Ingrese la opcion que desea: ");
        scanf("%d",&option);


        switch(option)
        {
        case 1:
            readNumber(&x);
            break;

        case 2:
            readNumber(&y);
            break;

        case 3:
            printf("\ta. Calcular la suma (A+B)\n");
            printf("\tb. Calcular la resta (A-B)\n");
            printf("\tc. Calcular la division (A/B)\n");
            printf("\td. Calcular la multiplicacion (A*B)\n");
            printf("\td. Calcular el factorial(A!)\n");
            resultAddition = add(x,y);
            resultSubstraction = substract(x,y);
            if(y==0)
            {
                flagDivisionZero = 1;
            }
            else
            {
                flagDivisionZero = 0;
                resultDivision = divide(x,y);
            }
            resultMultiplication = multiply (x,y);
            resultFactorialA = factorial(x);
            resultFactorialB = factorial (y);
            break;

        case 4:
            printResults( resultAddition, resultSubstraction, resultDivision, resultMultiplication, resultFactorialA, resultFactorialB, flagDivisionZero );
            break;

        case 5:
            flagEnd = 1;
        }
    }
    while(flagEnd==0);

    return 0;
}


void printMenu(int x, int y) //por valor
{
    printf("1. Ingresar 1er operando (A=%d)\n", x);
    printf("2. Ingresar 2do operando (B=%d)\n", y);
    printf("3. Calcular todas las operaciones\n");
    printf("4. Informar resultados\n");
    printf("5. Salir\n\n");
}


void readNumber(int* pnumber) // por referencia
{

    printf("Ingrese el valor del operando: ");

    scanf("%d",pnumber);
}

void printResults(int resultAddition, int resultSubstraction, float resultDivision, int resultMultiplication, int resultFactorialA, int resultFactorialB, int flagDivisionZero )
{
    printf("a. El resultado de A+B es: %d\n", resultAddition);
    printf("b. El resultado de A-B es: %d\n", resultSubstraction);
    if(flagDivisionZero==0)
    {
        printf("c. El resultado de A/B es: %.2f\n", resultDivision);
    }
    else
    {
        printf("c. No es posible dividir por cero.\n");
    }
    printf("d. El resultado de A*B es: %d\n", resultMultiplication);
    printf("e. El factorial de A es: %d y El factorial de B es: %d\n", resultFactorialA, resultFactorialB);
}
