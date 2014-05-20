/**
 * Triplets Game - VIOPE 2014
 *
 * @creation date	2014-05-19
 *
 **/

/*=====================================
 * System includes
 *===================================*/
#include <stdio.h>

/*=====================================
 * Local includes
 *===================================*/
#include "data_structs.h"
#include "board.h"
#include "PL_ui.h"
#include "PT_save_read_moves.h"
#include "main.h"

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
//int example_of_function(char *info_s){
//
//	int value_to_return = ...;
//
//	return value_to_return;
//}

position_t pvp_normal_mode(position_t pos){
    int check=0;

    do
    {
        printf("It's your move %s! (all your moves: %d)\n",cmp.current_player_move.name,cmp.current_player_move.moves);
        pos = select_interface_gameplay(pos);
//        read_move(&pos);
        check = function_validate_move(pos);
    }
    while(check != 0);

    return pos;

}

position_t pvp_column_mode(position_t pos){

    int check=0;

    pos.Y_int++;
    if(pos.Y_int == board_get_size() + 1){
        pos.Y_int = 1;
    }

    pos.Y = pos.Y_int + 64;


    do
    {

        printf("It's your move %s! (all your moves: %d): %c",cmp.current_player_move.name,cmp.current_player_move.moves, pos.Y);
        read_row(&pos);
        //PL_HTMLread_move(&pos);

        check = function_validate_move(pos);
    }
    while(check != 0);

    return pos;
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
//static void example_of_private_function(int num_states){
//	/* fill in the code */
//}
