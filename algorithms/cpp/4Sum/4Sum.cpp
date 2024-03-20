// Source : https://leetcode.com/problems/4sum/
// Author : Garfield Zhang
// Date   : 2024-03-20

/****************************************************************************************
 *
 * Given an array nums of n integers, return an array of all the unique quadruplets 
 * [nums[a], nums[b], nums[c], nums[d]] such that:
 *
 * 0 <= a, b, c, d < n
 * a, b, c, and d are distinct.
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 *
 * You may return the answer in any order.
 *
 ****************************************************************************************/

class Solution {
public:
    typedef long long LL;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++ ) {
            if (i && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size(); j ++ ) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                for (int k = j + 1, l = nums.size() - 1; k < l; k ++ ) {
                    if (k > j + 1 && nums[k] == nums[k - 1]) continue;
                    while (l - 1 > k && (LL)nums[i] + nums[j] + nums[k] + nums[l - 1] >= target) l -- ;
                    if ((LL)nums[i] + nums[j] + nums[k] + nums[l] == (LL)target) {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
		            }
                }
            }
        }
        return res;
    }
};
