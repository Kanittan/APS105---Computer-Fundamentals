/* Title: Lab 4 (Part 2) */
/* Date: 5/02/2021 */
/* Name: Kanit Mongkonrattanachai */
/* UofT Student Number: 1007390538 */

/* Program: Draws a Hollow Triangle based on the number of Rows. */


#include <stdio.h>

int main(int argc, char **argv)
{
    int numRow;        /* Input Variable */
    int i, k, space;   /* Computation Variaable */
    
	printf("Enter the number of rows in the triangle: ");
    scanf("%d", &numRow);
    
    /* Loop for Line of Number */
    for(i = 1; i <= numRow; i++)
    {
        /* Loop to print Leading Spaces in each Line. */
        for(space = 1; space <= numRow - i; space++)
        {
            printf(" ");
        }

        /* Loop to print "*" */
        for(k = 1; k <= 2*i - 1; k++)
        {
            if (k == 1 || (k == i * 2 - 1) || i == numRow )
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    
	return 0;
}