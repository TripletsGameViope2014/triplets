/**
 * Triplets Game - VIOPE 2014
 *
 * @creation date	2014-05-15
 *
 **/

/*=====================================
 * System includes
 *===================================*/
#include <stdio.h>
#include <ctype.h>

#ifdef _WIN32

#include <Windows.h>

#else

#include <time.h>
#include <sys/stat.h>

#endif

/*=====================================
 * Local includes
 *===================================*/
#include "util.h"

/*=====================================
 * Prototypes of **private** functions
 *===================================*/

/*=====================================
 * Public functions
 *===================================*/

void getDate(char dateExtended[]);
void set_game_counter(int gameCounter);
int get_game_counter();
int increment_game_counter();
int get_file_lines(char fileName[]);
void create_folder(char folderName[]);
void string_to_lower(char string[]);


/**
 * This function receives a string and puts there the current date
 *
 * @v Empty String
 * @return	void
 * @date	2014-05-15
 * @author	João Ramos (PT)
 **/

void getDate(char dateExtended[])
{

#ifdef _WIN32
    SYSTEMTIME str_t;
    GetSystemTime(&str_t);

//	printf("Date: %d/%d/%d f%d:%d",str_t.wYear,str_t.wMonth,str_t.wDay,str_t.wHour,str_t.wMinute);

    sprintf(dateExtended, "%d/%d/%d-%d:%d", str_t.wYear, str_t.wMonth, str_t.wDay, str_t.wHour, str_t.wMinute);

#endif

#ifdef linux

    time_t currTime;
    struct tm *localTime;
    currTime = time(NULL);

    localTime = localtime (&currTime);

//    printf("Date: %s", asctime(localTime));

    strcpy(dateExtended, asctime(localTime));

#endif
}

/**
 * This function saves the new game counter
 *
 * @v gameCounter
 * @return	void
 * @date	2014-05-16
 * @author	João Ramos (PT)
 **/

void set_game_counter(int gameCounter)
{
    FILE *counter;

    counter=fopen("logs/gamecounter.txt", "wt");
    if (counter==NULL)
    {
        printf("Error writing on game counter file.");
    }
    else
    {
        fprintf(counter, "game counter = %d", gameCounter);

        fclose(counter);
    }

}

/**
 * This function return the game counter
 *
 * @v
 * @return	gameCounter
 * @date	2014-05-16
 * @author	João Ramos (PT)
 **/

int get_game_counter()
{
    FILE *counter;
    int gameCounter=0;

    counter=fopen("logs/gamecounter.txt", "rt");
    if (counter==NULL)
    {
        printf("Error reading game counter file.");
    }
    else
    {
        fscanf(counter, "game counter = %d", &gameCounter);

        fclose(counter);
    }


    return gameCounter;
}

/**
 * Increments game counter and saves
 *
 * @v
 * @return	gameCounter
 * @date	2014-05-16
 * @author	João Ramos (PT)
 **/

int increment_game_counter()
{
    int gameCounter;
    gameCounter=get_game_counter();
    gameCounter++;
    set_game_counter(gameCounter);

    return gameCounter;
}

/**
 * This function returns the number of lines of a file
 *
 * @v
 * @return	gameCounter
 * @date	2014-05-16
 * @author	João Ramos (PT)
 **/

int get_file_lines(char fileName[])
{
    FILE *fp;
    int lineCounter=0;
    int ch;

    fp=fopen(fileName, "rt");
    if (fp!=NULL){
    do
        {
            ch = fgetc(fp);
            if( ch== '\n')
            {
                lineCounter++;
            }
        }
        while( ch != EOF );

        fclose(fp);

}

return lineCounter;
}

/**
 * This function creates a folder
 *
 * @v folderName
 * @return	void
 * @date	2014-05-15
 * @author	João Ramos (PT)
 **/

void create_folder(char folderName[])
{
   #ifdef _WIN32
   CreateDirectory(folderName,NULL);
   #else
   mkdir(folderName, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
   #endif
}

void string_to_lower(char string[])
{
    int i;

    for (i=0;string[i]!='\0';i++)
    {
        string[i]=tolower(string[i]);
    }
}

/*=====================================
 * Private functions
 *===================================*/

