#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spirallyTraverse(vector<vector<int>>& mat) {
        vector<int> result;
        if (mat.empty() || mat[0].empty()) return result;

        int top = 0, bottom = mat.size() - 1;
        int left = 0, right = mat[0].size() - 1;

        while (top <= bottom && left <= right) {
            // Traverse from left to right
            for (int i = left; i <= right; ++i) {
                result.push_back(mat[top][i]);
            }
            top++; // Move the top boundary down

            // Traverse from top to bottom
            for (int i = top; i <= bottom; ++i) {
                result.push_back(mat[i][right]);
            }
            right--; // Move the right boundary left

            if (top <= bottom) {
                // Traverse from right to left
                for (int i = right; i >= left; --i) {
                    result.push_back(mat[bottom][i]);
                }
                bottom--; // Move the bottom boundary up
            }

            if (left <= right) {
                // Traverse from bottom to top
                for (int i = bottom; i >= top; --i) {
                    result.push_back(mat[i][left]);
                }
                left++; // Move the left boundary right
            }
        }

        return result;
    }
};
