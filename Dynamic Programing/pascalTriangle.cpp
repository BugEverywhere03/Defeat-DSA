#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> getRowByMemory(int rowIndex, unordered_map<int, vector<int>> &memory)
{
    if (rowIndex == 0)
        return memory[rowIndex];
    vector<int> row;
    if (memory.find(rowIndex) == memory.end())
    {
        vector<int> preVec = getRowByMemory(rowIndex - 1, memory);
        for (int i = 0; i <= rowIndex; ++i)
        {
            if (i == 0 || i == rowIndex)
                row.push_back(1);
            else
                row.push_back(preVec[i - 1] + preVec[i]);
        }
        memory[rowIndex] = row;
    }
    return row;
}
vector<int> getRow(int rowIndex)
{
    unordered_map<int, vector<int>> memoRow;
    memoRow[0] = vector<int>(1);
    return getRowByMemory(rowIndex, memoRow);
}

int main()
{
    vector<int> pascalRow = getRow(4);
    for (int col : pascalRow)
    {
        cout << col << " ";
    }
    return 0;
}
