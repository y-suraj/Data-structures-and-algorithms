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

**Solution:**

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


### Search in rotated sorted array-I

<p class="mt-6 w-full text-new_secondary text-[14px] dark:text-zinc-200"><p>Given an integer array nums, sorted in ascending order (with distinct values) and a target value k. The array is <strong>rotated</strong> at some pivot point that is unknown. Find the <strong>index</strong> at which k is present and if k is not present return -1.</p></p>

Examples:
```
Input : nums = [4, 5, 6, 7, 0, 1, 2], k = 0

Output: 4

Explanation: Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. Thus, we get output as 4, which is the index at which 0 is present in the array.
```
```
Input: nums = [4, 5, 6, 7, 0, 1, 2], k = 3

Output: -1

Explanation: Here, the target is 3. Since 3 is not present in the given rotated sorted array. Thus, we get the output as -1.
```
```
Input: nums = [4, 5, 6, 7, 0, 1, 2], k = 5
Output:
1
```

Constraints:

- 1 <= nums.length <= 10^4
- -10^4 <= nums[i] <= 10^4
- All values of nums are unique.
- nums is an ascending array that is possibly rotated.
- -10^4 <= k <= 10^4

**Solution:**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to search for the target element in a rotated sorted array
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1; 

        // Applying binary search algorithm 
        while (low <= high) {
            int mid = (low + high) / 2;

            // Check if mid points to the target
            if (nums[mid] == target) return mid;

            // Check if the left part is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target <= nums[mid]) {
                    // Target exists in the left sorted part
                    high = mid - 1;
                } else {
                    // Target does not exist in the left sorted part
                    low = mid + 1;
                }
            } else {
                // Check if the right part is sorted
                if (nums[mid] <= target && target <= nums[high]) {
                    // Target exists in the right sorted part
                    low = mid + 1;
                } else {
                    // Target does not exist in the right sorted part
                    high = mid - 1;
                }
            }
        }
        // If target is not found
        return -1; 
    }
};

