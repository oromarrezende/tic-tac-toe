#ifndef TICTACTOE_H
#define TICTACTOE_H

#define PLAYER_1 'X'
#define PLAYER_2 'O'
#define DRAW -1

typedef struct{
    char board[3][3];
    char turn;
}tictactoe;

int move(tictactoe *ttt, const char x, const char y);

int has_winner(const tictactoe *ttt);



#endif // TICTACTOE_H