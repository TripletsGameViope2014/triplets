#ifndef SP_H_INCLUDED
#define SP_H_INCLUDED

int validate (char board [N][N], int column, int row);
void random (char board[SIZE][SIZE]);
int finish_game (char board [SIZE][SIZE],int columnName,int rowNumber);
int diagonally1 (char board [SIZE][SIZE],int columnNumber,int rowNumber);
int diagonally2 (char board [SIZE][SIZE],int columnNumber,int rowNumber);
int horizontal (char board [SIZE][SIZE],int columnNumber,int rowNumber);
int vertical (char board [SIZE][SIZE],int columnNumber,int rowNumber);
void smart (char board[SIZE][SIZE]);
void write(char board[N][N]);

#endif // SP_H_INCLUDED
