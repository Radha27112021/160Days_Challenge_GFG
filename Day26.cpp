#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Function to calculate minimum intervals to remove
int minRemoval(vector<vector<int>>& intervals) {
    // Sort the intervals based on their end times
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int prev_end = INT_MIN;
    int remove_count = 0;

    for (const auto& interval : intervals) {
        if (interval[0] < prev_end) {
            // Overlapping interval
            remove_count++;
        } else {
            // Update the end of the last non-overlapping interval
            prev_end = interval[1];
        }
    }

    return remove_count;
}

int main() {
    // Test input
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    
    // Output the result
    cout << "Minimum number of intervals to remove: " << minRemoval(intervals) << endl;

    return 0;
}
