#ifndef SP_H_INCLUDED
#define SP_H_INCLUDED


/*Relative path:    "..\..\..\..\GitHub\triplets\project\data_structs.h"
                    "..\..\..\..\GitHub\triplets\project\data_structs.c"
                    "..\..\..\..\GitHub\triplets\project\util.c"
                    "..\..\..\..\GitHub\triplets\project\util.h"
                    "..\..\..\..\GitHub\triplets\project\board.h"
                    "..\..\..\..\GitHub\triplets\project\board.c"
                    "..\..\..\..\GitHub\triplets\project\SP.h"
                    "..\..\..\..\GitHub\triplets\project\SP_finish_game.c"

*/

#include "C:\Users\Gabriel Amarista\Documents\GitHub\triplets\project\data_structs.h"
#include "C:\Users\Gabriel Amarista\Documents\GitHub\triplets\project\data_structs.c"
#include "C:\Users\Gabriel Amarista\Documents\GitHub\triplets\project\util.c"
#include "C:\Users\Gabriel Amarista\Documents\GitHub\triplets\project\util.h"
#include "C:\Users\Gabriel Amarista\Documents\GitHub\triplets\project\board.h"
#include "C:\Users\Gabriel Amarista\Documents\GitHub\triplets\project\board.c"
#include "C:\Users\Gabriel Amarista\Documents\GitHub\triplets\project\SP.h"
#include "C:\Users\Gabriel Amarista\Documents\GitHub\triplets\project\SP_finish_game.c"


/**
 * These are the functions to test the finish game
 * The functions are divided by the size of the board
 * For every size of the board we checked the four corner
 * For every corner we had three tests: Horizontally, Vertically and Diagonally
 * The first test is to make sure that it does not finish when we don't have three pieces together
 * A total of 49 tests
 *
 * @v info_s
 * @date	2014-05-21
 * @author	Gabriel Rodrigues (Triplets Team)
 **/


/*
    +----------+
    |1        2| These are the numbers of the corners
    |          | Example:
    |          |        finish_gamePL_test_large_1v:
    |          |        First corner (1) and vertically check, large board.
    |3        4|
    +----------+



*/


TEST(finish_gamePL_test_one){


    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[0][1].piece = '#';
    board[0][4].piece = '#';
    board[0][3].piece = '#';
    CHECK(finish_gamePL(board) == 0);
}

///LARGE BOARD

TEST(finish_gamePL_test_large_1v){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[0][1].piece = '#';
    board[0][2].piece = '#';
    board[0][3].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_large_1d){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[1][1].piece = '#';
    board[2][2].piece = '#';
    board[3][3].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_large_1h){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[1][0].piece = '#';
    board[2][0].piece = '#';
    board[3][0].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_large_4d){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[BOARD_LARGE-3][BOARD_LARGE-3].piece = '#';
    board[BOARD_LARGE-2][BOARD_LARGE-2].piece = '#';
    board[BOARD_LARGE-1][BOARD_LARGE-1].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_large_4v){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[BOARD_LARGE-1][BOARD_LARGE-3].piece = '#';
    board[BOARD_LARGE-1][BOARD_LARGE-2].piece = '#';
    board[BOARD_LARGE-1][BOARD_LARGE-1].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}


TEST(finish_gamePL_test_large_4h){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[BOARD_LARGE-3][BOARD_LARGE-1].piece = '#';
    board[BOARD_LARGE-2][BOARD_LARGE-1].piece = '#';
    board[BOARD_LARGE-1][BOARD_LARGE-1].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_large_3v){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[0][BOARD_LARGE-3].piece = '#';
    board[0][BOARD_LARGE-2].piece = '#';
    board[0][BOARD_LARGE-1].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_large_3d){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[2][BOARD_LARGE-3].piece = '#';
    board[1][BOARD_LARGE-2].piece = '#';
    board[0][BOARD_LARGE-1].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_large_3h){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[2][BOARD_LARGE-1].piece = '#';
    board[1][BOARD_LARGE-1].piece = '#';
    board[0][BOARD_LARGE-1].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_large_2h){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[BOARD_LARGE-3][0].piece = '#';
    board[BOARD_LARGE-2][0].piece = '#';
    board[BOARD_LARGE-1][0].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_large_2d){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[BOARD_LARGE-3][2].piece = '#';
    board[BOARD_LARGE-2][1].piece = '#';
    board[BOARD_LARGE-1][0].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}


