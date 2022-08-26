// Source : https://leetcode.cn/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
// Author : Hang Zhang
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

class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int res = 0, sum = 0;
        for (int i = 0, j = 0; i < arr.length; i ++ ) {
            sum += arr[i];
            if (i - j >= k) sum -= arr[j ++ ];
            if (i - j + 1 == k && sum >= k * threshold) res ++ ;
        }
        return res;
    }
}
