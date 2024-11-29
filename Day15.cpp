#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string& s1, string& s2) {
        string ans = "";
        int i = s1.size() - 1, j = s2.size() - 1, carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += s1[i--] - '0';
            if (j >= 0) sum += s2[j--] - '0';

            ans += (sum % 2) + '0';  // Append the result of sum % 2
            carry = sum / 2;         // Update carry
        }

        reverse(ans.begin(), ans.end());

        // Remove leading zeros
        int start = 0;
        while (start < ans.size() && ans[start] == '0') {
            start++;
        }
        
        return start == ans.size() ? "0" : ans.substr(start);
    }
};

int main() {
    Solution sol;
    string s1 = "1101", s2 = "111";
    cout << sol.addBinary(s1, s2) << endl; // Output: 10100
    return 0;
}
