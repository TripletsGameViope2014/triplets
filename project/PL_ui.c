




/**
 * Triplets Game - VIOPE 2014
 * @file: PL_ui.c
 * @creation date	2014-05-01
 *
 **/

/*=====================================
 * System includes
 *===================================*/
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#ifdef WIN32
#include "conio.h"
#else
#include <unistd.h>
#endif // WIN32
#include <string.h> //strcpy();

/*=====================================
 * Local includes
 *===================================*/
#include "data_structs.h"
#include "PL_ui.h"
#include "unistd.h"
#include "PT_save_read_moves.h"
#include "highscores.h"
#include "util.h"
#include "board.h"

/*=====================================
 * Prototypes of **private** functions
 *===================================*/


/*=====================================
 * Public functions
 *===================================*/



 /**
 * This function clears the screen
 *
 * @v info_s
 * @return	none
 * @date	2014-05-11
 * @author	Triplets Team
 **/
void clearscr(void)
{
#ifdef WIN32
    system("cls");
#else
    write(1,"\E[H\E[2J",7);
#endif
}

 /**
 * This function reads a char to pause the program
 *
 * @v info_s
 * @return	An int
 * @date	2014-05-11
 * @author	Triplets Team
 **/
int readchar(void)
{
#ifdef WIN32
    return getch();
#else
    int ch = getchar();
    if (ch != '\n')
    {
        scanf("%*[^\n]%*c");
    }
    return ch;
#endif
}

 /**
 * This function shows the game rules
 *
 * @v info_s
 * @return	none
 * @date	2014-04-18
 * @author	PL Team
 **/
void show_game_rules()
{
    clearscr();
    printf("This game is called Triplets Game. \n");
    printf("\nThe rules are:\n");
    printf("1. The goal is to connect 3 pieces in a line\n\t-This can be vertically, horizontally or across\n\t-First to do this, is the winner\n");
    printf("2. You can win with your own pieces or your opponent's pieces - be careful!\n");
    printf("3. There's 3 board sizes: small (3x3) medium (6x6) and large (12x12).\n");
    printf("4. Matches can be played as Player vs Player or Player vs Computer.\n");
    printf("\nPress any key to go back to main menu...");
    readchar();
}

 /**
 * This function shows the credits
 *
 * @v info_s
 * @return	none
 * @date	2014-04-21
 * @author	PL Team
 **/
void show_credits()
{
    clearscr();
    printf("Triplets game developers:\n\n Poland Team:\n -Paliga Krzysztof\n -Gradzi%cski Tomasz\n -Daniel W%cgrzyn\n\n",228,169);
    printf(" Portugal Team:\n -Jo%co Ramos\n -Eduardo Andrade\n -Gabriel Rodrigues\n\n",199);
    printf(" Spain Team:\n -Nuria Manchado Bustelos\n -Andres Martin de la Iglesia\n\n");
    printf(" Promoters:\n -Patricio Domingues (Portugal)\n -Vitor Carreira (Portugal)\n -Gustavo Reis (Portugal)\n\n");
    printf("Press any key to go back to main menu...");
    readchar();
}

 /**
 * This function shows the welcome screen
 *
 * @v info_s
 * @return	none
 * @date	2014-04-15
 * @author	PL Team
 **/
void welcome_screen()
{
    printf("              ####################################################\n");
    printf("              #                                                  #\n");
    printf("              #  @@@@@@@ @@@@   @  @@@@   @     @@@@@  @@@@@@@   #\n");
    printf("              #     @    @   @  @  @   @  @     @         @      #\n");
    printf("              #     @    @@@@   @  @@@@   @     @@@       @      #\n");
    printf("              #     @    @   @  @  @      @     @         @      #\n");
    printf("              #     @    @   @  @  @      @@@@  @@@@@     @ GAME #\n");
    printf("              #                                                  #\n");
    printf("              #                    Viope 2014                    #\n");
    printf("              #                                                  #\n");
    printf("              ####################################################\n\n");
    printf("Press any key to continue...");
    readchar();
}

 /**
 * This function shows the menu to pick the size of the board
 *
 * @v info_s
 * @return	none
 * @date	2014-04-18
 * @author	PL Team
 **/
