#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to check if we can place cows with at least 'distance'
    bool canPlaceCows(vector<int> &stalls, int k, int distance) {
        int cowsPlaced = 1;  // Place the first cow at stalls[0]
        int lastPosition = stalls[0];

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPosition >= distance) {
                cowsPlaced++;
                lastPosition = stalls[i];
            }
            if (cowsPlaced >= k) return true;
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        // Step 1: Sort the stall positions
        sort(stalls.begin(), stalls.end());

        // Step 2: Binary Search for the maximum minimum distance
        int low = 1; // Minimum possible distance
        int high = stalls.back() - stalls[0]; // Maximum possible distance
        int result = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canPlaceCows(stalls, k, mid)) {
                result = mid; // Update result
                low = mid + 1; // Try for a larger distance
            } else {
                high = mid - 1; // Reduce the distance
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;
    cout << "Maximum minimum distance: " << solution.aggressiveCows(stalls, k) << endl;

    stalls = {10, 1, 2, 7, 5};
    k = 3;
    cout << "Maximum minimum distance: " << solution.aggressiveCows(stalls, k) << endl;

    stalls = {2, 12, 11, 3, 26, 7};
    k = 5;
    cout << "Maximum minimum distance: " << solution.aggressiveCows(stalls, k) << endl;

    return 0;
}
