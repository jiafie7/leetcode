// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author : Garfield Zhang
// Date   : 2024-03-27

/****************************************************************************************
 *
 * Given an integer array nums sorted in non-decreasing order, remove the duplicates
 * in-place such that each unique element appears only once. The relative order 
 * of the elements should be kept the same. Then return the number of unique elements in nums.
 *
 * Consider the number of unique elements of nums to be k, to get accepted, you
 * need to do the following things:
 *
 * Change the array nums such that the first k elements of nums contain the unique 
 * elements in the order they were present in nums initially. The remaining elements 
 * of nums are not important as well as the size of nums.
 *
 * Return k.
 *
 ****************************************************************************************/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i ++ )
            if (!i || nums[i] != nums[i - 1]) 
                nums[k ++ ] = nums[i];
        return k;
    }
};
