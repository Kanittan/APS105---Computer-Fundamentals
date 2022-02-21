/* Title: Lab 2 (Part 3) */
/* Date: 21/01/2021 */
/* Name: Kanit Mongkonrattanachai */
/* UofT Student Number: 1007390538 */

/* Program: Computes the Future Value of the Investment A from different input variable. */

#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
	double inputAmountDeposit, inputInterestRate, inputNumInterestCompoundedPerYear, inputTime; /* Input Variable */
    double power, futureValueOfInvestment; /* Computation Variable */
    
    /* Input Information for each variable */
    printf("The amount deposited P: ");
    scanf("%lf",&inputAmountDeposit);
    
    printf("The interest rate r: ");
    scanf("%lf", &inputInterestRate);
    
    printf("The number of times the interest is compounded n: ");
    scanf("%lf", &inputNumInterestCompoundedPerYear);
    
    printf("The period of time t the money is invested (in years): ");
    scanf("%lf", &inputTime);
    
    
    /* Calculates the Future value of Investent A */
    power = (inputNumInterestCompoundedPerYear)*(inputTime);
    futureValueOfInvestment = (inputAmountDeposit)*(pow((1 + ((inputInterestRate)/(inputNumInterestCompoundedPerYear))),(power)));
    
    
    printf("The future value of the investment A: %.2lf\n", futureValueOfInvestment);
    
    return 0;
}