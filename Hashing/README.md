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
Time Complexity: O(N) + O(2xN) ~ O(3xN), where N is the size of the array. 
The function takes O(N) to insert all elements into the set data structure. 
After that, for every starting element, we find the consecutive elements. 
Although nested loops are used, the set will be traversed at most twice in the worst case. 
Therefore, the time complexity is O(2xN) instead of O(N2).

Space Complexity: O(N), as we use a set data structure to solve this problem.

Note: The time complexity assumes that we use an unordered_set, which has O(1) time complexity for set operations.

In the worst case, if the set operations take O(N), the total time complexity would be approximately O(N2). 
If we use a set instead of an unordered_set, the set operations will have a time complexity of O(logN), resulting in a total time complexity of O(NlogN).
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
Time Complexity: O(N) or O(NxlogN) depending on the map data structure used, where N is the size of the array. 
For example, using an unordered_map in C++ gives a time complexity of O(N) (though in the worst case, unordered_map takes O(N) to find an element, making the time complexity O(N^2)). 
If we use a map data structure, the time complexity is O(NxlogN). The best case complexity is O(N) as we are traversing the array with a loop.

Space Complexity: O(N), since we are using a map data structure.
*/
```

## Count subarrays with given sum

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

Examples:

```
Input: nums = [1, 1, 1], k = 2

Output: 2

Explanation: In the given array [1, 1, 1], there are two subarrays that sum up to 2: [1, 1] and [1, 1]. Hence, the output is 2.
```
```
Input: nums = [1, 2, 3], k = 3

Output: 2

Explanation: In the given array [1, 2, 3], there are two subarrays that sum up to 3: [1, 2] and [3]. Hence, the output is 2.
```
```
Input: nums = [3, 1, 2, 4], k = 6
Output: 2
```
Constraints:

- 1 <= nums.length <= 10^5
- -1000 <= nums[i] <= 1000
- -10^7 <= k <= 10^7

Solution:

```cpp
class Solution {
   public:
    int subarraySum(vector<int> &nums, int k) {
        int n = nums.size();

        map<int, int> prefixSumMap;

        int subArrayWithSumK_count = 0, currentPrefixSum = 0;

        // Setting 0 in the map.
        prefixSumMap[0] = 1;

        for (int i = 0; i < n; i++) {
            // Add current element to the prefix sum:
            currentPrefixSum += nums[i];

            /*Calculate the value to
            remove (currentPrefixSum - k)*/
            int sumToRemove = currentPrefixSum - k;

            /* Add the number of subarrays
             with the sum to be removed*/
            subArrayWithSumK_count += prefixSumMap[sumToRemove];

            /* Update the count of current
            prefix sum in the map*/
            prefixSumMap[currentPrefixSum] += 1;
        }
        return subArrayWithSumK_count;
    }
};

/*
Time Complexity: O(N) or O(NxlogN) depending on the map data structure used, where N is the size of the array. 
For example, if we use an unordered_map in C++, the time complexity will be O(N), but if we use a map, the time complexity will be O(NxlogN). 
The minimum complexity is O(N) as we are using a single loop to traverse the array.

Space Complexity: O(N) as we are using a map data structure.
*/
```

## Count subarrays with given xor K

Given an array of integers nums and an integer k, return the total number of subarrays whose XOR equals to k.

Examples:
```
Input : nums = [4, 2, 2, 6, 4], k = 6

Output : 4

Explanation : The subarrays having XOR of their elements as 6 are [4, 2],  [4, 2, 2, 6, 4], [2, 2, 6], and [6]
```
```
Input :nums = [5, 6, 7, 8, 9], k = 5

Output : 2

Explanation : The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]
```
```
Input : nums = [5, 2, 9], k = 7
Output: 1
```

Constraints:

- 1 <= nums.length <= 10^5
- 1 <= nums[i] <= 10^9
- 1 <= k <= 10^9

Solution:

```cpp

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysWithXorK(vector<int>& nums, int k)
    {
        int n = nums.size(); 
        int xr = 0;
        map<int, int> mpp; 
        // setting the value of 0.
        mpp[xr]++; 
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            // prefix XOR till index i:
            xr = xr ^ nums[i];

            // By formula: x = xr^k:
            int x = xr ^ k;

            // add the occurrence of xr^k to the count:
            cnt += mpp[x];

            // Insert the prefix xor till index i into the map:
            mpp[xr]++;
        }
        return cnt;
    }
};

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;

    // Create an instance of the Solution class
    Solution solution;

    // Function call to get the result
    int ans = solution.subarraysWithXorK(a, k);

    cout << "The number of subarrays with XOR k is: " << ans << "\n";
    return 0;
}

