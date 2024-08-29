#include <iostream>
using namespace std;

// Function to print the tic-tac-toe board
void printBoard(char board[3][3]) {
    for (int row = 0; row < 3; row++) {
        for (char cell : board[row]) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

// Function to check if a player has won
bool checkWin(char board[][3], char player) {
    // Check rows
    for (int i=0; i<3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) 
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentPlayer = 'X';

    while (true) {
        // Print the board
        printBoard(board);

        // Get the player's move
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row column (1 2)): ";
        std::cin >> row >> col;

        // Update the board
        board[row-1][col-1] = currentPlayer;

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}