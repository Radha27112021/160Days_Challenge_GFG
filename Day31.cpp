class Solution {
public:
    int peakElement(vector<int> &arr) {
        int n = arr.size();
        int s = 0; // Start index
        int e = n - 1; // End index

        while (s <= e) {
            int mid = s + (e - s) / 2; // To avoid overflow
            
            // Check if mid is a peak element
            if ((mid == 0 || arr[mid] > arr[mid - 1]) &&
                (mid == n - 1 || arr[mid] > arr[mid + 1])) {
                return mid;
            }
            // If the left neighbor is greater, search on the left half
            else if (mid > 0 && arr[mid - 1] > arr[mid]) {
                e = mid - 1;
            }
            // Otherwise, search on the right half
            else {
                s = mid + 1;
            }
        }
        return -1; // No peak element found (shouldn't happen in this problem)
    }
};
