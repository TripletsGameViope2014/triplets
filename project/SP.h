#ifndef SP_H_INCLUDED
#define SP_H_INCLUDED


/**
 * Header file for all the functions of
 * the CPU's moves and the
 * finishing game
 *
 * @date: 2014-05-02
 *
 * Triplets Game - VIOPE 2014
 */

/*=====================================
 * includes
 *===================================*/
/* System includes */
//#include <...>

/* local includes */
#include "data_structs.h"

/*=====================================
 * macros and defines
 *===================================*/

 /* Number of aligned pieces that are needed to finish the game */
#define NUM_ALIGNED_PIECES_FINISH (3)

/*=====================================
 * typedefs
 *===================================*/

/*=====================================
 * function prototypes
 *===================================*/
int validate (board_t board [MAX_BOARDSIZE][MAX_BOARDSIZE], int column, int row);
void random_cpu (board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE]);
int diagonally1 (board_t board [MAX_BOARDSIZE][MAX_BOARDSIZE],int columnNumber,int rowNumber);
int diagonally2 (board_t board [MAX_BOARDSIZE][MAX_BOARDSIZE],int columnNumber,int rowNumber);
int horizontal (board_t board [MAX_BOARDSIZE][MAX_BOARDSIZE],int columnNumber,int rowNumber);
int vertical (board_t board [MAX_BOARDSIZE][MAX_BOARDSIZE],int columnNumber,int rowNumber);
void smart (board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE]);
int finish_gamePL(board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE]);
int oneMovFinish (board_t board [MAX_BOARDSIZE][MAX_BOARDSIZE]);
int okMove (position_t pos, board_t board [MAX_BOARDSIZE][MAX_BOARDSIZE]);
int check_let_player_win(board_t board [MAX_BOARDSIZE][MAX_BOARDSIZE]);
int emptyboard(board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE]);
extern void refresh_last_piece(int i, int j);

#endif // SP_H_INCLUDED