int main() {
    vector<int> nums = {7, 8, 9, 1, 2, 3, 4, 5, 6}; 
    int target = 1; 

    // Create an instance of the Solution class
    Solution sol;

    // Function call to search for the target element
    int result = sol.search(nums, target);

    if (result == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << result << "\n";

    return 0;
}
```

**Complexity Analysis:**
<p><strong>Time Complexity:</strong> O(logN), as the search space is reduced logarithmically, where N is the size of the given array.</p>

<p><strong>Space Complexity:</strong> O(1), not using any extra data structure.</p>


### Search in rotated sorted array-II

<p>Given an integer array nums, sorted in ascending order (may contain duplicate values) and a target value <strong>k</strong>. Now the array is <strong>rotated</strong> at some pivot point unknown to you. Return True if k is present and otherwise, return False.</p>

Examples:
```
Input : nums = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3

Output: True

Explanation: The element 3 is present in the array. So, the answer is True.
```
```
Input : nums = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 10

Output: False

Explanation:The element 10 is not present in the array. So, the answer is False.
```
```
Input : nums = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 7
Output:
True
```

Constraints:

- 1 <= nums.length <= 10^4
- -10^4 <= nums[i] <= 10^4
- nums is guaranteed to be rotated at some pivot.
- -10^4 <= k <= 10^4

**Solution:**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*  Function to search for the target element 
        in a rotated sorted array with duplicates   */
    bool searchInARotatedSortedArrayII(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n - 1;
        
        // Applying binary search algorithm 
        while (low <= high) {
            int mid = (low + high) / 2;

            // Check if mid points to the target
            if (arr[mid] == target) return true;

            // Handle duplicates: if arr[low], arr[mid], and arr[high] are equal
            if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
                low = low + 1;
                high = high - 1;
                continue;
            }

            // Check if the left part is sorted
            if (arr[low] <= arr[mid]) {
                /*  Eliminate the right part if target
                    exists in the left sorted part */
                if (arr[low] <= target && target <= arr[mid]) {
                    high = mid - 1;
                } 
                // Otherwise eliminate the left part
                else {
                    low = mid + 1;
                }
            } else {
                /*  If the right part is sorted and
                    target exists in the right sorted
                    part, eliminate the left part   */
                if (arr[mid] <= target && target <= arr[high]) {
                    low = mid + 1;
                } 
                // Otherwise eliminate the right part
                else {
                    high = mid - 1;
                }
            }
        }
        // If target is not found
        return false;
    }
};

int main() {
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int target = 3; 

    // Create an instance of the Solution class
    Solution sol;

    // Function call to search for the target element
    bool result = sol.searchInARotatedSortedArrayII(arr, target);

    if (!result)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";

    return 0;
}
```

<strong>Complexity Analysis:&nbsp;</strong>
<p><strong>Time Complexity:</strong>O(logN) for the best and average cases.  As in the best and average scenarios, the binary search algorithm is primarily used and hence the time complexity is O(logN). <br>
However, in the worst-case scenario, it'll be O(N/2) where all array elements are the same but not the target (e.g., given array = {3, 3, 3, 3, 3, 3, 3}), we continue to reduce the search space by adjusting the low and high pointers until they intersect, which will end up taking O(N/2) time complexity.</p>
<p><strong>Space Complexity:</strong>O(1), as we are not using any extra space to solve this problem.</p>


### Find minimum in Rotated Sorted Array

<p>Given an integer array nums of size N, sorted in ascending order with distinct values, and then <strong>rotated</strong> an unknown number of times (between 1 and N), find the <strong>minimum</strong> element in the array.</p>

```
Examples:

Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]

Output: 0
```
```
Explanation: Here, the element 0 is the minimum element in the array.

Input : nums = [3, 4, 5, 1, 2]

Output: 1
```
```
Explanation:Here, the element 1 is the minimum element in the array.

Input : nums = [4, 5, 6, 7, -7, 1, 2, 3]
Output:
-7
```

Constraints:

- n == nums.length
- 1 <= n <= 10^4
- -10^4 <= nums[i] <= 10^4
- All the integers of nums are unique.
- nums is sorted and rotated between 1 and n times.

**Solution**

```cpp
class Solution {
   public:
    int findMin(vector<int> &arr) {
        int n = arr.size();

        int low = 0, high = n - 1, minimum = INT_MAX;

        while (low <= high) {
            int mid = (low + high) / 2;

            minimum = min(minimum, arr[mid]);

            // check if the left part is sorted
            if (arr[low] < arr[mid]) {
                if (arr[mid] > arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                if (arr[low] > arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return minimum;
    }
};
```

<strong>Complexity Analysis:&nbsp;</strong>

<strong>Time Complexity:</strong> O(log(N)), where N is size of the array. Because binary search is being used.

<strong>Space Complexity:</strong> O(1) As no additional space is used.


### Find out how many times the array is rotated

<p>Given an integer array nums of size n, sorted in ascending order with distinct values. The array has been <strong>right</strong> <strong>rotated</strong> an unknown number of times, between 0 and n-1 (including). Determine the <strong>number</strong> of rotations performed on the array.</p>

Examples:

```
Input : nums = [4, 5, 6, 7, 0, 1, 2, 3]

Output: 4

Explanation: The original array should be [0, 1, 2, 3, 4, 5, 6, 7]. So, we can notice that the array has been rotated 4 times.
```
```
Input: nums = [3, 4, 5, 1, 2]

Output: 3

Explanation: The original array should be [1, 2, 3, 4, 5]. So, we can notice that the array has been rotated 3 times.
```
```
Input: nums = [4, 5, 1, 2]
Output:
2
```

Constraints:

- n == nums.length
- 1 <= n <= 10^4
- -10^4 <= nums[i] <= 10^4
- All the integers of nums are unique.

**Solution**

```cpp
class Solution {
   public:
    int findKRotation(vector<int> &nums) {
        int n = nums.size();

        int low = 0, high = n - 1, index = -1, temp = INT_MAX;

        while (low <= high) {
            int mid = (low + high) / 2;

            // if current mid value is lesser than previous mid
            if (nums[mid] < temp) {
                temp = nums[mid];
                index = mid;
            }
            // check if left half is sorted
            if (nums[low] < nums[mid]) {
                if (nums[mid] > nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                if (nums[low] > nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return index;
    }
};
```

<strong>Complexity Analysis:&nbsp;</strong>

<strong>Time Complexity:</strong> O(N), where N is size of the array. As the array is being traversed only once using a single loop.

<strong>Space Complexity:</strong> As no additional space is used, so the Space Complexity is O(1).

### Single element in sorted array

<p>Given an array nums sorted in non-decreasing order. Every number in the array except one appears twice. Find the <strong>single</strong> number in the array.</p>

Examples:
```
Input :nums = [1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6]

Output:4

Explanation: Only the number 4 appears once in the array.
```
```
Input : nums = [1, 1, 3, 5, 5]

Output:3

Explanation: Only the number 3 appears once in the array.
```
```
Input :nums = [1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7]
Output:
7
```

Constraints:

- n == nums.length
- 1 <= n <= 10^4
- -10^4 <= nums[i] <= 10^4

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to find the single non 
    duplicate element in a sorted array*/
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(); // Size of the array.

        // Edge cases:
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = (low + high) / 2;

            // If nums[mid] is the single element:
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            }

            // We are in the left part:
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1])
                || (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                // Eliminate the left half:
                low = mid + 1;
            }
            // We are in the right part:
            else {
                // Eliminate the right half:
                high = mid - 1;
            }
        }

        // Dummy return statement:
        return -1;
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4};
    
    // Create an object of the Solution class.
    Solution sol;
    
    int ans = sol.singleNonDuplicate(nums);
    
    // Print the result.
    cout << "The single element is: " << ans << "\n";
    
    return 0;
}
```

<strong>Complexity Analysis:&nbsp;</strong>

<strong>Time Complexity:</strong> O(logN), N is size of the given array. We are basically using the Binary Search algorithm.

<strong>Space Complexity:</strong> As no additional space is used, so the Space Complexity is O(1)


## On answers

### Find square root of a number
Given a positive integer n. Find and return its square root. If n is not a perfect square, then return the floor value of sqrt(n).

Examples:
```
Input: n = 36

