#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    char nonRepeatingChar(string &s) {
        vector<int> freq(26, 0); // Array to store frequency of each letter
        vector<int> index(26, -1); // Array to store the first index of each letter
        
        // Count frequency and track the first index of each character
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            freq[c - 'a']++;
            if (index[c - 'a'] == -1) {
                index[c - 'a'] = i; // Record the first occurrence index
            }
        }
        
        // Find the first non-repeating character based on the smallest index
        int minIndex = s.size();
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 1) {
                minIndex = min(minIndex, index[i]);
            }
        }
        
        // If no non-repeating character is found, return '$'
        return (minIndex == s.size()) ? '$' : s[minIndex];
    }
};
