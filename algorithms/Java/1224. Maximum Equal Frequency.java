// Source : https://leetcode.cn/problems/maximum-equal-frequency/
// Author : Hang Zhang
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

class Solution {
    public int maxEqualFreq(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<>(), hash = new HashMap<>();
        int res = 0, len = 0;
        for (int x: nums) {
            Integer c = cnt.get(x);
            if (c != null) {
                hash.put(c, hash.get(c) - 1);
                if (hash.get(c) == 0) hash.remove(c);
            }

            cnt.put(x, cnt.getOrDefault(x, 0) + 1);
            hash.put(cnt.get(x), hash.getOrDefault(cnt.get(x), 0) + 1);
            len ++ ;

            if (hash.size() == 1) {
                for (Map.Entry<Integer, Integer> entry: hash.entrySet()) {
                    if (entry.getKey() == 1 || entry.getValue() == 1)  res = len;
                }
            } else if (hash.size() == 2) {
                int[][] tmp = new int[2][2];
                int k = 0;
                for (Map.Entry<Integer, Integer> entry: hash.entrySet()) {
                    tmp[k][0] = entry.getKey();
                    tmp[k][1] = entry.getValue();
                    k ++ ;
                }
                if (tmp[0][0] > tmp[1][0]) {
                    int t = tmp[0][0];
                    tmp[0][0] = tmp[1][0];
                    tmp[1][0] = t;
                    t = tmp[0][1];
                    tmp[0][1] = tmp[1][1];
                    tmp[1][1] = t;
                }
                if (tmp[0][0] == 1 && tmp[0][1] == 1) res = len;
                if (tmp[1][0] == tmp[0][0] + 1 && tmp[1][1] == 1) res = len;
            }
        }
        return res;
    }
}
