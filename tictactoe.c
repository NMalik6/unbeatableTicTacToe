#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "wincheck.h"

typedef struct Node {
    int val;
} Node;

// return 100 for x win, 0 for draw, and -100 for O win
int minimax(char board[3][3], bool xTurn, int *row, int *column) {
    int w = checkEnd(board);
    if(w == 1) {
        return 100;
    } else if(w == -1) {
        return -100;
    } else if(w == 10) {
        return 0;
    }
    // game still in play
    int bestScore, r, c;
    if(xTurn) {
        bestScore = -1000;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == '-') {
                    char alteredBoard[3][3];
                    memcpy(alteredBoard, board, 9);
                    alteredBoard[i][j] = 'X';
                    int m = minimax(alteredBoard, false, row, column);
                    if(m > bestScore) {
                        bestScore = m;
                        r = i;
                        c = j;
                    }
                }
            }
        }
    }
    else {
        bestScore = 1000;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == '-') {
                    char alteredBoard[3][3];
                    memcpy(alteredBoard, board, 9);
                    alteredBoard[i][j] = 'O';
                    int m = minimax(alteredBoard, true, row, column);
                    if(m < bestScore) {
                        bestScore = m;
                        r = i;
                        c = j;
                    }
                }
            }
        }
    }
    *row = r;
    *column = c;
    return bestScore;
}

void printBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void makeMove(char board[3][3], bool xTurn) {
    int row = 0, column = 0;
    if(xTurn) {
        int m = minimax(board, true, &row, &column);
        printf("X move: %d%d\n", row, column);
        board[row][column] = 'X';
    } else {
        int m = minimax(board, false, &row, &column);
        printf("O move: %d%d\n", row, column);
        board[row][column] = 'O';
    }
}

void playGame() {
    char board[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
    printBoard(board);
    bool xTurn = true;
    int end = checkEnd(board);
    while(end == 0) {
        if(xTurn) {
            makeMove(board, xTurn);
        } else {
            int r, c;
            printf("Enter move:");
            scanf("%d %d", &r, &c);
            board[r][c] = 'O';
        }
        printBoard(board);
        xTurn = !xTurn;
        end = checkEnd(board);
    }
    if(end == 1) {
        printf("X win");
    } else if(end == -1) {
        printf("O win");
    } else if(end == 10) {
        printf("Draw");
    } else {
        printf("hmmm");
    }
}

int main(){
    playGame();
    return 0;
}