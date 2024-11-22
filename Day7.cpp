#include <bits/stdc++.h> // Includes all standard libraries
using namespace std;
class Solution
{
public:
    // Function to calculate the maximum profit from a single transaction
    int maximumProfit(vector<int> &prices)
    {
        int maxProfit = 0;                      // Initialize maxProfit to 0 (no profit initially)
        int minPrice = prices[0];               // Initialize minPrice to the first price (minimum price seen so far)
        for (int i = 0; i < prices.size(); i++) // Iterate through the prices array
        {
            // Update minPrice to the smallest value seen so far
            minPrice = min(minPrice, prices[i]);
            // Calculate profit if stock is sold on the current day
            int profit = prices[i] - minPrice;
            // Update maxProfit if this profit is greater than the previous max
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit; // Return the maximum profit possible
    }
};
int main()
{
    Solution sol;                                // Create an object of the Solution class
    vector<int> prices = {7, 10, 1, 3, 6, 9, 2}; // Array of stock prices for different days
    int result = sol.maximumProfit(prices);
    cout << "Maximum Profit: " << result << endl;
    return 0;
}
