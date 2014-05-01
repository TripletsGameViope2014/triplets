/**
 * Triplets Game - VIOPE 2014
 *
 * @creation date	2014-03-27
 *
 **/

/*=====================================
 * System includes
 *===================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <ctype.h>

/*=====================================
 * Local includes
 *===================================*/
#include "board.h"
#include "data_structs.h"
#include "save_read_moves.h"

/*=====================================
 * Prototypes of **private** functions
 *===================================*/
static void example_of_private_function(int num_states);


/*=====================================
 * Public functions
 *===================================*/

/**
 * Brief description of the function
 *
 * @v info_s	string hold with some info
 * @return	what does this function returns
 * @date	2014-03-27
 * @author	name of the author of the function
 **/


int example_of_function(char *info_s){

	int value_to_return = ...;

	return value_to_return;
}

/**
 * This function initializes the log file
 *
 * @v info_s	parameters to create the file
 * @return	void
 * @date	2014-04-14
 * @author	Eduardo Andrade (PT)
 **/

void createLogs(int wYear, int wMonth, int wDay, int wHour, int wMinute, int gameCounter, char logName[], int dimension){
    FILE *newLog;
    char year[5];
    char month[3];
    char day[3];
    char hour[3];
    char minute[3];
    char dateExtended[15] = "";

    sprintf(year, "%d", wYear);     // turn int variables into char for strcat
    sprintf(month, "%d", wMonth);
    sprintf(day, "%d", wDay);
    sprintf(hour, "%d", wHour);
    sprintf(minute, "%d", wMinute);

    strcat(dateExtended, year);     // joining date into single array
    strcat(dateExtended, "/");
    strcat(dateExtended, month);
    strcat(dateExtended, "/");
    strcat(dateExtended, day);
    strcat(dateExtended, "-");
    strcat(dateExtended, hour);
    strcat(dateExtended, ":");
    strcat(dateExtended, minute);

    newLog = fopen(logName, "w");
    if(newLog == NULL){
        printf("\n\tERR: Unable to create Log!");
    }
    else{
        fprintf(newLog, "--Triplets Log--\n");
        fprintf(newLog, "Game #%d\n", gameCounter);
        fprintf(newLog, "Matrix Dimension: %d\n", dimension);
        // call function to initiate matrix with dimension dimension (empty)
        fprintf(newLog, "Started on: %s\n", dateExtended);
    }
    fclose(newLog);
}

/**
 * This function is called every time the user makes a move, and saves it in the log file
 *
 * @v info_s	parameters to write on the file
 * @return	void
 * @date	2014-04-14
 * @author	Eduardo Andrade (PT)
 **/

void savePlayLog(char playerName[], int playNumber, int moveX, char moveY, int gameCounter, char logName[]){
    FILE *playLog;

    playLog = fopen(logName, "a");
    if(playLog == NULL){
        printf("\n\tERR: Couldn't write to %s", logName);
    }
    else{
        fprintf(playLog, "Player %s ; Play %d ; Move [%d][%c]", playerName, playNumber, moveX, moveY);
    }
    fclose(playLog);
}

/**
 * Closes the log file with the number of moves (it's needed to load moves)
 *
 * @v playNumber->number of moves to write ; logName->logfile name
 * @return	void
 * @date	2014-05-15
 * @author João Ramos (PT)
 **/

void closePlayLog(int playNumber, char logName[])
{
FILE *playLog;

    playLog = fopen(logName, "a");
    if(playLog == NULL){
        printf("\n\tERR: Couldn't close %s", logName);
    }
    else{
        fprintf(playLog, "# Game closed successfully!\n");
        fprintf(playLog, "# Number of moves: %d", playNumber);
    }
    fclose(playLog);
}

/**
 * Makes a replay of the game (loads the logfile and then input every single move into the function designed to the user input)
 *
 * @v gameNum->the game number to load the respective logfile
 * @return	void
 * @date	2014-05-15
 * @author João Ramos (PT)
 **/

void loadLogs(int gameNum){

    FILE *logFile;

char logName[30] = "TripletsLog-";
char gameCounterChar[4];
int playNumber;
int gameCounter;
char dateExtended[15];
char playerName[30];
int dimension;
int i;
int moveX;
char moveY;

    sprintf(gameCounterChar, "%d", gameNum);
    strcat(logName, gameCounterChar);
    strcat(logName, ".txt");

    logFile = fopen(logName, "r");
    if(logFile == NULL){
        printf("\n\tERR: Unable to read Log!");
    }
    else{

        fscanf(logFile, "# Game closed successfully!");
        fscanf(logFile, "# Number of moves: %d", &playNumber);

        fscanf(logFile, "--Triplets Log--\n");
        fscanf(logFile, "Game #%d\n", &gameCounter);
        fscanf(logFile, "# Matrix Dimension: %d", &dimension);
        // call function to initiate an empty matrix with dimension dimension
        fscanf(logFile, "Started on: %s\n", &dateExtended);


for (i=0;i<playNumber;i++){
        fscanf(logFile, "Player %s ; Play %d ; Move [%d][%c]", &playerName, &playNumber, &moveX, &moveY);
        // call function to do a singular move
        Sleep(2000); // time between moves
}

Sleep(3000);

        // call MENU function
    }

    fclose(logFile);
}


/**
 * This function read a string from the user and 
 * separate the value of the column and the row
 *
 * @v info_s	Also validates the size of the string and limits
 * 			Of the row and column.
 * @return doesn't return anything, the struct position_t pass
 * 		by refference.
 * @date	2014-04-20
 * @author	Gabriel Rodrigues (PT Team)
 **/

