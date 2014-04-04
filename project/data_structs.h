#ifndef __DATA_STRUCTS_H__
#define __DATA_STRUCTS_H__
/**
 * Header file that holds the main data
 * structure definitions
 *
 * @creation date: 2014-03-30
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
/* Some defines */
#define BOARD_SMALL 3 //small board size
#define BOARD_MEDIUM 6 //medium board size
#define BOARD_LARGE 12 //large board size
#define EMPTY ' ' //free position on the board
#define PIECE '#' //board position occupied
#define MAX_PLAYERNAME_LENGTH 20 //maximum size for a player’s nickname
#define MAX_BOARDSIZE 12 //maximum size of the board

/*=====================================
 * typedefs
 *===================================*/

/**
 * Stores data regarding a player
 */
typedef struct player
{
	int moves;	// number of moves
	char name[MAX_PLAYERNAME_LENGTH];
}player_t;

/** The possible game modes
 * PvP - player vs Player
 * PvC - player vs Computer
 * CvC - computer vs computer
 */
typedef enum {pvp, pvc, cvc} game_mode_t;

/**
 * Stores the configuration of the current game
 */
typedef struct game
{
	int player_first;  	// represents the player first option
	game_mode_t game_mode; 	//represents the game mode
	char board[MAX_BOARDSIZE][MAX_BOARDSIZE];
	int board_columns;  	// number of columns of the board
	int board_rows;     	// number of rows of the board
}game_t;

/**
 * FIXME: data structures to hold the game's statistics
 */

/*=====================================
 * External declarations
 *===================================*/

/*=====================================
 * function prototypes
 *===================================*/
extern game_t* get_current_game_ptr(void);
extern player_t* get_players_ptr(void);


extern int is_valid_board_size(const int board_size);
extern int set_board_size(const int board_size);
extern void reset_data_structs(void);


#endif
