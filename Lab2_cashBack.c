/* Title: Lab 2 (Part 1) */
/* Date: 21/01/2021 */
/* Name: Kanit Mongkonrattanachai */
/* UofT Student Number: 1007390538 */

/* Program: Computes Total Amount from the input Price and Weight of Produce with Promotion of receiving 10 cents back for every 3 dollars spent on produce.*/


#include <stdio.h>

int main(int argc, char **argv)
{
	double priceInput, weightInput;                         /* Input variable */
    double totalAmount, cashbackAmount, discountedAmount;   /* Computation variable */
    
    printf("Enter the price per pound: ");   
    scanf("%lf", &priceInput);
    
    printf("Enter the total weight: ");
    scanf("%lf", &weightInput);
    
    
    totalAmount = (priceInput) * (weightInput);   /* Calculates the Total Amount of produce and subtract by 10 cents for every 3 dollars spent.*/
    cashbackAmount = (int)(totalAmount/3) * 0.10;
    discountedAmount = totalAmount - cashbackAmount;
    
    
    printf("The total charge is: %.2lf\n", discountedAmount);   /* Display Discounted Amount to 2 decimal places.*/
    
    printf("You saved: %.2lf\n", cashbackAmount);   /* Display Cashback Amount to 2 decimal places.*/
    
    return 0;
}