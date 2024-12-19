#include <vector>
using namespace std;

class Solution {
public:
    int kthMissing(vector<int>& arr, int k) {
        int current = 1; // Start checking from 1
        int index = 0;   // Index to traverse the array
        int count = 0;   // Count of missing numbers found

        while (count < k) {
            if (index < arr.size() && arr[index] == current) {
                // Current number is in the array, move to the next number
                index++;
            } else {
                // Current number is missing
                count++;
                if (count == k) {
                    return current;
                }
            }
            current++;
        }

        return current; // Return the result
    }
};
