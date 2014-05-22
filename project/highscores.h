#ifndef __HIGHSCORES_H__
#define __HIGHSCORES_H__

/**
 * Header file for highscores.c
 * Triplets Game - VIOPE 2014
 * @file: highscores.h
 *
 * @creation	2014-04-14
 *
 **/

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

#define MAX_HIGHSCORES 10

/*=====================================
 * typedefs
 *===================================*/

/**
 * Stores highscores
 */
  typedef struct
 {
     char player_name[MAX_PLAYERNAME_LENGTH];
     int player_moves;
     int game_counter;
     char game_mode[5];
 } highscores_t;

/*=====================================
 * function prototypes
 *===================================*/
extern void init_highscores(void);
extern void verify_new_highscore(int new_player_moves, char new_player_name[], int game_size, int gameCounter, int game_mode_i);
extern void show_highscores();
extern void createHighscores(highscores_t highscores[], int highscore_type);
extern void clearscr(void);
extern int readchar(void);
extern int highscore_menu();

#endif
