class Solution {
public:
    void setMatrixZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        // Use first row and first column as markers
        bool firstRowHasZero = false, firstColHasZero = false;

        // Check if the first row contains zero
        for (int j = 0; j < m; ++j) {
            if (mat[0][j] == 0) {
                firstRowHasZero = true;
                break;
            }
        }

        // Check if the first column contains zero
        for (int i = 0; i < n; ++i) {
            if (mat[i][0] == 0) {
                firstColHasZero = true;
                break;
            }
        }

        // Use the first row and column to mark zero rows and columns
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (mat[i][j] == 0) {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }

        // Nullify cells based on markers in the first row and column
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }

        // Nullify the first row if needed
        if (firstRowHasZero) {
            for (int j = 0; j < m; ++j) {
                mat[0][j] = 0;
            }
        }

        // Nullify the first column if needed
        if (firstColHasZero) {
            for (int i = 0; i < n; ++i) {
                mat[i][0] = 0;
            }
        }
    }
};
