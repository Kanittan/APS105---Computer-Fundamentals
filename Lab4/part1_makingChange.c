/* Title: Lab 4 (Part 1) */
/* Date: 5/02/2021 */
/* Name: Kanit Mongkonrattanachai */
/* UofT Student Number: 1007390538 */

/* Program: A Program that determines the number and amount of coins that can make up a specific number of cents inputted by the user.*/


#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
    int inputAmount; /* Input Varaible */
    int startingAmount, numQuarter, numDime, numNickel, numCent; /* Computational Varaible */
    
    
    /* do while Loop that determins the number and amount of coins that can make up a specific number of cents. Program repeatedly prompts for Valid Input */
    do
    {
        printf("Please give an amount in cents less than 100: ");
        scanf("%d", &inputAmount);
        
        numQuarter = 0;
        numDime = 0;
        numNickel = 0;
        numCent = 0;
        startingAmount = inputAmount;
        
        /* IF Input is Invalid.*/
        if((startingAmount <= 0) || (startingAmount > 99) || (startingAmount < 1))
        {
            printf("Goodbye");
            break;
        }
        
        while(inputAmount-25 >= 0)
        {
            inputAmount = inputAmount-25;
            numQuarter = numQuarter + 1;
        }
    
    
        while(inputAmount-10 >= 0)
        {
            inputAmount = inputAmount-10;
            numDime = numDime + 1;
        }
    
    
        while(inputAmount-5 >= 0)
        {
            inputAmount = inputAmount-5;
            numNickel = numNickel + 1;
        }
    
    
        while(inputAmount-1 >= 0)
        {
            inputAmount = inputAmount-1;
            numCent = numCent + 1;
        }
        
        if((startingAmount > 0) && (startingAmount <= 99) && (startingAmount >= 1))
        {
            printf("%d cents: ", startingAmount);
        }
    
    
        /* Number of Quarter(Singular or Plural) */
        if((numQuarter == 1) && ((numDime > 0) || (numNickel > 0) || (numCent > 0)))
        {
            printf("%d quarter", numQuarter);
            printf(", ");
        }
            
        else if(numQuarter == 1)
        {
            printf("%d quarter", numQuarter);
        }
    
        else if((numQuarter > 1) && ((numDime > 0) || (numNickel > 0) || (numCent > 0)))
        {
            printf("%d quarters", numQuarter);
            printf(", ");
        }
            
        else if(numQuarter > 1)
        {
            printf("%d quarters", numQuarter);
        }
            
        else if(numQuarter == 0)
        {
            printf("");
        }
        
    
    
        /* Number of Dime(Singular or Plural) */
        if((numDime == 1) && ((numNickel > 0) || (numCent > 0)))
        {
            printf("%d dime", numDime);
            printf(", ");
        }
            
        else if(numDime == 1)
        {
            printf("%d dime", numDime);
        }
    
        else if((numDime > 1) && ((numNickel > 0) || (numCent > 0)))
        {
            printf("%d dimes", numDime);
            printf(", ");
        }
            
        else  if(numDime > 1)
        {
            printf("%d dimes", numDime);
        }
        
        else if(numDime == 0)
        {
            printf("");
        }
    
    
        /* Number of Nickel (Singular or Plural) */
            if((numNickel == 1) && (numCent > 0))
            {
                printf("%d nickel", numNickel);
                printf(", ");
            }
            
            else if(numNickel == 1)
            {
                printf("%d nickel", numNickel);
            }
    
            else if((numNickel > 1) && (numCent > 0))
            {
                printf("%d nickels", numNickel);
                printf(", ");
            }
            
            else if((numNickel > 1) && (numCent ==0))
            {
                printf("%d nickels", numNickel);
            }
            
            
            else if(numNickel == 0)
            {
                printf("");
            }
            
    
    
        /* Number of Cent(Singular or Plural) */
            if(numCent == 1)
            {
                printf("%d cent", numCent);
            }
    
            else if(numCent > 1)
            {
                printf("%d cents", numCent);
            }
            
            else if(numCent == 0)
            {
                printf("");
            }
            
            if((startingAmount > 0) && (startingAmount <= 99) && (startingAmount >= 1))
            {
                printf(".\n");
            }

    }while((startingAmount >= 1) && (startingAmount <= 99));
    
	return 0;
}