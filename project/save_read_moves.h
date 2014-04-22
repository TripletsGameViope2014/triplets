#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__
Note: change the __TEMPLATE_H__ macro to name of file _H
(e.g., __DATASTRUCTURES_H__ for datastructures.h)

/**
 * Header file for...
 *
 * @creation date:
 *
 * Triplets Game - VIOPE 2014
 */

/*=====================================
 * includes
 *===================================*/
/* System includes */
#include <...>

/* local includes */
#include "..."

/*=====================================
 * macros and defines
 *===================================*/
#define MAX_NAME	(20)  /* to be erase, already exists on data_structs.h */

/*=====================================
 * typedefs
 *===================================*/
typedef struct example{
	int 	field_A;	/* a comment about the field */
	int	field_B;
}example_t;

/*=====================================
 * function prototypes
 *===================================*/

extern void read_move(position_t *pos);
extern int function_validate_move(position_t pos);
extern void clean_buffer_keyboard(void);
extern char * terminate_string_at_first_slash_n(char *str); 
extern void createLogs(int wYear, int wMonth, int wDay, int wHour, int wMinute, int gameCounter, char logName[], int dimension);
extern void savePlayLog(char playerName[], int playNumber, int moveX, char moveY, int gameCounter, char logName[]);
extern void closePlayLog(int playNumber, char logName[]);
extern void loadLogs(int gameNum);

#endif
