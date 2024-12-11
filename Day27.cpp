#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        int i = n - 1, j = 0;
        
        // Compare and swap the largest of 'a' with the smallest of 'b'
        while (i >= 0 && j < m) {
            if (a[i] > b[j]) {
                swap(a[i], b[j]);
            }
            i--;
            j++;
        }

        // Sort both arrays to maintain sorted order
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};
