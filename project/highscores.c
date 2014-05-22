/**
 * Triplets Game - VIOPE 2014
 *
 * @file: highscores.c
 *
 * @creation date	2014-05-14
 *
 **/

/*=====================================
 * includes
 *===================================*/
/* System includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* local includes */
#include "data_structs.h"
#include "highscores.h"
#include "PL_ui.h"
#include "PT_save_read_moves.h"
/*=====================================
 * Prototypes of **private** functions
 *===================================*/
//static void example_of_private_function(int num_states);


/*=====================================
 * Public functions
 *===================================*/

/**
 * Function that creates/loads highscores by default
 * Is called at main, to load highscores or create them if they don't exist
 *
 * @return	void
 * @date	2014-05-14
 * @author	Eduardo Andrade (PT Team)
 */

void init_highscores()
{
    highscores_t highscores3x3[MAX_HIGHSCORES];
    highscores_t highscores6x6[MAX_HIGHSCORES];
    highscores_t highscores12x12[MAX_HIGHSCORES];
    highscores_t highscores9x9[MAX_HIGHSCORES];
    FILE *highscoresFile3x3;
    FILE *highscoresFile6x6;
    FILE *highscoresFile12x12;
    FILE *highscoresFile9x9;
    int i, highscore_type;

    /* Set default highscores */
    for(i=0; i<MAX_HIGHSCORES; i++)
    {
        strcpy(highscores3x3[i].player_name, "DEFAULT");
        highscores3x3[i].player_moves = 999;
        strcpy(highscores3x3[i].game_mode, "NONE");
        highscores3x3[i].game_counter = 999;
    }
    for(i=0; i<MAX_HIGHSCORES; i++)
    {
        strcpy(highscores6x6[i].player_name, "DEFAULT");
        highscores6x6[i].player_moves = 999;
        strcpy(highscores6x6[i].game_mode, "NONE");
        highscores6x6[i].game_counter = 999;
    }
    for(i=0; i<MAX_HIGHSCORES; i++)
    {
        strcpy(highscores12x12[i].player_name, "DEFAULT");
        highscores12x12[i].player_moves = 999;
        strcpy(highscores12x12[i].game_mode, "NONE");
        highscores12x12[i].game_counter = 999;
    }
    for(i=0; i<MAX_HIGHSCORES; i++)
    {
        strcpy(highscores9x9[i].player_name, "DEFAULT");
        highscores9x9[i].player_moves = 999;
        strcpy(highscores9x9[i].game_mode, "NONE");
        highscores9x9[i].game_counter = 999;
    }

    // load highscores, if file doesn't exist, create new
    highscoresFile3x3 = fopen("data/highscores/highscores3x3.dat", "rb");
    if (highscoresFile3x3 == NULL)
    {
        highscore_type = 1;
        createHighscores(highscores3x3, highscore_type);
    }
    else
    {
        fread(highscores3x3,sizeof(highscores_t),MAX_HIGHSCORES,highscoresFile3x3);
    }
    fclose(highscoresFile3x3);

    highscoresFile6x6 = fopen("data/highscores/highscores6x6.dat", "rb");
    if (highscoresFile6x6 == NULL)
    {
        highscore_type = 2;
        createHighscores(highscores6x6, highscore_type);
    }
    else
    {
        fread(highscores6x6,sizeof(highscores_t),MAX_HIGHSCORES,highscoresFile6x6);
    }
    fclose(highscoresFile6x6);

    highscoresFile12x12 = fopen("data/highscores/highscores12x12.dat", "rb");
    if (highscoresFile12x12 == NULL)
    {
        highscore_type = 3;
        createHighscores(highscores12x12, highscore_type);
    }
    else
    {
        fread(highscores12x12,sizeof(highscores_t),MAX_HIGHSCORES,highscoresFile12x12);
    }
    fclose(highscoresFile12x12);

    highscoresFile9x9 = fopen("data/highscores/highscores9x9.dat", "rb");
    if(highscoresFile9x9==NULL)
    {
        highscore_type = 4;
        createHighscores(highscores9x9, highscore_type);
    }
}

/**
 * This function creates the highscores's files
 *
 * @v info_s	create them in a folder
 * @return	void
 * @date	2014-05-14
 * @author	PT Team
 **/
