#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    // Function to find maximum circular subarray sum
    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size();

        // Step 1: Find the maximum subarray sum using Kadane's algorithm (non-circular)
        int maxKadane = kadane(arr);

        // Step 2: Find the total sum of the array
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
        }

        // Step 3: Invert the elements of the array and find the minimum subarray sum
        for (int i = 0; i < n; i++) {
            arr[i] = -arr[i];
        }
        int minKadane = kadane(arr);

        // Step 4: The maximum circular subarray sum will be totalSum + minKadane
        // But we must not include the case where all elements are inverted (which would be a negative sum)
        int maxCircular = totalSum + minKadane;

        // Step 5: The result will be the maximum of maxKadane and maxCircular
        if (maxCircular == 0) {  // If maxCircular equals 0, it means the entire array was negative.
            return maxKadane;
        }
        return max(maxKadane, maxCircular);
    }

private:
    // Kadane's algorithm to find the maximum subarray sum
    int kadane(vector<int> &arr) {
        int maxSum = arr[0];
        int currentSum = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            currentSum = max(arr[i], currentSum + arr[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};
