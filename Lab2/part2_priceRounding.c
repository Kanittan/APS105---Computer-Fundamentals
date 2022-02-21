/* Title: Lab 2 (Part 2) */
/* Date: 21/01/2021 */
/* Name: Kanit Mongkonrattanachai */
/* UofT Student Number: 1007390538 */

/* Program: Rounds an inputted price to the nearest nickel. */


#include <stdio.h>  /* stdio.h library allows for printf() function. */
#include <math.h>   /* math.h library allows for round() function. */

int main(int argc, char **argv)
{
    float inputNum1, inputNum2;                  /* Input Variable */
    float priceInNickelNum1, priceInDollarNum1;  /* Computation Variable */
    
    printf("Enter the price as a float with two decimals: ");
    scanf("%f",&inputNum1);                      
    
    priceInNickelNum1 = round((inputNum1)*20);   /* Use round() function to round to nearest nickel */
    priceInDollarNum1 = (priceInNickelNum1)/20;  /* Convert back to Dollar. Use float variable to display answer in 2 decimal places.*/
    
    printf("The total charge is: %.2f\n", priceInDollarNum1);
    
    return 0;
}