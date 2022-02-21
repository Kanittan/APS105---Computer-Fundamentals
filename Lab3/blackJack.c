/* Title: Lab 3 */
/* Date: 1/01/2021 */
/* Name: Kanit Mongkonrattanachai */
/* UofT Student Number: 1007390538 */

/* Program: Performs a Simplified Version of Blackjack between a Player and a Dealer.*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(int argc, char **argv)
{
    /* Seed Random Number Generator */
    if(argc==1)
       srand(time(NULL));
         else
            srand(atoi(argv[1]));
            

    /* Input Varaible*/
    int dealerInputNum, playerInputNum;
    
    /* Computational Varaible*/
    int dealerFirstCard, playerFirstCard;
    int dealerCardWorth, playerCardWorth;
    int currentDealerCard, currentDealerCardWorth, dealerCard, currentPlayerCard, currentPlayerCardWorth, playerCard;
    int newDealerCard, newDealerCardWorth, newPlayerCard, newPlayerCardWorth;
    
    
    /* Generate Random Numbers from 1 to 13 */
    dealerFirstCard = rand() %13 + 1;
    playerFirstCard = rand() %13 + 1;
    
    printf("First cards: player %d, dealer %d\n", playerFirstCard, dealerFirstCard);
    
    /* Worth of Player Number*/
    switch(playerFirstCard)
    {
        case 11: playerCardWorth = 10;
            break;
        case 12: playerCardWorth = 10;
            break;
        case 13: playerCardWorth = 10;
            break;
        default: playerCardWorth = playerFirstCard;
            break;
    }
    
    /* Worth of Dealer Number*/
    switch(dealerFirstCard)
    {
        case 11: dealerCardWorth = 10;
            break;
        case 12: dealerCardWorth = 10;
            break;
        case 13: dealerCardWorth = 10;
            break;
        default: dealerCardWorth = dealerFirstCard;
            break;
    }
    
    
    /*Algorithm Computation for Player: Gives random number based on Player's decision.*/
    while(playerCardWorth <= 21)
    {
        printf("Type 1 for Hit, 0 to Stay:");
        scanf("%d", &playerInputNum);
        
        if(playerInputNum == 1)
        {
            newPlayerCard = rand() %13 + 1;
            switch(newPlayerCard)
            {
            case 11: newPlayerCardWorth = 10;
                break;
            case 12: newPlayerCardWorth = 10;
                break;
            case 13: newPlayerCardWorth = 10;
                break;
            default: newPlayerCardWorth = newPlayerCard;
                break;
            }
            playerCardWorth =  playerCardWorth + newPlayerCardWorth;
            printf("Player gets a %d, worth is %d\n", newPlayerCard, playerCardWorth);
        }
        
        if(playerInputNum == 0)
        {
            break;
        }

    }
    if(playerCardWorth > 21)
    {
        printf("Player over 21, Dealer wins\n");
    }
    
    if(playerCardWorth <= 21)
    {
        printf("Dealer gets:");
        while(dealerCardWorth <= 17)       /*Game Algorithm for Dealer*/
        {
            newDealerCard = rand() %13 + 1;
            switch(newDealerCard)
            {
            case 11: newDealerCardWorth = 10;
                break;
            case 12: newDealerCardWorth = 10;
                break;
            case 13: newDealerCardWorth = 10;
                break;
            default: newDealerCardWorth = newDealerCard;
                break;
            }
            dealerCardWorth =  dealerCardWorth + newDealerCardWorth;
            printf("% d", newDealerCard);
        }
    }

    
    if(dealerCardWorth > 21)
        {
            printf("\nDealer over 21, Player wins\n");
        }
    
    
    if(dealerCardWorth == playerCardWorth)
        {
            printf("\nTie\n!");
        }
    

    if((dealerCardWorth > playerCardWorth) && (dealerCardWorth < 21))
        {
            printf("\nDealer better than Player, Dealer wins\n");
        }
    

    if ((playerCardWorth > dealerCardWorth) && (playerCardWorth < 21))
        {
            printf("\nPlayer better than Dealer, Player wins\n");
        }
}