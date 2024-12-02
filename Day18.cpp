class Solution {
public:
    vector<int> search(string& pat, string& txt) {
        vector<int> result;
        int m = pat.size();
        int n = txt.size();
        
        // Step 1: Compute the LPS array
        vector<int> lps(m, 0);
        computeLPSArray(pat, m, lps);
        
        // Step 2: Search the pattern in the text
        int i = 0; // index for txt
        int j = 0; // index for pat
        while (i < n) {
            if (pat[j] == txt[i]) { // Fixed: txt instead of text
                i++;
                j++;
            }
            if (j == m) {
                // Pattern found, store the starting index
                result.push_back(i - j);
                j = lps[j - 1]; // Continue to check for other occurrences
            } else if (i < n && pat[j] != txt[i]) { // Fixed: txt instead of text
                // Mismatch after j matches
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        
        return result;
    }

private:
    void computeLPSArray(string& pat, int m, vector<int>& lps) {
        int len = 0; // length of the previous longest prefix suffix
        lps[0] = 0;  // lps[0] is always 0
        int i = 1;

        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
};
