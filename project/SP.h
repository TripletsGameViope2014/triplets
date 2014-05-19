#ifndef SP_H_INCLUDED
#define SP_H_INCLUDED

#include "data_structs.h"

int validate (board_t board [MAX_BOARDSIZE][MAX_BOARDSIZE], int column, int row);
void random_cpu (board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE]);
int finish_game (board_t board [MAX_BOARDSIZE][MAX_BOARDSIZE],int columnName,int rowNumber);
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

#endif // SP_H_INCLUDED
