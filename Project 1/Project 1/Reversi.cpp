#include "Reversi.h"

Reversi::Reversi() {
    resetBoard();
}

int Reversi::count(char color) {
    int total = 0;
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (board[r][c] == color) {
                total++;
            }
        }
    }
    return total;
}

void Reversi::setDisk(int row, int col, char color) {
    // set disk at position
    board[row][col] = color;
    // flip all possible colors
    flipColors(row, col, color);
    // change player turn if other player has possible moves
    if (playerTurn == 'b') {
        if (hasValidMove('w')) {
            playerTurn = 'w';
        }
    }
    else {
        if (hasValidMove('b')) {
            playerTurn = 'b';
        }
    }
}

int Reversi::resultOfMove(int row, int col, char color) {
    // create a copy of current board
    char copyBoard[ROWS][COLS];
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            copyBoard[r][c] = board[r][c];
        }
    }
    // make a move on original board
    setDisk(row, col, color);
    // calculate color squares
    int colorNum = count(color);
    int otherNum;
    if (color == 'b') {
        otherNum = count('w');
    }
    else {
        otherNum = count('b');
    }
    // reverse the original board
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            board[r][c] = copyBoard[r][c];
        }
    }
    // reset player's turn
    playerTurn = color;
    // return the difference of color
    return (colorNum - otherNum);
}

void Reversi::bestMove(int& row, int& col, int& fliped, char color) {
    // set fliped to minimum possible score
    fliped = -64;
    // look for every possible moves
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (isValidMove(r, c, color)) {
                // get move result
                int result = resultOfMove(r, c, color);
                // check if current move is best move
                if (fliped < result) {
                    // set this move to best move
                    row = r;
                    col = c;
                    fliped = result;
                }
            }
        }
    }
}

void Reversi::printBoard() {
    // print staring line
    cout << "---------------------------------" << endl;
    // print board line by line
    for (int r = 0; r < ROWS; r++) {
        // print each line with chars seperated by |
        cout << "| ";
        for (int c = 0; c < COLS; c++) {
            cout << board[r][c] << " | ";
        }
        // print end of line
        cout << endl;
        cout << "---------------------------------" << endl;
    }
}

void Reversi::resetBoard() {
    // clear board
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            board[r][c] = ' ';
        }
    }
    // set first player turn
    playerTurn = 'b';
    // set first 2 colors for each player
    board[3][4] = 'b';
    board[4][3] = 'b';
    board[3][3] = 'w';
    board[4][4] = 'w';
}

void Reversi::printTurn() {
    // get current player turn
    if (playerTurn == 'b') {
        cout << "Player 1: Black" << endl;
    }
    else {
        cout << "Player 2: White" << endl;
    }
}

