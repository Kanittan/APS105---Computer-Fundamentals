#include <stdio.h>

//#include <stdbool.h> Why if we don't include there it doesn't work? It should work since stdbool.h is declared in the header file.

#include "project_reversi_skeleton.h" // DO NOT modify this line







// Function: initializeBoard

void initializeBoard(char board[][26], int n){

    //Keep value of "U" into the board. (Not printing U into board.)

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            board[i][j]='U';

        }

    }

    

    //Change U to W and B into the center of the board.

    board[(n/2)-1][(n/2)-1]='W';

    board[n/2][n/2]='W';

    board[(n/2)-1][n/2]='B';

    board[n/2][(n/2)-1]='B';

}





// Function: printBoard

void printBoard(char board[][26], int n) {

    

    //Print Horizontal axis:

    printf("  ");

    for(int i=0;i<n;i++){

        printf("%c",97+i);

    }

    

    //Print Vertical axis: abcde... AND print U to board.

    printf("\n");

    for(int i=0;i<n;i++){

        printf("%c ",97+i);

        for(int j=0;j<n;j++){

            printf("%c",board[i][j]);

        }

        printf("\n");

    }

}





/*

 * Function:  positionInBounds 

 * --------------------

 * Checks whether the specified (row, col) lies within the board dimensions.

 */

bool positionInBounds(int n, int row, int col) {

    int p=row,q=col;

    if(p>=0 && q>=0 && p<n && q<n) // Try with >= and <= if does not work. //

        return true;

    else

    {

        /*printf("Invalid Move"); */

        return false;

    }

    

}





// Function: checkPosition Check inputted position is "U".

bool checkPosition(char board[][26], int row, int col)

{

    if((board[row][col]=='W') || (board[row][col]=='B')) //Check "U" --> Return True else return false.

    {

        //printf("Invalid Position");

        return false;

    }

    else

        return true;

}





// Function: checkLegalInDirection

bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol) {

    

    char oppositeColor;

    if(colour == 'W') {

        oppositeColor = 'B';

    }

    else if(colour == 'B')

    {

        oppositeColor = 'W';

    }

    

    if(checkPosition(board, row, col)==false)

    {

        return false;

    }



    

    if(positionInBounds(n, row+deltaCol, col+deltaRow)==false)//check boundaries

    {

        return false;

    }

    

    if(board[(row)+deltaCol][(col)+deltaRow]==colour)//check neighbour Must be opposite color.

    {

        return false;

    }

    

    

    int incrementRow=(row)+deltaCol, incrementCol=(col)+deltaRow;

    while(positionInBounds(n, incrementRow, incrementCol)&&(board[incrementRow][incrementCol]==oppositeColor))//keep iterating

    {

        incrementRow = incrementRow+deltaCol;

        incrementCol = incrementCol+deltaRow;

        

    }

    //May have to CHECK Again.

    if(positionInBounds(n, incrementRow, incrementCol)==false){

        //printf("IN BOUND\n");

        return false;//check edge

    }



        

    else if(board[incrementRow][incrementCol]=='U'){

        return false; //hit unoccupied

    }

        

    else if(board[incrementRow][incrementCol]==colour)

    {

        return true; // our color

    }

    return false;

}





int flipInDirection(char board[][26], int row, int col, char colour, int deltaRow, int deltaCol, bool flip) {

     // Postition after move

     int currentRow = row+deltaCol;

     int currentCol = col+deltaRow;

     char oppositeColour = ' ';

     if(colour == 'W')

     {

        oppositeColour = 'B';

     }

     else if(colour == 'B')

     {

        oppositeColour = 'W';

     }

     

     int countTiles = 0;

     // Flip tiles until tile have same colour

     while(board[currentRow][currentCol] == oppositeColour)

     {

      if(flip)

      {

        board[currentRow][currentCol] = colour;

      }

        currentRow += deltaCol;

        currentCol += deltaRow;

        countTiles++;

     }

     

     return countTiles;

}





// Function: checkValidAndFlip

int checkValidAndFlip(char board[][26], int row, int col, char colour, int n, bool flip){

     int countTiles = 0;

     

     if(checkLegalInDirection(board, n, row, col, colour, 1, 0))

        countTiles += flipInDirection(board, row, col, colour, 1, 0, flip);

    

    

    if(checkLegalInDirection(board, n, row, col, colour, -1, 0))

        countTiles += flipInDirection(board, row, col, colour, -1, 0, flip);

    

    

    if(checkLegalInDirection(board, n, row, col, colour, 0, 1))

        countTiles += flipInDirection(board, row, col, colour, 0, 1, flip);

    

    

    if(checkLegalInDirection(board, n, row, col, colour, 0, -1))

        countTiles += flipInDirection(board, row, col, colour, 0, -1, flip);

    

    

    if(checkLegalInDirection(board, n, row, col, colour, 1, 1))

        countTiles += flipInDirection(board, row, col, colour, 1, 1, flip);

    

    

    if(checkLegalInDirection(board, n, row, col, colour, 1, -1))

        countTiles += flipInDirection(board, row, col, colour, 1, -1, flip);

    

    

    if(checkLegalInDirection(board, n, row, col, colour, -1, 1))

        countTiles += flipInDirection(board, row, col, colour, -1, 1, flip);

    

    if(checkLegalInDirection(board, n, row, col, colour, -1, -1))

        countTiles += flipInDirection(board, row, col, colour, -1, -1, flip);

     

     // Count AND/OR flip

     // Use countTiles for check isAvailable

     if(countTiles > 0 && flip)

     {

        board[row][col] = colour;

        countTiles++;

     }

     else if(countTiles > 0)

     {

        countTiles++;

     }

     //////////// SAME AS ABOVE////////////////////////////////

     /*if(flip)

     {

      board[row][col] = colour;

     }

     if(countTiles > 0)

     {

      countTiles++;

     }*/

     return countTiles;

}





