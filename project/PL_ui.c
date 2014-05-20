#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "board.h"
#ifdef WIN32
#include "conio.h"
#else
#include <unistd.h>
#endif // WIN32
#include <string.h> //strcpy();
#include "data_structs.h"
#include "PL_ui.h"
#include "unistd.h"
#include "PT_save_read_moves.h"
#include "highscores.h"
#include "util.h"

void clearscr(void)
{
#ifdef WIN32
    system("cls");
#else
    write(1,"\E[H\E[2J",7);
#endif
}

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
    printf("              #                    Viope 2014 LOLO                    #\n");
    printf("              #                                                  #\n");
    printf("              ####################################################\n\n");
    printf("Press any key to continue...");
    readchar();
}

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
        printf("3. Large board (%dx%d)\n\n", BOARD_LARGE, BOARD_LARGE);
        printf("(Choose an option and press enter): ");

        control=scanf("%d",&size_board);
        clean_buffer_keyboard();

    }
    while (size_board<1 || size_board>3 || control ==0);

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
        clearscr();
        printf("Triplets - Player vs Computer \n\n");
        do
        {
            printf("Enter your name: ");
            scanf("%s",G_players[0].name);
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
            scanf("%s",G_players[0].name);

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
            scanf("%s",G_players[1].name);

            strcpy(player2nameAux,G_players[1].name);
            string_to_lower(player2nameAux);

            if (!(strcmp(player2nameAux,"cpu")) || !(strcmp(player2nameAux,player1nameAux)))
            {
                printf("Invalid name.\n");
            }
        }
        while (!(strcmp(player2nameAux,"cpu")) || !(strcmp(player2nameAux,player1nameAux)));

        show_pvp_mode();
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

void show_who_first()

{
    int control;
    int who_first_start_game;

    do
    {
        clearscr();
        printf("Triplets - %s vs %s\n\n", G_players[0].name, G_players[1].name);
        printf("Select who goes first:\n1. %s\n2. %s\n\n(Choose an option and press enter): ",G_players[0].name,G_players[1].name);
        control=scanf("%d",&who_first_start_game);
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

void init_players()
{
        cmp.current_player_move.number=1;
        cmp.previous_player_move.number=2;
}

void show_pvp_mode()
{

    int menu_choose;
    int control; // to verify if it is not a char!

    do
    {
        clearscr();
        printf("Triplets Game\n\n");
        printf("Choose the PvP Mode:\n");
        printf("1. Normal Mode: \n");
        printf("2. Column Mode (it's a challenge!): \n\n");
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