void createHighscores(highscores_t highscores[], int highscore_type)
{
    int i;
    FILE *createHighscoresFile;

    if(highscore_type == 1)
    {
        createHighscoresFile = fopen("data/highscores/highscores3x3.dat", "wb");
        if(createHighscoresFile == NULL)
        {
            printf("\nERROR: Couldn't create highscores3x3.dat file!");
        }
        else
        {
            for(i=0; i<MAX_HIGHSCORES; i++)
            {
                fwrite(highscores,sizeof(highscores_t),MAX_HIGHSCORES,createHighscoresFile);
            }
            fclose(createHighscoresFile);
        }
    }
    else
    {
        if(highscore_type == 2)
        {
            createHighscoresFile = fopen("data/highscores/highscores6x6.dat", "wb");
            if(createHighscoresFile == NULL)
            {
                printf("\nERROR: Couldn't create highscores6x6.dat file!");
            }
            for(i=0; i<MAX_HIGHSCORES; i++)
            {
                fwrite(highscores,sizeof(highscores_t),MAX_HIGHSCORES,createHighscoresFile);
            }
            fclose(createHighscoresFile);
        }
        else
        {
            if(highscore_type == 3)
            {
                createHighscoresFile = fopen("data/highscores/highscores12x12.dat", "wb");
                if(createHighscoresFile == NULL)
                {
                    printf("\nERROR: Couldn't create highscores12x12.dat file!");
                }
                for(i=0; i<MAX_HIGHSCORES; i++)
                {
                    fwrite(highscores,sizeof(highscores_t),MAX_HIGHSCORES,createHighscoresFile);
                }
                fclose(createHighscoresFile);
            }
            else
            {
                createHighscoresFile = fopen("data/highscores/highscores9x9.dat", "wb");
                if(createHighscoresFile == NULL)
                {
                    printf("\nERROR: Couldn't create highscores9x9.dat file!");
                }
                for(i=0; i<MAX_HIGHSCORES; i++)
                {
                    fwrite(highscores,sizeof(highscores_t),MAX_HIGHSCORES,createHighscoresFile);
                }
                fclose(createHighscoresFile);
            }
        }
    }
}


/**
 * This function recieves the winning player info and checks if it's a new highscore
 * If yes, saves it in the new position, if not, discards it and doesn't inform the player
 *
 * @v info_s	Necessary after the game ends
 * @return	 an integer to show if it updated highscores or not
 * @date	2014-05-14
 * @author	Eduardo Andrade (PT Team)
 **/

void verify_new_highscore(int new_player_moves, char new_player_name[], int game_size, int gameCounter, int game_mode_i)
{
    int i, o, highscoresChanged=0;
    char game_mode[5];
    FILE *fileHighscores;
    char filename[50] = "";
    highscores_t highscores[MAX_HIGHSCORES];

    if(game_mode_i == 1)
    {
        strcpy(game_mode, "PVP");
    }
    else
    {
        strcpy(game_mode, "PVC");
    }

    // use the game_size variable to obtain the filename to load
    sprintf(filename, "data/highscores/highscores%dx%d.dat", game_size, game_size);

    fileHighscores = fopen(filename, "rb");
    if (fileHighscores == NULL)
    {
        printf("\nERROR: Could not find/write to %s\nCouldn't check for highscores.", filename);
    }
    else
    {
        fread(highscores,sizeof(highscores_t),MAX_HIGHSCORES,fileHighscores);
        fclose(fileHighscores);

        for(i=0; i<MAX_HIGHSCORES; i++)
        {
            if(new_player_moves < highscores[i].player_moves)
            {
                highscoresChanged = 1;
                /* New highscore found, adding to structure array */
                for(o=MAX_HIGHSCORES-2; o>i; o--)       // move older scores down
                {
                    strcpy(highscores[o].player_name, highscores[o-1].player_name);
                    strcpy(highscores[o].game_mode, highscores[o-1].game_mode);
                    highscores[o].player_moves = highscores[o-1].player_moves;
                    highscores[o].game_counter = highscores[o-1].game_counter;
                }
                //  adding new highscore to the position found
                highscores[i].player_moves = new_player_moves;
                strcpy(highscores[i].player_name, new_player_name);
                strcpy(highscores[i].game_mode, game_mode);
                highscores[i].game_counter = gameCounter;
                i=MAX_HIGHSCORES; // sets i to max number, to skip verifying or replacing more highscores
            }
        }
        fileHighscores = fopen(filename, "wb");
        if(fileHighscores == NULL)
        {
            printf("\nERROR: Could not find/write to %s\nCouldn't check for highscores.", filename);
        }
        else
        {
            fwrite(highscores, sizeof(highscores_t), MAX_HIGHSCORES, fileHighscores);
            fclose(fileHighscores);

            if(highscoresChanged==1)
            {
                printf("\nCongratulations %s! You made it to the highscores!\nYou are on position %d on the %dx%d highscores, with %d moves!\n",
                       new_player_name, o+1, game_size, game_size, new_player_moves);
            }
        }
    }
}

