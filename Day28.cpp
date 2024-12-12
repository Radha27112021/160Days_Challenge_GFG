class Solution {
public:
    int countFreq(vector<int>& arr, int target) {
        // Get the size of the array
        int n = arr.size();
        
        // Initialize a variable to keep track of the count of occurrences
        int count = 0;

        // Iterate through each element in the array
        for (int i = 0; i < n; i++) {
            // Check if the current element matches the target value
            if (arr[i] == target) {
                // Increment the count if there is a match
                count++;
            }
        }

        // Return the total count of occurrences of the target
        return count;
    }
};