void Reversi::flipColors(int row, int col, char color) {
    // create flag to help fliping colors
    bool needFlip = false;
    // look for virtical line
    // look up
    for (int i = row - 1; i >= 0; i--) {
        if ((color == 'b' && board[i][col] == 'w') || (color == 'w' && board[i][col] == 'b')) {
            needFlip = true;
        }
        else if (needFlip && board[i][col] == color) {
            // flip the color
            for (int r = row - 1; r >= 0; r--) {
                if (board[r][col] == color) {
                    break;
                }
                else {
                    board[r][col] = color;
                }
            }
            needFlip = false;
            break;
        }
        else {
            needFlip = false;
            break;
        }
    }
    // look down
    for (int i = row + 1; i < ROWS; i++) {
        if ((color == 'b' && board[i][col] == 'w') || (color == 'w' && board[i][col] == 'b')) {
            needFlip = true;
        }
        else if (needFlip && board[i][col] == color) {
            // flip the color
            for (int r = row + 1; r < ROWS; r++) {
                if (board[r][col] == color) {
                    break;
                }
                else {
                    board[r][col] = color;
                }
            }
            needFlip = false;
            break;
        }
        else {
            needFlip = false;
            break;
        }
    }
    // look for horizontal line
    // look left
    for (int i = col - 1; i >= 0; i--) {
        if ((color == 'b' && board[row][i] == 'w') || (color == 'w' && board[row][i] == 'b')) {
            needFlip = true;
        }
        else if (needFlip && board[row][i] == color) {
            // flip the color
            for (int c = col - 1; c >= 0; c--) {
                if (board[row][c] == color) {
                    break;
                }
                else {
                    board[row][c] = color;
                }
            }
            needFlip = false;
            break;
        }
        else {
            needFlip = false;
            break;
        }
    }
    // look right
    for (int i = col + 1; i < COLS; i++) {
        if ((color == 'b' && board[row][i] == 'w') || (color == 'w' && board[row][i] == 'b')) {
            needFlip = true;
        }
        else if (needFlip && board[row][i] == color) {
            // flip the color
            for (int c = col + 1; c < COLS; c++) {
                if (board[row][c] == color) {
                    break;
                }
                else {
                    board[row][c] = color;
                }
            }
            needFlip = false;
            break;
        }
        else {
            needFlip = false;
            break;
        }
    }
    // look for diagonal line
    // look upper left
    for (int i = row - 1, j = col - 1; i >= 0, j >= 0; i--, j--) {
        if ((color == 'b' && board[i][j] == 'w') || (color == 'w' && board[i][j] == 'b')) {
            needFlip = true;
        }
        else if (needFlip && board[i][j] == color) {
            // flip the color
            for (int r = row - 1, c = col - 1; r >= 0, c >= 0; r--, c--) {
                if (board[r][c] == color) {
                    break;
                }
                else {
                    board[r][c] = color;
                }
            }
            needFlip = false;
            break;
        }
        else {
            needFlip = false;
            break;
        }
    }
    // look upper right
    for (int i = row - 1, j = col + 1; i >= 0, j < COLS; i--, j++) {
        if ((color == 'b' && board[i][j] == 'w') || (color == 'w' && board[i][j] == 'b')) {
            needFlip = true;
        }
        else if (needFlip && board[i][j] == color) {
            // flip the color
            for (int r = row - 1, c = col + 1; r >= 0, c < COLS; r--, c++) {
                if (board[r][c] == color) {
                    break;
                }
                else {
                    board[r][c] = color;
                }
            }
            needFlip = false;
            break;
        }
        else {
            needFlip = false;
            break;
        }
    }
    // look lower left
    for (int i = row + 1, j = col - 1; i < ROWS, j >= 0; i++, j--) {
        if ((color == 'b' && board[i][j] == 'w') || (color == 'w' && board[i][j] == 'b')) {
            needFlip = true;
        }
        else if (needFlip && board[i][j] == color) {
            // flip the color
            for (int r = row + 1, c = col - 1; r < ROWS, c >= 0; r++, c--) {
                if (board[r][c] == color) {
                    break;
                }
                else {
                    board[r][c] = color;
                }
            }
            needFlip = false;
            break;
        }
        else {
            needFlip = false;
            break;
        }
    }
    // look lower right
    for (int i = row + 1, j = col + 1; i < ROWS, j < COLS; i++, j++) {
        if ((color == 'b' && board[i][j] == 'w') || (color == 'w' && board[i][j] == 'b')) {
            needFlip = true;
        }
        else if (needFlip && board[i][j] == color) {
            // flip the color
            for (int r = row + 1, c = col + 1; r < ROWS, c < COLS; r++, c++) {
                if (board[r][c] == color) {
                    break;
                }
                else {
                    board[r][c] = color;
                }
            }
            needFlip = false;
            break;
        }
        else {
            needFlip = false;
            break;
        }
    }
}

