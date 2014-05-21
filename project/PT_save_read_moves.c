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
#include <ctype.h>

/*=====================================
 * Local includes
 *===================================*/
#include "board.h"
#include "data_structs.h"
#include "PT_save_read_moves.h"
#include "util.h"
#include "PL_ui.h"
#include "sockets.h"
#include "SP.h"

/*=====================================
 * Prototypes of **private** functions
 *===================================*/
//static void example_of_private_function(int num_states);

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

/**
 * This function initializes the log file
 *
 * @v info_s	parameters to create the file
 * @return	void
 * @date	2014-04-14
 * @author	Eduardo Andrade (PT)
 **/

void createLogs(int gameCounter, int dimension)
{
    FILE *newLog;
    char logName[255];
    char dateExtended[32] = "";
    getDate(dateExtended);

    sprintf(logName, "data/logs/TripletsLog-%d.txt", gameCounter);

    newLog = fopen(logName, "wt");
    if(newLog == NULL)
    {
        printf("\n\tERR: Unable to create Log!");
    }
    else
    {
        fprintf(newLog, "--Triplets Log--\n");
        fprintf(newLog, "Game #%d\n", gameCounter);
        fprintf(newLog, "Matrix Dimension: %dx%d\n", dimension, dimension);
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

void savePlayLog(char playerName[], int playNumber, int moveX, char moveY, int gameCounter)
{
    FILE *playLog;
    char logName[255];

    sprintf(logName, "data/logs/TripletsLog-%d.txt", gameCounter);

    playLog = fopen(logName, "at");
    if(playLog == NULL)
    {
        printf("\n\tERR: Couldn't write to %s", logName);
    }
    else
    {
        fprintf(playLog, "Player %s ; Play %d ; Move [%d][%c]\n", playerName, playNumber, moveX, moveY);
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

void closePlayLog(int playNumber, int gameCounter, char playerName[])
{
    FILE *playLog;
    char logName[255];

    sprintf(logName, "data/logs/TripletsLog-%d.txt", gameCounter);

    playLog = fopen(logName, "at");
    if(playLog == NULL)
    {
        printf("\n\tERR: Couldn't close %s", logName);
    }
    else
    {
        fprintf(playLog, "# Game closed successfully!\n");
        fprintf(playLog, "# Winner: %s - %d moves", playerName, playNumber);
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

void loadLogs(int gameCounter)
{

    FILE *playLog;

    int playNumber;
    char dateExtended[32];
    char playerName[30];
    int dimension;
    int i;
    int moveX;
    char moveY;
    int lineCounter=0;
    int headLinesNumber=6;
    char logName[255];

    sprintf(logName, "data/logs/TripletsLog-%d.txt", gameCounter);

    lineCounter=get_file_lines(logName);

    lineCounter-=headLinesNumber;

    lineCounter++; // to add the last line which doesn't have /n !!


    playLog = fopen(logName, "rt");
    if(playLog == NULL)
    {
        printf("\n\tERR: Unable to read Log!");
    }
    else
    {
        gameCounter=0;
        dimension=0;
        fscanf(playLog, "--Triplets Log--\n");
        fscanf(playLog, "Game #%d\n", &gameCounter);
        fscanf(playLog, "Matrix Dimension: %dx%d\n", &dimension, &dimension);
        fscanf(playLog, "Started on: %s\n", dateExtended);

        board_set_size(dimension);
        board_set_empty();
        clearscr();
        board_print_raw();
        init_players();

        for (i=0; i<lineCounter; i++)
        {
            printf("\nPress any key to print next move...");
            readchar();
            clearscr();
            fscanf(playLog, "Player %s ; Play %d ; Move [%d][%c]\n", playerName, &playNumber, &moveX, &moveY);


            board_set_content_row_col(moveX, moveY);
            if (i==lineCounter-1)
            {
                finish_gamePL(get_current_game_ptr()->board);
            }
            board_print_raw();
            printf("\nPlayer Name: %s - Play Number: %d - Move: [%d][%c]\n",playerName, playNumber, moveX, moveY); // was just to test if it's reading right

            cmp.tmp=cmp.current_player_move;                   //swap current player
            cmp.current_player_move=cmp.previous_player_move;  //
            cmp.previous_player_move=cmp.tmp;

        }
        printf("\nWINNER: %s\a\n", playerName);
        printf("\nPress any key to go back to menu...");
        readchar();



    }

    fclose(playLog);

}

/**
 * This function shows the replay menu
 *
 * @v Empty String
 * @return	void
 * @date	2014-05-15
 * @author	João Ramos (PT)
 **/

void replay_menu()
{
    int gameCounter=get_game_counter();
    int control;
    int i;
    int option;

    if (gameCounter==0)
    {
        printf("There are no games available.\n");
        printf("Press any key to go back to main menu...");
        readchar();
    }
    else
    {
        do
        {
            printf("\nGames available to replay:\n\n");

            for (i=1; i<=gameCounter; i++)
            {
                print_game_information(i);
            }

            printf("\n(Choose an option and press enter).\nInsert 0 to return to main menu: ");

            control=scanf("%d",&option);
            clean_buffer_keyboard();

        }
        while (control ==0 || option<0 || option>gameCounter);
        if (option!=0)
        {
            loadLogs(option);
        }
    }
}

/**
 * This function prints the information of the (gameCounter) game
 *
 * @v gameCounter
 * @return	void
 * @date	2014-05-15
 * @author	João Ramos (PT)
 **/

void print_game_information(int gameCounter)
{

    FILE *playLog;

    int playNumber;
    char dateExtended[32];
    char playerName1[30];
    char playerName2[30];
    int dimension;
    int moveX;
    char moveY;
    int lineCounter=0;
    int headLinesNumber=6;

    char logName[255];

    sprintf(logName, "data/logs/TripletsLog-%d.txt", gameCounter);

    lineCounter=get_file_lines(logName);

    lineCounter-=headLinesNumber;

    lineCounter++; // to add the last line which doesn't have /n !!

    playLog = fopen(logName, "rt");
    if(playLog == NULL)
    {
        printf("\nERR: Unable to read Log!");
    }
    else
    {
        gameCounter=0;
        dimension=0;
        fscanf(playLog, "--Triplets Log--\n");
        fscanf(playLog, "Game #%d\n", &gameCounter);
        fscanf(playLog, "Matrix Dimension: %dx%d\n", &dimension, &dimension);
        fscanf(playLog, "Started on: %s\n", dateExtended);

        fscanf(playLog, "Player %s ; Play %d ; Move [%d][%c]\n", playerName1, &playNumber, &moveX, &moveY); // for the first player
        fscanf(playLog, "Player %s ; Play %d ; Move [%d][%c]\n", playerName2, &playNumber, &moveX, &moveY); // for the first player

        printf("#%d Game - Players: %s vs. %s | Date: %s\n", gameCounter, playerName1, playerName2, dateExtended);

    }

    fclose(playLog);

}


/**
 * This function read a string from the user and
 * separate the value of the column and the row
 *
 * @v info_s	Also validates the size of the string and limits
 * 			Of the row and column.
 * @return doesn't return anything, the struct position_t pass
 * 		by reference.
 * @date	2014-04-20
 * @author	Gabriel Rodrigues (PT Team)
 **/

void read_move(position_t *pos)
{

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

    do
    {
        do
        {
            printf("Write your move [3 characters max]: ");
            fgets(move_in_board, maxLength, stdin);    //gets in the string move_in_board a maximum of maxLength characters coming from the STDIN


            /* Terminate the string at the first \n */
            terminate_string_at_first_slash_n(move_in_board);

            /* Compute # of chars in move_in_board */
            move_in_board_strlen = strlen(move_in_board);

            if( move_in_board_strlen > 3)
            {
                clean_buffer_keyboard();
                printf("The move has a maximum of three characters!\n");
            }

        }
        while(move_in_board_strlen > 3);

        pos->X = input_is_digit(move_in_board);
        pos->Y = input_is_char(move_in_board);
        pos->Y = toupper(pos->Y);
        pos->Y_int = board_col_to_matrix_idx(pos->Y);

        if(pos->X < 1 || pos->X > dimension)
        {
            printf("Invalid number!\nThe number has to be between 1 - %d\n\n", dimension);
        }
        if(pos->Y_int == -1 || pos->Y_int >= dimension)
        {
            printf("Invalid letter!\nIt has to be between A - %c\n\n", 64+dimension);
        }

    }
    while(pos->Y_int == -1 || pos->Y_int >= dimension || pos->X < 1 || pos->X > dimension);

//    if the move reach this point is because is -> printf("Part of the board! \n");

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

int function_validate_move(position_t pos)
{

    if(board_get_content_row_col(pos.X, pos.Y) == EMPTY)
    {

//     if the move gets inside this if, then is a ->  printf("Valid move!\n");
        board_set_content_row_col(pos.X, pos.Y);
    }
    else
    {
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

void clean_buffer_keyboard(void)
{
    char chr;
    do
    {
        chr = getchar();
        // printf("char = %c", chr);
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

char* terminate_string_at_first_slash_n(char *str)
{
    char* ptr;
    ptr = strchr(str, '\n');
    if (ptr != NULL)
    {
        *ptr = '\0';
    }
    return str;
}


/**
 *
 * @param
 * @return
 * 2014-04-18
 * Gabriel (PT)
 **/
char input_is_char(char position[3])
{

    char array_letters[24] = "aAbBcCdDeEfFgGhHiIjJkKlL"; //array to compare with the input

    char* ptr = NULL;
    int i, counter = 0;
    char first_character; // returns char ('\0' if no character found)

    for(i = 0; i < sizeof(array_letters); i++)
    {
        ptr = strchr(position, array_letters[i]);   //checks if in the vector position exists a character of the vector arrayLetters
        if(ptr != NULL)
        {
            first_character = *ptr;
            counter++;
            if(counter > 1)
            {
                printf("[WARNING] There is more that one Letter!\n");
                return '\0';
            }
        }
    }
    return first_character;
}

int input_is_digit(char position[3])
{

    int i, j;
    char * ptr = NULL;       // ptr: pointer LINE 82
    int numbersInString[2] = {-1, -1};      //vector that helps the return of two-digits numbers
    int aux = 0;        //auxiliar to position of the vector: numbersInString
    char arrayNumbers[10] = "0123456789";       //array to compare with the obtained input
    for(j=0; j < 3; j++)
    {
        for(i=0; i < 10; i++)
        {
            if(position[j] == arrayNumbers[i])
            {
                numbersInString[aux] = i;
                aux++;
            }
            if(aux > 2)
            {
                printf("[Warning] too much numbers in this move\n");
                return -1;
            }

        }
    }

    ptr = strchr(position, '-'); // In order to make sure that the user didn't write the "minus" symbol
    if(ptr != NULL)
    {
        numbersInString[0] = -1;  //To return -1 at the end
    }

    if(numbersInString[0] != -1 && numbersInString[1] != -1)   //Look if we gottwo numbers
    {
        numbersInString[0] = numbersInString[0]*10 + numbersInString[1];
        //printf("first if numberInString[0] = %d\n", numbersInString[0]);
    }
    else
    {
        if(numbersInString[0] != -1)   //Look if we got one number
        {
            //continue
            //printf("second if numberInString[0] = %d\n", numbersInString[0]);
        }
    }
    //if we didn't got any number it'll return -1 as we state at the beggining in numbersInString
    if(numbersInString[0] < 13)
    {
        return numbersInString[0];
    }
    else
    {
        return -1;
    }
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

void test_representation_matrix(board_t matrix[MAX_BOARDSIZE][MAX_BOARDSIZE], int dimension)
{
    int i, j;
    printf("GAME BOARD! %d x %d\n\n", dimension, dimension);
    printf("   \t A     B     C     D     E     F     G     H     I     J     K     L\n\n");
    for(i = 0 ; i < dimension; i++)
    {

        printf("  %d\t", i+1);

        for(j = 0; j < dimension; j++)
        {
            +
            printf("|%c|   ", matrix[i][j].piece);
        }
        printf("\n\n");

    }
}


/**
 * This TEST function represents the environment which the "reading,
 * validating and converting moves functionality" needs to work
 * properly.
 *
 * @v info_s	This is a test function
 *
 * @return	 void
 * @date	2014-04-25
 * @author	Gabriel Rodrigues(PT Team)
 **/

void test_reading_converting_validating()
{
    int counter = 1, check = 0;
    reset_data_structs();
    board_set_size(BOARD_MEDIUM);
    int dimension = board_get_size();
    position_t pos;

    while(counter == 1)
    {
        test_representation_matrix(get_current_game_ptr()->board, dimension);

        do
        {
            read_move(&pos);

            check = function_validate_move(pos);
        }
        while(check != 0);
        //arise the variable "int playNumber".
        //save in log
    }
}

void PL_HTMLread_move(position_t *pos)
{
    /* Maximum size for the buffer to read a move: 3 characters + 1 \n + 1 \0 => 5 */
#define READ_MOVE_MAX_BUFF_LEN      (5)

    //The move_in_board (being the move read from the user) is 5 to verify the length of the input
    //char move_in_board[READ_MOVE_MAX_BUFF_LEN];
    char move_in_board[READ_MOVE_MAX_BUFF_LEN];

    // Maximum number of characters we want to read with fgets (includes '\n' and '\0')
    int maxLength = READ_MOVE_MAX_BUFF_LEN; //This allows one more character in order to verify the length of the input

    FILE *mov;
    startServer();
    printf("Write your move [3 characters max]: ");
    //fgets(move_in_board, maxLength, stdin);    //gets in the string move_in_board a maximum of maxLength characters coming from the STDIN
    mov = fopen("move.mv","r+");
    fgets(move_in_board, maxLength, mov);
    fclose(mov);
    /* Terminate the string at the first \n */
    terminate_string_at_first_slash_n(move_in_board);
    pos->X = input_is_digit(move_in_board);
    pos->Y = input_is_char(move_in_board);
    pos->Y = toupper(pos->Y);
    pos->Y_int = board_col_to_matrix_idx(pos->Y);
}

void read_row(position_t *pos){

    int control;
    int dimension = board_get_size();
    do
    {
        printf("Write your move: %c", pos->Y);
        control = scanf("%d", &pos->X);

        if(pos->X < 1 || pos->X > dimension || control == 0)
        {
            printf("Invalid number!\nThe number has to be between 1 - %d\n", dimension);
        }
        clean_buffer_keyboard();
    }
    while(pos->X < 1 || pos->X > dimension || control == 0);

//    if the move reach this point is because is -> printf("Part of the board! \n");

}

/*=====================================
 * Private functions
 *===================================*/
