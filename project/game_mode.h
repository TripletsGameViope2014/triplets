#ifndef __GAME_MODE_H__
#define __GAME_MODE_H__

/**
 * Header file for game_mode.c
 *
 * @date: 2014-05-18
 *
 * Triplets Game - VIOPE 2014
 */

/*=====================================
 * includes
 *===================================*/
/* System includes */
//#include <...>

/* local includes */
#include "data_structs.h"
#include "board.h"
#include "PL_ui.h"
#include "PT_save_read_moves.h"

/*=====================================
 * macros and defines
 *===================================*/

/*=====================================
 * typedefs
 *===================================*/

/*=====================================
 * function prototypes
 *===================================*/

extern position_t pvp_normal_mode(position_t pos);
extern position_t pvp_column_mode(position_t pos);


#endif
