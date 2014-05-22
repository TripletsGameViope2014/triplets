/**
 * Triplets Game - VIOPE 2014
 * @file: SP_finish_game.c
 * @creation date	2014-05-02
 *
 **/


/*=====================================
 * System includes
 *===================================*/

/*=====================================
 * Local includes
 *===================================*/
#include "data_structs.h"
#include "SP.h"
#include "board.h"

/*=====================================
 * Prototypes of **private** functions
 *===================================*/


/*=====================================
 * Public functions
 *===================================*/

/**
 * This function change the color of the last piece
 *
 * @v info_s	At the end of the game
 * @return	void
 * @date	2014-05-21
 * @author	PT Team
 **/
void refresh_last_piece(int i, int j)
{
                if (get_current_game_ptr()->board[i][j].lastPiece==0)
                {
                    get_current_game_ptr()->board[i][j].lastPiece = 2;
                }

                else
                {
                    if (get_current_game_ptr()->board[i][j].lastPiece==1)
                    {
                        get_current_game_ptr()->board[i][j].lastPiece = 3;
                    }
                }
}


/**
 * This function verifies is the game is finished or not
 *
 * @v info_s
 * @return	An int, if the game was finished or not
 * @date	2014-05-02
 * @author	Triplets Team
 **/
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

/*=====================================
 * Private functions
 *===================================*/
