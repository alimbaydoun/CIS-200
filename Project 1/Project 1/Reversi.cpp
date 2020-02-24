#include "Reversi.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Reversi::Reversi() {
    resetBoard();
}

//Pre-condition: takes count of the disks on the board
//Post-condition:  takes count of the disks on the board
//Description:  takes count of the disks on the board
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

//Pre-condition: sets the disk at its position
//Post-condition: sets the disk at its position
//Description: sets the disk at its position
void Reversi::setDisk(int row, int col, char color) {
    // set disk at position
    board[row][col] = color;
    // flips all possible colors
    flipColors(row, col, color);
    // changes player turn if other player has possible moves
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

//Pre-condition: prints the result of move
//Post-condition: prints the result of move
//Description: prints the result of move
int Reversi::resultOfMove(int row, int col, char color) {
    // creates a copy of current board
    char copyBoard[ROWS][COLS];
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            copyBoard[r][c] = board[r][c];
        }
    }
    // makes a move on original board
    setDisk(row, col, color);
    // calculates color squares
    int colorNum = count(color);
    int otherNum;
    if (color == 'b') {
        otherNum = count('w');
    }
    else {
        otherNum = count('b');
    }
    // reverses the original board
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            board[r][c] = copyBoard[r][c];
        }
    }
    // resets player's turn
    playerTurn = color;
    // returns the difference of color
    return (colorNum - otherNum);
}

//Pre-condition: checks for the best move
//Post-condition: checks for the best move
//Description: checks for the best move
void Reversi::bestMove(int& row, int& col, int& fliped, char color) {
    // sets fliped to minimum possible score
    fliped = -64;
    // looks for every possible moves
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (isValidMove(r, c, color)) {
                // gets move result
                int result = resultOfMove(r, c, color);
                // checkes if current move is best move
                if (fliped < result) {
                    // sets this move to best move
                    row = r;
                    col = c;
                    fliped = result;
                }
            }
        }
    }
}

//Pre-condition: print lines between the board
//Post-condition: prints the lines between the board
//Description: prints the lines between the board
void Reversi::printBoard() {
    // prints staring line
    cout << "---------------------------------" << endl;
    // prints board line by line
    for (int r = 0; r < ROWS; r++) {
        // prints each line with chars seperated by |
        cout << "| ";
        for (int c = 0; c < COLS; c++) {
            cout << board[r][c] << " | ";
        }
        // prints end of line
        cout << endl;
        cout << "---------------------------------" << endl;
    }
}

//Pre-condition: clears the board and sets the turn
//Post-condition: clears the board and sets the turn
//Description: clears the board and sets the turn
void Reversi::resetBoard() {
    // cleares board
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            board[r][c] = ' ';
        }
    }
    // sets first player turn
    playerTurn = 'b';
    // sets first 2 colors for each player
    board[3][4] = 'b';
    board[4][3] = 'b';
    board[3][3] = 'w';
    board[4][4] = 'w';
}

//Pre-condition: gets the current player's turn
//Post-condition: gets the current player's turn
//Description: gets the current player's turn
void Reversi::printTurn() {
    // gets current player turn
    if (playerTurn == 'b') {
        cout << "Player 1: Black" << endl;
    }
    else {
        cout << "Player 2: White" << endl;
    }
}

