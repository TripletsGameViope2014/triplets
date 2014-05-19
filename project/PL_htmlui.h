#ifndef PL_HTMLUI_H_INCLUDED
#define PL_HTMLUI_H_INCLUDED

void WriteHTML(board_t board [MAX_BOARDSIZE][MAX_BOARDSIZE], char* HTMLName);
int finish_game_wrapper(position_t current_pos);

#endif // PL_HTMLUI_H_INCLUDED
