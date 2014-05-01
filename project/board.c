/**
* Triplets Game - VIOPE 2014
* @file: board.c
*
* @creation 2014-03-30
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
#include "data_structs.h"


/*=====================================
* Public declarations
*===================================*/

/*=====================================
* Public functions
*===================================*/

/**
* Getter function for the board size
*
* @return Current board size
* @date 2014-03-31
* @author Triplet VIOPE 2014
*/
int board_get_size(void){
return get_current_game_ptr()->board_rows;
}

/**
* Function to set the board size
*
* @v board_size value to use for board size
* @return 0 if the specified board size is invalid, otherwise it returns
* the board size
* @date 2014-03-31
* @author Triplet VIOPE 2014
*/
int board_set_size(const int board_size)
{
if( ! board_is_valid_size(board_size) ){
fprintf(stderr, "[Err] Invalid board size:%d\n", board_size);
return 0;
}

/* Setting the board size */
get_current_game_ptr()->board_rows = board_size;

/* Clear board */
board_set_empty();

return board_size;
}

/**
* Function that the **whole** board as empty (the whole matrix)
*
* @return None
* @date 2014-03-31
* @author Triplet VIOPE 2014
*/
void board_set_empty(void){
int i,j;
int board_size = MAX_BOARDSIZE;

for(i=0;i<board_size;i++){
for(j=0;j<board_size;j++){
get_current_game_ptr()->board[i][j] = EMPTY;
}
}
}


/**
* Validate the board_size parameter checking whether board_size is
* valid (i.e., is BOARD_SMALL, BOARD_MEDIUM or BOARD_LARGE) or not valid.
*
* @v board_size board size to validate
* @return 1 if board size is valid
* @date 2014-03-31
* @author Triplet VIOPE 2014
*/
int board_is_valid_size(const int board_size)
{
if( board_size == BOARD_SMALL
|| board_size == BOARD_MEDIUM
|| board_size == BOARD_LARGE ){
return 1;
}

/* Still here? Not valid... */
return 0;
}

/**
* Print the current board to stdout in a raw manner
* (nofancy characters to draw the boarders)
*/

/**
* Print the current board
* @return None
* @date 2014-04-21
* @author  PL team -Triplet VIOPE 2014
*/
void board_print_raw(void){
	int i,j,k,l,m;
	int board_size = board_get_size();
	printf("[INFO] Board: %d x %d\n", board_size,board_size);
	if(board_size==BOARD_SMALL){
	printf("     GAME BOARD\n");}
    if(board_size==BOARD_MEDIUM){
	printf("           GAME BOARD\n");}
	if(board_size==BOARD_LARGE){
	printf("                     GAME BOARD\n");}

	for(i=0;i<board_size;i++){
            printf("    ");
	    for(k=0;k<board_size;k++){
		        printf("+---");}
        printf("+\n");
        if (i>8){
            printf(" %d ",i+1);
        }
        else{
        printf("  %d ",i+1);
        }
		for(j=0;j<board_size;j++){
			printf("| ");
			printf("%c ", get_current_game_ptr()->board[i][j]);
		}
		printf("|\n");
	}
	printf("    ");
	for(l=0;l<board_size;l++){
        printf("+---");}
	printf("+\n     ");
	char f=65;
	for(m=0;m<board_size;m++){
        printf(" %c  ",f);
        f=f+1;}
printf("\n");
}



/*=====================================
* Private functions
*===================================*/