// Function:makeMove

int makeMove(const char board[26][26], int n, char turn, int *row, int *col) {

    

    int score=0, highestScore=0;

    int scoreArray[26][26]; //Stores score in each row and column.

    // 1. Check Available position

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            score=checkValidAndFlip(board, i, j, turn, n, false); //scoreArray[i][j]=checkValidAndFlip(board, i, j, turn, n, false) because checkValidandFlip returns a score.

            scoreArray[i][j]=score;

            score=0;

        }

        

    }



    

    int rowHighScore=0, colHighScore=0;

    for(int i=0;i<n;i++){       //Changes made: Switch to iterate every row first because it allows us to check condition for cases highest score in many position, we can choose the lowest row.

        for(int j=0;j<n;j++){   //1.) Choose highest score in entire row first.(Follows rule: If score equal: Choose Lowest row.) | THEN: 2.) Choose highest score in enture column.(Follows rule: If score equal: Choose Lowest column.)

            if(i==0 && j==0)

            {

                highestScore=scoreArray[i][j]; //Invalid: highestScore=scoreArray[0][0] and highestScore=scoreArray[i][j] without if().

            }

            

            if(scoreArray[i][j]==highestScore) //2 Equal sign.

            {

                if(i<rowHighScore)

                {

                    rowHighScore = i;

                }

            

                else if(i==rowHighScore)

                {

                    if(j<colHighScore)

                    {

                        colHighScore = j;

                    }

                }

            }

            

            if(scoreArray[i][j]>highestScore) //Added: If scoreArray[i][j] = highestScore then, highestScore !=scoreArray[i][j] because 1>1 is false.

            {

                highestScore = scoreArray[i][j];

                rowHighScore = i;

                colHighScore = j;

            }

        }

    }

    *row = rowHighScore;

    *col = colHighScore;

    

    return 0;

}



bool moveAvailable(char board[][26] ,int n, char colour)

{

    for(int row=0; row<n; row++)

    {

        for(int col=0; col<n; col++)

        {

            if(checkValidAndFlip(board, row, col, colour, n, false)>0)

                return true;

        }

    }

    return false; //MUST RETURN false outside of loop. Check in every position where valid move is possible.

    

}



char findOpposite(char turn)

{

    if(turn=='W')

    {

        return 'B';

    }

    else

        return 'W';

}











#ifndef COMPETE_MODE // DO NOT DELETE THIS LINE

int main(void) {



int n;

char turn;

char computerColour, humanColour;



int rowComputer, colComputer;

int computerScore, totalComputerScore=0;



char rowHuman, colHuman;

int humanScore, totalHumanScore=0;



char board[26][26];

    printf("Enter the board dimension: ");

    scanf("%d",&n);

    

    printf("Computer plays (B/W) : ");

    scanf(" %c", &computerColour);

    

    // Initalize first board.

    initializeBoard(board, n);

    

    //print first board.

    printBoard(board, n);

    

    if(computerColour=='B')

    {

        humanColour='W';

    }

    else

        humanColour='B';

        

    turn = 'B';

    

    int countFlip=0;

    

    

    while(true)

    {

        //Computer Move.

        if(turn==computerColour)

        {

            makeMove(board, n, computerColour, &rowComputer, &colComputer);

            countFlip=checkValidAndFlip(board, rowComputer, colComputer, computerColour, n, true);

            printf("Computer places %c at %c%c.\n", computerColour, rowComputer+'a', colComputer+'a');

        }

        

        

        //Player move.

        else

        {

            printf("Enter move for colour %c (RowCol): ", humanColour);

            scanf(" %c%c",&rowHuman,&colHuman);

            

            countFlip=checkValidAndFlip(board, rowHuman-97, colHuman-97, humanColour, n, true);

            

            if(countFlip<=0)

            {

                printf("Invalid move.\n");

                break;

            }

        }

        



        // When Game is NOT Over: Check of the counterpart has any available moves left.

            printBoard(board,n);

            

            if(moveAvailable(board, n, findOpposite(turn))==true)

            {

                turn = findOpposite(turn);

            }

            

            else if(moveAvailable(board, n, findOpposite(turn))==false)

            {

                if(moveAvailable(board,n, turn)==true)

                {

                    printf("%c player has no valid move.\n", findOpposite(turn));

                }

                    

                if(moveAvailable(board,n, turn))

                {

                    turn = turn;



                }

                

                else

                {

                    break;

                }

            }

                

            

    }

    

    int countBlack=0, countWhite=0;

    for(int i=0;i<n;i++)

    {

        for(int j=0; j<n;j++)

        {

            if(board[i][j]=='B')

            {

                countBlack++;

            }

            else if(board[i][j]=='W')

            {

                countWhite++;

            }

        }

    }

    

    

    if(countBlack > countWhite) //Finish this code.

    {

        printf("B player wins.\n");

    }

    else if(countWhite > countBlack)

    {

        printf("W player wins.\n");

    }

    

        

                    //turn=findOpposite(Turn);

}

    



#endif