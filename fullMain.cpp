#include <iostream>

using namespace std;

char board[3][3] = {{' ', ' ', ' '},
                    {' ', ' ', ' '},
                    {' ', ' ', ' '}};

void displayBoard()
{
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

bool checkWin(char player)
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }

    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

bool isBoardFull()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main()
{
    char currentPlayer = 'X';

    while (true)
    {
        displayBoard();

        int row, col;
        cout << "\nPlayer " << currentPlayer << ", enter your move (row col)(3 X 3): ";
        cin >> row >> col;
        row=row-1;
        col=col-1;
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ')
        {
            cout << "Invalid move. Please try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(currentPlayer))
        {
            displayBoard();
            cout << "\nPlayer " << currentPlayer << " wins!\n";
            break;
        }
        else if (isBoardFull())
        {
            displayBoard();
            cout << "\nIt's a tie!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
