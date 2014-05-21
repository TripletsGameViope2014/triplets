#ifndef __UTIL_H__
#define __UTIL_H__

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


/* local includes */


/*=====================================
 * macros and defines
 *===================================*/


/*=====================================
 * typedefs
 *===================================*/


/*=====================================
 * function prototypes
 *===================================*/
extern void getDate(char dateExtended[]);
extern void set_game_counter(int gameCounter);
extern int get_game_counter();
extern int increment_game_counter();
extern int get_file_lines(char fileName[]);
extern void create_folder(char folderName[]);
extern void string_to_lower(char string[]);

/*
 *	Color codes:
 *	0 - black
 *	1 - red
 *	2 - green
 *	3 - yellow
 *	4 - blue
 *	5 - magenta
 *	6 - cyan
 *	7 - white
*/
extern void setTextColor(int foreground, int background);

#endif
