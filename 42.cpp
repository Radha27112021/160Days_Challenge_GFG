#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool twoSum(vector<int>& arr, int target) {
        unordered_map<int, int> hashMap; // Stores the complement and its index

        for (int i = 0; i < arr.size(); i++) {
            int complement = target - arr[i];

            // Check if complement exists in the hash map
            if (hashMap.find(complement) != hashMap.end()) {
                return true;
            }

            // Add current element to hash map
            hashMap[arr[i]] = i;
        }

        return false; // No such pair exists
    }
};
