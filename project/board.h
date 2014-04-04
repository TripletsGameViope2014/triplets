#ifndef __BOARD_H__
#define __BOARD_H__
/**
 * Header file for board.c
 *
 * @date: 2014-03-31
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

/*=====================================
 * macros and defines
 *===================================*/

/*=====================================
 * typedefs
 *===================================*/

/*=====================================
 * function prototypes
 *===================================*/
extern int board_get_size(void);
extern int board_set_size(const int board_size);
extern void board_set_empty(void);
extern int board_is_valid_size(const int board_size);
extern void board_print_raw(void);

#endif
