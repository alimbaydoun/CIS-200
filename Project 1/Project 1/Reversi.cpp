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
//Post-condition: changes player turn if other player has possible moves
//Description: flips all possible colors
void Reversi::setDisk(int row, int col, char color) {
    
    board[row][col] = color;
    
    flipColors(row, col, color);
    
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

//Pre-condition: calculates color squares
//Post-condition: makes a move on original board and prints the result of move
//Description: creates a copy of current board and reverses the original board
int Reversi::resultOfMove(int row, int col, char color) {
    // 
    char copyBoard[ROWS][COLS];
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            copyBoard[r][c] = board[r][c];
        }
    }
    // 
    setDisk(row, col, color);
    // 
    int colorNum = count(color);
    int otherNum;
    if (color == 'b') {
        otherNum = count('w');
    }
    else {
        otherNum = count('b');
    }
    // 
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            board[r][c] = copyBoard[r][c];
        }
    }
    
    playerTurn = color;
    
    return (colorNum - otherNum);
}

//Pre-condition: sets fliped to minimum possible score
//Post-condition: checks if current move is best move and sets this move to best move
//Description: looks for every possible moves and gets move result
void Reversi::bestMove(int& row, int& col, int& fliped, char color) {
     
    fliped = -64;
     
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (isValidMove(r, c, color)) {
                 
                int result = resultOfMove(r, c, color);
                 
                if (fliped < result) {
                     
                    row = r;
                    col = c;
                    fliped = result;
                }
            }
        }
    }
}

//Pre-condition: prints staring line
//Post-condition: prints board line by line
//Description: prints each line with chars seperated by |
void Reversi::printBoard() {
     
    cout << "---------------------------------" << endl;
     
    for (int r = 0; r < ROWS; r++) {
         
        cout << "| ";
        for (int c = 0; c < COLS; c++) {
            cout << board[r][c] << " | ";
        }
        
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

//Pre-condition: 
//Post-condition: flips the color when the color is placed on the board
//Description: Reversi funtion uses the flipColors function to filp colors on the board
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
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if ((color == 'b' && board[i][j] == 'w') || (color == 'w' && board[i][j] == 'b')) {
            needFlip = true;
        }
        else if (needFlip && board[i][j] == color) {
            // flips the color
            for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--) {
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
    for (int i = row - 1, j = col + 1; i >= 0 && j < COLS; i--, j++) {
        if ((color == 'b' && board[i][j] == 'w') || (color == 'w' && board[i][j] == 'b')) {
            needFlip = true;
        }
        else if (needFlip && board[i][j] == color) {
            // flips the color
            for (int r = row - 1, c = col + 1; r >= 0 && c < COLS; r--, c++) {
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
    for (int i = row + 1, j = col - 1; i < ROWS && j >= 0; i++, j--) {
        if ((color == 'b' && board[i][j] == 'w') || (color == 'w' && board[i][j] == 'b')) {
            needFlip = true;
        }
        else if (needFlip && board[i][j] == color) {
            // flips the color
            for (int r = row + 1, c = col - 1; r < ROWS && c >= 0; r++, c--) {
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
    for (int i = row + 1, j = col + 1; i < ROWS && j < COLS; i++, j++) {
        if ((color == 'b' && board[i][j] == 'w') || (color == 'w' && board[i][j] == 'b')) {
            needFlip = true;
        }
        else if (needFlip && board[i][j] == color) {
            // flips the color
            for (int r = row + 1, c = col + 1; r < ROWS && c < COLS; r++, c++) {
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
//Post-condition: bool function returns true or false based on checks
//Description: functions for each direction check if move is valid and returns true or false
bool Reversi::isValidMove(int row, int col, char color) {
    // checks for empty spot
    if (board[row][col] != ' ') {
        return false;
    }
    bool hasFlip = false; 
    // virtical line
        // up
    for (int i = row - 1; i >= 0; i--) {
        if ((color == 'b' && board[i][col] == 'w') || (color == 'w' && board[i][col] == 'b')) {
            hasFlip = true;
        }
        else {
            // checks if placing color at current position flips any color and have same same color
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
            // checks if placing color at current position flips any color and have same same color
            if (hasFlip && ((color == 'b' && board[i][col] == 'b') || (color == 'w' && board[i][col] == 'w'))) {
                return true;
            }
            else {
                hasFlip = false;
                break;
            }
        }
    }

    // for horizontal line
        // left
    for (int i = col - 1; i >= 0; i--) {
        if ((color == 'b' && board[row][i] == 'w') || (color == 'w' && board[row][i] == 'b')) {
            hasFlip = true;
        }
        else {
            // checks if placing color at current position flips any color and have same same color
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
            // checks if placing color at current position flips any color and have same same color
            if (hasFlip && ((color == 'b' && board[row][i] == 'b') || (color == 'w' && board[row][i] == 'w'))) {
                return true;
            }
            else {
                hasFlip = false;
                break;
            }
        }
    }
    // diagonal line
        // upper left
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if ((color == 'b' && board[i][j] == 'w') || (color == 'w' && board[i][j] == 'b')) {
            hasFlip = true;
        }
        else {
            // checks if placing color at current position flips any color and have same same color
            if (hasFlip && ((color == 'b' && board[i][j] == 'b') || (color == 'w' && board[i][j] == 'w'))) {
                return true;
            }
            else {
                hasFlip = false;
                break;
            }
        }
    }
    // upper right
    for (int i = row - 1, j = col + 1; i >= 0 && j < COLS; i--, j++) {
        if ((color == 'b' && board[i][j] == 'w') || (color == 'w' && board[i][j] == 'b')) {
            hasFlip = true;
        }
        else {
            // checks if placing color at current position flips any color and have same same color
            if (hasFlip && ((color == 'b' && board[i][j] == 'b') || (color == 'w' && board[i][j] == 'w'))) {
                return true;
            }
            else {
                hasFlip = false;
                break;
            }
        }
    }
    // lower left
    for (int i = row + 1, j = col - 1; i < ROWS && j >= 0; i++, j--) {
        if ((color == 'b' && board[i][j] == 'w') || (color == 'w' && board[i][j] == 'b')) {
            hasFlip = true;
        }
        else {
            // checks if placing color at current position flips any color and have same same color
            if (hasFlip && ((color == 'b' && board[i][j] == 'b') || (color == 'w' && board[i][j] == 'w'))) {
                return true;
            }
            else {
                hasFlip = false;
                break;
            }
        }
    }
    // lower right
    for (int i = row + 1, j = col + 1; i < ROWS && j < COLS; i++, j++) {
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
//Post-condition: returns the players turn
//Description: gets the players turn
char Reversi::getPlayerTurn() {
    return playerTurn;
}

//Pre-condition: checks if isValidMove valid
//Post-condition: returns true or false based on function
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
//Post-condition: returns possible moves to isValidMove
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

//Pre-condition: finds the possible moves and removes them
//Post-condition: removes the possible moves
//Description: finds the possible moves and removes them
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
//Post-condition: prints result of game
//Description: gets a count of squares for both players and prints the result of the game
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