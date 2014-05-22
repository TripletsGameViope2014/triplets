#ifndef PL_HTMLUI_H_INCLUDED
#define PL_HTMLUI_H_INCLUDED


/**
 * Header file for PL_htmlui.c
 *
 * @date: 2014-05-12
 *
 * Triplets Game - VIOPE 2014
 */

/*=====================================
 * includes
 *===================================*/
/* System includes */
//#include <...>

/* local includes */
//#include "..."

/*=====================================
 * macros and defines
 *===================================*/


/*=====================================
 * typedefs
 *===================================*/


/*=====================================
 * function prototypes
 *===================================*/
void WriteHTML(board_t board [MAX_BOARDSIZE][MAX_BOARDSIZE], char* HTMLName);
int finish_game_wrapper(position_t current_pos);


#endif // PL_HTMLUI_H_INCLUDED
