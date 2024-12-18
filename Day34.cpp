#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to check the number of students required
    int func(vector<int>& arr, int maxPages) {
        int students = 1; // Start with 1 student
        int pagesSum = 0; // Pages assigned to the current student

        for (int pages : arr) {
            if (pagesSum + pages > maxPages) { 
                // Assign pages to the next student
                students++;
                pagesSum = pages; // Start a new sum for the next student
            } else {
                pagesSum += pages; // Add pages to the current student
            }
        }
        return students;
    }

    // Function to find the minimum maximum pages
    int findPages(vector<int>& arr, int k) {
        if (arr.size() < k) { // If books are fewer than students
            return -1;
        }

        int low = *max_element(arr.begin(), arr.end()); // Largest single book
        int high = accumulate(arr.begin(), arr.end(), 0); // Total sum of pages

        while (low <= high) {
            int mid = low + (high - low) / 2; // Calculate the mid value
            int noOfStudents = func(arr, mid); // Check how many students are needed

            if (noOfStudents > k) {
                low = mid + 1; // Increase maxPages (mid) since allocation failed
            } else {
                high = mid - 1; // Try for a smaller maxPages
            }
        }

        return low; // Minimum maximum pages
    }
};
