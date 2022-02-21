/* Title: Lab 1 */
/* Date: 18/01/21 */
/* Name: Kanit Mongkonrattanachai */
/* UofT Student Number: 1007390538 */
/* Program: Computes Half the Sum, Twice the Product, and Average of the 3 Inputted Numbers. */

#include <stdio.h>

int main(int argc, char **argv)
{
    double inputNumber1, inputNumber2, inputNumber3;          /* Input Variable */
    double halfSumOutput, twiceProductOutput, averageOutput;  /* Computation Variable */
    
    printf("Enter First Number: ");
    scanf("%lf", &inputNumber1);      /* Reads from Standard Input of an inputted Real Number. Then store inputted Real Number into inputNumber1 variable. */
    
    printf("Enter Second Number: ");
    scanf("%lf", &inputNumber2);      /* Reads from Standard Input of an inputted Real Number. Then store inputted Real Number into inputNumber2 variable. */
    
    printf("Enter Third Number: ");
    scanf("%lf", &inputNumber3);      /* Reads from Standard Input of an inputted Real Number. Then store inputted Real Number into inputNumber3 variable. */
    
    
    halfSumOutput = (inputNumber1 + inputNumber2 + inputNumber3) / 2;      /* Variable that adds all 3 inputted Real Number and divide by 2 to obtain Half the Sum */
	printf("Half the Sum: %.2lf\n", halfSumOutput);                        /* Prints statement in " " and replaces %.2l/f with Half the Sum to 2 decimal places */
    
    twiceProductOutput = (inputNumber1 * inputNumber2 * inputNumber3) * 2; /* Variable that multiplies all 3 inputted Real Number and multiply by 2 to obtain Twice the Product */
    printf("Twice the Product: %.2lf\n", twiceProductOutput);              /* Prints statement in " " and replaces %.2l/f with Twice the Product to 2 decimal places */
    
    averageOutput = (inputNumber1 + inputNumber2 + inputNumber3) / 3;      /* Variable that adds all 3 inputted Real Number and divide by 3 to obtain Average of the 3 Real Numbers */
    printf("Average: %.2lf\n", averageOutput);                             /* Prints statement in " " and replaces %.2l/f with Average of the 3 Real Numbers to 2 decimal places */
	return 0;
}
