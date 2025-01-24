#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfitII(vector<int> prices)
{
    int maxProfit = 0;
    int minPrice = 0, maxPrice = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        while (i < prices.size() - 1 && prices[i + 1] < prices[i])
            i++;
        minPrice = prices[i];
        while (i < prices.size() - 1 && prices[i + 1] > prices[i])
            i++;
        maxPrice = prices[i];
        maxProfit += max(maxPrice - minPrice, 0);
    }
    return maxProfit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = maxProfitII(prices);
    cout << result << endl;
    return 0;
}