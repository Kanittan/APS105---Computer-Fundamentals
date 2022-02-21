/*
 * File:        project_reversi_skeleton.c
 * Author:      APS105H1 Teaching Team
 * Modified by: * Kanit Mongkonrattanachai *
 *
 * Date: Jan 2021
 */
#include <stdio.h>
#include <stdbool.h>
#include "project_reversi_skeleton.h" // DO NOT modify this line

// Note: You may want to add more function declarations here
// =========   Function declaration  ==========

        


// ========= Function implementation ==========

// Function: Initialize board //
// Initializes the Position of starting White and Black //
/*
void boardInitialize(char board[26][26], int n){
    
    board[(n/2)-1][(n/2)-1]='W';
    board[n/2][n/2]='W';
    board[(n/2)-1][n/2]='B';
    board[n/2][(n/2)-1]='B';
    printf("\n");
    
}
*/

// Function: boardConfiguration
void boardConfiguration(char board[][26], int n){ //Must incluse size of column when passing array.
    printf("Enter board configuration:");
    printf("\n");
    char color;
    char row,col;
    for(int i=0;(color!='!' && row!='!' && col!='!');i++){
        scanf(" %c%c%c",&color,&row,&col);
        board[row-97][col-97]=color;
        
        //printf("color: %c ; row: %c ; col: %c", color, row, col);
       // printf("%d ; %d", row-97, col-97);
       // printf("%c", board[row-97][col-97]);
        
        //printf("%c", board[row-97][col-97]);
    }
}


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

/*
 * Function:  printBoard 
 * --------------------
 * Print the whole board to the terminal window.
 */
void printBoard(char board[][26], int n) {
    /*
    printf("  ");
    for(int i=0;i<n;i++){
        printf("%c",97+i);  //97 = ASCII of "a". 97+1 = 98 - b
    }
    */
    
    //Print Horizontal axis: abcde...
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
bool checkPosition(char board[][26], char row, char col)
{
    if((board[row][col]=='W') || (board[row][col]=='B')) //Check "U" --> Return True else return false.
    {
        //printf("Invalid Position");
        return false;
    }
    else
        return true;
}

/*

void printAvailableMoves(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol){

    if(checkLegalInDirection(board, n, row, col, colour, deltaRow, deltaCol) == true)
    {
        if(colour=='W')
        {
            printf("Available moves for W:\n");
            while((checkLegalInDirection(board, n, row, col, colour, deltaRow, deltaCol) == true) && (colour=='W'))
            {
                printf("%c%c", row+97,col+97); //Problem: 1.)Must print row and column as "Character".  2.)MUST Print all available moves for white and black separately.
            }
        }
        
        if(colour=='B')
        {
            printf("Available moves for B:\n");
            while((checkLegalInDirection(board, n, row, col, colour, deltaRow, deltaCol) == true) && (colour=='B'))
            {
                printf("%c%c", row+97,col+97);
            }
        }
        
        
        printf("Available moves for B:\n");
    }
}


/*
 * Function:  checkLegalInDirection 
 * --------------------
 * Checks whether (row, col) is a legal position for a tile of colour by “looking” in the direction 
 * specified by deltaRow and deltaCol.
 */
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol) {
    
    char oppositeColor;
    if(colour == 'W') {
        oppositeColor = 'B';
    }
    else if(colour == 'B')
    {
        oppositeColor = 'W';
    }
    /*
    if((row==0) && (col==0))
        printf("Checkpoint1 deltaRow=%d, deltaCol=%d\n",deltaRow, deltaCol);
    */
    //printf("%d %d", row+deltaRow, col+deltaCol);
    
    if(checkPosition(board, row, col)==false)
    {
        return false;
    }
    /*
    if((row==0) && (col==0))
        printf("CheckpointNEW deltaRow=%d, deltaCol=%d\n",deltaRow, deltaCol);
    */
    
    if(positionInBounds(n, row+deltaCol, col+deltaRow)==false)//check boundaries
    {
        return false;
    }
    
    /*
    if((row==0) && (col==0))
        printf("Checkpoint2 deltaRow=%d, deltaCol=%d\n",deltaRow, deltaCol);
    */
    if(board[(row)+deltaCol][(col)+deltaRow]==colour)//check neighbour Must be opposite color.
    {
        return false;
    }
    
    /*
    if((row==0) && (col==0))
        printf("Checkpoint3 deltaRow=%d, deltaCol=%d\n",deltaRow, deltaCol);
    */
    
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
        /*
        if((row==0) && (col==0))
            printf("Checkpoint4 deltaRow=%d, deltaCol=%d\n",deltaRow, deltaCol);
        */
        
        return false; //hit unoccupied
    }
        
    else if(board[incrementRow][incrementCol]==colour)
    {
        /*
        if((row==0) && (col==0))
            printf("Checkpoint5 deltaRow=%d, deltaCol=%d\n",deltaRow, deltaCol);
        */
        //printf("%c%c\n", row+97,col+97);
        return true; // our color
    }
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

