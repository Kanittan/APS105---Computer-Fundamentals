#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARDROWS 9
#define BOARDCOLS 11

bool dumpComputer = false; //causes dump of computer board before game if true (for debugging)


// boards. 0 means empty, non-zero means ship is there, number is size, -tive means hit on a ship

int playerBoard[BOARDROWS+1][BOARDCOLS+1];

int computerBoard[BOARDROWS+1][BOARDCOLS+1];

int compShotBoard[BOARDROWS+1][BOARDCOLS+1];


int getRand(int lowval,int highval){
    
    return (rand()%(highval+1-lowval) + lowval);

    }


int getShot(bool fromUser, int board[BOARDROWS+1][BOARDCOLS+1]){

    int row,col;

    while(1){

        if(fromUser){

            printf("Give a shot (row, col):");

            scanf("%d%d",&row,&col);

            if(col<1 || col > BOARDCOLS || row < 1 || row > BOARDROWS)

                printf("Invalid input\n");

            else  //valid input

                break;

        }

        else { //computer generated

            row=getRand(1,BOARDROWS);

            col=getRand(1,BOARDCOLS);
            

            if(compShotBoard[row][col]==0) { //make sure haven't shot here before

                compShotBoard[row][col]=1; //valid shot

                break;

            }

        }

    } //will leave this loop with valid input

    if(board[row][col] != 0){

        if(board[row][col]>0)

            board[row][col]= -1*board[row][col]; //make sure is -tive

        return -1*board[row][col]; //a hit!

    }

    return 0; //miss

}

            



bool allShipsNotHit(int board[BOARDROWS+1][BOARDCOLS+1]){

    for(int i=1;i<=BOARDROWS;i++){

        for(int j=1;j<=BOARDCOLS;j++){

            if(board[i][j]>0) //ship and not hit

                return(true);

        }

    }

    return (false); //no ships found not all hit

}



bool noneLeft(int valueToFind,int board[BOARDROWS+1][BOARDCOLS+1]){

    for(int i=1;i<=BOARDROWS;i++){

        for(int j=1;j<=BOARDCOLS;j++){

            if(board[i][j]==valueToFind) //ship and not hit

                return(false);

        }

    }

    return (true); //no ships found, all hit

}



void populateBoard(bool getUserInput, int board[BOARDROWS+1][BOARDCOLS+1]){



    //******* YOUR CODE GOES HERE TO POPULATE THE BOARDS

    //**** use subroutines (other functions you generate) to make your code easier to understand and more organized

    //**** do not (permanently) alter any other code please
    
    int startingRow, startingCol, orientation;
    
    if(getUserInput == true)
    {
        
        int shipSize=5; 
       
            do
            {
                printf("Give starting row, starting column and orientation (3 inputs) for ship of size=%d:", shipSize);
                scanf("%d%d%d", &startingRow, &startingCol, &orientation);
                    
                if((orientation!=0) && (orientation!=1))
                {
                    if((orientation!=0) && (orientation!=1))
                    {
                        do{
                            printf("Invalid Input\n");
                            printf("Give starting row, starting column and orientation (3 inputs) for ship of size=%d:", shipSize);
                            scanf("%d%d%d", &startingRow, &startingCol, &orientation);
                        }while((orientation!=0) && (orientation!=1));
                                
                                
                }
            }
                    
                
                    
                    //Horizontal Orientation
                    else if(orientation==0)
                    {
                        for(int k=0; k<(shipSize); k++)
                        {
                            if(((startingCol+shipSize)<1) || ((startingCol+shipSize)>11) || (startingRow<1) || (startingRow>9) || (startingCol<1) || (startingCol>11) || ((orientation!=1) && (orientation!=0)))
                            {
                                while(((startingCol+shipSize)<1) || ((startingCol+shipSize)>11) || (startingRow<1) || (startingRow>9) || (startingCol<1) || (startingCol>11) || ((orientation!=1) && (orientation!=0)))
                                {
                                            
                                    printf("Invalid Input\n");
                                    printf("Give starting row, starting column and orientation (3 inputs) for ship of size=%d:", shipSize);
                                    scanf("%d%d%d", &startingRow, &startingCol, &orientation);
                                            
                                }
                            }
                            else{
                                while(board[startingRow][startingCol+k] !=0)
                                {
                                    printf("Conflicts with ships already placed\n");
                                    printf("Give starting row, starting column and orientation (3 inputs) for ship of size=%d:", shipSize);
                                    scanf("%d%d%d", &startingRow, &startingCol, &orientation);
                                }
                            }
                        }
                        
                            
                            
                        for(int b=0; b<(shipSize); b++)
                        {
                            board[startingRow][startingCol+b]=shipSize;
                        }
                    }
                            
                        
                        
                    //Vertical Orientation
                    else if(orientation==1)
                    {
                        for(int m=0; m<(shipSize); m++)
                        {
                            if(((startingRow+shipSize)<1) || ((startingRow+shipSize)>9) || (startingRow<1) || (startingRow>9) || (startingCol<1) || (startingCol>11) || ((orientation!=1) && (orientation!=0)))
                            {
                                while(((startingRow+shipSize)<1) || ((startingRow+shipSize)>9) || (startingRow<1) || (startingRow>9) || (startingCol<1) || (startingCol>11) || ((orientation!=1) && (orientation!=0)))
                                {
                                            
                                    printf("Invalid Input\n");
                                    printf("Give starting row, starting column and orientation (3 inputs) for ship of size=%d:", shipSize);
                                    scanf("%d%d%d", &startingRow, &startingCol, &orientation);
                                            
                                }
                            }
                            else{
                                while(board[startingRow+m][startingCol] !=0)
                                {
                                    printf("Conflicts with ships already placed\n");
                                    printf("Give starting row, starting column and orientation (3 inputs) for ship of size=%d:", shipSize);
                                    scanf("%d%d%d", &startingRow, &startingCol, &orientation);
                                }
                            }
                        }
                        
                        for(int q=0; q<(shipSize); q++)
                            {
                                board[startingRow+q][startingCol]=shipSize;
                            }
                                
                            
                    }
            
                        
                shipSize = shipSize-1;
            }while(shipSize>0);
                           
    }
    
    
    
    else if(getUserInput == false)
    {
        for(int shipSize = 5; shipSize>0; shipSize--)
        {
            do{
                startingRow = getRand(1,BOARDROWS);
                startingCol = getRand(1,BOARDCOLS);
                orientation = getRand(0,1);
                
                if((startingRow<1) || (startingRow>9) || (startingCol<1) || (startingCol>11) || ((orientation!=1) && (orientation!=0)))
                    {
                        printf("Invalid Input\n");
                    }
                        
                else if(board[startingRow][startingCol]!=0)
                    {
                        printf("Conflicts with ships already placed\n");
                    }
            }while((startingRow<1) || (startingRow>9) || (startingCol<1) || (startingCol>11) || ((orientation!=1) && (orientation!=0)) || (board[startingRow][startingCol]!=0));
            
            
                        //Horizontal Orientation
                        if(orientation==0)
                        {
                            
                            for(int k=0; k<shipSize; k++)
                            {
                                while(board[startingRow][startingCol+k] !=0)
                                {
                                    printf("Conflicts with ships already placed\n");
                                    printf("Give starting row, starting column and orientation (3 inputs) for ship of size=%d:", shipSize);
                                    scanf("%d%d%d", &startingRow, &startingCol, &orientation);
                                }
                                
                                if(board[startingRow][startingCol+k]==0)
                                {
                                    board[startingRow][startingCol+k]=shipSize;
                                }
                            
                            }  
                        }
                        
                        //Vertical Orientation
                        else if(orientation==1)
                        {
                            for(int m=0; m<shipSize; m++)
                            {
                                while(board[startingRow+m][startingCol] !=0)
                                {
                                    printf("Conflicts with ships already placed\n");
                                    printf("Give starting row, starting column and orientation (3 inputs) for ship of size=%d:", shipSize);
                                    scanf("%d%d%d", &startingRow, &startingCol, &orientation);
                                }
                                
                                if(board[startingRow+m][startingCol]==0)
                                {
                                    board[startingRow+m][startingCol]=shipSize;
                                }
                            
                            }
                        }
        }
        
    }
    

}



