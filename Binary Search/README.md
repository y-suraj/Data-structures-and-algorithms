# Binary Search

## Fundamentals

### Search X in sorted array

<p>Given a sorted array of integers nums with 0-based indexing, find the <strong>index</strong> of a specified <strong>target</strong> integer. If the target is found in the array, return its index. If the target is not found, return -1.</p>

Examples:
```
Input: nums = [-1,0,3,5,9,12], target = 9

Output: 4

Explanation: The target integer 9 exists in nums and its index is 4
```
```
Input: nums = [-1,0,3,5,9,12], target = 2

Output: -1

Explanation: The target integer 2 does not exist in nums so return -1
```
```
Input: nums = [-1,0,3,5,9,12], target = -1
Output: 0
```

Constraints:

- 1 <= nums.length <= 10^5
- -10^5 < nums[i], target < 10^5
- nums is sorted in ascending order.

Solution:
```cpp
class Solution {
public:
    // Finds index of target in sorted array
    int search(vector<int> &nums, int target) {

        // Search range
        int low = 0, high = nums.size() - 1;

        // Binary search loop
        while (low <= high) {

            // Middle index
            int mid = (low + high) / 2;

            // Move right if mid is less than target
            if (nums[mid] < target) {
                low = mid + 1;
            }
            // Move left if mid is greater than target
            else if (nums[mid] > target) {
                high = mid - 1;
            }

            // Target found
            else {
                return mid;
            }
        }
        // Target not found
        return -1;
    }
};
```
<p><strong>Time Complexity: O(log(N))</strong> (where N is the size of the given array) <br>
    In each step, the search space is divided into two halves. In the worst case, this process will continue until the search space can no longer be divided and the number of divisions required to reduce the array size to one is log(N), making the overall time complexity O(log(N)).
</p>
<p><strong>Space Complexity: O(1)</strong> <br>
Using only a couple of variables.</p>

### Lower Bound

<p ><p>Given a sorted array of nums and an integer x, write a program to find the <strong>lower bound</strong> of <strong>x</strong>. The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.</p><p>If no such index is found, return the size of the array.</p></p>

Examples:
```
Input : nums= [1,2,2,3], x = 2

Output:1

Explanation: Index 1 is the smallest index such that arr[1] >= x.
```
```
Input : nums= [3,5,8,15,19], x = 9

Output: 3

Explanation: Index 3 is the smallest index such that arr[3] >= x.
```
```
Input : nums= [3,5,8,15,19], x = 3
Output: 0
```

Constraints:

- 1 <= nums.length <= 10^5
- -10^5 < nums[i], x < 10^5
- nums is sorted in ascending order.

Solution:
```cpp
class Solution {
public:
    // Finds the lower bound index for x
    int lowerBound(vector<int> &nums, int x) {

        // Size of the array
        int n = nums.size();

        // Search range
        int low = 0, high = n - 1;

        // Default lower bound (not found case)
        int lowerBoundIndex = n;

        // Binary search loop
        while (low <= high) {
            // Middle index
            int mid = (low + high) / 2;

            // Move right if mid is less than x
            if (nums[mid] < x) {
                low = mid + 1;
            }
            // Move left and update result
            else {
                lowerBoundIndex = mid;
                high = mid - 1;
            }
        }
        // Return the lower bound index
        return lowerBoundIndex;
    }
};
```
<p><strong>Time Complexity:</strong> O(log N), where N is the size of the given array. For using the Binary Search algorithm, the search space is divided in half each time, resulting in a logarithmic time complexity.</p>
<p><strong>Space Complexity:</strong> O(1), not using any extra space to solve this problem.</p>


### Upper Bound
<p><p>Given a sorted array of nums and an integer x, write a program to find the <strong>upper bound</strong> of <strong>x</strong>. The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than a given key i.e. x.</p><p>If no such index is found, return the size of the array.</p></p>

Examples:
```
Input : n= 4, nums = [1,2,2,3], x = 2

Output:3

Explanation: Index 3 is the smallest index such that arr[3] > x.
```
```
Input : n = 5, nums = [3,5,8,15,19], x = 9

Output: 3

Explanation: Index 3 is the smallest index such that arr[3] > x.
```
```
Input : n = 5, nums = [3,5,8,15,19], x = 3
Output: 1
```
Constraints:

