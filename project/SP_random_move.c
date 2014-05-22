/**
 * Triplets Game - VIOPE 2014
 * @file: SP_random_move.c
 * @creation date	2014-05-02
 *
 **/

/*=====================================
 * System includes
 *===================================*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


/*=====================================
 * Local includes
 *===================================*/
#include "board.h"
#include "PL_ui.h"
#include "PT_save_read_moves.h"
#include "util.h"
#include "SP.h"

/*=====================================
 * Prototypes of **private** functions
 *===================================*/


/*=====================================
 * Public functions
 *===================================*/




/**
 * This function represents the random move
 * made by the CPU
 *
 * @v info_s	Just in PvC, in easy mode
 * @return	none
 * @date	2014-04-16
 * @author	SP Team
 **/
void random_cpu (board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE])
{
 position_t position;
 srand(time (NULL));
 int sizes=MAX_BOARDSIZE;

    do
    {
      position.X=rand()%sizes;
      position.Y_int=rand()%sizes;

    }while(!function_validate_move_cpu(position));
    savePlayLog(cmp.current_player_move.name, cmp.current_player_move.moves+cmp.previous_player_move.moves+1, position.X+1, position.Y_int+'A', get_game_counter()+1);
    board[position.X][position.Y_int].piece=PIECE;//Piece is a constant define char '#'
    board[position.X][position.Y_int].player = cmp.current_player_move.number;
    set_last_piece(position.X, position.Y_int);
}


/*=====================================
 * Private functions
 *===================================*/
