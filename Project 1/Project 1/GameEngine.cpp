#include "Reversi.h"
#include <iostream>
#include <string>
#include <vector>

//Pre-condition: contains menu logic and user prompts
//Post-condition: outputs the required main function to start the program
//Description: main function displays the menu and outputs for the Reversi "Othello" program
int main() {
    
    Reversi game; // create a game object
   
    while (true) {
        
        if (game.isOver()) {
            
            game.printBoard(); // prints the game board
            
            game.printResult(); // prints the result
            cout << endl;
            
            cout << "Do you want to play Again? (enter y or n): ";
            
            char input; 
            cin >> input; // get user input
            cout << endl; // print empty line
           
            if (input == 'y' or input == 'Y') {
                game.resetBoard();
            }
            else {
                cout << "Thank you for playing!" << endl; // print end game message
                break;
            }
        }
        game.printTurn();
        game.printBoard();
       
        int option = 0;
            // Displays menu option
        while (true) {
            cout << "Menu:" << endl;
            cout << "\t1) Place a disk" << endl;
            cout << "\t2) See movement rules" << endl;
            cout << "\t3) Display possible moves" << endl;
            cout << "\t4) See best move" << endl;
            cout << "Select: ";
            
            cin >> option; // gets user input
            
            if (option == 1) {
                    // asks user for row and col
                int row;
                int col;
                cout << "Enter a row number (from 0 to 7): ";
                cin >> row;
                cout << "Enter a col number (from 0 to 7): ";
                cin >> col;
                    // checks if row and col are valid
                if (game.isValidMove(row, col, game.getPlayerTurn())) {
                    // places disk at given row and col
                    game.setDisk(row, col, game.getPlayerTurn());
                    cout << endl; // print new line
                    break; // breakes inner loop
                }
                else {
                    cout << "Invalid Move!" << endl;
                }
            }
            
            else if (option == 2) {
                // game rules
                cout << "Rules:" << endl;
                cout << "1) Player with dark disk always play first" << endl;
                cout << "2) To make a move player places a single disk on empty square of board";
                cout << " this must meet folowing conditions:" << endl;
                cout << "\t1) it creates a straight line(vertically, horizontally, or diagonally)";
                cout << " between new piece and another of player's piece on the board" << endl;
                cout << "\t2) there must be one or more of the opponent's pieces between current player's pieces" << endl;
                cout << "3) After player selects a valid square all opponent's piece between player's piece";
                cout << " are converted in to player's piece color" << endl;
                cout << "4) Move might couse pieces to switch in multiple direction" << endl;
                cout << "5) Player alternates turn after making a move, if a player can not make move they";
                cout << " must \"pass\" their turn" << endl;
                cout << "6) When no player can make a move game is over and result is calculated" << endl << endl;
            }
            
            else if (option == 3) {
                
                game.getPossibleMoves(game.getPlayerTurn()); // places x on all possible moves
                
                game.printBoard(); // reprints the board
                
                game.removePossibleMoves(); // cleares all possible moves from board
            }
           
            else if (option == 4) {
                int row = 0;
                int col = 0;
                int switched = 0;
                
                game.bestMove(row, col, switched, game.getPlayerTurn()); // gets the best move
                
                cout << "Your best move is: " << row << ", " << col << " and will result in a "; // prints the best move
                if (switched > 0) {
                    cout << "+";
                }
                cout << switched << " score differential" << endl;
            }
           
            else {
                
                cout << "Invalid option!" << endl; // prints the error message
            }
        }
    }

    return 0;
}