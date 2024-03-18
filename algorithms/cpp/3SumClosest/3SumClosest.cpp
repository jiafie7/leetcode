// Source : https://leetcode.com/problems/3sum-closest/
// Author : Garfield Zhang
// Date   : 2024-03-18

/****************************************************************************************
 *
 * Given an integer array nums of length n and an integer target, find three integers 
 * in nums such that the sum is closest to target.
 *
 * Return the sum of the three integers.
 *
 * You may assume that each input would have exactly one solution.
 *
 ****************************************************************************************/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        pair<int, int> res(INT_MAX, INT_MAX);
        for (int i = 0; i < nums.size(); i ++ )
            for (int j = i + 1, k = nums.size() - 1; j < k; j ++ ) {
                while (k - 1 > j && nums[i] + nums[j] + nums[k - 1] >= target) k -- ;
                int s = nums[i] + nums[j] + nums[k];
                res = min(res, make_pair(abs(s - target), s));
                if (k - 1 > j) {
                    s = nums[i] + nums[j] + nums[k - 1];
                    res = min(res, make_pair(target - s, s));
                }
            }
        return res.second;
    }
};