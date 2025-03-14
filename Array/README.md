# Array

## [Print second largest element - tuf](/Array/tuf/Print%20second%20largest%20element.cpp)
```cpp
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    int largest = -1;
	    int secLargest = -1;
	    for(int i=0; i<n; i++) {
	        if(arr[i] > largest) {
	            secLargest = largest;
	            largest = arr[i];
	        }
	        else if(arr[i] > secLargest && arr[i] != largest) {
	            secLargest = arr[i];
	        }
	    }
	    return secLargest;
	}
};
```
<br>Better:
```cpp
class Solution {
   public:
    int secondLargestElement(vector<int>& nums) {
        // calculate the size of vector
        int n = nums.size();

        /*Initialize variables to store the
        largest and second largest elements*/
        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        /* Single traversal to find the
        largest and second largest elements*/
        for (int i = 0; i < n; i++) {
            int current = nums[i];

            // if current element is found the largest
            if (current > largest) {
                // assign the previous largest element as the second largest
                // element
                secondLargest = largest;
                // assign the current element as the largest element
                largest = current;
            }
            // if any element found greater that second largest, but
            // less than or equals to the largest element
            else if (current > secondLargest && current < largest) {
                // assign current to the secondLargest
                secondLargest = current;
            }
        }
        return secondLargest == INT_MIN ? -1 : secondLargest;
    }
};
```

## [Find the Union](https://www.codingninjas.com/studio/problems/sorted-array_6613259)
Solution 1:
```cpp
#include <set>
vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Set to store the unique elements
    set<int> s;
    vector<int> res;

    int n = a.size(), m = b.size();

    for(int i = 0; i < n; i++) {
        s.insert(a[i]);
    }
    for(int i = 0; i < m; i++) {
        s.insert(b[i]);
    }

    for(auto x : s) {
        res.push_back(x);
    }

    return res;
}
// TC: O(n + m), where n and m are the number of integers in arrays a and b.
// SC: O(n + m)
```
Reference: [Union of Two Sorted Arrays](https://takeuforward.org/data-structure/union-of-two-sorted-arrays/)

## [Longest Subarray with given Sum K(Positives) - tuf](https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399)
**Problem Statement**: Given an array and a sum k, we need to print the length of the longest subarray that sums to k.
```cpp
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int left = 0, right = 0, n = a.size();
    long long sum = a[0];
    int maxLen = 0;
    
    while(right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward the right pointer:
        right++;
        if (right < n) sum += a[right];
    }
    return maxLen;
}
// TC: O(2*N), where N is the size of the array.
```
Reference: [Longest Subarray with given Sum K(Positives)](https://takeuforward.org/data-structure/longest-subarray-with-given-sum-k/)

## [Move Zero's to End](https://www.naukri.com/code360/problems/ninja-and-the-zero-s_6581958)
**Problem Statement**: You are given an array of integers, your task is to move all the zeros in the array to the end of the array and move non-negative integers to the front by maintaining their order.
```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int zeroNum = 0;

        for(int i=0; i<n; i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[zeroNum]);
                zeroNum++;
            }

        }
    }
};
```
Reference: [Move all Zeros to the end of the array](https://takeuforward.org/data-structure/move-all-zeros-to-the-end-of-the-array/)
