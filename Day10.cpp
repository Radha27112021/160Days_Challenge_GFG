class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        // code here...
        int max_n = 0;
        int min_n =INT_MIN;
        for(int num : arr){
            max_n = max(num , max_n+num);
            min_n = max(min_n, max_n);
        }
        return min_n;
    }
};
