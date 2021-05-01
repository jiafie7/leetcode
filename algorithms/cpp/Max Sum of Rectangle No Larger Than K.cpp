// Source : https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/
// Author : Hang Zhang
// Date   : 2021-05-01

/***************************************************************************************************************
 *
 * Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix 
 * such that its sum is no larger than k.
 *
 * It is guaranteed that there will be a rectangle with a sum no larger than k.
 *
 * Example 1:
 * Input: matrix = [[1,0,1],[0,-2,3]], k = 2
 * Output: 2
 * Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, 
 * and 2 is the max number no larger than k (k = 2).
 *
 * Example 2:
 * Input: matrix = [[2,2,-1]], k = 3
 * Output: 3
 *
 * Constraints:
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 100
 * -100 <= matrix[i][j] <= 100
 * -105 <= k <= 105
 *
 ****************************************************************************************************************/

class Solution {
public:
    vector<vector<int>> sums;

    int get(int x1, int y1, int x2, int y2) {
        return sums[x2][y2] - sums[x1 - 1][y2] - sums[x2][y1 - 1] + sums[x1 - 1][y1 - 1];
    }

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        sums = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i ++ )
            for (int j = 1; j <= n; j ++ )
                sums[i][j] = sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1] + matrix[i - 1][j - 1];

        int res = INT_MIN;
        for (int x1 = 1; x1 <= m; x1 ++ )
            for (int x2 = x1; x2 <= m; x2 ++ ) {
                set<int> S;
                S.insert(0);
                for (int y2 = 1; y2 <= n; y2 ++ ) {
                    int si = get(x1, 1, x2, y2);
                    auto it = S.lower_bound(si - k);
                    if (it != S.end()) res = max(res, si - *it);
                    S.insert(si);
                }
            }
        return res;
    }
};

