class Solution {
public:
    // Function to count inversions in the array
    int inversionCount(vector<int>& arr) {
        int n = arr.size();
        return mergeSort(arr, 0, n - 1);
    }

private:
    // Helper function for merge sort
    int mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) return 0;
        int m = l + (r - l) / 2;
        int invCount = mergeSort(arr, l, m) + mergeSort(arr, m + 1, r);
        invCount += merge(arr, l, m, r);
        return invCount;
    }

    // Helper function for merging two sorted arrays and counting inversions
    int merge(vector<int>& arr, int l, int m, int r) {
        vector<int> left(arr.begin() + l, arr.begin() + m + 1);
        vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

        int i = 0, j = 0, k = l, invCount = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
                invCount += left.size() - i; // Count inversions
            }
        }

        while (i < left.size()) arr[k++] = left[i++];
        while (j < right.size()) arr[k++] = right[j++];
        return invCount;
    }
};
