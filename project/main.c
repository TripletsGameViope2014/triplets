#include <stdlib.h>
/**
* Triplets Game - VIOPE 2014
* @file main.c
*
* @creation date 2014-03-27
*
**/

/*=====================================
* System includes
*===================================*/
#include <stdio.h>
#include <string.h>

/*=====================================
* Local includes
*===================================*/
#include "data_structs.h"
#include "board.h"
#include "PL_ui.h"
#include "PT_save_read_moves.h"
#include "SP.h"
#include "debug.h"
#include "highscores.h"
#include "util.h"
#include "pl_htmlui.h"

int finish_game_wrapper(position_t current_pos)
{
    char S[1024];
    sprintf(S,"Calling finish_game: X=%d,Y=%d",current_pos.X, current_pos.Y_int);
    // debug_append_to_file("debug.txt", S);
    //return finish_game(get_current_game_ptr()->board,current_pos.X, current_pos.Y_int);
    return finish_gamePL(get_current_game_ptr()->board);
}

void select_move()
{
    if(G_current_game.cpu_mode == easy)
    {
        random_cpu(get_current_game_ptr()->board);
    }
    else
    {
        //if(G_current_game.cpu_mode == hard){
        smart(get_current_game_ptr()->board);
    }
}



/*=====================================
* main
*===================================*/
int main(void)
{
    init_highscores();
    int gameCounter=get_game_counter();
    int control;
    int option;
    if (gameCounter==0)
    {
        set_game_counter(gameCounter); // creates the file
    }
    create_folder("logs");
    reset_data_structs();
    clearscr();


    welcome_screen();
    do
    {
        show_menu();

do{
        int check=0;

        gameCounter=increment_game_counter(); // this function increments gameCounter, save it in file and returns it

        createLogs(gameCounter, board_get_size());

        if(G_current_game.game_mode==pvp)  //pvp mode
        {

            if(G_current_game.player_first==1)   // who first start game,  first move
            {
                cmp.current_player_move=G_players[0];
                cmp.previous_player_move=G_players[1];
            }
            else
            {
                cmp.current_player_move=G_players[1];
                cmp.previous_player_move=G_players[0];
            }



//    while(1){   // in while add finish_game...
            while( !finish_game_wrapper(pos) )
            {
                //system("cls");
                clearscr();
                WriteHTML(get_current_game_ptr()->board,"test.html");
                board_print_raw();
                do
                {
                    //
                    printf("It's your move %s! (all your moves: %d)\n",cmp.current_player_move.name,cmp.current_player_move.moves);
                    read_move(&pos);
                    check = function_validate_move(pos);
                }
                while(check != 0);

                cmp.current_player_move.moves+=1;

                savePlayLog(cmp.current_player_move.name, cmp.current_player_move.moves+cmp.previous_player_move.moves, pos.X, pos.Y, gameCounter);

                cmp.tmp=cmp.current_player_move;                   //swap current player
                cmp.current_player_move=cmp.previous_player_move;  //
                cmp.previous_player_move=cmp.tmp;                  //
            }//end while(1)
            cmp.tmp=cmp.current_player_move;                   //swap current player
            cmp.current_player_move=cmp.previous_player_move;  //
            cmp.previous_player_move=cmp.tmp;
            board_print_raw();

            WriteHTML(get_current_game_ptr()->board,"test.html");

            printf("%s wins! (In %d moves!)\n",cmp.current_player_move.name,cmp.current_player_move.moves);
            closePlayLog(cmp.current_player_move.moves, gameCounter, cmp.current_player_move.name);
            verify_new_highscore(cmp.current_player_move.moves, cmp.current_player_move.name, G_current_game.board_columns, gameCounter, 1);

        }// end pvp mode

        if(G_current_game.game_mode==pvc)  //pvc mode
        {

            if(G_current_game.player_first==1)   // who first start game,  first move
            {
                cmp.current_player_move=G_players[0];
                cmp.previous_player_move=G_players[1];// G_players[1] is cpu player
            }
            else
            {
                cmp.current_player_move=G_players[1];
                cmp.previous_player_move=G_players[0];
            }
            while(!finish_game_wrapper(pos))
            {
                //system("cls");
                clearscr();
                board_print_raw();

                if(!strcmp(cmp.current_player_move.name,"CPU"))
                {
                    printf("Computers move was: ");
                    select_move();
                }
                else
                {
                    do
                    {
                        printf("%s your move! (all your moves: %d)\n",cmp.current_player_move.name,cmp.current_player_move.moves);
                        read_move(&pos);
                    }
                    while(function_validate_move(pos));



                }
                cmp.current_player_move.moves+=1;

                if (strcmp(cmp.current_player_move.name,"CPU"))
                {
                    savePlayLog(cmp.current_player_move.name, cmp.current_player_move.moves+cmp.previous_player_move.moves, pos.X, pos.Y, gameCounter);
                }


                cmp.tmp=cmp.current_player_move;                   //swap current player
                cmp.current_player_move=cmp.previous_player_move;  //
                cmp.previous_player_move=cmp.tmp;
            }

            clearscr();
            board_print_raw();
            cmp.current_player_move.moves+=1;
            cmp.tmp=cmp.current_player_move;                   //swap current player
            cmp.current_player_move=cmp.previous_player_move;  //
            cmp.previous_player_move=cmp.tmp;

            printf("%s wins! (In %d moves!)\n",cmp.current_player_move.name,cmp.current_player_move.moves);
            closePlayLog(cmp.current_player_move.moves, gameCounter, cmp.current_player_move.name);

            if (strcmp(cmp.current_player_move.name,"CPU"))
            {
                verify_new_highscore(cmp.current_player_move.moves, cmp.current_player_move.name, G_current_game.board_columns, gameCounter, 0);
            }
        }// end pvc
        do
        {

            printf("\n1. Rematch\n");
            printf("2. Show Replay\n");
            printf("3. Go back to menu\n");
            printf("(Choose an option and press enter): ");

            control=scanf("%d",&option);
            clean_buffer_keyboard();


        }
        while (option<1 || option >3 || control==0);

        switch (option)

        {
    case 1:
board_set_empty();
show_who_first();
        break;
        case 2:
            loadLogs(gameCounter);
            break;
        }

    } while (option==1);
}
    while (1);
    return 0;
}
