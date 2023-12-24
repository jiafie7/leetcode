// Source : https://leetcode.cn/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
// Author : Garfield Zhang
// Date   : 2022-08-26

/************************************************************************************************************************
 *
 * Given an array of integers arr and two integers k and threshold,
 * return the number of sub-arrays of size k and average greater than or equal to threshold.
 *
 * Example 1:
 * Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
 * Output: 3
 * Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively.
 * All other sub-arrays of size 3 have averages less than 4 (the threshold).
 *
 ***********************************************************************************************************************/
 
 class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        res, sum, i, j = 0, 0, 0, 0
        while i < len(arr):
            sum += arr[i]
            if i - j >= k:
                sum -= arr[j]
                j += 1
            if i - j + 1 == k and sum >= k * threshold:
                res += 1
            i += 1
        return res
 
