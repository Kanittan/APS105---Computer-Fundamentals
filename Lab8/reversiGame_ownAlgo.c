#include <stdio.h>
//#include <stdbool.h>

#include "lab8part2lib.h"

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



// Copy boardSource to boardDestination

void copyBoard(char boardDestination[][26] ,const char boardSource[26][26], int n){ //Array pass by reference: Constant to prevent making any internal changes to board.

	int countRow = 0, countCol = 0;

	for(countRow = 0; countRow < n; countRow++)

	{

		for(countCol = 0; countCol < n; countCol++)

		{

			boardDestination[countRow][countCol] = boardSource[countRow][countCol];

		}

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



        return false;//check edge

    }



        

    else if(board[incrementRow][incrementCol]=='U'){

        /*

        if((row==0) && (col==0))

            printf("Checkpoint4 deltaRow=%d, deltaCol=%d\n",deltaRow, deltaCol);

        */

        

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



int checkValidAndFlip(char board[][26], int row, int col, char colour, int n, bool flip){

// Function: checkValidAndFlip



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

    

    int boardScore[26][26];

    int countTile=0;

    int score=0, countTurn=-4;

    // 1. Create Score Board. Check Available position

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            score=checkValidAndFlip(board, i, j, turn, n, false); //scoreArray[i][j]=checkValidAndFlip(board, i, j, turn, n, false) because checkValidandFlip returns a score.

            boardScore[i][j]=score;

            if(board[i][j]=='W' || board[i][j]=='B')

            {

                countTurn++;

            }

            if(turn==board[i][j])

            {

                countTile++;

            }

        }

    }

    int lowestScore = n*n + 1;

    int lowestRow = -1, lowestCol = -1;

     

    int highestScore = -1;

    int highestRow = -1, highestCol = -1;

    

    int countCorner = 0;

    int boardCornerScore[4];

    int cornerRow[4];

    int cornerCol[4];

    

    int countBorder = 0;

    int boardBorderScore[96];

    int borderRow[96];

    int borderCol[96];

    

    int boardScoreRow[576];

    int boardScoreCol[576];

    int countScore = 0;

    int boardScoreScore[576]; //Store score from boardscoreRow and boardScoreCol(26x26)-(Corner and Border)

    

    

    for(int countRow = 0; countRow < n; countRow++)

    {

        for(int countCol = 0; countCol < n; countCol++)

        {

            if(boardScore[countRow][countCol] > 0)

            {

            // check corner

                if((countRow == 0 && countCol == 0) || (countRow == 0 && countCol == n-1) || (countRow == n-1 && countCol == 0) || (countRow == n-1 && countCol == n-1))

                {

                    boardCornerScore[countCorner] = boardScore[countRow][countCol];

                    cornerRow[countCorner] = countRow;

                    cornerCol[countCorner] = countCol;

                    countCorner++;

                }

                // check border

                else if(countRow == 0 || countRow == n-1 || countCol == 0 || countCol == n-1)

                {

                    boardBorderScore[countBorder] = boardScore[countRow][countCol];

                    borderRow[countBorder] = countRow;

                    borderCol[countBorder] = countCol;

                    countBorder++;

                }

                

                // Store highest and lowest score.

                else

                {

                    boardScoreScore[countScore] = boardScore[countRow][countCol];

                    boardScoreRow[countScore] = countRow;

                    boardScoreCol[countScore] = countCol;

                    countScore++;



                }

               

            }

        }

    }
    

    int temp1, temp2, temp3;

    //Sort Score Lowest to Highest:

    for(int countArr1=0; countArr1<countScore; countArr1++)

    {

        for(int countArr2=countArr1+1; countArr2<countScore ; countArr2++)

        {

            if(boardScoreScore[countArr1] > boardScoreScore[countArr2])

            {

                temp1 = boardScoreScore[countArr1];

                boardScoreScore[countArr1] = boardScoreScore[countArr2];

                boardScoreScore[countArr2] = temp1;

                

                // Switch Corresponding Row

                temp2 = boardScoreRow[countArr1];

                boardScoreRow[countArr1] = boardScoreRow[countArr2];

                boardScoreRow[countArr2] = temp2;

                

                // Switch Correspondign Column

                temp3 = boardScoreCol[countArr1];

                boardScoreCol[countArr1] = boardScoreCol[countArr2];

                boardScoreCol[countArr2] = temp3;

            }

        }

    }



    

    if(countCorner > 0)

    {

        int highestScore=0;

        for(int i=0; i<countCorner;i++)

        {

            if(boardCornerScore[i] > highestScore)

            {

                highestScore = boardCornerScore[i];

                *row = cornerRow[i];

                *col = cornerCol[i];

            }

        }

    }

    

    else if(countBorder > 0)

    {

        int highestScore=0;

        for(int i=0; i<countBorder;i++)

        {

            if(boardBorderScore[i] > highestScore)

            {

                highestScore = boardBorderScore[i];

                *row = borderRow[i];

                *col = borderCol[i];

            }

        }

    }

    

    

    // make less score at begining game

    // if position row = 1 || row = n-2 || col = 1 || col = n-2

    else if((countTurn < (((float)n*n)-4)*96/100) && countTile > ((float)n*n)*36/100)

//96 and 36 wins Smertest AI

    {

        

        int i=0;

        while(i<countScore)

        {

            if(boardScoreRow[i]==1 || boardScoreRow[i]==n-2 || boardScoreCol[i]==1 || boardScoreCol[i]==n-2)

            {

                i++;

            }

            else

            {

                *row = boardScoreRow[i];

                *col = boardScoreCol[i];

                break;

            }

        }

        

        if(i==countScore)

        {

            *row = boardScoreRow[0];

            *col = boardScoreCol[0];

        }

    }

    

    else

    {

        

        int i=countScore-1;

        while(i>=0)

        {

            if(boardScoreRow[i]==1 || boardScoreRow[i]==n-2 || boardScoreCol[i]==1 || boardScoreCol[i]==n-2)

            {

                i--;

            }

            else

            {

                *row = boardScoreRow[i];

                *col = boardScoreCol[i];

//                printf("row=%d, col=%d\n", *row, *col);

                break;

            }

        }

        

        if(i==-1)

        {

            *row = boardScoreRow[countScore-1];

            *col = boardScoreCol[countScore-1];

//            printf("row=%d, col=%d\n", *row, *col);

        }

//        printf("row=%d, col=%d\n", *row, *col);

    }

    

    return 0;

}





bool moveAvailable(char board[][26] ,int n, char colour)

{

    //printf("Checkpoint 4");

    //printf("\n=%d, color=%c\n", n,colour);

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