bool Reversi::isValidMove(int row, int col, char color) {
    // look for empty spot
    if (board[row][col] != ' ') {
        return false;
    }
    bool hasFlip = false; // set flag to false
    // look for virtical line
        // look up
    for (int i = row - 1; i >= 0; i--) {
        if ((color == 'b' && board[i][col] == 'w') || (color == 'w' && board[i][col] == 'b')) {
            hasFlip = true;
        }
        else {
            // check if placing color at current position flips any color and have same same color at end
            if (hasFlip && ((color == 'b' && board[i][col] == 'b') || (color == 'w' && board[i][col] == 'w'))) {
                return true;
            }
            else {
                hasFlip = false;
                break;
            }
        }
    }
    // look down
    for (int i = row + 1; i < ROWS; i++) {
        if ((color == 'b' && board[i][col] == 'w') || (color == 'w' && board[i][col] == 'b')) {
            hasFlip = true;
        }
        else {
            // check if placing color at current position flips any color and have same same color at end
            if (hasFlip && ((color == 'b' && board[i][col] == 'b') || (color == 'w' && board[i][col] == 'w'))) {
                return true;
            }
            else {
                hasFlip = false;
                break;
            }
        }
    }

    // look for horizontal line
        // look left
    for (int i = col - 1; i >= 0; i--) {
        if ((color == 'b' && board[row][i] == 'w') || (color == 'w' && board[row][i] == 'b')) {
            hasFlip = true;
        }
        else {
            // check if placing color at current position flips any color and have same same color at end
            if (hasFlip && ((color == 'b' && board[row][i] == 'b') || (color == 'w' && board[row][i] == 'w'))) {
                return true;
            }
            else {
                hasFlip = false;
                break;
            }
        }
    }
    // look right
    for (int i = col + 1; i < COLS; i++) {
        if ((color == 'b' && board[row][i] == 'w') || (color == 'w' && board[row][i] == 'b')) {
            hasFlip = true;
        }
        else {
            // check if placing color at current position flips any color and have same same color at end
            if (hasFlip && ((color == 'b' && board[row][i] == 'b') || (color == 'w' && board[row][i] == 'w'))) {
                return true;
            }
            else {
                hasFlip = false;
                break;
            }
        }
    }
    // look for diagonal line
        // look upper left
    for (int i = row - 1, j = col - 1; i >= 0, j >= 0; i--, j--) {
        if ((color == 'b' && board[i][j] == 'w') || (color == 'w' && board[i][j] == 'b')) {
            hasFlip = true;
        }
        else {
            // check if placing color at current position flips any color and have same same color at end
            if (hasFlip && ((color == 'b' && board[i][j] == 'b') || (color == 'w' && board[i][j] == 'w'))) {
                return true;
            }
            else {
                hasFlip = false;
                break;
            }
        }
    }
    // look upper right
    for (int i = row - 1, j = col + 1; i >= 0, j < COLS; i--, j++) {
        if ((color == 'b' && board[i][j] == 'w') || (color == 'w' && board[i][j] == 'b')) {
            hasFlip = true;
        }
        else {
            // check if placing color at current position flips any color and have same same color at end
            if (hasFlip && ((color == 'b' && board[i][j] == 'b') || (color == 'w' && board[i][j] == 'w'))) {
                return true;
            }
            else {
                hasFlip = false;
                break;
            }
        }
    }
    // look lower left
    for (int i = row + 1, j = col - 1; i < ROWS, j >= 0; i++, j--) {
        if ((color == 'b' && board[i][j] == 'w') || (color == 'w' && board[i][j] == 'b')) {
            hasFlip = true;
        }
        else {
            // check if placing color at current position flips any color and have same same color at end
            if (hasFlip && ((color == 'b' && board[i][j] == 'b') || (color == 'w' && board[i][j] == 'w'))) {
                return true;
            }
            else {
                hasFlip = false;
                break;
            }
        }
    }
    // look lower right
    for (int i = row + 1, j = col + 1; i < ROWS, j < COLS; i++, j++) {
        if ((color == 'b' && board[i][j] == 'w') || (color == 'w' && board[i][j] == 'b')) {
            hasFlip = true;
        }
        else {
            // check if placing color at current position flips any color and have same same color at end
            if (hasFlip && ((color == 'b' && board[i][j] == 'b') || (color == 'w' && board[i][j] == 'w'))) {
                return true;
            }
            else {
                hasFlip = false;
                break;
            }
        }
    }
    return false;
}

char Reversi::getPlayerTurn() {
    return playerTurn;
}

bool Reversi::hasValidMove(char color) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (isValidMove(r, c, color)) {
                return true;
            }
        }
    }
    return false;
}

void Reversi::getPossibleMoves(char color) {
    // check all board square for possible move
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (isValidMove(r, c, color)) {
                board[r][c] = 'x';
            }
        }
    }
}

void Reversi::removePossibleMoves() {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (board[r][c] == 'x') {
                board[r][c] = ' ';
            }
        }
    }
}

bool Reversi::isOver() {
    // game is over when any player does not have valid move
    // player turn is changed when disk is set
    // so is current player does not have any moves left then game is over
    return !(hasValidMove(playerTurn));
}

void Reversi::printResult() {
    // get count of squares for both players
    int white = count('w');
    int black = count('b');
    if (white > black) {
        cout << "Congrats the Light Player Won the Game! " << white << " - " << black << endl;
    }
    else if (white < black) {
        cout << "Congrats the Dark Player Won the Game! " << black << " - " << white << endl;
    }
    else {
        cout << "The Game is a Tie! " << white << " - " << black << endl;
    }
}