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
#define BLACK 0
#define GREEN 10
#define WHITE 7
#define RED 12
#define BLUE 9
#define YELLOW 14
#define LIGHT_GRAY 7
#define LAST_MOVE_COLOR RED
#define PLAYER_1_COLOR GREEN
#define PLAYER_2_COLOR YELLOW
#define DIFFERENT_COLORS YELLOW // NOTE!!! if = 0 it prints different colors. if != 0 it prints all in the color represented by the constant!
#define BACKGROUND_FINISH BLACK

/*=====================================
 * typedefs
 *===================================*/

/**
 * Stores data regarding a player
 */
typedef struct player
{
	int moves;	// number of moves
	int number;
	char name[MAX_PLAYERNAME_LENGTH];
}player_t;

/** The possible game modes
 * PvP - Player vs Player
 * PvC - player vs Computer
 * CvC - computer vs computer
 */
typedef enum {pvp, pvc, cvc} game_mode_t;

/** The possible difficulty modes           //
 * EASY - Player vs Computer (Easy)         //
 * HARD - Player vs Computer (Hard)         // NEW enum type for the difficulty of the CPU
 * NONE - Player vs Player                  //
 */                                         //
typedef enum {easy, hard, none} cpu_difficulty_t; //

/** The possible difficulty modes           //
 * NORMAL - Player vs Player (Normal Mode)         //
 * COLUMN - Player vs Player (Column Mode)         // NEW enum type for the mode of the PvP
 * NONE   - Player vs Player                  //
 */                                         //
typedef enum {normal, column, notpvp} pvp_mode_t;

/** The possible interface                       //
 * HTML - HTML interface                         //
 * CONSOLE - Console interface                   // NEW enum type for the mode of the PvP
 */
typedef enum {html, console} game_interface_t;


/**
 * Stores the configuration of the current game
 */
 typedef struct board
 {
     int player;
     int lastPiece;
     char piece;
 } board_t;

typedef struct game
{
	int player_first;  	// represents the player first option
	game_mode_t game_mode; 	//represents the game mode
	board_t board[MAX_BOARDSIZE][MAX_BOARDSIZE];
	int board_columns;  	// number of columns of the board
	int board_rows;     	// number of rows of the board
	cpu_difficulty_t cpu_mode;  ///represents the difficulty of the cpu in the PvC mode NEW
	pvp_mode_t pvp_mode; ///represents the game mode
	game_interface_t interface_mode; // represents the interface of the game play
}game_t;


/**
 * auxiliary structure to assign who is currently moves, and change current player
 * @date	2014-05-05
 * @author	PL team
 **/
typedef struct
{
  player_t current_player_move;
  player_t previous_player_move;
  player_t tmp; //temporary
}current_move_t;

/**
 * Stores the move played by the user
 */
typedef struct
{
    	char Y;		//char that indicates the column for the user
    	int X;		//int that indicates the row for the user and the index of the board later
    	int Y_int;	//int to indicate the index of the column in the matrix
}position_t;


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
