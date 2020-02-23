#include "Reversi.h"

int main() {
    // create a game object
    Reversi game;
    while (true) {
        // check if game is over
        if (game.isOver()) {
            // print game board
            game.printBoard();
            // print the result
            game.printResult();
            cout << endl; // print empty line
            // ask user if they want to play again
            cout << "Do you want to play Again? (enter y or n): ";
            // get user input
            char input;
            cin >> input;
            cout << endl; // print empty line
            if (input == 'y' or input == 'Y') {
                game.resetBoard();
            }
            else {
                // print good bye
                cout << "Thank you for playing!" << endl;
                break;
            }
        }
        game.printTurn();
        game.printBoard();
        int option = 0;
        // Display menu option
        while (true) {
            cout << "Menu:" << endl;
            cout << "\t1) Place a disk" << endl;
            cout << "\t2) See movement rules" << endl;
            cout << "\t3) Display possible moves" << endl;
            cout << "\t4) See best move" << endl;
            cout << "Select: ";
            // get user input
            cin >> option;
            // do as option selected
            if (option == 1) {
                // ask user for row and col
                int row;
                int col;
                cout << "Enter a row number (from 0 to 7): ";
                cin >> row;
                cout << "Enter a col number (from 0 to 7): ";
                cin >> col;
                // check if possition is valid
                if (game.isValidMove(row, col, game.getPlayerTurn())) {
                    // place disk at given position
                    game.setDisk(row, col, game.getPlayerTurn());
                    cout << endl; // print new line
                    break; // break inner loop
                }
                else {
                    cout << "Invalid Move!" << endl;
                }
            }
            else if (option == 2) {
                // enter game rules here
                cout << "Rules:" << endl;
                cout << "1) Player with dark disk always play first" << endl;
                cout << "2) To make a move player places a single disk on empty square of board";
                cout << " this must meet folowing conditions:" << endl;
                cout << "\ti) it creates a straight line(vertically, horizontally, or diagonally)";
                cout << " between new piece and another of player's piece on the board" << endl;
                cout << "\tii) there must be one or more of the opponent's pieces between current player's pieces" << endl;
                cout << "3) After player selects a valid square all opponent's piece between player's piece";
                cout << " are converted in to player's piece color" << endl;
                cout << "4) Move might couse pieces to flip in multiple direction" << endl;
                cout << "5) Player alternates turn after making a move, if a player can not make move they";
                cout << " must \"pass\" their turn" << endl;
                cout << "6) When no player can make a move game is over and result is calculated" << endl << endl;
            }
            else if (option == 3) {
                // place x on all possible moves
                game.getPossibleMoves(game.getPlayerTurn());
                // reprint board
                game.printBoard();
                // clear possible moves mark from board
                game.removePossibleMoves();
            }
            else if (option == 4) {
                int row = 0;
                int col = 0;
                int fliped = 0;
                // get best move
                game.bestMove(row, col, fliped, game.getPlayerTurn());
                // print best move
                cout << "Your best move is: " << row << ", " << col << " and will result in a ";
                if (fliped > 0) {
                    cout << "+";
                }
                cout << fliped << " score differential" << endl;
            }
            else {
                // print error
                cout << "Invalid option!" << endl;
            }
        }//end of display menu
    }

    return 0;
}