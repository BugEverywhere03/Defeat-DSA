#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kSmallestInSortedArray(vector<vector<int>> &matrix, int k)
{
    vector<int> temp;
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            temp.push_back(matrix[i][j]);
        }
    }
    sort(temp.begin(), temp.end());
    return temp[k - 1];
}
// int kSmallestInSortedArray(vector<vector<int>> &matrix, int k)
// {
//     if (k == 1)
//     {
//         return matrix[0][0];
//     }
//     int col = k / matrix.size();
//     int row = k % matrix.size() - 1;
//     return matrix[col][row];
// }

int main()
{
    vector<vector<int>> matrix = {{1, 2}, {1, 3}};
    cout << kSmallestInSortedArray(matrix, 2);
    return 0;
}