void choose_board()
{
    int control; // to verify if it is not a char!
    int size_board;
    do
    {
        //clearscr();
        printf("\nChoose board size:\n");
        printf("1. Small board (%dx%d)\n", BOARD_SMALL, BOARD_SMALL);
        printf("2. Medium board (%dx%d)\n", BOARD_MEDIUM, BOARD_MEDIUM);
        printf("3. Big board (%dx%d)\n", BOARD_BIG, BOARD_BIG);
        printf("4. Large board (%dx%d)\n\n", BOARD_LARGE, BOARD_LARGE);
        printf("(Choose an option and press enter): ");

        control=scanf("%d",&size_board);
        clean_buffer_keyboard();

    }
    while (size_board<1 || size_board>4 || control ==0);

    switch(size_board)
    {
    case 1:
        board_set_size(BOARD_SMALL);
        G_current_game.board_columns=BOARD_SMALL;
        G_current_game.board_rows=BOARD_SMALL;
        break;
    case 2:
        board_set_size(BOARD_MEDIUM);
        G_current_game.board_columns=BOARD_MEDIUM;
        G_current_game.board_rows=BOARD_MEDIUM;
        break;
    case 3:
        board_set_size(BOARD_BIG);
        G_current_game.board_columns=BOARD_BIG;
        G_current_game.board_rows=BOARD_BIG;
        break;
    case 4:
        board_set_size(BOARD_LARGE);
        G_current_game.board_columns=BOARD_LARGE;
        G_current_game.board_rows=BOARD_LARGE;
        break;
    default:
        clearscr();
        choose_board();
        break;
    }
}


 /**
 * This function shows the main menu
 *
 * @v info_s
 * @return	none
 * @date	2014-04-14
 * @author	PL Team
 **/
void show_menu()
{
    int menu_choose;
    int control; // to verify if it is not a char!
    char player1nameAux[MAX_PLAYERNAME_LENGTH]="";
    char player2nameAux[MAX_PLAYERNAME_LENGTH]="";

    do
    {
        clearscr();
        printf("Triplets Game\n\n");
        printf("1. Play : Player vs Computer (PvC)\n");
        printf("2. Play : Player vs Player (PvP)\n");
        printf("3. Game rules\n");
        printf("4. High scores\n");
        printf("5. Replay game\n");
        printf("6. Credits\n\n");
        printf("7. Exit Game.\n\n");
        printf("(Choose an option and press enter): ");



        control=scanf("%d",&menu_choose);
        clean_buffer_keyboard();


    }
    while (menu_choose<1 || menu_choose>7 || control == 0);


    switch(menu_choose)
    {

    case 1:
        G_current_game.game_mode=pvc;
        G_current_game.pvp_mode = notpvp;
        show_difficulty();
        choose_interface();
        clearscr();
        printf("Triplets - Player vs Computer \n\n");
        do
        {
            printf("Enter your name: ");
            fgets(G_players[0].name, MAX_PLAYERNAME_LENGTH, stdin);
            terminate_string_at_first_slash_n(G_players[0].name);
            strcpy(player1nameAux,G_players[0].name);
            string_to_lower(player1nameAux);

            if (!strcmp(player1nameAux,"cpu"))
            {
                printf("Invalid name.\n");
            }
        }
        while (!strcmp(player1nameAux,"cpu"));
        strcpy(G_players[1].name, "CPU");// G_players[1] is cpu player
        choose_board();


        show_who_first();

        break;

    case 2:
        G_current_game.game_mode=pvp;
        G_current_game.cpu_mode = none;
        clearscr();
        printf("Triplets - Player vs Player\n");
        do
        {
            printf("Enter the name of player 1: ");
            fgets(G_players[0].name, MAX_PLAYERNAME_LENGTH, stdin);
            terminate_string_at_first_slash_n(G_players[0].name);
            strcpy(player1nameAux,G_players[0].name);
            string_to_lower(player1nameAux);

            if (!(strcmp(player1nameAux,"cpu")))
            {
                printf("Invalid name.\n");
            }
        }
        while (!(strcmp(player1nameAux,"cpu")));
        do
        {
            printf("\nEnter the name of player 2: ");
            fgets(G_players[1].name, MAX_PLAYERNAME_LENGTH, stdin);
            terminate_string_at_first_slash_n(G_players[1].name);
            strcpy(player2nameAux,G_players[1].name);
            string_to_lower(player2nameAux);

            if (!(strcmp(player2nameAux,"cpu")) || !(strcmp(player2nameAux,player1nameAux)))
            {
                printf("Invalid name.\n");
            }
        }
        while (!(strcmp(player2nameAux,"cpu")) || !(strcmp(player2nameAux,player1nameAux)));

        show_pvp_mode();
        if (G_current_game.pvp_mode == normal)
        {
            choose_interface();
        }
        else
        {
            G_current_game.interface_mode = console;
        }
        choose_board();
        show_who_first();

        break;

    case 3:
        show_game_rules();
        show_menu();
        break;
    case 4:
        //show High scores//
        show_highscores();
        show_menu();
        break;
    case 5:
        replay_menu(); // this is in PT_save_read_moves.c
        show_menu();
        break;
    case 6:
        show_credits();
        show_menu();
        break;
    case 7:
        exit(0);
        break;
    default:
        clearscr();
        show_menu();
        break;
    }
}

 /**
 * This function shows the possible difficulties of
 * the CPU and allows the user to pick one
 *
 * @v info_s
 * @return	none
 * @date	2014-05-13
 * @author	Gabriel Rodrigues
 **/
