#include "tictactoe.h"

int move(tictactoe *ttt, const char x, const char y){
    if(x >= 0 && x < 3 && y >= 0 && y < 3){
        if(ttt->board[x][y] != PLAYER_1 && ttt->board[x][y] != PLAYER_2){
            ttt->board[x][y] = ttt->turn;
            ttt->turn = (ttt->turn == PLAYER_1)?PLAYER_2:PLAYER_1;
            return ttt->turn;
        }
    }
    return 0;
}

int has_winner(const tictactoe *ttt){
    char last_p;
    char i, j;

    // Check rows
    for(i = 0; i < 3; i++){
        last_p = ttt->board[i][0];
        for(j = 1; j < 3 && ttt->board[i][j] == last_p; j++);
        if(j == 3 && (last_p == PLAYER_1 || last_p == PLAYER_2))
            return last_p;
    }

    // Check columns
    for(i = 0; i < 3; i++){
        last_p = ttt->board[0][i];
        for(j = 1; j < 3 && ttt->board[j][i] == last_p; j++);
        if(j == 3 && (last_p == PLAYER_1 || last_p == PLAYER_2))
            return last_p;
    }

    // Check main diagonal
    if(ttt->board[0][0] == ttt->board[1][1] && ttt->board[1][1] == ttt->board[2][2])
        if(ttt->board[1][1] == PLAYER_1 || ttt->board[1][1] == PLAYER_2)
            return ttt->board[1][1];

    // Check secondary diagonal
    if(ttt->board[2][0] == ttt->board[1][1] && ttt->board[1][1] == ttt->board[0][2])
        if(ttt->board[1][1] == PLAYER_1 || ttt->board[1][1] == PLAYER_2)
            return ttt->board[1][1];

    // Check for not a draw
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(!(ttt->board[i][j] == PLAYER_1 || ttt->board[i][j] == PLAYER_2))
                return 0;
        }
    }
    
    return DRAW;
}