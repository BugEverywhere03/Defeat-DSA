#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

bool isValidSodoku(vector<vector<char>> &board)
{
    const int row = 9;
    const int col = 9;
    unordered_map<int, unordered_set<char>> checkRow;
    unordered_map<int, unordered_set<char>> checkCol;

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == '.')
                continue;
            if (checkRow[i].find(board[i][j]) != checkRow[i].end() || checkCol[j].find(board[i][j]) != checkCol[j].end())
                return false;
            checkCol[j].insert(board[i][j]);
            checkRow[i].insert(board[i][j]);
        }
    }
    unordered_set<char> check;
    for (int i = 0; i < row; i += 1)
    {
        for (int j = 0; j < col; j += 1)
        {
            if (board[i][j] == '.')
            {
                continue;
            }
            if (check.find(board[i][j]) != check.end())
                return false;
            check.insert(board[i][j]);
        }
        if (i + 1)
    }
}