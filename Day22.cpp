#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findHIndex(vector<int>& citations) {
    // Sort citations in descending order
    sort(citations.rbegin(), citations.rend());

    int hIndex = 0;
    for (int i = 0; i < citations.size(); i++) {
        // Check if the current citation count is at least (i + 1)
        if (citations[i] >= i + 1) {
            hIndex = i + 1;
        } else {
            break;
        }
    }

    return hIndex;
}

int main() {
    vector<int> citations1 = {3, 0, 5, 3, 0};
    vector<int> citations2 = {5, 1, 2, 4, 1};
    vector<int> citations3 = {0, 0};

    cout << "H-Index for citations1: " << findHIndex(citations1) << endl; // Output: 3
    cout << "H-Index for citations2: " << findHIndex(citations2) << endl; // Output: 2
    cout << "H-Index for citations3: " << findHIndex(citations3) << endl; // Output: 0

    return 0;
}
