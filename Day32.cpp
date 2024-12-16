class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // Ensure 'a' is the smaller array to optimize binary search
        if (a.size() > b.size()) 
            return kthElement(b, a, k);
        
        int n = a.size(), m = b.size();
        int low = max(0, k - m), high = min(k, n);
        
        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = k - cut1;

            int left1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
            int left2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
            int right1 = (cut1 == n) ? INT_MAX : a[cut1];
            int right2 = (cut2 == m) ? INT_MAX : b[cut2];

            if (left1 <= right2 && left2 <= right1) {
                return max(left1, left2);
            } else if (left1 > right2) {
                high = cut1 - 1; // Move to the left in array a
            } else {
                low = cut1 + 1; // Move to the right in array a
            }
        }
        
        return 1; // Placeholder, execution shouldn't reach here
    }
};