- 1 <= nums.length <= 10^5
- -10^5 < nums[i], x < 10^5
- nums is sorted in ascending order.

Solution:

```cpp
class Solution {
public:
    // Finds the upper bound index for x
    int upperBound(vector<int> &nums, int x) {

        // Size of the array
        int n = nums.size();

        // Search range
        int low = 0, high = n - 1;

        // Default upper bound (not found case)
        int upperBoundIndex = n;

        // Binary search loop
        while (low <= high) {
            // Middle index
            int mid = (low + high) / 2;

            // Move right if mid element <= x
            if (nums[mid] <= x) {
                low = mid + 1;
            }
            // Move left and update result
            else {
                upperBoundIndex = mid;
                high = mid - 1;
            }
        }
        // Return the upper bound index
        return upperBoundIndex;
    }
};
```
<p><strong>Time Complexity:</strong> O(logN), where N is the size of the given array. We are using the Binary Search algorithm, which divides the search space in half each time, resulting in a logarithmic time complexity.</p>
<p><strong>Space Complexity:</strong> O(1), as we are not using any extra space to solve this problem.</p>

## Logic Building

### Search insert position
<p>Given a sorted array of nums consisting of distinct integers and a target value, return the <strong>index</strong> if the <strong>target</strong> is found. If not, return the index where it would be if it were inserted in order.</p>

Examples:
```
Input: nums = [1, 3, 5, 6], target = 5

Output: 2

Explanation: The target value 5 is found at index 2 in the sorted array. Hence, the function returns 2.
```
```
Input: nums = [1, 3, 5, 6], target = 2

Output: 1

Explanation: The target value 2 is not found in the array. However, it should be inserted at index 1 to maintain the sorted order of the array.
```
```
Input: nums = [1, 3, 5, 6], target = 7
Output: 4
```

Constraints:

- 1 <= nums.length <= 10^5
- -10^5 <= nums[i] <= 10^5
- nums contains distinct values sorted in ascending order.
- -10^5<= target <= 10^5

Solution:
```cpp
class Solution {
public:
    // Finds index to insert target in sorted array
    int searchInsert(vector<int> &nums, int target)  {

        // Size of the array
        int n = nums.size();

        // Search range
        int low = 0, high = n - 1;

        // Binary search loop
        while (low <= high) {
            // Middle index
            int mid = (low + high) / 2;

            // Move left if mid element > target
            if (nums[mid] > target) {
                high = mid - 1;
            }
            // Move right if mid element < target
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            // Target found
            else {
                return mid;
            }
        }
        // Return insertion index (position of low)
        return low;
    }
};
```

<p><strong>Time Complexity:</strong> O(logN), where N is the size of the given array. We are using the Binary Search algorithm, which divides the search space in half each time, resulting in a logarithmic time complexity.</p>
<p><strong>Space Complexity:</strong> O(1), as we are not using any extra space to solve this problem.</p>

### Floor and Ceil in Sorted Array

<p>Given a sorted array nums and an integer x. Find the <strong>floor</strong> and <strong>ceil</strong> of x in nums. The floor of x is the largest element in the array which is smaller than or equal to x. The ceiling of x is the smallest element in the array greater than or equal to x. If no floor or ceil exists, output -1.</p>

Examples:
```
Input : nums =[3, 4, 4, 7, 8, 10], x= 5

Output: 4 7

Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.
```
```
Input : nums =[3, 4, 4, 7, 8, 10], x= 8

Output: 8 8

Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.
```
```
Input : nums = [2, 4, 6, 8, 10, 12, 14], x= 1
Output:
[-1, 2]
```

Constraints:

- 1 <= nums.length <= 10^5 
- 0 < nums[i], x < 10^5 
- nums is sorted in ascending order.

