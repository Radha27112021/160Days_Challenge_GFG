#include <bits/stdc++.h> // Includes all standard libraries
using namespace std;
class Solution
{
public:
    // Function to calculate the maximum profit from a single transaction
    int maximumProfit(vector<int> &prices)
    {
        int maxProfit = 0;        // Initialize maxProfit to 0 (no profit initially)
        int minPrice = prices[0]; // Initialize minPrice to the first price (minimum price seen so far)

        // Iterate through the prices array
        for (int i = 0; i < prices.size(); i++)
        {
            minPrice = min(minPrice, prices[i]); // Update minPrice to the smallest value seen so far
            int profit = prices[i] - minPrice;   // Calculate profit if stock is sold on the current day
            maxProfit = max(maxProfit, profit);  // Update maxProfit if this profit is greater than the previous max
        }

        return maxProfit; // Return the maximum profit possible
    }
};
int main()
{
    Solution sol;                                // Create an object of the Solution class
    vector<int> prices = {7, 10, 1, 3, 6, 9, 2}; // Array of stock prices for different days
                                                 // Call the function and print the result
    int result = sol.maximumProfit(prices);
    cout << "Maximum Profit: " << result << endl; // Output the maximum profit
    return 0;
}
