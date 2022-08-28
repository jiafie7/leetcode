// Source : https://leetcode.cn/problems/sort-the-matrix-diagonally/
// Author : Hang Zhang
// Date   : 2022-08-28

/**************************************************************************************************************
 *
 * A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column 
 * and going in the bottom-right direction until reaching the matrix's end. 
 * For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].
 *
 * Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.
 *
 * Example 1:
 * Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
 * Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
 *
 *************************************************************************************************************/

class Solution {
    public int[][] diagonalSort(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        for (int b = -(n - 1); b <= m - 1; b ++ ) {
            ArrayList<Integer> q = new ArrayList<>();
            for (int x = 0, y = b; x < n && y < m; x ++ , y ++ ) 
                if (y >= 0)
                    q.add(mat[x][y]);
            q.sort(Comparator.naturalOrder());
            for (int x = 0, y = b, k = 0; x < n && y < m; x ++ , y ++ )
                if (y >= 0)
                    mat[x][y] = q.get(k ++ );
        }
        return mat;
    }
}
