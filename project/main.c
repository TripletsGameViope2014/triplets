#include <stdlib.h>
/**
 * Triplets Game - VIOPE 2014
 * @file main.c
 *
 * @creation date	2014-03-27
 *
 **/

/*=====================================
 * System includes
 *===================================*/
#include <stdio.h>

/*=====================================
 * Local includes
 *===================================*/
#include "data_structs.h"
#include "board.h"


/*=====================================
 * main
 *===================================*/
int main(void){
	reset_data_structs();

	/* Simple testing code */
	board_set_size(BOARD_MEDIUM);

	board_print_raw();

	return 0;
}
