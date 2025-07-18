#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Constants for players
const int PLAYER_X = 1; // Human player
const int PLAYER_O = -1; // AI player
const int EMPTY = 0;

// Function to print the board
void printBoard(const vector<vector<int>>& board) {
    cout << "\nBoard:\n";
    for (const auto& row : board) {
        for (int cell : row) {
            char c = (cell == PLAYER_X) ? 'X' : (cell == PLAYER_O) ? 'O' : '.';
            cout << c << " ";
        }
        cout << endl;
    }
}

// Function to check if there is a winner
int checkWinner(const vector<vector<int>>& board) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != EMPTY && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
        if (board[0][i] != EMPTY && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }
    // Check diagonals
    if (board[0][0] != EMPTY && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] != EMPTY && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];
    // No winner
    return EMPTY;
}

// Function to check if the board is full
bool isBoardFull(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            if (cell == EMPTY) return false;
        }
    }
    return true;
}

// Minimax function
int minimax(vector<vector<int>>& board, int depth, bool isMaximizing) {
    int winner = checkWinner(board);
    if (winner == PLAYER_X) return 10 - depth;
    if (winner == PLAYER_O) return depth - 10;
    if (isBoardFull(board)) return 0;

    if (isMaximizing) {
        int bestScore = numeric_limits<int>::min();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_O;
                    int score = minimax(board, depth + 1, false);
                    board[i][j] = EMPTY;
                    bestScore = max(bestScore, score);
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = numeric_limits<int>::max();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = PLAYER_X;
                    int score = minimax(board, depth + 1, true);
                    board[i][j] = EMPTY;
                    bestScore = min(bestScore, score);
                }
            }
        }
        return bestScore;
    }
}

// Function to find the best move for the AI player
pair<int, int> findBestMove(vector<vector<int>>& board) {
    int bestScore = numeric_limits<int>::min();
    pair<int, int> bestMove = {-1, -1};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = PLAYER_O;
                int score = minimax(board, 0, false);
                board[i][j] = EMPTY;
                if (score > bestScore) {
                    bestScore = score;
                    bestMove = {i, j};
                }
            }
        }
    }
    return bestMove;
}

int main() {
    vector<vector<int>> board(3, vector<int>(3, EMPTY));
    cout << "Tic Tac Toe: You (X) vs AI (O)\n";
    printBoard(board);

    while (true) {
        int row, col;
        // Human move
        do {
            cout << "Enter your move (row and column: 0 1 2): ";
            cin >> row >> col;
        } while (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != EMPTY);

        board[row][col] = PLAYER_X;
        printBoard(board);

        if (checkWinner(board) == PLAYER_X) {
            cout << "You win!\n";
            break;
        }
        if (isBoardFull(board)) {
            cout << "It's a draw!\n";
            break;
        }

        // AI move
        cout << "AI is making a move...\n";
        pair<int, int> aiMove = findBestMove(board);
        board[aiMove.first][aiMove.second] = PLAYER_O;
        printBoard(board);

        if (checkWinner(board) == PLAYER_O) {
            cout << "AI wins!\n";
            break;
        }
        if (isBoardFull(board)) {
            cout << "It's a draw!\n";
            break;
        }
    }

    return 0;
}

