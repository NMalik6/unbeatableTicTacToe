int checkHorizontalWin(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if(board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X') {
            return 1;
        }
        else if(board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O') {
            return -1;
        }
    }
    return 0;
}

int checkVerticalWin(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if(board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X') {
            return 1;
        }
        else if(board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O') {
            return -1;
        }
    }
    return 0;
}

int checkDiagonalWin(char board[3][3]) {
    if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
        return 1;
    }
    else if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
        return -1;
    }
    else if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
        return 1;
    }
    else if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
        return -1;
    }
    return 0;
}

int checkWin(char board[3][3]) {
    int sum = checkHorizontalWin(board) + checkVerticalWin(board) + checkDiagonalWin(board);
    if (sum > 0) {
        return 1;
    }
    else if (sum < 0) {
        return -1;
    }
    else {
        return 0;
    }
}

int checkEnd(char board[3][3]) {
    int w = checkWin(board);
    if(w != 0) {
        return w;
    }
    // check if all spaces are used
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == '-') {
                return w;
            }
        }
    }
    return 10;
}