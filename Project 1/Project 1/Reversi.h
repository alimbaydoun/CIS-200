#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Reversi {
private:
    const static int ROWS = 8;
    
    const static int COLS = 8;
    
    char board[ROWS][COLS]; // each square holds 'b' , 'w' or ' '

    char playerTurn; // the current turn of the player


public:
    Reversi(); // initializes the board to all blank spaces
   
    int count(char color); // returns the number of squares containing a color
   
    void setDisk(int row, int col, char color); // sets the square at(row,col) to color
    
    int resultOfMove(int row, int col, char color); // returns number of color - number of other color when disk of color is placed at(row,col)
    
    void bestMove(int& row, int& col, int& fliped, char color); // returns the max resultOfMove(row,col) when a disk of color is placed at(row,col) by returning the row and col by reference
   
    void printBoard(); // prints the board to ther console screen
  
    void resetBoard(); // reset game to the starting position

    void printTurn(); // prints the current player's turn on console
    
    void flipColors(int row, int col, char color); // flip all possible colors from the given position to the given color
   
    bool isValidMove(int row, int col, char color); // returns true if player with the given color can place disk at(row,col)
   
    char getPlayerTurn(); // returns the current player's turn in color(b or w)
    
    bool hasValidMove(char color); // returns true if the current player has any valid move
    
    void getPossibleMoves(char color); // places 'x' on the board square for all possible moves for current player
   
    void removePossibleMoves(); // removes all 'x' from the board
   
    bool isOver(); // returns true if the game is over
   
    void printResult(); // prints the result
};