int checkValidAndFlip(char board[][26], int row, int col, char colour, int n, bool flip) {
     //int deltaRow = -1;
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

//     while(deltaRow < 2)
//     {
//        int deltaCol = -1;
//        while(deltaCol < 2)
//        {
//            if(!(deltaCol == 0 && deltaRow == 0))
//            {
//                if(checkLegalInDirection(board, n, row, col, colour, deltaRow, deltaCol))
//                {
//                    countTiles += flipInDirection(board, row, col, colour, deltaRow, deltaCol, flip);
//                }
//            }
//        deltaCol++;
//      }
//        deltaRow++;
//    }
     
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



//Function: flipTile
// Function to flip the OPPOSITE Color chess that is in between 2 SAME Color chess.
//void flipTile(char board[][26], int n, char colour, char row, char col, int deltaRow, int deltaCol)
//{
//    
//    char oppositeColour;
//    if(colour=='W')
//        oppositeColour = 'B';
//    else if(colour=='B')
//        oppositeColour= 'W';
//    
//    int incrementRow=(row-97)+deltaCol, incrementCol=(col-97)+deltaRow;
//    while((board[incrementRow][incrementCol]==oppositeColour))//keep iterating
//    {
//        
//        printf("incrementRow=%d incrementCol=%d colour=%c", incrementRow, incrementCol, colour);
//        board[incrementRow][incrementCol]=colour; //To CHANGE/FLIP the opposite color chess.
//        incrementRow = incrementRow+deltaCol;
//        incrementCol = incrementCol+deltaRow;
//    }
//    
//    
//    board[row-97][col-97]=colour; //Place Color chess into the EMPTY(U) Space.
//}

//
/*
// Function: checkLegalInMove //
//function to check if any specific move is legal
bool checkLegalInMove(char board[26][26], int N, char row, char col, char colour){
    int r=row-'a',c=col-'a';
    for(int deltaRow=-1;deltaRow<=1;deltaRow++){
        for(int deltaCol=-1;deltaCol<=1;deltaCol++){
            if(positionInBounds(N,row,col)){
                checkLegalInDirection(board,N,('a'+r),('a'+c),colour,deltaRow,deltaCol);
                printf("Valid move.\n");
                return true;
            }
            else
                printf("Invalid move.\n");
            return false;
        }
    }
}
*/


// Function: printMove (NOT USED)
// Prints the board after the move is legal. //
/*
bool printMove(char board[26][26], int n){
    char color,row,col,temp;
    printf("Enter a move:\n");
    scanf(" %c%c%c",&color,&row,&col);
    
    if(checkPosition(board, row, col)==true)
    {
        if((checkLegalInDirection(board, n, row, color, col,0,1)==true) || (checkLegalInDirection(board, n, row, color, col,0,-1)==true) || (checkLegalInDirection(board, n, row, color, col,1,0)==true) || (checkLegalInDirection(board, n, row, color, col,-1,0)==true) || (checkLegalInDirection(board, n, row, color, col,1,1)==true) || (checkLegalInDirection(board, n, row, color, col,-1,1)==true) || (checkLegalInDirection(board, n, row, color, col,1,-1)==true) || (checkLegalInDirection(board, n, row, color, col,-1,-1)==true))
        {
            printf("checkPosition");
            board[(row-'a')][(col-'a')]=color;
        }
    }
}
 * 
 */
/*
    if(checkLegalInDirection(board, n, row, color, col,0,1)==false)
    {
        return false;
    }
    
    if(checkLegalInDirection(board, n, row, color, col,0,-1)==false)
    {
        return false;
    }
    
    if(checkLegalInDirection(board, n, row, color, col,1,0)==false)
    {
        return false;
    }
    
    if(checkLegalInDirection(board, n, row, color, col,-1,0)==false)
    {
        return false;
    }
    
    if(checkLegalInDirection(board, n, row, color, col,1,1)==false)
    {
        return false;
    }
    
    if(checkLegalInDirection(board, n, row, color, col,-1,1)==false)
    {
        return false;
    }
    
    if(checkLegalInDirection(board, n, row, color, col,1,-1)==false)
    {
        return false;
    }
    
    if(checkLegalInDirection(board, n, row, color, col,-1,-1)==false)
    {
        return false;
    }
    
}
*/


/*    
    char color,row,col,temp;
    printf("Enter a move:\n");
    scanf(" %c%c%c",&color,&row,&col);
    temp=board[row-'a'][col-'a'];
    board[row-'a'][col-'a']=color;
    
    if(checkPosition(board, n, row, col))
    {
        return false;
    }
    
    if(checkPosition(board, n, row, col)
    {
        
    }
*/

/*
    if(checkPosition(board, n, row, col))
    {
        return false;
    }
    if(checkLegalInDirection(board,n,row,col,color,0,1)){
        printf("  ");
        for(int i=0;i<n;i++){
            printf("%c",97+i);
        }
        printf("\n");
        for(int i=0;i<n;i++){
            printf("%c ",97+i);
            for(int j=0;j<n;j++){
                printf("%c",board[i][j]);
            }
            printf("\n");
        }
    }
    else{
        board[row-'a'][col-'a']=temp;
        printf("  ");
        for(int i=0;i<n;i++){
            printf("%c",97+i);
        }
        printf("\n");
        for(int i=0;i<n;i++){
            printf("%c ",97+i);
            for(int j=0;j<n;j++){
                printf("%c",board[i][j]);
            }
            printf("\n");
        }
    }
}
*/



/*
 * Function:  makeMove 
 * --------------------
 * The player "turn" makes a move at (row, col).
 * Note: This function MUST NOT change board, only row and col can be changed to reflect the move.
 */
int makeMove(const char board[26][26], int n, char turn, int *row, int *col) {
    (void)board;
    (void)n;
    (void)turn;
    (void)row;
    (void)col;
    return 0;
}

#ifndef COMPETE_MODE // DO NOT DELETE THIS LINE
int main(void) {
    // Complete your main function here
int n;
    char board[26][26];
    printf("Enter the board dimension: ");
    scanf("%d",&n);
    
    initializeBoard(board,n);
    printBoard(board,n); //Pass by Reference
    
    boardConfiguration(board, n);
    printBoard(board,n);
    
    printf("Available moves for W:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(checkLegalInDirection(board, n, i, j, 'W', 1, 0))
                printf("%c%c\n", i+97,j+97);
            
            
            else if(checkLegalInDirection(board, n, i, j, 'W', -1, 0))
                printf("%c%c\n", i+97,j+97);
            
            
            else if(checkLegalInDirection(board, n, i, j, 'W', 0, 1))
                printf("%c%c\n", i+97,j+97);
            
            
            else if(checkLegalInDirection(board, n, i, j, 'W', 0, -1))
                printf("%c%c\n", i+97,j+97);
            
            
            else if(checkLegalInDirection(board, n, i, j, 'W', 1, 1))
                printf("%c%c\n", i+97,j+97);
            
            
            else if(checkLegalInDirection(board, n, i, j, 'W', 1, -1))
                printf("%c%c\n", i+97,j+97);
            
            
            else if(checkLegalInDirection(board, n, i, j, 'W', -1, 1))
                printf("%c%c\n", i+97,j+97);
            
            else if(checkLegalInDirection(board, n, i, j, 'W', -1, -1))
                printf("%c%c\n", i+97,j+97);
        }
    }
    
    
    printf("Available moves for B:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            if(checkLegalInDirection(board, n, i, j, 'B', 1, 0))
                printf("%c%c\n", i+97,j+97);
            
            
            else if(checkLegalInDirection(board, n, i, j, 'B', -1, 0))
                printf("%c%c\n", i+97,j+97);
            
            
            else if(checkLegalInDirection(board, n, i, j, 'B', 0, 1))
                printf("%c%c\n", i+97,j+97);
            
            
            else if(checkLegalInDirection(board, n, i, j, 'B', 0, -1))
                printf("%c%c\n", i+97,j+97);
            
            
            else if(checkLegalInDirection(board, n, i, j, 'B', 1, 1))
                printf("%c%c\n", i+97,j+97);
            
            
            else if(checkLegalInDirection(board, n, i, j, 'B', 1, -1))
                printf("%c%c\n", i+97,j+97);
            
            
            else if(checkLegalInDirection(board, n, i, j, 'B', -1, 1))
                printf("%c%c\n", i+97,j+97);
            
            else if(checkLegalInDirection(board, n, i, j, 'B', -1, -1))
                printf("%c%c\n", i+97,j+97);
        }
    }
    
    char colour, row, col;
    printf("Enter a move:\n");
    scanf(" %c%c%c",&colour,&row,&col);
    
    int countFlip;
    countFlip=checkValidAndFlip(board, row-97, col-97, colour, n, true);
    
    if(countFlip>0)
    {
        printf("Valid move.\n");
    }
    
    else
    {
        printf("Invalid move.\n");
    }
    printBoard(board,n);
    
    