/*
Time Complexity: O(N) or O(NxlogN), where N is the size of the array. If we use an unordered_map in C++, the time complexity is O(N). 
However, with a map data structure, the time complexity is O(NxlogN). 
In the worst case for an unordered_map, the searching time can increase to O(N), making the overall time complexity O(N2).

Space Complexity: O(N), as we are using a map data structure.
*/

```

## Extras

### [3551. Minimum Swaps to Sort by Digit Sum](https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum/description/)

<div class="elfjS" data-track-load="description_content"><p>You are given an array <code>nums</code> of <strong>distinct</strong> positive integers. You need to sort the array in <strong>increasing</strong> order based on the sum of the digits of each number. If two numbers have the same digit sum, the <strong>smaller</strong> number appears first in the sorted order.</p>

<p>Return the <strong>minimum</strong> number of swaps required to rearrange <code>nums</code> into this sorted order.</p>

<p>A <strong>swap</strong> is defined as exchanging the values at two distinct positions in the array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [37,100]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Compute the digit sum for each integer: <code>[3 + 7 = 10, 1 + 0 + 0 = 1] → [10, 1]</code></li>
	<li>Sort the integers based on digit sum: <code>[100, 37]</code>. Swap <code>37</code> with <code>100</code> to obtain the sorted order.</li>
	<li>Thus, the minimum number of swaps required to rearrange <code>nums</code> is 1.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [22,14,33,7]</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Compute the digit sum for each integer: <code>[2 + 2 = 4, 1 + 4 = 5, 3 + 3 = 6, 7 = 7] → [4, 5, 6, 7]</code></li>
	<li>Sort the integers based on digit sum: <code>[22, 14, 33, 7]</code>. The array is already sorted.</li>
	<li>Thus, the minimum number of swaps required to rearrange <code>nums</code> is 0.</li>
</ul>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [18,43,34,16]</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Compute the digit sum for each integer: <code>[1 + 8 = 9, 4 + 3 = 7, 3 + 4 = 7, 1 + 6 = 7] → [9, 7, 7, 7]</code></li>
	<li>Sort the integers based on digit sum: <code>[16, 34, 43, 18]</code>. Swap <code>18</code> with <code>16</code>, and swap <code>43</code> with <code>34</code> to obtain the sorted order.</li>
	<li>Thus, the minimum number of swaps required to rearrange <code>nums</code> is 2.</li>
</ul>
</div>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>nums</code> consists of <strong>distinct</strong> positive integers.</li>
</ul>
</div>

**Solution:**
```cpp
class Solution {
public:
    int digitSum(int n) {
        int sum = 0;

        while (n != 0) {
            int rem = n % 10;
            sum += rem;
            n /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Pair each number with its digit sum
        vector<pair<int, int>> digitSumAndValue;
        for (int num : nums) {
            digitSumAndValue.push_back({digitSum(num), num});
        }

        // Step 2: Sort by digit sum, and by value if digit sums are equal
        sort(digitSumAndValue.begin(), digitSumAndValue.end(),
             [](pair<int, int>& a, pair<int, int>& b) {
                 if (a.first != b.first)
                     return a.first < b.first;
                 return a.second < b.second;
             });

        // Step 3: Build the target sorted array
        vector<int> sortedNums;
        for (auto& p : digitSumAndValue) {
            sortedNums.push_back(p.second);
        }

        // Step 4: Create a map from value to its index in the original array
        unordered_map<int, int> valueToIndex;
        for (int i = 0; i < n; ++i) {
            valueToIndex[nums[i]] = i;
        }

        // Step 5: Count minimum number of swaps via cycle detection
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || nums[i] == sortedNums[i])
                continue;

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = valueToIndex[sortedNums[j]];
                ++cycleSize;
            }

            if (cycleSize > 1) {
                swaps += (cycleSize - 1);
            }
        }

        return swaps;
    }
};
```
**Time Complexity**: O(n log n)

**Space Complexity**: O(n)
