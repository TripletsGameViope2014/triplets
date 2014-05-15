#include <stdio.h>
#include "board.h"
#include "PL_ui.h"
#include "SP.h"
#include "PT_save_read_moves.h"
#include "util.h"
#include "main.h"

void smart (char board[MAX_BOARDSIZE][MAX_BOARDSIZE])
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
                    if(board[i][j]==PIECE)
                    {

                        pos.X=i-2;
                        pos.Y_int=j-1;

                        if(okMove(pos, get_current_game_ptr()->board))
                        {
                            board[i-2][j-1]=PIECE;
                            m=0;
                        }
                        else
                        {

                            pos.X=i-2;
                            pos.Y_int=j+1;

                            if(okMove(pos, get_current_game_ptr()->board))
                            {
                                board[i-2][j+1]=PIECE;
                                m=0;
                            }
                            else
                            {

                                pos.X=i-1;
                                pos.Y_int=j+2;

                                if(okMove(pos, get_current_game_ptr()->board))
                                {
                                    board[i-1][j+2]=PIECE;
                                    m=0;
                                }
                                else
                                {

                                    pos.X=i+1;
                                    pos.Y_int=j+2;

                                    if(okMove(pos, get_current_game_ptr()->board))
                                    {
                                        board[i+1][j+2]=PIECE;
                                        m=0;
                                    }
                                    else
                                    {

                                        pos.X=i+2;
                                        pos.Y_int=j+1;

                                        if(okMove(pos, get_current_game_ptr()->board))
                                        {
                                            board[i+2][j+1]=PIECE;
                                            m=0;
                                        }
                                        else
                                        {

                                            pos.X=i+2;
                                            pos.Y_int=j-1;

                                            if(okMove(pos, get_current_game_ptr()->board))
                                            {
                                                board[i+2][j-1]=PIECE;
                                                m=0;
                                            }
                                            else
                                            {
                                                pos.X=i+1;
                                                pos.Y_int=j-2;

                                                if(okMove(pos, get_current_game_ptr()->board))
                                                {
                                                    board[i+1][j-2]=PIECE;
                                                    m=0;
                                                }
                                                else
                                                {
                                                    pos.X=i-1;
                                                    pos.Y_int=j-2;

                                                    if(okMove(pos, get_current_game_ptr()->board))
                                                    {
                                                        board[i-1][j-2]=PIECE;
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
                savePlayLog(cmp.current_player_move.name, cmp.current_player_move.moves+cmp.previous_player_move.moves+1, pos.X, pos.Y_int+'A', get_game_counter());
            }

        }
    }

}

int oneMovFinish (char board [MAX_BOARDSIZE][MAX_BOARDSIZE])
{
    int i,j;
    position_t pos;
    for(i=0; i<MAX_BOARDSIZE; i++)
    {
        for(j=0; j<MAX_BOARDSIZE; j++)
        {
            if(board[i][j]==EMPTY)
            {
                board[i][j]=PIECE;
                pos.X=i;
                pos.Y_int=j;
                if (finish_game_wrapper(pos))
                {

                    return 1;
                }
                else
                    board[i][j]= EMPTY;
            }

        }

    }
    return 0;
}

int emptyboard(char board[MAX_BOARDSIZE][MAX_BOARDSIZE])
{
    int i, j;

    for(i=0; i<MAX_BOARDSIZE; i++)
    {
        for(j=0; j<MAX_BOARDSIZE; j++)
        {
            if(board[i][j]!=EMPTY)
                return 0;
        }
    }
    return 1;

}

int check_let_player_win(char board [MAX_BOARDSIZE][MAX_BOARDSIZE])
{
    int i,j;
    position_t pos;
    for(i=0; i<MAX_BOARDSIZE; i++)
    {
        for(j=0; j<MAX_BOARDSIZE; j++)
        {
            if(board[i][j]==EMPTY)
            {
                board[i][j]=PIECE;
                pos.X=i;
                pos.Y_int=j;
                if (finish_game_wrapper(pos))
                {
                    board[i][j]=EMPTY;
                    return 1;
                }
                else
                    board[i][j]= EMPTY;
            }

        }

    }
    return 0;


}

int okMove (position_t pos, char board [MAX_BOARDSIZE][MAX_BOARDSIZE])
{
    if(function_validate_move_cpu(pos))
    {
        board[pos.X][pos.Y_int]=PIECE;
        if(check_let_player_win(get_current_game_ptr()->board))
        {
            board[pos.X][pos.Y_int]=EMPTY;
            return 0;
        }
        else
            return 1;
    }

}



