#include <stdlib.h>
#include <stdio.h>
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
    printf("Rules are:\n");
    printf("1. Who will put THIRD piece vertically, horizontally or across - WINS\n");
    printf("2. You can select small, medium or large board.\n");
    printf("3. Matches can be played as Player vs Player or Player vs Computer.\n");
    printf("Press any key to go back to main menu...");
    readchar();
}
void show_credits()
{
    clearscr();
    printf("Triplet game authors:\n\n from Poland:\n -Paliga Krzysztof\n -Gradzi%cski Tomasz\n -Daniel W%cgrzyn\n\n",228,169);
    printf(" from Portugal:\n -Jo%co Ramos\n -Eduardo Andrade\n -Gabriel Rodrigues\n\n",199);
    printf(" from Spain:\n -Nuria MANCHADO BUSTELOS\n -Andres MARTIN DE LA IGLESIA\n\n");
    printf(" promoter:\n -Patricio Domingues (from Portugal)\n\n");
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
    printf("              #                    Viope 2014                    #\n");
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
        clearscr();
        printf("Choose board size\n");
        printf("1. Small board (3x3)\n");
        printf("2. Medium board (6x6)\n");
        printf("3. Large board (12x12)\n\n");
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
    int who_first_start_game;
    int menu_choose;
    int control; // to verify if it is not a char!

    do
    {
        clearscr();
        printf("Triplets Game\n\n");
        printf("1. Game Player vs Computer\n");
        printf("2. Game Player vs Player\n");
        printf("3. Game rules\n");
        printf("4. High scores\n");
        printf("5. Credits of the program\n\n");
        printf("6. Exit Game.\n\n");
        printf("(Choose an option and press enter): ");



        control=scanf("%d",&menu_choose);
        clean_buffer_keyboard();


    }
    while (menu_choose<1 || menu_choose>6 || control == 0);


    switch(menu_choose)
    {

    case 1:
        G_current_game.game_mode=pvc;
        clearscr();
        printf("enter your name: ");
        scanf("%s",G_players[0].name);
        strcpy(G_players[1].name, "cpu");// G_players[1] is cpu player
        choose_board();


        do
        {
            clearscr();
            printf("who first start game?\n1. %s\n2. %s\n (Choose an option and press enter): ",G_players[0].name,G_players[1].name);
            control=scanf("%d",&who_first_start_game);
            clean_buffer_keyboard();

        }
        while (who_first_start_game<1 || who_first_start_game>2 || control==0);

        switch(who_first_start_game)
        {
        case 1:
            G_current_game.player_first= 1;
            break;
        case 2:
            G_current_game.player_first= 0;
            break;
        }

        clearscr();
        break;
    case 2:
        G_current_game.game_mode=pvp;
        clearscr();
        printf("enter name player 1: ");
        scanf("%s",G_players[0].name);
        printf("\nenter name player 2: ");
        scanf("%s",G_players[1].name);
        choose_board();

        do
        {
            clearscr();
            printf("who first start game?\n1. %s\n2. %s\n (Choose an option and press enter): ",G_players[0].name,G_players[1].name);
            control=scanf("%d",&who_first_start_game);
            clean_buffer_keyboard();
        }
        while (who_first_start_game<1 || who_first_start_game>2 || control==0);
        switch(who_first_start_game)
        {
        case 1:
            G_current_game.player_first= 1;
            break;
        case 2:
            G_current_game.player_first= 0;
            break;
        }
        clearscr();
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
        show_credits();
        show_menu();
        break;
    case 6:
        exit(0);
        break;
    default:
        clearscr();
        show_menu();
        break;
    }
}

