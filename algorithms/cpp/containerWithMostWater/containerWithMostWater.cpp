// Source : https://leetcode.com/problems/container-with-most-water/description/
// Author : Garfield Zhang
// Date   : 2024-03-12

/****************************************************************************************
 * 
 * You are given an integer array height of length n. There are n vertical lines 
 * drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
 *
 * Find two lines that together with the x-axis form a container, such that the 
 * container contains the most water.
 *
 * Return the maximum amount of water a container can store. 
 *
 * Notice that you may not slant the container.
 *
 ****************************************************************************************/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for (int i = 0, j = height.size() - 1; i < j; ) {
            res = max(res, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j]) i ++ ;
            else j -- ;
        }
        return res;
    }
};