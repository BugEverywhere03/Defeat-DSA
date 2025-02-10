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
    unordered_map<int, unordered_set<char>> checkSquad3x3;
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
            int numSquar = (i / 3) * 3 + (j / 3);
            if (checkSquad3x3[numSquar].find(board[i][j]) != checkSquad3x3[numSquar].end())
                return false;
            checkSquad3x3[numSquar].insert(board[i][j]);
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout << isValidSodoku(board) << endl;
    return 0;
}