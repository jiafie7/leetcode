// Source : https://leetcode.cn/problems/sort-the-matrix-diagonally/
// Author : Garfield Zhang
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
  
  class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        n, m = len(mat), len(mat[0])
        for b in range(-( n - 1), m):
            q = []
            x, y = 0, b
            while x < n and y < m:
                if y >= 0:
                    q.append(mat[x][y])
                x, y = x + 1, y + 1
            q.sort()
            x, y, k = 0, b, 0
            while x < n and y < m:
                ifa y >= 0:
                    mat[x][y] = q[k]
                    k += 1
                x, y = x + 1, y + 1
        return mat
  
