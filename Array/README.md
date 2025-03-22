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

## [Pascal's Triangle I](https://leetcode.com/problems/pascals-triangle/)
**Problem Statement**: You are given an array of integers, your task is to move all the zeros in the array to the end of the array and move non-negative integers to the front by maintaining their order.

Given two integers r and c, return the value at the rth row and cth column in a Pascal's Triangle.


In Pascal's triangle:

- The first row has one element with a value of 1.
- Each row has one more element in it than its previous row.
- The value of each element is equal to the sum of the elements directly above it when arranged in a triangle format.

Examples:
```
Input: r = 4, c = 2

Output: 3

Explanation: The Pascal's Triangle is as follows:

1
1 1
1 2 1
1 3 3 1

....

Thus, value at row 4 and column 2 = 3
```
```
Input: r = 5, c = 3

Output: 6

Explanation: The Pascal's Triangle is as follows:

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1

....

Thus, value at row 5 and column 3 = 6
```
```
Input: r = 6, c = 2
Output:
5
```

Constraints:

- 1 <= r, c <= 30
- c <= r
- All values will fit inside a 32-bit integer.


Solution 1:
```cpp
class Solution {
public:
    int pascalTriangleI(int r, int c) {
        // function to print the element in rth row and cth column
        return nCr(r-1, c-1);
        // note: for zero indexed problem, use nCr(r, c);
    }
private:
    int nCr(int n, int r) {
        // choose the smaller value for lesser interactions
        r = min(r, n-r);

        // base case
        if(r==1) return n;

        int res = 1;

        // calculate nCr using iterative method avoiding overflow
        for(int i=0; i<r; i++) {
            res = res * (n-i);
            res = res / (i+1);
        }

        // return the result
        return res;
    }
};
```

## [Pascal's Triangle II](https://leetcode.com/problems/pascals-triangle-ii/description/)
**Problem Statement**: Given an integer r, return all the values in the rth row in Pascal's Triangle in correct order.


In Pascal's triangle:

- The first row has one element with a value of 1.
- Each row has one more element in it than its previous row.
- The value of each element is equal to the sum of the elements directly above it when arranged in a triangle format.

Examples:
```
Input: r = 4

Output: [1, 3, 3, 1]

Explanation: The Pascal's Triangle is as follows:

1
1 1
1 2 1
1 3 3 1

....

Thus the 4th row is [1, 3, 3, 1]
```
```
Input: r = 5

Output: [1, 4, 6, 4, 1]

Explanation: The Pascal's Triangle is as follows:

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1

....

Thus the 5th row is [1, 4, 6, 4, 1]
```
```
Input: r = 6
Output:
[1, 5, 10, 10, 5, 1]
```

Constraints:

- 1 <= r <= 30
- All values will fit inside a 32-bit integer.


Solution:
```cpp
class Solution {
public:
    vector<int> pascalTriangleII(int r) {
        vector<int> ans(r); // to store the answer
        // set the first element of the row as 1
        ans[0] = 1;

        // compute each element in the rth row
        for(int i=1; i<r; i++) {
            ans[i] = (ans[i-1] * (r-i))/i;
        }

        return ans; // return the result
    }
};
```

## Pascal's Triangle III
**Problem Statement**: Given an integer n, return the first n rows of Pascal's triangle.


In Pascal's triangle:

- The first row has one element with a value of 1.
- Each row has one more element in it than its previous row.
- The value of each element is equal to the sum of the elements directly above it when arranged in a triangle format.

Examples:
```
Input: n = 4

Output: [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1]]

Explanation: The Pascal's Triangle is as follows:

1
1 1
1 2 1
1 3 3 1

1st Row has its value set to 1.

All other cells take their value as the sum of the values directly above them
```
```
Input: n = 5

Output: [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]

Explanation: The Pascal's Triangle is as follows:

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1

1st Row has its value set to 1.

All other cells take their value as the sum of the values directly above them
```
```
Input: n = 3
Output:
[[1], [1, 1], [1, 2, 1]]
```
Constraints:

- 1 <= n <= 30
- All values will fit inside a 32-bit integer.


Solution 1:
```cpp
class Solution {
   public:
    vector<vector<int>> pascalTriangleIII(int numRows) {
        vector<vector<int>> ans{{1}};  // to store the result
        // to store the previous row for current row's elements
        vector<int> prevRow;

        // iterate through the number of rows
        for (int row = 1; row <= numRows - 1; row++) {
            ans.push_back(calculate_row_elements(prevRow, row));
            prevRow =
                ans[row];  // set prevRow as current for futher calculations
        }
        prevRow.clear();
        return ans;
    }

   private:
    vector<int> calculate_row_elements(vector<int>& prevRow, int row) {
        // store 1 at the first position by default in the current row
        vector<int> curRow(1, 1);
        // Calculate element values based on the previous row
        for (int col = 1; col <= row - 1; col++) {
            // Calculate element value based on Pascal's triangle formula
            curRow.push_back(prevRow[col - 1] + prevRow[col]);
        }
        // last element will be one in every row
        curRow.push_back(1);
        // return the current row
        return curRow;
    }
};
```
Solution 2:
```cpp
class Solution {
private:
    /* Function to generate a single
    row of Pascal's Triangle*/
    vector<int> generateRow(int row) {
        
        long long ans = 1;
        vector<int> ansRow;
        /// Inserting the 1st element
        ansRow.push_back(1); 

        // Calculate the rest of the elements
        for (int col = 1; col < row; col++) {
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

public:
    /* Function to generate Pascal's
    Triangle up to n rows*/
    vector<vector<int>> pascalTriangle(int n) {
        vector<vector<int>> pascalTriangle;

        // Store the entire Pascal's Triangle
        for (int row = 1; row <= n; row++) {
            pascalTriangle.push_back(generateRow(row));
        }
        
        //return the pascalTriangle
        return pascalTriangle;
    }
};
```

## Rotate matrix by 90 degrees
**Problem Statement**: Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise.

The rotation must be done in place, meaning the input 2D matrix must be modified directly.
Examples:
```
Input: matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output: matrix = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]
```
```
Input: matrix = [[0, 1, 1, 2], [2, 0, 3, 1], [4, 5, 0, 5], [5, 6, 7, 0]]
Output: matrix = [[5, 4, 2, 0], [6, 5, 0, 1], [7, 0, 3, 1], [0, 5, 1, 2]]
```

Constraints:

- n == matrix.length.
- n == matrix[i].length.
- 1 <= n <= 100.
- -104 <= matrix[i][j] <= 104

Solution:
```cpp
class Solution {
public:
    void rotateMatrix(vector<vector<int>>& matrix) {
        int n = matrix[0].size(); // length of one row

        // transpose the matrix
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // reverse every row of the matrix
        for(int i=0; i<n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```
