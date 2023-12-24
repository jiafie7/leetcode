// Source : https://leetcode.cn/problems/check-if-n-and-its-double-exist/
// Author : Garfield Zhang
// Date   : 2022-08-31

/*************************************************************************************************************************
 *
 * Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).
 *
 * More formally check if there exists two indices i and j such that :
 *   i != j
 *   0 <= i, j < arr.length
 *   arr[i] == 2 * arr[j]
 *
 * Example 1:
 * Input: arr = [10,2,5,3]
 * Output: true
 * Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.
 *
 * Example 2:
 * Input: arr = [3,1,7,11]
 * Output: false
 * Explanation: In this case does not exist N and M, such that N = 2 * M.
 *
 ************************************************************************************************************************/
  
  class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        hash = set()
        for x in arr:
            if x * 2 in hash or x % 2 == 0 and x / 2 in hash:
                return True
            hash.add(x)
        return False
  