/**
 * This function shows highscores when called
 *
 * @v info_s	shows the highscores
 * @return	void
 * @date	2014-05-14
 * @author	PT Team
 **/


void show_highscores()
{
    int i, menuOption, exitOption, numHighscores=0, logToLoad=-1;
    FILE *loadHighscores;
    highscores_t highscores[MAX_HIGHSCORES];

    menuOption = highscore_menu();

    if (menuOption==0)
    {
        //back to main menu
    }
    else
    {
        clearscr();

        if(menuOption==1)
        {
            loadHighscores = fopen("data/highscores/highscores3x3.dat", "rb");
        }
        else
        {
            if(menuOption==2)
            {
                loadHighscores = fopen("data/highscores/highscores6x6.dat", "rb");
            }
            else
            {
                if(menuOption==3){
                    loadHighscores = fopen("data/highscores/highscores9x9.dat", "rb");
                }
                else{
                    loadHighscores = fopen("data/highscores/highscores12x12.dat", "rb");
                }
            }
        }
        if (loadHighscores == NULL)     // verify if file exists
        {
            printf("\nERROR: Couldn't read scores!\n");
        }
        else
        {
            for(i=0; i<MAX_HIGHSCORES; i++)
            {
                fread(highscores,sizeof(highscores_t),MAX_HIGHSCORES,loadHighscores);
            }
            do
            {
                printf("\t\t\t-- Triplets Highscores -");
                //cosmetic stuff
                if(menuOption==1)
                {
                    printf(" 3x3 --\n");
                }
                else
                {
                    if(menuOption==2)
                    {
                        printf(" 6x6 --\n");
                    }
                    else
                    {
                        if(menuOption==4){
                            printf(" 12x12 --\n");
                        }
                        else{
                            printf(" 9x9 --\n");
                        }
                    }
                }

                for(i=0; i<MAX_HIGHSCORES; i++)
                {
                    if(highscores[i].player_moves != 999)
                    {
                        printf("\n#%d - Player Name: %s / Player Score: %d @ %s Mode",
                               i+1, highscores[i].player_name, highscores[i].player_moves, highscores[i].game_mode);
                        numHighscores++;
                    }
                }
                if(numHighscores==0)
                {
                    printf("\nThere are still no highscores to see here!");
                    printf("\nPress any key to go back...");
                    readchar();
                    break;
                }
                else
                {
                    printf("\n\n1-%d. Select match to replay", numHighscores);
                    printf("\n0. Exit to main menu");
                    printf("\nSelect option: ");
                    scanf("%d", &exitOption);
                    logToLoad = highscores[exitOption-1].game_counter;
                }

                if(exitOption==0)
                {
                    break;
                }
                clearscr();
            }
            while (exitOption < 0 || exitOption > numHighscores);
            fclose(loadHighscores);
            loadLogs(logToLoad);
        }
    }
}

/*=====================================
 * Private functions
 *===================================*/

/**
 * This function shows a menu to show the different highscores (based on the boardsize)
 *
 * @v info_s	shows a menu
 * @return	an integer that is used in other functions
 * @date	2014-05-15
 * @author	PT Team
 **/

int highscore_menu()
{
    int option;

    clearscr();
    do
    {
        printf("Triplets - Highscores\n");
        printf("\n1. 3x3 Highscores");
        printf("\n2. 6x6 Highscores");
        printf("\n3. 9x9 Highscores");
        printf("\n4. 12x12 Highscores");
        printf("\n(Choose an option and press enter).\nInsert 0 to return to main menu: ");
        scanf("%d", &option);
    }
    while(option < 0 || option > 4);

    return option;
}
