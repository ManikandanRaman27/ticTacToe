#include <iostream>
#include<stdlib.h>
using namespace std;
// Function to print the Tic Tac Toe board
void printBoard(char board[3][3]) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Function to check if the game is over
bool isGameOver(char board[3][3]) {
    // Check rows, columns, and diagonals for a winning condition
    for (int i = 0; i < 3; i++) {
            if(board[i][0]!=' ' && board[0][i]!=' '){
                if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
                    (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
                    return true;
                }
            }
    }
    if(board[0][0]!=' ' && board[0][2]!=' '){
        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
            (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
            return true;
        }
    }
        // Check for empty spaces, if any, the game is not over yet
    for (int k = 0; k < 3; k++) {
        for (int j = 0; j < 3; j++) {
            if (board[k][j] == ' ') {
                return false;
            }
        }
    }
    // If no empty spaces and no winner, the game is a draw
    printBoard(board);
    cout<<"Match Draw.No One is Winner!!!";
    exit(1);
}

// Function to check if a move is valid
bool isValidMove(int row, int col, char board[3][3]) {
    // Check if the chosen position is within the board and if it's empty
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

// Function to play Tic Tac Toe
void playTicTacToe() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    bool player1Turn = true;
    bool gameOver = false;

    while (!gameOver) {
        printBoard(board);
        int row, col;
        if (player1Turn) {
            cout << "Player 1's turn (X): ";
        } else {
            cout << "Player 2's turn (O): ";
        }
        cin >> row>> col;

        if (isValidMove(row-1, col-1, board)) {
            if (player1Turn) {
                board[row-1][col-1] = 'X';
            } else {
                board[row-1][col-1] = 'O';
            }
            if (isGameOver(board)) {
                printBoard(board);
                if (player1Turn) {
                    cout << "Player 1 (X) wins!" << endl;
                } else {
                    cout << "Player 2 (O) wins!" << endl;
                }
                gameOver = true;
            } else {
                player1Turn = !player1Turn;
            }
        }
        else {
            cout << "Invalid move! Try again." << endl;
        }
    }
}

// Main function
int main() {
    cout << "Welcome to Tic Tac Toe!" << endl;
    playTicTacToe();
    return 0;
}
