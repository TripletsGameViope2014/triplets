

void random (char board[SIZE][SIZE])
//We must use #include<time.h> and #include<stdlib.h>.


{int randRow,randColumn;
 position_t position;
 srand(time (NULL));

    do
    {
      position.X=1+rand%SIZE;
      position.Y_int=1+rand%SIZE;

    }while(validate(position));

    board[position.X][position.Y]=PIECE//Piece is a constant define char '#'

}