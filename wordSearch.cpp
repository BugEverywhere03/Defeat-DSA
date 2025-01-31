#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
using namespace std;

bool backtrackSearh(vector<vector<char>> &board, string word, int index, int m, int n)
{
    if (index == word.size())
    {
        return true;
    }
    if (m < 0 || m >= board.size() || n < 0 || n >= board[0].size() || board[m][n] != word[index])
        return false;
    char temp = board[m][n];
    board[m][n] = '*';
    bool isExists = backtrackSearh(board, word, index + 1, m + 1, n) || backtrackSearh(board, word, index + 1, m - 1, n) || backtrackSearh(board, word, index + 1, m, n + 1) || backtrackSearh(board, word, index + 1, m, n - 1);
    board[m][n] = temp;
    return isExists;
}

bool exist(vector<vector<char>> &board, string word)
{
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[0].size(); ++j)
        {

            if (backtrackSearh(board, word, 0, i, j))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    cout << exist(board, word) << endl;
    return 0;
}