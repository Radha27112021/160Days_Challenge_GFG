#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextSmaller(n, n);   // Next smaller elements
        vector<int> prevSmaller(n, -1);  // Previous smaller elements
        
        stack<int> st;
        
        // Finding Next Smaller Elements
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                nextSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        // Clear the stack for Previous Smaller computation
        while (!st.empty()) st.pop();
        
        // Finding Previous Smaller Elements
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                prevSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        // Array to store result
        vector<int> result(n, 0);
        
        // Calculate result for each window size
        for (int i = 0; i < n; i++) {
            int len = nextSmaller[i] - prevSmaller[i] - 1;
            result[len - 1] = max(result[len - 1], arr[i]);
        }
        
        // Fill remaining entries
        for (int i = n - 2; i >= 0; i--) {
            result[i] = max(result[i], result[i + 1]);
        }
        
        return result;
    }
};
