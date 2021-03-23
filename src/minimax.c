#include <stdio.h>

#include "tictactoe.h"
#include "minimax.h"

int minimax(tictactoe ttt, char player){
    int winner = has_winner(&ttt);
    int i;
    tictactoe ttt_copy;
    int score = -2, new_score;

    // Temos um vencedor
    if(winner){
        if(winner == DRAW){
            return 0;
        }
        if(winner == player){
            return -1;
        }else{
            return 1;
        }
    }

    for(i = 0; i < 9; i++){
        ttt_copy = ttt;
        if(move(&ttt_copy, i/3, i%3)){
            new_score = -minimax(ttt_copy, ttt.turn);
            if(new_score > score){
                score = new_score;
            }
        }
    }
    return score;
}

int find_best_move(const tictactoe* ttt, char *x, char *y){
    int i;
    tictactoe ttt_copy;
    int score = -2, new_score;

    for(i = 0; i < 9; i++){
        ttt_copy = *ttt;
        if(move(&ttt_copy, i/3, i%3)){
            new_score = -minimax(ttt_copy, ttt->turn);
            if(new_score > score){
                score = new_score;
                *x = i/3;
                *y = i%3;
            }
        }
    }
    return score;
}