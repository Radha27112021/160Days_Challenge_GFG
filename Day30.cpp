#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int key) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == key) {
                return i; // If the key is found, return the index
            }
        }
        return -1; // Return -1 if the key is not found
    }
};

int main() {
    Solution obj;
    vector<int> arr = {5, 6, 7, 8, 9, 10, 1, 2, 3}; // Example input
    int key = 3;

    int result = obj.search(arr, key);
    cout << "Index of " << key << " is: " << result << endl;

    return 0;
}
