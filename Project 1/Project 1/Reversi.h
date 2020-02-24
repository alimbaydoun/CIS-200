#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Reversi {
private:
    const static int ROWS = 8;
    
    const static int COLS = 8;
    
    char board[ROWS][COLS]; // each square hold 'b' , 'w' or ' '

    char playerTurn; // current turn of the player


public:
    Reversi(); // initializes the board to all blanks
   
    int count(char color); // returns the number of square containing color
   
    void setDisk(int row, int col, char color); // sets the square at(row,col) to color
    // returns number of color - number of other color when disk of color is placed at(row,col)
    
    int resultOfMove(int row, int col, char color);
    // returns the max resultOfMove(row,col) when a disk of color is placed at(row,col) by
    // returning the row and col by refrence
    void bestMove(int& row, int& col, int& fliped, char color);
   
    void printBoard(); // prints the board to console screen
  
    void resetBoard(); // reset game to starting position

    void printTurn(); // prints current player's turn on console
    
    void flipColors(int row, int col, char color); // flip all possible colors from given possition to given color
   
    bool isValidMove(int row, int col, char color); // return true if player with given color can place disk at(row,col)
   
    char getPlayerTurn(); // returns current player turn in color(b or w)
    
    bool hasValidMove(char color); // return true if player with color has any valid move
    
    void getPossibleMoves(char color); // places 'x' on board square for all possible moves for player with given color
   
    void removePossibleMoves(); // removes all 'x' from board
   
    bool isOver(); // returns true if game is over
   
    void printResult(); // prints result to console
};