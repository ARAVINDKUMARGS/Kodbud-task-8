#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int choice, row, col;
char turn = 'X';
bool draw = false;

void displayBoard() {
    cout << "\nTic Tac Toe\n";
    for(int i = 0; i < 3; i++) {
        cout << " ";
        for(int j = 0; j < 3; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

bool checkWin() {
    for(int i = 0; i < 3; i++)
        if ((board[i][0]==board[i][1] && board[i][1]==board[i][2]) || 
            (board[0][i]==board[1][i] && board[1][i]==board[2][i]))
            return true;

    if ((board[0][0]==board[1][1] && board[1][1]==board[2][2]) ||
        (board[0][2]==board[1][1] && board[1][1]==board[2][0]))
        return true;

    return false;
}

void playerTurn() {
    cout << "Player " << turn << ", enter a number: ";
    cin >> choice;
    row = (choice-1)/3;
    col = (choice-1)%3;

    if (board[row][col] != 'X' && board[row][col] != 'O')
        board[row][col] = turn;
    else {
        cout << "Invalid move, try again.\n";
        playerTurn();
    }
}

int main() {
    int moves = 0;
    while (!checkWin() && moves < 9) {
        displayBoard();
        playerTurn();
        turn = (turn == 'X') ? 'O' : 'X';
        moves++;
    }
    displayBoard();
    if (checkWin())
        cout << "Player " << ((turn == 'X') ? 'O' : 'X') << " wins!\n";
    else
        cout << "It's a draw!\n";
    return 0;
}
