#include "Header.h"

void RunGame();
std::string TicTacToe::Execute(std::vector<double>& userVector) {
    RunGame();
    return "";
}

std::string TicTacToe::Execute(std::string& a) {
    RunGame();
    return a;
}

std::string TicTacToe::GetName() {
    return "playTicTacToe()";
}

void DisplayBoard(char board[3][3]) {
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

bool CheckWin(char board[3][3], char player) {
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

bool CheckDraw(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool IsValidMove(char board[3][3], int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

void RunGame() {
    char board[3][3] = { { ' ', ' ', ' ' },
                         { ' ', ' ', ' ' },
                         { ' ', ' ', ' ' } };

    char currentPlayer = 'X';

    while (true) {
        DisplayBoard(board);

        int row, col;
        std::cout << "Spieler " << currentPlayer << ", geben Sie Ihre Zugkoordinaten ein (Zeile und Spalte): ";

        while (true) {
            std::cin >> row >> col;

            if (std::cin.fail() || !IsValidMove(board, row, col)) {
                std::cout << "Ungültige Eingabe. Versuchen Sie es erneut." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                break;
            }
        }

        board[row][col] = currentPlayer;

        if (CheckWin(board, currentPlayer)) {
            DisplayBoard(board);
            std::cout << "Spieler " << currentPlayer << " hat gewonnen!" << std::endl;
            break;
        }

        if (CheckDraw(board)) {
            DisplayBoard(board);
            std::cout << "Das Spiel endet unentschieden!" << std::endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        system("clear"); // Clear console screen (works on Unix-like systems, for Windows use "cls")
    }

    return;
}