Output: 6

Explanation: 6 is the square root of 36.
```
```
Input: n = 28

Output: 5

Explanation: The square root of 28 is approximately 5.292. So, the floor value will be 5.
```
```
Input: n=50
Output:
7
```

Constraints:

- 0 <= n <= 2^31 - 1

Solution:

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to compute the floor of
       square root of a given integer */
    long long floorSqrt(long long n) {
        long long low = 1, high = n;
        
        // Binary search on the answer space
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long val = mid * mid;
            
            // Check if val is less than or equal to n
            if (val <= (long long)(n)) {
                // Move to the right part
                low = mid + 1;
            } else {
                // Move to the left part
                high = mid - 1;
            }
        }
        
        // Return the floor of square root
        return high;
    }
};

int main() {
    int n = 28;
    
    // Create an object of the Solution class
    Solution sol;
    
    int ans = sol.floorSqrt(n);
    
    // Print the result
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    
    return 0;
}
```

### Find Nth root of a number
<p>Given two numbers N and M, find the <strong>Nth</strong> root of M. The Nth root of a number M is defined as a number X such that when X is raised to the power of N, it equals M. If the Nth root is not an integer, return -1.</p>

Examples:

```
Input: N = 3, M = 27

Output: 3

Explanation: The cube root of 27 is equal to 3.
```
```
Input: N = 4, M = 69

Output:-1

Explanation: The 4th root of 69 does not exist. So, the answer is -1.
```
```
Input: N = 4, M = 81
Output:
3
```

Constraints:

- 1 <= N <= 30
- 1 <= M <= 10^9

**Solution:**

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    /* Function to calculate power using
    exponentiation by squaring method*/
    int helperFunc(int mid, int n, int m) {
        long long ans = 1, base = mid;
        
        while (n > 0) {
            if (n % 2) {
                ans = ans * base;
                if (ans > m) return 2;  // Early exit
                n--;
            } 
            else {
                n /= 2;
                base = base * base;
                if(base > m) return 2;
            }
        }
        if (ans == m) return 1;
        return 0;
    }

    
public:
    // Function to find the Nth root of M
    int NthRoot(int N, int M) {
        // Binary search on the answer space
        int low = 1, high = M;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            int midN = helperFunc(mid, N, M);
            
            if (midN == 1) {
                
                // Return mid if mid^N== M
                return mid;
            } 
            else if (midN == 0) {
                // Move to the right half if mid^N < M
                low = mid + 1;
            } 
            else {
                // Move to the left half if mid^N > M
                high = mid - 1;
            }
        }
        // Return -1 if no nth root found
        return -1;
    }
};

int main() {
    int n = 3, m = 27;
    
    // Create an object of the Solution class
    Solution sol;
    
    // Function call to find the Nth root of M
    int ans = sol.NthRoot(n, m);
    
    // Print the result
    cout << "The answer is: " << ans << "\n";
    
    return 0;
}
```