void showBoard(int board[BOARDROWS+1][BOARDCOLS+1]){

    printf("   Cols\n");

    printf("    1  2  3  4  5  6  7  8  9 10 11\n");

    printf("     ________________________________\n");

    for(int i=1;i<=BOARDROWS;i++){

        printf("R%d|",i);

        for(int j=1;j<=BOARDCOLS;j++){

            if(board[i][j]>=0)

                printf(" ");

            printf("%d ",board[i][j]);

        }

        printf("|\n");

    }

    printf("  __________________________________\n");

}



int main(int argc, char **argv)

{

    bool playerBoardOK,computerBoardOK;

    

    // initialize the seed randomly. 
     	srand(time(NULL)); 


    //init the boards

    for(int i=0;i<BOARDROWS;i++){

        for(int j=0;j<BOARDCOLS;j++){

            playerBoard[i][j]=0;

            computerBoard[i][j]=0;

            compShotBoard[i][j]=0;

        }

    }



    populateBoard(true,playerBoard);

    populateBoard(false,computerBoard);

    printf("Your board is\n");

    showBoard(playerBoard);

    if(dumpComputer){

        printf("\n\nComputer board is\n");

        showBoard(computerBoard);

    }



    // play starts here

    playerBoardOK=true;

    computerBoardOK=true;

    while(playerBoardOK && computerBoardOK){

        int hit=getShot(true,computerBoard); //shot from user

        if(hit){

            printf("HIT on size %d\n",hit);

            if(noneLeft(hit,computerBoard))

                printf("Sunk computer's %d\n",hit);

        }

        else

            printf("MISS!!\n");

        hit=getShot(false,playerBoard);

        if(hit){

            printf("Computer hits! Size=%d\n", hit);

            if(noneLeft(hit,playerBoard))

                printf("Sunk your %d\n",hit);

        }

        else

            printf("Computer miss!\n");

        playerBoardOK = allShipsNotHit(playerBoard);

        computerBoardOK = allShipsNotHit(computerBoard);

//    showBoard(playerBoard); //debug

//    showBoard(computerBoard); //debug

   }

   if(playerBoardOK)

       printf("You win!\n");

    else

        printf("You lose.\n");

    showBoard(computerBoard);



	return 0;

}
