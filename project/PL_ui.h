#ifndef _PL_UI_H_
#define _PL_UI_H_

/**
 * Header file for PL_ui.c
 *
 * @date: 2014-05-01
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
player_t G_players[2];
game_t G_current_game;
current_move_t cmp;
position_t pos;

/*=====================================
 * typedefs
 *===================================*/

/*=====================================
 * function prototypes
 *===================================*/
extern void welcome_screen();
extern void show_menu();
extern void clearscr(void);
extern int readchar(void);
extern void show_difficulty();
extern void show_who_first();
extern void init_players();
extern void show_pvp_mode();
extern void choose_interface();


#endif
