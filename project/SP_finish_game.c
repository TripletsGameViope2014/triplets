#include "data_structs.h"
#include "SP.h"
#include "board.h"

/* Number of aligned pieces that are needed to finish the game */
#define NUM_ALIGNED_PIECES_FINISH (3)


int finish_gamePL(board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE])
{
    int i,j;
    // Diagonally <-
    for(i=0; i<MAX_BOARDSIZE-2; i++)
    {
        for(j=0; j<MAX_BOARDSIZE-2; j++)
        {
            if(board[i][j].piece == PIECE &&
                    board[i+1][j+1].piece == PIECE &&
                    board[i+2][j+2].piece == PIECE)
            {

            refresh_last_piece(i,j);
            refresh_last_piece(i+1,j+1);
            refresh_last_piece(i+2,j+2);

                return 1;
            }

        }
    }
    // Diagonally ->
    for(i=0; i<MAX_BOARDSIZE-2; i++)
    {
        for(j=0; j<MAX_BOARDSIZE-2; j++)
        {
            if(board[i+2][j].piece == PIECE &&
                    board[i+1][j+1].piece == PIECE &&
                    board[i][j+2].piece == PIECE)
            {
                refresh_last_piece(i+2,j);
                refresh_last_piece(i+1,j+1);
                refresh_last_piece(i,j+2);

                return 1;
            }
        }
    }
    // Horizontally
    for(i=0; i<MAX_BOARDSIZE-2; i++)
    {
        for(j=0; j<MAX_BOARDSIZE; j++)
        {
            if(board[i][j].piece == PIECE &&
                    board[i+1][j].piece == PIECE &&
                    board[i+2][j].piece == PIECE)
            {
                refresh_last_piece(i,j);
                refresh_last_piece(i+1,j);
                refresh_last_piece(i+2,j);
                return 1;
            }
        }
    }
    // Vertically
    for(i=0; i<MAX_BOARDSIZE; i++)
    {
        for(j=0; j<MAX_BOARDSIZE-2; j++)
        {
            if(board[i][j].piece == PIECE &&
                    board[i][j+1].piece == PIECE &&
                    board[i][j+2].piece == PIECE)
            {
                refresh_last_piece(i,j);
                refresh_last_piece(i,j+1);
                refresh_last_piece(i,j+2);

                return 1;
            }
        }
    }
    return 0;
}

void refresh_last_piece(int i, int j)
{
                if (get_current_game_ptr()->board[i][j].lastPiece==0)
                {
                    get_current_game_ptr()->board[i][j].lastPiece = 2;
                }

                else
                {
                    get_current_game_ptr()->board[i][j].lastPiece = 3;
                }

}


/*
int finish_game (char board [MAX_BOARDSIZE][MAX_BOARDSIZE],int columnNumber,int rowNumber)
{
    // FIXME: not needed
    //int columnNumber,i,j;
    //columnNumber=turn_name(columnName);//This function turn the columnName in to a number;
  if(diagonally1(board,columnNumber,rowNumber)||diagonally2(board,columnNumber,rowNumber)||horizontal(board,columnNumber,rowNumber)||vertical(board,columnNumber,rowNumber))
    return 1;
  else
    return 0;
    }

int diagonally1 (char board [MAX_BOARDSIZE][MAX_BOARDSIZE],int columnNumber,int rowNumber)
{
    int contador = 0,i=columnNumber,j=rowNumber;
            while (board[i][j]==PIECE&&i>0&&j>0)
            {
               i--;
                j--;
            }

            while (board[i][j]==PIECE && contador < NUM_ALIGNED_PIECES_FINISH)
            {
                contador++;


                i++;
                j++;
            }
if (contador==3)
    return 1;
else return 0;

}

int diagonally2 (char board [MAX_BOARDSIZE][MAX_BOARDSIZE],int columnNumber,int rowNumber)
{
    int contador = 0,i=columnNumber,j=rowNumber;
            while (board[i][j]==PIECE&&i<MAX_BOARDSIZE&&j<MAX_BOARDSIZE)
            {
               i++;
                j--;
            }

            while (board[i][j]==PIECE && contador < NUM_ALIGNED_PIECES_FINISH)
            {
                contador++;


                i--;
                j++;
            }
if (contador==(NUM_ALIGNED_PIECES_FINISH-1)){
    return 1;
}
else{
    return 0;
}

}

 int horizontal (char board [MAX_BOARDSIZE][MAX_BOARDSIZE],int columnNumber,int rowNumber)
{
 if((((board[rowNumber][columnNumber-1]==PIECE)&&(columnNumber-1>0))&&((board[rowNumber][columnNumber-2]==PIECE)&&(columnNumber-2>0)))||(((board[rowNumber][columnNumber-1]==PIECE)&&(columnNumber-1>0))&&((board[rowNumber][columnNumber+1]==PIECE)&&(columnNumber+1<13)))||(((board[rowNumber][columnNumber+1]==PIECE)&&(columnNumber+1<13))&&((board[rowNumber][columnNumber+2]==PIECE)&&(columnNumber+2<13))))
    return 1;
 else
    return 0;
}
int vertical (char board [MAX_BOARDSIZE][MAX_BOARDSIZE],int columnNumber,int rowNumber)
{
 if((((board[rowNumber-1][columnNumber]==PIECE)&&(rowNumber-1>0))&&((board[rowNumber-2][columnNumber]==PIECE)&&(rowNumber-2>0)))||(((board[rowNumber-1][columnNumber]==PIECE)&&(rowNumber-1>0))&&((board[rowNumber+1][columnNumber]==PIECE)&&(rowNumber+1<13)))||(((board[rowNumber+1][columnNumber]==PIECE)&&(rowNumber+1<13))&&((board[rowNumber+2][columnNumber]==PIECE)&&(rowNumber+2<13))))
    return 1;
 else
    return 0;
}
*/

