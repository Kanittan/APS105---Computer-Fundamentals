/* Title: Lab 5 */
/* Date: 21/02/2021 */
/* Name: Kanit Mongkonrattanachai */
/* UofT Student Number: 1007390538 */

/* Program: A Program that creates a Pascal Triangle based on the the number of inputted row. */

#include <stdio.h>

//Declaration of Functions
int factorial(int);
int choose(int i, int j);

int main() 
{
    int n, result;

    do
    {
        printf("Enter the number of rows: ");
        scanf("%d", &n);
        
        if(n < 0)
        {
            break;
        }
        
        // Loop for Number of Rows
        for(int i = 0; i < n; i++)
        {
            // Loop to print Leading Spaces of each Line
            for(int space = 1; space < n - i; ++space)
            {
                printf("   ");
            }

            // Loop to print Number in each Columins of a Row
            for(int j = 0; j <= i; j++)
            {
                result = choose(i, j);
                printf("%-6d", result);
            }

            // Print New Line Character
            printf("\n");
        }    
    } while(n >= 0);
    
    return 0;
}



// Function for Computing Factorial
int factorial(int n)
{
    int product = 1;

    while(n > 0)
    {
        product = product * n;
        n = n-1;
    }

    return product;   
}



//Function for Computing Formula nCr
int choose(int i, int j)
{
    int result;
    result = factorial(i) / (factorial(j) * factorial(i-j));
    return result;
}