```cpp
class Solution {
public:
    // Returns floor and ceil of x from a sorted array
    vector<int> getFloorAndCeil(vector<int> nums, int x) {

        // Size of the array
        int n = nums.size();

        // If x is smaller than the first element
        if (x < nums[0]) {
            return {-1, nums[0]};
        }
        // If x is greater than the last element
        else if (x > nums[n - 1]) {
            return {nums[n - 1], -1};
        }

        // Binary search range
        int low = 0, high = n - 1;

        // Binary search loop
        while (low <= high) {
            // Middle index
            int mid = (low + high) / 2;

            // Move left if mid element > x
            if (nums[mid] > x) {
                high = mid - 1;
            }
            // Move right if mid element < x
            else if (nums[mid] < x) {
                low = mid + 1;
            }
            // If element equals x
            else {
                return {nums[mid], nums[mid]};
            }
        }

        // Floor = largest element < x → nums[high]
        // Ceil = smallest element > x → nums[low]
        vector<int> ans(2, 0);
        ans[0] = nums[high];
        ans[1] = nums[low];

        return ans;
    }
};
```
<p><strong>Time Complexity:</strong> O(logN), where N is the size of the given array. We are using the Binary Search algorithm, which divides the search space in half each time, resulting in a logarithmic time complexity.</p>
<p><strong>Space Complexity:</strong> O(1), as we are not using any extra space to solve this problem.</p>


### First and last occurrence

<p>Given an array of integers nums sorted in non-decreasing order, find the <strong>starting</strong> and <strong>ending</strong> position of a given target value. If the target is not found in the array, return [-1, -1].</p>

Examples:
```
Input: nums = [5, 7, 7, 8, 8, 10], target = 8

Output: [3, 4]

Explanation:The target is 8, and it appears in the array at indices 3 and 4, so the output is [3,4]
```
```
Input: nums = [5, 7, 7, 8, 8, 10], target = 6

Output: [-1, -1]

Expalantion: The target is 6, which is not present in the array. Therefore, the output is [-1, -1].
```
```
Input: nums = [5, 7, 7, 8, 8, 10], target = 5
Output:
[0, 0]
```

Constraints:

- 0 <= nums.length <= 10^5
- -10^9 <= nums[i] <= 10^9
- nums is a non-decreasing array.
- -10^9 <= target <= 10^9

Solution:

```cpp
class Solution
{
private:
    // Function to find the first occurrence of the target
    int firstOccurrence(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;
        int first = -1;

        // Applying Binary Search Algorithm
        while(low <= high) {
            int mid = low + (high - low) / 2; 

            /*  If the target element is found, we 
                update the first variable to mid and
                eliminate the right half to look for 
                more smaller index where target is present */
            if(nums[mid] == target) {
                first = mid;
                high = mid - 1;  
            } 

            /*  If middle element is smaller,
                we eliminate the left half  */
            else if(nums[mid] < target) {
                low = mid + 1;  
            } 
            
            /*  If middle element is greater,
                we eliminate the right half  */
            else {
                high = mid - 1;  
            }
        }
        return first;
    }

    // Function to find the last occurrence of the target
    int lastOccurrence(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;
        int last = -1;

        // Applying Binary Search Algorithm
        while(low <= high) {
            int mid = low + (high - low) / 2; 

            /*  If the target element is found, we 
                update the last variable to mid and
                eliminate the left half to look for 
                more greater index where target is present */
            if(nums[mid] == target) {
                last = mid;
                low = mid + 1;
            } 
            
            /*  If middle element is smaller,
                we eliminate the left half  */
            else if(nums[mid] < target) {
                low = mid + 1;  
            } 
            
            /*  If middle element is greater,
                we eliminate the right half  */
            else {
                high = mid - 1; 
            }
        }
        return last;
    }

public:
    // Function to find the first and last occurrences of the target
    vector<int> searchRange(vector<int> &nums, int target) {

        // Function call to find the first occurence of target
        int first = firstOccurrence(nums, target); 
        
        // If the target is not present in the array
        if(first == -1) return {-1, -1};  

        // Function call to find the last occurence of target
        int last = lastOccurrence(nums, target);  

        return {first, last};  
    }
};
```

<p><strong>Time Complexity:</strong> O(log N), where N is the size of the given array. Both the <code>firstOccurrence</code> and <code>lastOccurrence</code> functions perform a binary search, which operates in logarithmic time. Thus, the overall time complexity is O(log N).</p>
<p><strong>Space Complexity:</strong> O(1), as we are using a constant amount of extra space regardless of the input size. The space used by the variables <code>low</code>, <code>high</code>, <code>mid</code>, <code>first</code>, and <code>last</code> does not depend on the size of the input array.</p>