TEST(finish_gamePL_test_large_2v){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[BOARD_LARGE-1][2].piece = '#';
    board[BOARD_LARGE-1][1].piece = '#';
    board[BOARD_LARGE-1][0].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

///BIG BOARD

TEST(finish_gamePL_test_big_1v){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[0][1].piece = '#';
    board[0][2].piece = '#';
    board[0][3].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_big_1d){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[1][1].piece = '#';
    board[2][2].piece = '#';
    board[3][3].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_big_1h){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[1][0].piece = '#';
    board[2][0].piece = '#';
    board[3][0].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_big_4d){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[BOARD_BIG-3][BOARD_BIG-3].piece = '#';
    board[BOARD_BIG-2][BOARD_BIG-2].piece = '#';
    board[BOARD_BIG-1][BOARD_BIG-1].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_big_4v){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[BOARD_BIG-1][BOARD_BIG-3].piece = '#';
    board[BOARD_BIG-1][BOARD_BIG-2].piece = '#';
    board[BOARD_BIG-1][BOARD_BIG-1].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}


TEST(finish_gamePL_test_big_4h){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[BOARD_BIG-3][BOARD_BIG-1].piece = '#';
    board[BOARD_LARGE-2][BOARD_BIG-1].piece = '#';
    board[BOARD_BIG-1][BOARD_BIG-1].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_big_3v){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[0][BOARD_BIG-3].piece = '#';
    board[0][BOARD_BIG-2].piece = '#';
    board[0][BOARD_BIG-1].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_big_3d){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[2][BOARD_BIG-3].piece = '#';
    board[1][BOARD_BIG-2].piece = '#';
    board[0][BOARD_BIG-1].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_big_3h){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[2][BOARD_BIG-1].piece = '#';
    board[1][BOARD_BIG-1].piece = '#';
    board[0][BOARD_BIG-1].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_big_2h){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[BOARD_BIG-3][0].piece = '#';
    board[BOARD_BIG-2][0].piece = '#';
    board[BOARD_BIG-1][0].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_big_2d){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[BOARD_BIG-3][2].piece = '#';
    board[BOARD_BIG-2][1].piece = '#';
    board[BOARD_BIG-1][0].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}


TEST(finish_gamePL_test_big_2v){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[BOARD_BIG-1][2].piece = '#';
    board[BOARD_BIG-1][1].piece = '#';
    board[BOARD_BIG-1][0].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

///MEDIUM BOARD

TEST(finish_gamePL_test_medium_1v){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[0][1].piece = '#';
    board[0][2].piece = '#';
    board[0][3].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_medium_1d){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[1][1].piece = '#';
    board[2][2].piece = '#';
    board[3][3].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_medium_1h){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[1][0].piece = '#';
    board[2][0].piece = '#';
    board[3][0].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_medium_4d){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[BOARD_MEDIUM-3][BOARD_MEDIUM-3].piece = '#';
    board[BOARD_MEDIUM-2][BOARD_MEDIUM-2].piece = '#';
    board[BOARD_MEDIUM-1][BOARD_MEDIUM-1].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_medium_4v){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[BOARD_MEDIUM-1][BOARD_MEDIUM-3].piece = '#';
    board[BOARD_MEDIUM-1][BOARD_MEDIUM-2].piece = '#';
    board[BOARD_MEDIUM-1][BOARD_MEDIUM-1].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}


TEST(finish_gamePL_test_medium_4h){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[BOARD_MEDIUM-3][BOARD_MEDIUM-1].piece = '#';
    board[BOARD_MEDIUM-2][BOARD_MEDIUM-1].piece = '#';
    board[BOARD_MEDIUM-1][BOARD_MEDIUM-1].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_medium_3v){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[0][BOARD_MEDIUM-3].piece = '#';
    board[0][BOARD_MEDIUM-2].piece = '#';
    board[0][BOARD_MEDIUM-1].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_medium_3d){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[2][BOARD_MEDIUM-3].piece = '#';
    board[1][BOARD_MEDIUM-2].piece = '#';
    board[0][BOARD_MEDIUM-1].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_medium_3h){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[2][BOARD_MEDIUM-1].piece = '#';
    board[1][BOARD_MEDIUM-1].piece = '#';
    board[0][BOARD_MEDIUM-1].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_medium_2h){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[BOARD_MEDIUM-3][0].piece = '#';
    board[BOARD_MEDIUM-2][0].piece = '#';
    board[BOARD_MEDIUM-1][0].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_medium_2d){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[BOARD_MEDIUM-3][2].piece = '#';
    board[BOARD_MEDIUM-2][1].piece = '#';
    board[BOARD_MEDIUM-1][0].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}


TEST(finish_gamePL_test_medium_2v){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[BOARD_MEDIUM-1][2].piece = '#';
    board[BOARD_MEDIUM-1][1].piece = '#';
    board[BOARD_MEDIUM-1][0].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

///SMALL BOARD

TEST(finish_gamePL_test_small_1v){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[0][1].piece = '#';
    board[0][2].piece = '#';
    board[0][3].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_small_1d){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[1][1].piece = '#';
    board[2][2].piece = '#';
    board[3][3].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_small_1h){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[1][0].piece = '#';
    board[2][0].piece = '#';
    board[3][0].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_small_4d){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[BOARD_SMALL-3][BOARD_SMALL-3].piece = '#';
    board[BOARD_SMALL-2][BOARD_SMALL-2].piece = '#';
    board[BOARD_SMALL-1][BOARD_SMALL-1].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_small_4v){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[BOARD_SMALL-1][BOARD_SMALL-3].piece = '#';
    board[BOARD_SMALL-1][BOARD_SMALL-2].piece = '#';
    board[BOARD_SMALL-1][BOARD_SMALL-1].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}


TEST(finish_gamePL_test_small_4h){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[BOARD_SMALL-3][BOARD_SMALL-1].piece = '#';
    board[BOARD_SMALL-2][BOARD_SMALL-1].piece = '#';
    board[BOARD_SMALL-1][BOARD_SMALL-1].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_small_3v){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[0][BOARD_SMALL-3].piece = '#';
    board[0][BOARD_SMALL-2].piece = '#';
    board[0][BOARD_SMALL-1].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_small_3d){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[2][BOARD_SMALL-3].piece = '#';
    board[1][BOARD_SMALL-2].piece = '#';
    board[0][BOARD_SMALL-1].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_small_3h){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[2][BOARD_SMALL-1].piece = '#';
    board[1][BOARD_SMALL-1].piece = '#';
    board[0][BOARD_SMALL-1].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_small_2h){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[BOARD_SMALL-3][0].piece = '#';
    board[BOARD_SMALL-2][0].piece = '#';
    board[BOARD_SMALL-1][0].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

TEST(finish_gamePL_test_small_2d){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[BOARD_SMALL-3][2].piece = '#';
    board[BOARD_SMALL-2][1].piece = '#';
    board[BOARD_SMALL-1][0].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}


TEST(finish_gamePL_test_small_2v){

    board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
    board[BOARD_SMALL-1][2].piece = '#';
    board[BOARD_SMALL-1][1].piece = '#';
    board[BOARD_SMALL-1][0].piece = '#';
    CHECK(finish_gamePL(board) == 1);
}

#endif // SP_H_INCLUDED
