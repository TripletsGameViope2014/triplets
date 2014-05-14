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

#ifdef _WIN32

#include <Windows.h>

#endif

#ifdef linux

#include <time.h>

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

/**
 * Brief description of the function
 *
 * @v info_s	string hold with some info
 * @return	what does this function returns
 * @date	2014-03-27
 * @author	name of the author of the function
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



/*=====================================
 * Private functions
 *===================================*/

