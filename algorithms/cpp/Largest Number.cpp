//Source : https://leetcode-cn.com/problems/largest-number/
//Author : Hang Zhang
//Date   : 2021-04-16

/*******************************************************************************************************
 * Given a list of non-negative integers nums, arrange them such that they form the largest number.
 * Note: The result may be very large, so you need to return a string instead of an integer. 
 
 * Example 1:
 * Input: nums = [10,2]
 * Output: "210"
 
 * Example 2:
 * Input: nums = [3,30,34,5,9]
 * Output: "9534330"
 
 * Example 3:
 * Input: nums = [1]
 * Output: "1"
 
 * Example 4:
 * Input: nums = [10]
 * Output: "10"

 * Constraints:
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 10^9
 ******************************************************************************************************/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort (nums.begin(), nums.end(), [](int x, int y) {
            string a = to_string(x), b = to_string(y);
            return a + b > b + a; //Two strings are combined and then sorted in descending order
        });
        string res;
        for (auto x: nums) res += to_string(x);
        int k = 0;
        while (k + 1 < res.size() && res[k] == '0') k ++ ;
        return res.substr(k);
    }
};