void read_move(position_t *pos){

/* Maximum size for the buffer to read a move: 3 characters + 1 \n + 1 \0 => 5 */
#define READ_MOVE_MAX_BUFF_LEN      (5)

    int dimension = board_get_size();

    //The move_in_board (being the move read from the user) is 5 to verify the length of the input
//    char move_in_board[READ_MOVE_MAX_BUFF_LEN];
    char move_in_board[READ_MOVE_MAX_BUFF_LEN];

    // Maximum number of characters we want to read with fgets (includes '\n' and '\0')
    int maxLength = READ_MOVE_MAX_BUFF_LEN; //This allows one more character in order to verify the length of the input

    // Keep the number of char in the move_in_board string
    size_t move_in_board_strlen;

    do{
        do{
            printf("Write your move [3 characters max]: ");
            fgets(move_in_board, maxLength, stdin);    //gets in the string move_in_board a maximum of maxLength characters coming from the STDIN


            /* Terminate the string at the first \n */
            terminate_string_at_first_slash_n(move_in_board);

            /* Compute # of chars in move_in_board */
            move_in_board_strlen = strlen(move_in_board);

            if( move_in_board_strlen > 3){
                clean_buffer_keyboard();
                printf("The move has a maximum of three characters!\n");
            }

        }while(move_in_board_strlen > 3);

        pos->X = input_is_digit(move_in_board);
        pos->Y = input_is_char(move_in_board);
        pos->Y = toupper(pos->Y);
        pos->Y_int = board_col_to_matrix_idx(pos->Y);

        if(pos->X < 1 || pos->X > dimension){
                printf("Invalid number!\nThe number has to be between 1 - %d\n\n", dimension);
        }
        if(pos->Y_int == -1 || pos->Y_int >= dimension){
                printf("Invalid letter!\nIt has to be between A - %c\n\n", 64+dimension);
        }

    }while(pos->Y_int == -1 || pos->Y_int >= dimension || pos->X < 1 || pos->X > dimension);

    printf("Part of the board! \n");

}


/**
 * This function validates if the given position is already
 * occupied or if it's free
 *
 * @v info_s	This function is called after "read_move"
 * @return	An int "1" if the spot is occupied or "0" if it's not
 * @date	2014-04-15
 * @author	Gabriel Rodrigues (PT Team)
 **/

int function_validate_move(position_t pos){

    if(board_get_content_row_col(pos.X, pos.Y) == EMPTY){

        printf("Valid move!\n");
        board_set_content_row_col(pos.X, pos.Y);
    }
    else{
        printf("That spot is occupied!!!\n");
        return 1;
        }
    return 0;
}


/**
 * This function cleans the buffer from useless  
 * things that could be there after a read from the STDIN
 *
 * @v info_s	It erases all until get and '\n' or EOF
 * @return	 Anything
 * @date	2014-04-15
 * @author	(PT Team)
 **/

void clean_buffer_keyboard(void){
    char chr;
    do
    {
        chr = getchar();
        printf("char = %c", chr);
    }
    while (chr != '\n' && chr != EOF);
}


/**
 * This function terminates the string when it finds the '\n'  
 *
 * @v info_s	Necessary after the "fgets" function because
 * 			we don't want the '\0' at the end of the string
 * @return	 a pointer to the string
 * @date	2014-04-18
 * @author	(PT Team)
 **/

char* terminate_string_at_first_slash_n(char *str){
	char* ptr;
	ptr = strchr(str, '\n');
	if (ptr != NULL)
	{
		*ptr = '\0';
	}
	return str;
}


/**
 * This function helps the test of reading, converting and
 * validating moves
 *
 * @v info_s	This represents the matrix (The Board)
 * 			
 * @return	 void
 * @date	2014-04-15
 * @author	Gabriel Rodrigues(PT Team)
 **/

void test_representation_matrix(char matrix[MAX_BOARDSIZE][MAX_BOARDSIZE], int dimension){
    int i, j;
    printf("GAME BOARD! %d x %d\n\n", dimension, dimension);
    printf("   \t A     B     C     D     E     F     G     H     I     J     K     L\n\n");
    for(i = 0 ; i < dimension; i++){

            printf("  %d\t", i+1);

            for(j = 0; j < dimension; j++){+
                printf("|%c|   ", matrix[i][j]);
            }
            printf("\n\n");

    }
}


/**
 * This TEST function represents the enviroment which the "reading,
 * validating and converting moves functionality" needs to work
 * properly.  
 *
 * @v info_s	This is a test function
 * 			
 * @return	 void
 * @date	2014-04-25
 * @author	Gabriel Rodrigues(PT Team)
 **/

void test_reading_converting_validating(){
    int counter = 1, check = 0;
    reset_data_structs();
    board_set_size(BOARD_MEDIUM);
    int dimension = board_get_size();
    position_t pos;

    while(counter == 1){
    test_representation_matrix(get_current_game_ptr()->board, dimension);

        do{
        read_move(&pos);

        check = function_validate_move(pos);
        }while(check != 0);
        //arise the variable "int playNumber".
        //save in log
    }
}



/*=====================================
 * Private functions
 *===================================*/

/**
 * This is a private function which is not exported to the .h file.
 * It can only be called from this file.
 *
 * @v numstates		number of states to process
 * @return		none
 * @date		2014-03-27
 * @author		...
 **/
static void example_of_private_function(int num_states){
	/* fill in the code */
}