void show_difficulty()
{

    int menu_choose;
    int control; // to verify if it is not a char!

    do
    {
        clearscr();
        printf("Triplets Game\n\n");
        printf("Choose the CPU difficulty:\n");
        printf("1. Player vs Computer: (EASY)\n");
        printf("2. Player vs Computer: (HARD)\n\n");
        printf("(Choose an option and press enter): ");

        control=scanf("%d",&menu_choose);
        clean_buffer_keyboard();
    }
    while(menu_choose<1 || menu_choose>2 || control == 0);

    switch(menu_choose)
    {

    case 1:
        G_current_game.cpu_mode = easy;
        break;
    case 2:
        G_current_game.cpu_mode = hard;
        break;
    }
}

 /**
 * This function shows and allows to pick the
 * player who is going to play first
 *
 * @v info_s
 * @return	none
 * @date	2014-04-22
 * @author	PL Team
 **/
void show_who_first()

{
    int control;
    int who_first_start_game;

    do
    {
        clearscr();
        printf("Triplets - %s vs %s\n\n", G_players[0].name, G_players[1].name);
        printf("Select who goes first:\n1. %s\n2. %s\n3. Random\n(Choose an option and press enter): ",G_players[0].name,G_players[1].name);
        control=scanf("%d",&who_first_start_game);
        if (who_first_start_game==3)
        {
            who_first_start_game=rand()%2 + 1;
        }
        clean_buffer_keyboard();
    }
    while (who_first_start_game<1 || who_first_start_game>2 || control==0);
    switch(who_first_start_game)
    {
    case 1:
        G_current_game.player_first= 1;
        G_players[0].number=1;
        G_players[1].number=2;
        break;
    case 2:
        G_current_game.player_first= 0;
        G_players[0].number=2;
        G_players[1].number=1;
        break;
    }
    clearscr();
}


 /**
 * This function initializes the selected players
 *
 * @v info_s
 * @return	none
 * @date	2014-05-21
 * @author	Joao Ramos
 **/
void init_players()
{
        cmp.current_player_move.number=1;
        cmp.previous_player_move.number=2;
}

 /**
 * This function shows the possible game modes of
 * the PvP mode and allows the user to pick one
 *
 * @v info_s
 * @return	none
 * @date	2014-05-20
 * @author	Gabriel Rodrigues
 **/
void show_pvp_mode()
{

    int menu_choose;
    int control; // to verify if it is not a char!

    do
    {
        clearscr();
        printf("Triplets Game\n\n");
        printf("Choose the PvP Mode:\n");
        printf("1. Normal Mode. \n");
        printf("2. Column Mode (it's a challenge!). \n\n");
        printf("(Choose an option and press enter): ");

        control=scanf("%d",&menu_choose);
        clean_buffer_keyboard();
    }
    while(menu_choose<1 || menu_choose>2 || control == 0);

    switch(menu_choose)
    {

    case 1:
        G_current_game.pvp_mode = normal;
        break;
    case 2:
        G_current_game.pvp_mode = column;
        break;
    }
}

 /**
 * This function shows the possible interfaces of
 * the gameplay and allows the user to pick one
 *
 * @v info_s
 * @return	none
 * @date	2014-05-21
 * @author	Gabriel Rodrigues
 **/
void choose_interface(){
    int menu_choose;
    int control; // to verify if it is not a char!

    do
    {
        printf("Triplets Game\n\n");
        printf("Choose the Gameplay interface: \n");
        printf("1. HTML: \n");
        printf("2. Console: \n\n");
        printf("(Choose an option and press enter): ");

        control=scanf("%d",&menu_choose);
        clean_buffer_keyboard();
    }
    while(menu_choose<1 || menu_choose>2 || control == 0);

    switch(menu_choose)
    {

    case 1:
        G_current_game.interface_mode = html;
        break;
    case 2:
        G_current_game.interface_mode = console;
        break;
    }
}


/*=====================================
 * Private functions
 *===================================*/

