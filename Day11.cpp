class Solution {
public:
    // Function to find maximum product subarray
    int maxProduct(vector<int>& arr) {
        // Edge case: if the array is empty
        if (arr.empty()) return 0;

        int max_ending_here = arr[0];
        int min_ending_here = arr[0];
        int max_product = arr[0];

        // Traverse the array starting from the second element
        for (size_t i = 1; i < arr.size(); ++i) {
            // If the current element is negative, swap max and min
            if (arr[i] < 0) {
                swap(max_ending_here, min_ending_here);
            }

            // Update max and min ending here
            max_ending_here = max(arr[i], max_ending_here * arr[i]);
            min_ending_here = min(arr[i], min_ending_here * arr[i]);

            // Update the overall maximum product
            max_product = max(max_product, max_ending_here);
        }

        return max_product;
    }
};
