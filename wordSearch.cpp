#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
using namespace std;
vector<pair<int, int>> getsequence(vector<vector<string>> &board, int m, int n)
{
    vector<pair<int, int>> result;
    int col = board.size();
    int row = board[0].size();
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            pair<int, int> position = {i, j};
            if (i > 0 && j > 0 && i < col && j < row)
            {
                if (m - 1 == i && j == n - 1)
                {

                    result.push_back(position);
                }
                if (m + 1 == i && j == n + 1)
                {
                    result.push_back(position);
                }
                if (m == i && (n - 1 == j || n + 1 == j))
                {
                    result.push_back(position);
                }
            }
        }
    }
    return result;
}

void backtrackSearh(unordered_map<string, pair<int, int>> found, vector<vector<string>> &board, string word, int index, int m, int n)
{
    if (index == word.size())
    {
        return;
    }
    vector<pair<int, int>> sequences = getsequence(board, m, n);
    for (int i = 0; i < sequences.size(); i++)
    {
        pair<int, int> curPair = sequences[i];
        if (board[curPair.first][curPair.second][0] == word[index])
        {
        }
    }
}

bool exist(vector<vector<string>> board, string word)
{
    return true;
}

int main()
{
    return 0;
}