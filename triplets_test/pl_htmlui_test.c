#include <stdlib.h>
#include <stdio.h>

#include "data_structs.h"
#include "board.h"
#include "data_structs.h"
#include "PL_ui.h"
#include "main.h"

void WriteHTML(board_t board [MAX_BOARDSIZE][MAX_BOARDSIZE], char* HTMLName)
{
    int i,j,m;
    FILE *HTML = fopen(HTMLName, "w+");
    fprintf(HTML,"<html>");
    fprintf(HTML,"<head>");
    fprintf(HTML,"<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\" />");
    fprintf(HTML,"<script src=\"./js/jquery-2.1.1.min.js\"></script>");
    fprintf(HTML,"<script src=\"./js/reload.js\"></script>");
    fprintf(HTML,"<script src=\"./js/click.js\"></script>");
    fprintf(HTML,"<body><center>");
    //fprintf(HTML,"TEST <br/>TEST2 <br/>TEST3");
    int board_size = board_get_size();
    fprintf(HTML,"TRIPLETS GAME (HTML Mode)<br />");
    if(!finish_game_wrapper(pos))
    {
        fprintf(HTML,"Now it's %s's move. (Current move no. %d)", cmp.current_player_move.name, cmp.current_player_move.moves+1);
    }
    else
    {
        if(G_current_game.game_mode == pvc)
        {
            fprintf(HTML,"<b>%s won! (In %d moves!)</b>",cmp.previous_player_move.name, cmp.previous_player_move.moves);
        }
        else
            fprintf(HTML,"<b>%s won! (In %d moves!)</b>",cmp.current_player_move.name, cmp.current_player_move.moves);
    }
    fprintf(HTML,"<table>");

    char f=65;
    for (i=0; i<board_size; i++)
    {
        if(i==0)
        {
            for(m=0; m<board_size; m++)
            {
                if (m==0)
                {
                    fprintf(HTML,"<td style=\"border:none;\"></td>");
                }
                fprintf(HTML,"<td style=\"border:none;\">%c</td>",f);
                f++;
            }
            fprintf(HTML,"<tr>"); // ROW
        }
        else
        {
            fprintf(HTML,"<tr>"); // ROW
        }

        for(j=0; j<board_size; j++) // COLUMN
        {
            if(j==0)
            {
                fprintf(HTML,"<td style=\"border:none;\">%d</td>",i+1);
                //fprintf(HTML,"<td>%c</td>",get_current_game_ptr()->board[i][j]);
                if(get_current_game_ptr()->board[i][j].piece == PIECE)
                {

                    switch (get_current_game_ptr()->board[i][j].lastPiece)
                    {
                    case 0:
                        fprintf(HTML,"<td id=\"%c%d\"> <img src = \"./move.png\" width = \"40\" height = \"40\" /> </td>",'a'+j,i+1);
                        break;
                    case 1:
                        fprintf(HTML,"<td id=\"%c%d\"> <img src = \"./move_last.png\" width = \"40\" height = \"40\" /> </td>",'a'+j,i+1);
                        break;
                    case 2:
                        fprintf(HTML,"<td id=\"%c%d\"> <img src = \"./move_finish.png\" width = \"40\" height = \"40\" /> </td>",'a'+j,i+1);
                        break;
                    case 3:
                        fprintf(HTML,"<td id=\"%c%d\"> <img src = \"./move_last.png\" width = \"40\" height = \"40\" /> </td>",'a'+j,i+1);
                        break;
                    }
                }
                else
                {
                    fprintf(HTML, "<td id=\"%c%d\"><a href = \"\"></a></td>",'a'+j,i+1);
                }
            }
            else
            {
                //fprintf(HTML,"<td>%c</td>",get_current_game_ptr()->board[i][j]);
                if(get_current_game_ptr()->board[i][j].piece == PIECE)
                {
                    switch (get_current_game_ptr()->board[i][j].lastPiece)
                    {
                    case 0:
                        fprintf(HTML,"<td id=\"%c%d\"> <img src = \"./move.png\" width = \"40\" height = \"40\" /> </td>",'a'+j,i+1);
                        break;
                    case 1:
                        fprintf(HTML,"<td id=\"%c%d\"> <img src = \"./move_last.png\" width = \"40\" height = \"40\" /> </td>",'a'+j,i+1);
                        break;
                    case 2:
                        fprintf(HTML,"<td id=\"%c%d\"> <img src = \"./move_finish.png\" width = \"40\" height = \"40\" /> </td>",'a'+j,i+1);
                        break;
                    case 3:
                        fprintf(HTML,"<td id=\"%c%d\"> <img src = \"./move_last.png\" width = \"40\" height = \"40\" /> </td>",'a'+j,i+1);
                        break;
                    }

                }
                else
                {
                    fprintf(HTML, "<td id=\"%c%d\"><a href = \"\"></a></td>",'a'+j,i+1);
                }
            }
        }
        fprintf(HTML,"</tr>");
    }
    fprintf(HTML,"</body></center></table>");
    fclose(HTML);
}

