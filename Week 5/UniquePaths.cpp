// UNIQUE PATHS

/*  PROBLEM:
    A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

    The robot can only move either down or right at any point in time. The robot is trying to reach the 
    bottom-right corner of the grid (marked 'Finish' in the diagram below).

    How many possible unique paths are there?
*/

/*  EXAMPLES:

    Input: m = 3, n = 2
    Output: 3
    Explanation:
    From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
    1. Right -> Right -> Down
    2. Right -> Down -> Right
    3. Down -> Right -> Right

    Input: m = 7, n = 3
    Output: 28
*/

/*  APPROACH: Bottom-Up Dynamic Programming - O(m*n)
    1. Create a two-dimensional vector to store the number of paths from each cell.
    2. Initialize the number of paths from a cell in the first row or first column as 1.
    3. Recursively count the number of paths to traverse the remaining cells as the sum of the paths generated by:
        a. Moving to the right cell
        b. Moving to the bottom cell
    4. Return the value in the last cell as the number of unique paths from the starting point to the ending point.
*/

// SOLUTION:
#include <bits/stdc++.h>

using namespace std;
 
class Solution {
public:
    int uniquePaths(int m, int n) {
        // Create a two-dimensional array to store the result of the sub-problems
        int count[m][n];
        // Paths to reach any cell from a cell in the first column is 1
        for(int i = 0; i < m; i++) {
            count[i][0] = 1;
        }
        // Paths to reach any cell from a cell in the first row is 1
        for(int j = 0; j < n; j++) {
            count[0][j] = 1;
        }
        // Recursively count the paths to traverse to other cells in a bottom-up manner
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                count[i][j] = count[i-1][j] + count[i][j-1];
            }
        }
        // Return the value in the last cell
        return count[m-1][n-1];
    }
};