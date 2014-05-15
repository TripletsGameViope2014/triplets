#include <stdlib.h>
#include<stdio.h>
#include <time.h>
#include "board.h"
#include "PL_ui.h"
#include "PT_save_read_moves.h"
#include "util.h"


void random_cpu (char board[MAX_BOARDSIZE][MAX_BOARDSIZE])
{
 position_t position;
 srand(time (NULL));
 int sizes=board_get_size();

    do
    {
      position.X=rand()%sizes;
      position.Y_int=rand()%sizes;

    }while(!function_validate_move_cpu(position));
    savePlayLog(cmp.current_player_move.name, cmp.current_player_move.moves+cmp.previous_player_move.moves+1, position.X, position.Y_int+'A', get_game_counter());
    board[position.X][position.Y_int]=PIECE;//Piece is a constant define char '#'

}


/*
void random_cpu (char board[MAX_BOARDSIZE][MAX_BOARDSIZE])
//We must use #include<time.h> and #include<stdlib.h>.
{int randRow,randColumn;
 //char columnName;
 srand(time (NULL));
 int SIZE=board_get_size();
 int check=1;

   // do
   // {
   //   randRow=rand()%SIZE;
   //   randColumn=rand()%SIZE;
     // columnName=turn_name(columnNumber);//This function turn the columnNumber in to a letter;

   // }while(!validate(board,randColumn,randRow));

do{
                randRow=rand()%SIZE;
                randColumn=rand()%SIZE;
                pos.X=randRow;
                pos.Y_int=randColumn;
               // printf("%s your move! (all your moves: %d)\n",cmp.current_player_move.name,cmp.current_player_move.moves);
               // read_move(&pos);
                check = function_validate_move(pos);
                }while(check != 0);


    board[randRow][randColumn]=PIECE;//Piece is a constant define char '#'

}
*/
