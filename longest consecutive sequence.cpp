//Longest Consecutive Sequence
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // Function to find the length of the longest consecutive sequence
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end()); // Store all numbers for O(1) lookup
        int longest = 0;

        for (int num : numSet) {
            // Only start counting if it's the beginning of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                // Count consecutive numbers
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }

                longest = max(longest, currentStreak);
            }
        }

        return longest;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = sol.longestConsecutive(nums);
    cout << "Length of longest consecutive sequence: " << result << endl;

    return 0;
}
