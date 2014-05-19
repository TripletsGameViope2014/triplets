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
#include <winsock2.h>
#include <Windows.h>

#else
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#endif

/*=====================================
 * Local includes
 *===================================*/
#include "util.h"

/*=====================================
 * Prototypes of **private** functions
 *===================================*/
static void startWindowsServer(void);
static void startUnixServer(void);

/*=====================================
 * Public functions
 *===================================*/

void OpenHTML(char* HTMLName)
{
    char command[100];
    #ifdef __linux__
    sprintf(command,"xdg-open %s",HTMLName);
    #elif _WIN32
    sprintf(command, "%s", HTMLName);
    #else
    sprintf(command, "open %s", HTMLName);
    #endif // __linux__
    printf("ABout to execute %s\n", command);
    system(command);
}


void startServer() {
	#ifdef _WIN32
	startWindowsServer();
	#else
	startUnixServer();
	#endif
}

void startUnixServer(void) {
    #ifndef _WIN32
    int mainSocket = socket( AF_INET, SOCK_STREAM, 0);
    if( mainSocket == -1)
    {
        printf( "Error creating socket:\n");
        exit(1);
    }

    struct sockaddr_in service;
    memset( & service, 0, sizeof( service ) );
    service.sin_family = AF_INET;
    service.sin_addr.s_addr = INADDR_ANY;
    service.sin_port = htons( 1234 );

int yes = 1;
if ( setsockopt(mainSocket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1 )
{
    perror("setsockopt");
}

    if( bind( mainSocket,( struct sockaddr * ) & service, sizeof( service ) ) != 0 )
    {
        printf( "bind() failed.\n" );
        close(mainSocket);
        exit(2);
    }
    if( listen( mainSocket, 1 ) != 0 ) {
        printf( "Error listening on socket.\n" );
        exit(3);
    }

    int cli = accept(mainSocket, NULL, NULL);

    int bytesSent;
    int bytesRecv = -1;
    char sendbuf[ 20 ] = "";
    char recvbuf[ 20 ] = "";
    char move[4] = "";
    bytesRecv = recv( cli, recvbuf, 20, 0 );
    recvbuf[bytesRecv] = '\0';
    printf( "Bytes received: %d\n", bytesRecv );
    printf( "Received text: %s\n", recvbuf );

    //bytesSent = send( cli, sendbuf, strlen( sendbuf ), 0 );

    char letter; int number;
    int token = sscanf(recvbuf, "GET /%c%d", &letter, &number);
    sprintf(move, "%c%d", letter, number);
    FILE *mov = fopen("move.mv", "w+");
    fprintf(mov,"%s", move);
    fclose(mov);
    close(cli);
    close(mainSocket);
    #endif

}


/**
 * Brief description of the function
 *
 * @v info_s	Function that starts listen server for JS sockets.
 * @return	Nothing.
 * @date	2014-05-15
 * @author	Krzysztof Paliga, Tomasz Gradzinski
 **/

 void startWindowsServer(void)
 {
     #ifdef _WIN32
    WSADATA wsaData;

    int result = WSAStartup( MAKEWORD( 2, 2 ), & wsaData );
    if( result != NO_ERROR )
        printf( "Initialization error.\n" );
    SOCKET mainSocket = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
    if( mainSocket == INVALID_SOCKET )
    {
        printf( "Error creating socket: %d\n", WSAGetLastError() );
        WSACleanup();
        //return 1;
    }

    struct sockaddr_in service;
    memset( & service, 0, sizeof( service ) );
    service.sin_family = AF_INET;
    service.sin_addr.s_addr = inet_addr( "127.0.0.1" );
    service.sin_port = htons( 1234 );


    if( bind( mainSocket,( SOCKADDR * ) & service, sizeof( service ) ) == SOCKET_ERROR )
    {
        printf( "bind() failed.\n" );
        closesocket( mainSocket );
        //return 1;
    }
    if( listen( mainSocket, 1 ) == SOCKET_ERROR )
        printf( "Error listening on socket.\n" );

    SOCKET acceptSocket = SOCKET_ERROR;
    //printf( "Waiting for a client to connect...\n" );

    while( acceptSocket == SOCKET_ERROR )
    {
        acceptSocket = accept( mainSocket, NULL, NULL );
    }

    //printf( "Client connected.\n" );
    mainSocket = acceptSocket;

    if( connect( mainSocket,( SOCKADDR * ) & service, sizeof( service ) ) != SOCKET_ERROR )
    {
        printf( "Failed to connect.\n" );
        WSACleanup();
        //return 1;
    }

    int bytesSent;
    int bytesRecv = SOCKET_ERROR;
    char sendbuf[ 20 ] = "";
    char recvbuf[ 9 ] = "";
    char move[4] = "";
    bytesRecv = recv( mainSocket, recvbuf, 9, 0 );
    //printf( "Bytes received: %d\n", bytesRecv );
    //printf( "Received text: %s\n", recvbuf );

    bytesSent = send( mainSocket, sendbuf, strlen( sendbuf ), 0 );
    //printf( "Bytes sent: %d\n", bytesSent );
    WSACleanup();

    int a;
    int b=0;
    for (a=5;a<8;a++)
    {
        if((recvbuf[a] == '/') || (recvbuf[a] == ' '))
            continue;
        move[b] = recvbuf[a];
        b++;

        //printf("\n");
    }
    //printf("%s", move);

    FILE *mov = fopen("move.mv", "w+");
    fprintf(mov,"%s", move);
    fclose(mov);
    #endif
 }
