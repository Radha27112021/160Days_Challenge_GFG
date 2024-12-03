#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChar(string& s) {
        int n = s.size();
        
        // Create a combined string of the form "s#reverse(s)"
        string combined = s + '#' + string(s.rbegin(), s.rend());
        
        // Reserve LPS array for combined string
        vector<int> lps(combined.size(), 0);
        
        // Optimized LPS calculation
        for (int i = 1; i < combined.size(); ++i) {
            int j = lps[i - 1];
            // Only iterate to previous lps until a match is found
            while (j > 0 && combined[i] != combined[j]) {
                j = lps[j - 1];
            }
            if (combined[i] == combined[j]) {
                ++j;
            }
            lps[i] = j;
        }
        
        // Return the minimum characters to add at the front
        return n - lps.back();
    }
};

int main() {
    Solution sol;
    string s = "abc";
    cout << sol.minChar(s) << endl; // Output: 2
    
    s = "aacecaaaa";
    cout << sol.minChar(s) << endl; // Output: 2
    
    return 0;
}
