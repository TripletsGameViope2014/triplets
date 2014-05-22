/**
 * Triplets Game - VIOPE 2014
 * @file: SP_smart_move.c
 * @creation date	2014-05-02
 *
 **/

/*=====================================
 * System includes
 *===================================*/
#include <stdio.h>

/*=====================================
 * Local includes
 *===================================*/
#include "board.h"
#include "PL_ui.h"
#include "SP.h"
#include "PT_save_read_moves.h"
#include "util.h"
#include "main.h"

/*=====================================
 * Prototypes of **private** functions
 *===================================*/


/*=====================================
 * Public functions
 *===================================*/



/**
 * This function represents the smart move
 * made by the CPU
 *
 * @v info_s	Just in PvC, in hard mode
 * @return	none
 * @date	2014-05-12
 * @author	SP Team
 **/
void smart (board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE])
{
    int i,j, m=3;
    position_t pos;
    if(emptyboard(get_current_game_ptr()->board))
        random_cpu(get_current_game_ptr()->board);

    else
    {
        if(oneMovFinish(get_current_game_ptr()->board))
        {

            printf("\n You have lose the game, I win :) \n");
        }
        else
        {

            for(i=0; i<MAX_BOARDSIZE&&m!=0; i++)
            {

                for(j=0; j<MAX_BOARDSIZE&&m!=0; j++)
                {
                    if(board[i][j].piece==PIECE)
                    {

                        pos.X=i-2;
                        pos.Y_int=j-1;

                        if(okMove(pos, get_current_game_ptr()->board))
                        {
                            board[i-2][j-1].piece=PIECE;
                            m=0;
                        }
                        else
                        {

                            pos.X=i-2;
                            pos.Y_int=j+1;

                            if(okMove(pos, get_current_game_ptr()->board))
                            {
                                board[i-2][j+1].piece=PIECE;
                                m=0;
                            }
                            else
                            {

                                pos.X=i-1;
                                pos.Y_int=j+2;

                                if(okMove(pos, get_current_game_ptr()->board))
                                {
                                    board[i-1][j+2].piece=PIECE;
                                    m=0;
                                }
                                else
                                {

                                    pos.X=i+1;
                                    pos.Y_int=j+2;

                                    if(okMove(pos, get_current_game_ptr()->board))
                                    {
                                        board[i+1][j+2].piece=PIECE;
                                        m=0;
                                    }
                                    else
                                    {

                                        pos.X=i+2;
                                        pos.Y_int=j+1;

                                        if(okMove(pos, get_current_game_ptr()->board))
                                        {
                                            board[i+2][j+1].piece=PIECE;
                                            m=0;
                                        }
                                        else
                                        {

                                            pos.X=i+2;
                                            pos.Y_int=j-1;

                                            if(okMove(pos, get_current_game_ptr()->board))
                                            {
                                                board[i+2][j-1].piece=PIECE;
                                                m=0;
                                            }
                                            else
                                            {
                                                pos.X=i+1;
                                                pos.Y_int=j-2;

                                                if(okMove(pos, get_current_game_ptr()->board))
                                                {
                                                    board[i+1][j-2].piece=PIECE;
                                                    m=0;
                                                }
                                                else
                                                {
                                                    pos.X=i-1;
                                                    pos.Y_int=j-2;

                                                    if(okMove(pos, get_current_game_ptr()->board))
                                                    {
                                                        board[i-1][j-2].piece=PIECE;
                                                        m=0;
                                                    }
                                                }

                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }

                }
            }
            if(m)
            {
                random_cpu(get_current_game_ptr()->board);
            }

            else
            {
                savePlayLog(cmp.current_player_move.name, cmp.current_player_move.moves+cmp.previous_player_move.moves+1, pos.X+1, pos.Y_int+'A', get_game_counter()+1);
                board[pos.X][pos.Y_int].player = cmp.current_player_move.number;
                set_last_piece(pos.X, pos.Y_int);
            }

        }
    }

}

/**
 * This function verifies is the next move makes the CPU
 * wins or not
 *
 * @v info_s	Just in PvC
 * @return	An int, if the move makes the CPU wins or not
 * @date	2014-05-12
 * @author	SP Team
 **/
int oneMovFinish (board_t board [MAX_BOARDSIZE][MAX_BOARDSIZE])
{
    int i,j;
    position_t pos;
    for(i=0; i<board_get_size(); i++)
    {
        for(j=0; j<board_get_size(); j++)
        {
            if(board[i][j].piece==EMPTY)
            {
                board[i][j].piece=PIECE;
                pos.X=i;
                pos.Y_int=j;
                if (finish_game_wrapper(pos))
                {
                    savePlayLog(cmp.current_player_move.name, cmp.current_player_move.moves+cmp.previous_player_move.moves+1, pos.X+1, pos.Y_int+'A', get_game_counter()+1);
                    board[pos.X][pos.Y_int].player = cmp.current_player_move.number;
                    set_last_piece(pos.X, pos.Y_int);

                    return 1;
                }
                else
                    board[i][j].piece=EMPTY;
            }

        }

    }
    return 0;
}


/**
 * This function verifies is the board is empty
 *
 * @v info_s	Just in PvC
 * @return	An int, if the board was empty or not
 * @date	2014-05-12
 * @author	SP Team
 **/
int emptyboard(board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE])
{
    int i, j;

    for(i=0; i<MAX_BOARDSIZE; i++)
    {
        for(j=0; j<MAX_BOARDSIZE; j++)
        {
            if(board[i][j].piece!=EMPTY)
                return 0;
        }
    }
    return 1;

}


/**
 * This function verifies is the move from the CPU is smart
 * or not and write it on the board
 *
 * @v info_s	Just in PvC
 * @return	An int, if the move was written or not
 * @date	2014-05-12
 * @author	SP Team
 **/
int check_let_player_win(board_t board [MAX_BOARDSIZE][MAX_BOARDSIZE])
{
    int i,j;
    position_t pos;
    for(i=0; i<MAX_BOARDSIZE; i++)
    {
        for(j=0; j<MAX_BOARDSIZE; j++)
        {
            if(board[i][j].piece==EMPTY)
            {
                board[i][j].piece=PIECE;
                pos.X=i;
                pos.Y_int=j;
                if (finish_game_wrapper(pos))
                {
                    board[i][j].piece=EMPTY;
                    return 1;
                }
                else
                    board[i][j].piece=EMPTY;
            }

        }

    }
    return 0;


}

/**
 * This function assists the verifications for the smart move
 * of the CPU
 *
 * @v info_s	Just in PvC
 * @return	An int, if the move was written or not
 * @date	2014-05-12
 * @author	SP Team
 **/
int okMove (position_t pos, board_t board [MAX_BOARDSIZE][MAX_BOARDSIZE])
{
    if(function_validate_move_cpu(pos))
    {
        board[pos.X][pos.Y_int].piece=PIECE;
        if(check_let_player_win(get_current_game_ptr()->board))
        {
            board[pos.X][pos.Y_int].piece=EMPTY;
            return 0;
        }
        else
            return 1;
    }
    else
    {
        return 0;
    }

}


/*=====================================
 * Private functions
 *===================================*/


