//Subarray Sum Equals K
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Function to count subarrays with sum equal to k
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // Base case: one way to have sum 0

        int count = 0;
        int sum = 0;

        for (int num : nums) {
            sum += num;

            // Check if there's a prefix sum that makes current sum - k
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[sum - k];
            }

            // Record current prefix sum
            prefixSumCount[sum]++;
        }

        return count;
    }
};

int main() {
    Solution sol;
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << "Enter target sum k: ";
    cin >> k;

    int result = sol.subarraySum(nums, k);
    cout << "Total subarrays with sum " << k << ": " << result << endl;

    return 0;
}
