#include <stdio.h>
#include <stdlib.h>

#include "tictactoe.h"
#include "minimax.h"

void print_ttt(const tictactoe*);
void clrscr(void);

int main(int argc, char *argv[]){
    // Initialize game
    tictactoe ttt = {{{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}, PLAYER_1};
    char x, y, winner;
    char against_computer, turn;
    char a, b;

    clrscr();
    printf("Welcome to Tic-Tac-Toe Game!\n\n");
    do{
        printf("Do you like to play against computer? (y/n): ");
        scanf(" %c", &against_computer);
    }while(against_computer != 'y' && against_computer != 'n');

    if(against_computer == 'y'){
        do{
            printf("Do you like to start? (y/n): ");
            scanf(" %c", &turn);
        }while(turn != 'y' && turn != 'n');
    }

    do{
        print_ttt(&ttt);
        if(against_computer == 'y' && (turn == 'y' && ttt.turn == PLAYER_2 || turn == 'n' && ttt.turn == PLAYER_1)){
            find_best_move(&ttt, &a, &b);
            move(&ttt, a, b);
        }else{
            printf("%s (%c) turn. ", (ttt.turn == PLAYER_1)?"PLAYER 1":"PLAYER 2", (ttt.turn == PLAYER_1)?PLAYER_1:PLAYER_2);
            do{
                printf("What is your co-ordinates: ");
                
                scanf(" %c%c", &x, &y);
            }while(!move(&ttt, x - '0', y - '0'));
        }
        clrscr();
        winner = has_winner(&ttt);
    }while(!winner);
    print_ttt(&ttt);

    if(winner == DRAW){
        printf("It is a draw!\n");
    }else{
        printf("Congratulations %s (%c)! You are the winner.\n", (winner == PLAYER_1)?"PLAYER 1":"PLAYER 2", (winner == PLAYER_1)?PLAYER_1:PLAYER_2);
    }
}

void print_ttt(const tictactoe* ttt){
    printf("  0 1 2 \n");
    printf("  ------\n");
    printf("0|%c %c %c|\n", ttt->board[0][0], ttt->board[0][1], ttt->board[0][2]);
    printf("1|%c %c %c|\n", ttt->board[1][0], ttt->board[1][1], ttt->board[1][2]);
    printf("2|%c %c %c|\n", ttt->board[2][0], ttt->board[2][1], ttt->board[2][2]);
    printf("  ------\n");
}

void clrscr(void){
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");  // Acceptable
    #endif

    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        printf("\e[1;1H\e[2J"); // Clear screen, POSIX only
    #endif
}