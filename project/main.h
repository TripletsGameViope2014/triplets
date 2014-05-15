#ifndef __MAIN_H__
#define __MAIN_H__

/**
 * Header file for...
 *
 * @creation date: 2014-05-15
 *
 * Triplets Game - VIOPE 2014
 */

/*=====================================
 * includes
 *===================================*/
/* System includes */
#include <stdio.h>
#include <string.h>

/* local includes */
#include "data_structs.h"
#include "board.h"
#include "PL_ui.h"
#include "PT_save_read_moves.h"
#include "SP.h"
#include "debug.h"
#include "highscores.h"
#include "util.h"
#include "pl_htmlui.h"

/*=====================================
 * macros and defines
 *===================================*/
#define MAX_NAME    (20)

/*=====================================
 * typedefs
 *===================================*/

/*=====================================
 * function prototypes
 *===================================*/
extern int finish_game_wrapper();
extern void select_move();
extern int main(void);



#endif
