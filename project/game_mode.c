/**
 * Triplets Game - VIOPE 2014
 * @file: game_mode.c
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


/*=====================================
 * Public functions
 *===================================*/

/**
 * This function represents the normal mode
 * of the Triplets game in PvP
 *
 * @v info_s	Depends on the interface
 * @return	The position being modified
 * @date	2014-05-18
 * @author	Gabriel Rodrigues
 **/
position_t pvp_normal_mode(position_t pos){
    int check=0;

    do
    {
        printf("It's your move %s! (all your moves: %d)\n",cmp.current_player_move.name,cmp.current_player_move.moves);
        pos = select_interface_gameplay(pos);
        check = function_validate_move(pos);
    }
    while(check != 0);

    return pos;

}

/**
 * This function represents the column mode
 * of the Triplets game in PvP
 *
 * @v info_s	Just for the text interface
 * @return	The position being modified
 * @date	2014-05-18
 * @author	Gabriel Rodrigues
 **/
position_t pvp_column_mode(position_t pos){

    int check=0;

    pos.Y_int++;
    if(pos.Y_int >= board_get_size() + 1){
        pos.Y_int = 1;
    }

    pos.Y = pos.Y_int + 64;


    do
    {

        printf("It's your move %s! (all your moves: %d)\n",cmp.current_player_move.name,cmp.current_player_move.moves);
        read_row(&pos);

        check = function_validate_move(pos);
    }
    while(check != 0);

    return pos;
}


/*=====================================
 * Private functions
 *===================================*/

