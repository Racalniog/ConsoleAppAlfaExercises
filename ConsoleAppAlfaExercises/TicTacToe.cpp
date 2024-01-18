#include "Header.h"

void runGame();

string TicTacToe::execute(string& a) {
    runGame();
    return a;
}
string TicTacToe::getName() const {
    return "playTicTacToe()";
}

void displayBoard(char board[3][3]) {
    std::cout << "  0 1 2" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            std::cout << "|" << board[i][j];
        }
        std::cout << "|" << std::endl;
        std::cout << "  -----" << std::endl;
    }
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool isValidMove(char board[3][3], int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

void runGame() {
    char board[3][3] = { { ' ', ' ', ' ' },
                         { ' ', ' ', ' ' },
                         { ' ', ' ', ' ' } };

    char currentPlayer = 'X';

    while (true) {
        displayBoard(board);

        int row, col;
        std::cout << "Spieler " << currentPlayer << ", geben Sie Ihre Zugkoordinaten ein (Zeile und Spalte): ";

        while (true) {
            std::cin >> row >> col;

            if (std::cin.fail() || !isValidMove(board, row, col)) {
                std::cout << "Ungültige Eingabe. Versuchen Sie es erneut." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                break;
            }
        }

        board[row][col] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            std::cout << "Spieler " << currentPlayer << " hat gewonnen!" << std::endl;
            break;
        }

        if (checkDraw(board)) {
            displayBoard(board);
            std::cout << "Das Spiel endet unentschieden!" << std::endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        system("cls"); // Clear console screen (works on Unix-like systems, for Windows use "cls")
    }

    return ;
}