//    bool E,W,N,S,NE,SE,NW,SW;
//    E=checkLegalInDirection(board, n, row-97, col-97, colour, 1, 0);
//    W=checkLegalInDirection(board, n, row-97, col-97, colour, -1, 0);
//    S=checkLegalInDirection(board, n, row-97, col-97, colour, 0, 1);
//    N=checkLegalInDirection(board, n, row-97, col-97, colour, 0, -1);
//    SE=checkLegalInDirection(board, n, row-97, col-97, colour, 1, 1);
//    NE=checkLegalInDirection(board, n, row-97, col-97, colour, 1, -1);
//    SW=checkLegalInDirection(board, n, row-97, col-97, colour, -1, 1);
//    NW= checkLegalInDirection(board, n, row-97, col-97, colour, -1, -1);
//    
//    int deltaRow, deltaCol;
//    if(E)
//    {
//        printf("Valid move.\n");
//        flipTile(board, n, colour, row, col, 1, 0); //Issue: How to pass by value of deltaRow and deltaCol from checkLegalinDirection into the function?
//        printBoard(board,n);
//    }
//    
//    if(W)
//    {
//        printf("Valid move.\n");
//        flipTile(board, n, colour, row, col, -1, 0); //Issue: How to pass by value of deltaRow and deltaCol from checkLegalinDirection into the function?
//        printBoard(board,n);
//    }
//    if(S)
//    {
//        printf("Valid move.\n");
//        
//        flipTile(board, n, colour, row, col, 0, 1); //Issue: How to pass by value of deltaRow and deltaCol from checkLegalinDirection into the function?
//        printBoard(board,n);
//    }
//    if(N)
//    {
//        printf("Valid move.\n");
//        
//        flipTile(board, n, colour, row, col, 0, -1); //Issue: How to pass by value of deltaRow and deltaCol from checkLegalinDirection into the function?
//        printBoard(board,n);
//    }
//    
//    if(SE)
//    {
//        printf("Valid move.\n");
//        flipTile(board, n, colour, row, col, 1, 1); //Issue: How to pass by value of deltaRow and deltaCol from checkLegalinDirection into the function?
//        printBoard(board,n);
//    }
//    
//    if(NE)
//    {
//        printf("Valid move.\n");
//        flipTile(board, n, colour, row, col, 1, -1); //Issue: How to pass by value of deltaRow and deltaCol from checkLegalinDirection into the function?
//        printBoard(board,n);
//    }
//    
//    if(SW)
//    {
//        printf("Valid move.\n");
//        flipTile(board, n, colour, row, col, -1, 1); //Issue: How to pass by value of deltaRow and deltaCol from checkLegalinDirection into the function?
//        printBoard(board,n);
//    }
//    
//    if(NW)
//    {
//        printf("Valid move.\n");
//        flipTile(board, n, colour, row, col, -1, -1); //Issue: How to pass by value of deltaRow and deltaCol from checkLegalinDirection into the function?
//        printBoard(board,n);
//    }
    
    
//    if(!(E || W || N || S || NE || SE || NW |SW))
//    {
//        printf("Invalid move.\n");
//        printBoard(board,n);
//    }
    
    //printAvailableMoves(board, n, row, col, colour, deltaRow, deltaCol);
    
    //printMove(board,n);
    return 0;
}
#endif // DO NOT DELETE THIS LINE