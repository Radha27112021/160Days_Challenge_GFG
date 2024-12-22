#include <vector>
using namespace std;

class Solution {
public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int n = mat.size();    // Number of rows
        int m = mat[0].size(); // Number of columns
        
        // Start from the top-right corner of the matrix
        int row = 0, col = m - 1;

        while (row < n && col >= 0) {
            if (mat[row][col] == x) {
                return true; // Element found
            } else if (mat[row][col] > x) {
                col--; // Move left
            } else {
                row++; // Move down
            }
        }

        return false; // Element not found
    }
};
