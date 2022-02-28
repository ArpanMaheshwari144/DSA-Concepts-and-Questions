#include <bits/stdc++.h>
#define n 4
using namespace std;

void printSolution(int board[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}

bool isSafe(int borad[n][n], int row, int col)
{
    // check upper diagonal
    int duprow = row;
    int dupcol = col;

    // check for upwards diagonally
    while (row >= 0 && col >= 0)
    {
        if (borad[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }

    col = dupcol;
    row = duprow;

    // check for left
    while (col >= 0)
    {
        if (borad[row][col] == 1)
        {
            return false;
        }
        col--;
    }

    col = dupcol;
    row = duprow;

    // check for downward diagonally
    while (row < n && col >= 0)
    {
        if (borad[row][col] == 1)
        {
            return false;
        }
        row++;
        col--;
    }
    return true;
}

bool solveNQ(int board[n][n], int col)
{
    if (col >= n)
    {
        return true;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 1;
            if (solveNQ(board, col + 1))
            {
                return true;
            }
            board[row][col] = 0; // backtrack
        }
    }
    return false;
}

int main()
{
    int board[n][n] = {{0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0}};

    if (solveNQ(board, 0) == false)
    {
        cout << "Solution does not exist";
        exit(0);
    }

    printSolution(board);

    return 0;
}