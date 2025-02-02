#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int totalGas = 0, totalCost = 0;
    int startingPosition = 0;
    int currGas = 0;
    for (int i = 0; i < gas.size(); ++i)
    {
        totalGas += gas[i];
        totalCost += cost[i];
        currGas = gas[i] - cost[i];
        if (currGas < 0)
        {
            startingPosition = i + 1;
            currGas = 0;
        }
    }
    return totalGas < totalCost ? -1 : startingPosition;
}
int main()
{
    vector<int> gas = {2, 3, 4};
    vector<int> cost = {3, 4, 3};
    cout << canCompleteCircuit(gas, cost);
    return 0;
}
