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

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> cnt, hash;

        int res = 0, len = 0;
        for (int x: nums) {
            if (cnt.count(x)) {
                hash[cnt[x]] -- ;
                if (!hash[cnt[x]]) hash.erase(cnt[x]);
            }
            cnt[x] ++ ;
            hash[cnt[x]] ++ ;

            len ++ ;
            if (hash.size() == 1) {
                for (auto& [k, v]: hash) {
                    if (k == 1 || v == 1) res = len;
                }
            }
            if (hash.size() == 2) {
                vector<vector<int>> tmp;
                for (auto& [k, v]: hash) {
                    tmp.push_back({k, v});
                }
                if (tmp[0][0] > tmp[1][0]) swap(tmp[0], tmp[1]);
                if (tmp[0][0] == 1 && tmp[0][1] == 1) res = len;
                else if (tmp[0][0] + 1 == tmp[1][0] && tmp[1][1] == 1) res = len;
            }
        }
        return res;
    }
};