//Pre-condition: flips the color when the color is placed on the board
//Post-condition: flips the color when the color is placed on the board
//Description: flips the color when the color is placed on the board
void Reversi::flipColors(int row, int col, char color) {
    // creates flag to help fliping colors
    bool needFlip = false;
    // looks for virtical line
    // looks up
    for (int i = row - 1; i >= 0; i--) {
        if ((color == 'b' && board[i][col] == 'w') || (color == 'w' && board[i][col] == 'b')) {
            needFlip = true;
        }
        else if (needFlip && board[i][col] == color) {
            // flips the color
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
    // looks down
    for (int i = row + 1; i < ROWS; i++) {
        if ((color == 'b' && board[i][col] == 'w') || (color == 'w' && board[i][col] == 'b')) {
            needFlip = true;
        }
        else if (needFlip && board[i][col] == color) {
            // flips the color
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
    // looks for horizontal line
    // looks left
    for (int i = col - 1; i >= 0; i--) {
        if ((color == 'b' && board[row][i] == 'w') || (color == 'w' && board[row][i] == 'b')) {
            needFlip = true;
        }
        else if (needFlip && board[row][i] == color) {
            // flips the color
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
    // looks right
    for (int i = col + 1; i < COLS; i++) {
        if ((color == 'b' && board[row][i] == 'w') || (color == 'w' && board[row][i] == 'b')) {
            needFlip = true;
        }
        else if (needFlip && board[row][i] == color) {
            // flips the color
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
    // looks for diagonal line
    // looks upper left
    for (int i = row - 1, j = col - 1; i >= 0, j >= 0; i--, j--) {
        if ((color == 'b' && board[i][j] == 'w') || (color == 'w' && board[i][j] == 'b')) {
            needFlip = true;
        }
        else if (needFlip && board[i][j] == color) {
            // flips the color
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
    // looks upper right
    for (int i = row - 1, j = col + 1; i >= 0, j < COLS; i--, j++) {
        if ((color == 'b' && board[i][j] == 'w') || (color == 'w' && board[i][j] == 'b')) {
            needFlip = true;
        }
        else if (needFlip && board[i][j] == color) {
            // flips the color
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
    // looks lower left
    for (int i = row + 1, j = col - 1; i < ROWS, j >= 0; i++, j--) {
        if ((color == 'b' && board[i][j] == 'w') || (color == 'w' && board[i][j] == 'b')) {
            needFlip = true;
        }
        else if (needFlip && board[i][j] == color) {
            // flips the color
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
    // looks lower right
    for (int i = row + 1, j = col + 1; i < ROWS, j < COLS; i++, j++) {
        if ((color == 'b' && board[i][j] == 'w') || (color == 'w' && board[i][j] == 'b')) {
            needFlip = true;
        }
        else if (needFlip && board[i][j] == color) {
            // flips the color
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

//Pre-condition: checks if a valid move is being made
//Post-condition: checks if a valid move is being made
//Description: checks if a valid move is being made
bool Reversi::isValidMove(int row, int col, char color) {
    // looks for empty spot
    if (board[row][col] != ' ') {
        return false;
    }
    bool hasFlip = false; // sets flag to false
    // looks for virtical line
        // looks up
    for (int i = row - 1; i >= 0; i--) {
        if ((color == 'b' && board[i][col] == 'w') || (color == 'w' && board[i][col] == 'b')) {
            hasFlip = true;
        }
        else {
            // checks if placing color at current position flips any color and have same same color at end
            if (hasFlip && ((color == 'b' && board[i][col] == 'b') || (color == 'w' && board[i][col] == 'w'))) {
                return true;
            }
            else {
                hasFlip = false;
                break;
            }
        }
    }
    // looks down
    for (int i = row + 1; i < ROWS; i++) {
        if ((color == 'b' && board[i][col] == 'w') || (color == 'w' && board[i][col] == 'b')) {
            hasFlip = true;
        }
        else {
            // checks if placing color at current position flips any color and have same same color at end
            if (hasFlip && ((color == 'b' && board[i][col] == 'b') || (color == 'w' && board[i][col] == 'w'))) {
                return true;
            }
            else {
                hasFlip = false;
                break;
            }
        }
    }

    // looks for horizontal line
        // looks left
    for (int i = col - 1; i >= 0; i--) {
        if ((color == 'b' && board[row][i] == 'w') || (color == 'w' && board[row][i] == 'b')) {
            hasFlip = true;
        }
        else {
            // checks if placing color at current position flips any color and have same same color at end
            if (hasFlip && ((color == 'b' && board[row][i] == 'b') || (color == 'w' && board[row][i] == 'w'))) {
                return true;
            }
            else {
                hasFlip = false;
                break;
            }
        }
    }
    // looks right
    for (int i = col + 1; i < COLS; i++) {
        if ((color == 'b' && board[row][i] == 'w') || (color == 'w' && board[row][i] == 'b')) {
            hasFlip = true;
        }
        else {
            // checks if placing color at current position flips any color and have same same color at end
            if (hasFlip && ((color == 'b' && board[row][i] == 'b') || (color == 'w' && board[row][i] == 'w'))) {
                return true;
            }
            else {
                hasFlip = false;
                break;
            }
        }
    }
    // looks for diagonal line
        // looks upper left
    for (int i = row - 1, j = col - 1; i >= 0, j >= 0; i--, j--) {
        if ((color == 'b' && board[i][j] == 'w') || (color == 'w' && board[i][j] == 'b')) {
            hasFlip = true;
        }
        else {
            // checks if placing color at current position flips any color and have same same color at end
            if (hasFlip && ((color == 'b' && board[i][j] == 'b') || (color == 'w' && board[i][j] == 'w'))) {
                return true;
            }
            else {
                hasFlip = false;
                break;
            }
        }
    }
    // looks upper right
    for (int i = row - 1, j = col + 1; i >= 0, j < COLS; i--, j++) {
        if ((color == 'b' && board[i][j] == 'w') || (color == 'w' && board[i][j] == 'b')) {
            hasFlip = true;
        }
        else {
            // checks if placing color at current position flips any color and have same same color at end
            if (hasFlip && ((color == 'b' && board[i][j] == 'b') || (color == 'w' && board[i][j] == 'w'))) {
                return true;
            }
            else {
                hasFlip = false;
                break;
            }
        }
    }
    // looks lower left
    for (int i = row + 1, j = col - 1; i < ROWS, j >= 0; i++, j--) {
        if ((color == 'b' && board[i][j] == 'w') || (color == 'w' && board[i][j] == 'b')) {
            hasFlip = true;
        }
        else {
            // checks if placing color at current position flips any color and have same same color at end
            if (hasFlip && ((color == 'b' && board[i][j] == 'b') || (color == 'w' && board[i][j] == 'w'))) {
                return true;
            }
            else {
                hasFlip = false;
                break;
            }
        }
    }
    // looks lower right
    for (int i = row + 1, j = col + 1; i < ROWS, j < COLS; i++, j++) {
        if ((color == 'b' && board[i][j] == 'w') || (color == 'w' && board[i][j] == 'b')) {
            hasFlip = true;
        }
        else {
            // checks if placing color at current position flips any color and have same same color at end
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

//Pre-condition: gets the players turn
//Post-condition: gets the players turn
//Description: gets the players turn
char Reversi::getPlayerTurn() {
    return playerTurn;
}

//Pre-condition: checks if the player has a valid move
//Post-condition: checks if the player has a valid move
//Description: checks if the player has a valid move
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

//Pre-condition: checks the board for possible moves
//Post-condition: checks the board for possible moves
//Description: checks the board for possible moves
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

//Pre-condition: removes the possible moves
//Post-condition: removes the possible moves
//Description: removes the possible moves
void Reversi::removePossibleMoves() {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (board[r][c] == 'x') {
                board[r][c] = ' ';
            }
        }
    }
}

//Pre-condition: The game is over when any player does not have valid move
//Post-condition: So the player's turn is changed when the disk is set
//Description: So the current player does not have any moves left, then game is over
bool Reversi::isOver() {
    return !(hasValidMove(playerTurn));
}

//Pre-condition: gets a count of squares for both players
//Post-condition: gets a count of squares for both players
//Description: gets a count of squares for both players
void Reversi::printResult() {
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