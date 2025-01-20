#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void createMatrix(vector<vector<int>> &matrix)
{
    int m, n;
    cout << "Enter M and N : " << endl;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int value;
            cout << "Enter value = " << endl;
            cin >> value;
            temp.push_back(value);
        }
        matrix.push_back(temp);
    }
}

void rotateImage(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    vector<vector<int>> matrix;
    createMatrix(matrix);
    rotateImage(matrix);
    for (vector<int> v : matrix)
    {
        for (int item : v)
            cout << item << "";
        cout << endl;
    }
    return 0;
}