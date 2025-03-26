#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int size = prices.size();
    vector<int> maxPrices(size, 0);
    maxPrices[size - 1] = prices[size - 1];
    for (int i = size - 2; i >= 0; --i)
    {
        maxPrices[i] = max(maxPrices[i + 1], prices[i]);
    }
    int maxProfit = 0;
    for (int i = 0; i < size; ++i)
    {
        maxProfit = max(maxProfit, maxPrices[i] - prices[i]);
    }
    return maxProfit;
}

int main()
{
    vector<int> prices = {7, 6, 5, 4, 3, 2, 1};
    cout << maxProfit(prices);
    return 0;
}