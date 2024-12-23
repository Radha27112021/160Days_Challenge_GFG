#include <vector>
using namespace std;

class Solution {
public:
    // Function to search a given number in a row-wise sorted matrix
    bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size();    // Number of rows
        int m = mat[0].size(); // Number of columns

        for (int i = 0; i < n; i++) {
            // Apply binary search on each row
            int left = 0, right = m - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;

                if (mat[i][mid] == x) {
                    return true; // Element found
                } else if (mat[i][mid] < x) {
                    left = mid + 1; // Search in the right half
                } else {
                    right = mid - 1; // Search in the left half
                }
            }
        }
        return false; // Element not found in any row
    }
};
