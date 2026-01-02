/*
================================================================================
PROBLEM: Two Sum
PLATFORM: LeetCode (Problem #1)
DIFFICULTY: Easy
TOPIC: Arrays, Hash Map
================================================================================

PROBLEM STATEMENT:
------------------
Given an array of integers nums and an integer target, return indices of the 
two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may 
not use the same element twice.

You can return the answer in any order.

EXAMPLES:
---------
Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

CONSTRAINTS:
------------
* 2 <= nums.length <= 10^4
* -10^9 <= nums[i] <= 10^9
* -10^9 <= target <= 10^9
* Only one valid answer exists.

================================================================================
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /*
    ============================================================================
    APPROACH 1: BRUTE FORCE
    ============================================================================
    Algorithm:
    ----------
    1. Use two nested loops
    2. For each element, check if any other element adds up to target
    3. Return indices when found
    
    Time Complexity: O(n^2) - Two nested loops
    Space Complexity: O(1) - No extra space used
    
    Status: ❌ Not Optimal (but works for small inputs)
    ============================================================================
    */
    vector<int> twoSum_BruteForce(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Check every pair of elements
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        
        return {}; // No solution found
    }
    
    /*
    ============================================================================
    APPROACH 2: HASH MAP (OPTIMAL SOLUTION)
    ============================================================================
    Algorithm:
    ----------
    1. Use a hash map to store (number -> index) pairs
    2. For each element, check if (target - current_element) exists in map
    3. If yes, return the indices
    4. If no, add current element to map and continue
    
    Time Complexity: O(n) - Single pass through array
    Space Complexity: O(n) - Hash map stores up to n elements
    
    Status: ✅ Optimal Solution
    ============================================================================
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap; // number -> index
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if complement exists in map
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            // Add current number to map
            numMap[nums[i]] = i;
        }
        
        return {}; // No solution found
    }
};

/*
================================================================================
TEST CASES
================================================================================
*/
void printResult(vector<int>& result) {
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
}

int main() {
    Solution solution;
    
    // Test Case 1
    cout << "Test Case 1:" << endl;
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = solution.twoSum(nums1, target1);
    cout << "Input: nums = [2,7,11,15], target = 9" << endl;
    cout << "Output: ";
    printResult(result1);
    cout << "Expected: [0, 1]" << endl << endl;
    
    // Test Case 2
    cout << "Test Case 2:" << endl;
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = solution.twoSum(nums2, target2);
    cout << "Input: nums = [3,2,4], target = 6" << endl;
    cout << "Output: ";
    printResult(result2);
    cout << "Expected: [1, 2]" << endl << endl;
    
    // Test Case 3
    cout << "Test Case 3:" << endl;
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = solution.twoSum(nums3, target3);
    cout << "Input: nums = [3,3], target = 6" << endl;
    cout << "Output: ";
    printResult(result3);
    cout << "Expected: [0, 1]" << endl << endl;
    
    return 0;
}

/*
================================================================================
COMPLEXITY ANALYSIS
================================================================================

Approach 1 (Brute Force):
-------------------------
Time Complexity: O(n^2)
- Two nested loops iterate through all pairs

Space Complexity: O(1)
- No additional data structures used

Approach 2 (Hash Map) - OPTIMAL:
--------------------------------
Time Complexity: O(n)
- Single pass through the array
- Hash map operations (insert/lookup) are O(1) average

Space Complexity: O(n)
- Hash map can store up to n elements in worst case

================================================================================
KEY INSIGHTS
================================================================================

1. Hash Map trades space for time - We use extra memory to achieve faster lookup
2. The complement approach is elegant: instead of searching for two numbers that
   sum to target, we search for (target - current_number)
3. We can solve this in a single pass without needing to sort the array
4. This problem teaches the fundamental hash map pattern used in many problems

================================================================================
LEARNING POINTS
================================================================================

✅ When to use Hash Map: When you need fast lookups (O(1))
✅ Complement Pattern: Very common in array/sum problems
✅ Trade-offs: Brute force vs Optimized (time vs space)
✅ Interview Tip: Always discuss multiple approaches!

================================================================================

Author: Sousnav Debnath
GitHub: https://github.com/SOUSNAV-deb03
Date: January 2025

================================================================================
*/
