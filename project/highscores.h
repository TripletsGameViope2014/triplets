/**
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
 } highscores_t;

/*=====================================
 * function prototypes
 *===================================*/
extern void init_highscores(void);
extern void verify_new_highscore(int new_player_moves, char new_player_name[], int gamemode);
extern void show_highscores();
extern void createHighscores(highscores_t highscores[], int highscore_type);
extern void clearscr(void);
extern int readchar(void);

int highscore_menu();
