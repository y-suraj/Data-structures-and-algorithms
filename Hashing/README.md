# Hashing

## Longest Consecutive Sequence in an Array

Given an array nums of n integers, return the length of the longest sequence of consecutive integers. The integers in this sequence can appear in any order.

Examples:
```
Input: nums = [100, 4, 200, 1, 3, 2]

Output: 4

Explanation: The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. This sequence can be formed regardless of the initial order of the elements in the array.
```
```
Input: nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]

Output: 9

Explanation: The longest sequence of consecutive elements in the array is [0, 1, 2, 3, 4, 5, 6, 7, 8], which has a length of 9. 

Input: nums = [1, 9, 3, 10, 4, 20, 2]
Output: 4
```

Constraints:
- 1 <= nums.length <= 10^5
- -10^9 <= nums[i] <= 10^9


Solution: 

```cpp
class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        // If the array is empty
        if (n == 0) return 0;

        // Initialize the longest sequence length
        int longest = 1;
        unordered_set<int> st;

        // Put all the array elements into the set
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }

        /* Traverse the set to
        find the longest sequence*/
        for (auto it : st) {
            // Check if 'it' is a starting number of a sequence
            if (st.find(it - 1) == st.end()) {
                // Initialize the count of the current sequence
                int currentLength = 1;

                // Starting element of the sequence
                int currentNumber = it;

                // Find consecutive nubmers in the set
                while (st.find(currentNumber + 1) != st.end()) {
                    // move to the necurrentNumbert element in the sequence
                    currentLength++;
                    // Increment the count of the sequence
                    currentNumber++;
                }
                // Update the longest sequence length
                longest = max(currentLength, longest);
            }
        }
        return longest;
    }
};


/*
Time Complexity: O(N) + O(2xN) ~ O(3xN), where N is the size of the array. The function takes O(N) to insert all elements into the set data structure. After that, for every starting element, we find the consecutive elements. Although nested loops are used, the set will be traversed at most twice in the worst case. Therefore, the time complexity is O(2xN) instead of O(N2).

Space Complexity: O(N), as we use a set data structure to solve this problem.

Note: The time complexity assumes that we use an unordered_set, which has O(1) time complexity for set operations.

In the worst case, if the set operations take O(N), the total time complexity would be approximately O(N2). If we use a set instead of an unordered_set, the set operations will have a time complexity of O(logN), resulting in a total time complexity of O(NlogN).
*/
```

## Longest subarray with sum K

Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.
Examples:
```
Input: nums = [10, 5, 2, 7, 1, 9],  k=15

Output: 4

Explanation: The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array is 4.
```
```
Input: nums = [-3, 2, 1], k=6

Output: 0

Explanation: There is no sub-array in the array that sums to 6. Therefore, the output is 0.
```
```
Input: nums = [-1, 1, 1], k=1
Output: 3
```
Constraints:

- 1<=n<=10^5
- -10^5<=nums[i]<=10^5
- -10^9<= k<=10^9

Solution

```cpp
class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int n = nums.size();

        map<int, int> preSumMap;

        int longestSubarraySize = 0, currentSum = 0;

        for(int i=0; i<n; i++) {
            // calculate the prefix sum till index i
            currentSum += nums[i];
            // if the currentSum equals k, update longestSubarraySize
            if(currentSum == k) {
                longestSubarraySize = max(longestSubarraySize, i + 1);
            }

            // Calculate the difference needed to reach k
            int diff = currentSum - k;

            // Calculate the length of subarray with sum k
            if(preSumMap.find(diff) != preSumMap.end()) {
                int len = i - preSumMap[diff];
                longestSubarraySize = max(longestSubarraySize, len);
            }

            // Store index of current sum if not already present 
            // (to keep the leftmost index)
            if(preSumMap.find(currentSum) == preSumMap.end()) {
                preSumMap[currentSum] = i;
            }
        }

        return longestSubarraySize;
    }
};


/*
Time Complexity: O(N) or O(NxlogN) depending on the map data structure used, where N is the size of the array. For example, using an unordered_map in C++ gives a time complexity of O(N) (though in the worst case, unordered_map takes O(N) to find an element, making the time complexity O(N^2)). If we use a map data structure, the time complexity is O(NxlogN). The best case complexity is O(N) as we are traversing the array with a loop.

Space Complexity: O(N), since we are using a map data structure.
*/
```

