// Source : https://leetcode.cn/problems/maximum-equal-frequency/
// Author : Garfield Zhang
// Date   : 2022-08-19

/****************************************************************************************************************************
 *
 * Given an array nums of positive integers, return the longest possible length of an array prefix of nums, 
 * such that it is possible to remove exactly one element from this prefix so that every number 
 * that has appeared in it will have the same number of occurrences.
 *
 * If after removing one element there are no remaining elements, it's still considered that 
 * every appeared number has the same number of ocurrences (0).
 *
 * Example 1:
 * Input: nums = [2,2,1,1,5,3,3,5]
 * Output: 7
 * Explanation: For the subarray [2,2,1,1,5,3,3] of length 7, if we remove nums[4] = 5, we will get [2,2,1,1,3,3], so that each number will appear exactly twice.
 *
 * Example 2:
 * Input: nums = [1,1,1,2,2,2,3,3,3,4,4,4,5]
 * Output: 13
 *
 *****************************************************************************************************************************/
  
  class Solution:
    def maxEqualFreq(self, nums: List[int]) -> int:
        cnt, hash = {}, {}
        res, length = 0, 0
        for x in nums:
            if x in cnt:
                hash[cnt[x]] -= 1
                if (hash[cnt[x]] == 0):
                    del hash[cnt[x]]
            cnt[x] = cnt.get(x, 0) + 1
            hash[cnt[x]] = hash.get(cnt[x], 0) + 1
            length += 1

            if len(hash) == 1:
                items = list(hash.items())
                if items[0][0] == 1 or items[0][1] == 1:
                    res = length
            elif len(hash) == 2:
                items = list(hash.items())
                if items[0][0] > items[1][0]:
                    items[0], items[1] = items[1], items[0]
                if items[0][0] == 1 and items[0][1] == 1:
                    res = length
                if items[1][0] == items[0][0] + 1 and items[1][1] == 1:
                    res = length
        return res
  
