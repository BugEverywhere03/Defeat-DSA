#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Using set
void setZeroesUsingSet(vector<vector<int>> &matrix)
{
    unordered_set<int> colMustChange;
    unordered_set<int> rowMustChange;
    int row = matrix.size();
    int col = matrix[0].size();
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (matrix[i][j] == 0)
            {
                colMustChange.insert(j);
                rowMustChange.insert(i);
            }
        }
    }
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (colMustChange.count(j) || rowMustChange.count(i))
                matrix[i][j] = 0;
        }
    }
}

void setZeroes(vector<vector<int>> &matrix)
{
    int state = 1;
    int max_row = matrix.size();
    int max_col = matrix[0].size();
    for (int i = 0; i < max_row; i++)
    {
        /* Kiểm tra xem các cột trong hàng đầu tiên có cột nào bằng 0 hay không
        để thay đổi các giá trị của phần tử đầu tiên ở mỗi hàng */
        if (!matrix[i][0])
            state = 0;
        // Gán các cột và hàng đầu tiên của ma trận thành 0 nếu trong hàng hoặc cột đó có 1 phần tử là 0
        for (int j = 1; j < max_col; ++j)
        {
            if (!matrix[i][j])
                matrix[i][0] = matrix[0][j] = 0;
        }
    }
    for (int i = 0; i < max_row; ++i)
    {
        for (int j = 1; j < max_col; ++j)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
            if (!state)
                matrix[i][0] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{0, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    // setZeroes(matrix);
    setZeroesUsingSet(matrix);
    for (auto v : matrix)
    {
        for (auto num : v)
        {
            cout << num << " | ";
        }
        cout << endl;
    }
    return 0;
}