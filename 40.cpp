class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int n = mat.size();      // Number of rows
        int m = mat[0].size();   // Number of columns

        // Binary search across the entire matrix treated as a 1D array
        int low = 0, high = n * m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Calculate row and column from mid index
            int row = mid / m;
            int col = mid % m;

            if (mat[row][col] == x) {
                return true; // Found the element
            } else if (mat[row][col] < x) {
                low = mid + 1; // Move to the right half
            } else {
                high = mid - 1; // Move to the left half
            }
        }

        return false; // Element not found
    }
};
