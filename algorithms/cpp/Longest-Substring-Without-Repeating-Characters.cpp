// Source : https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
// Author : Garfield Zhang 
// Date   : 2022-01-05

/*****************************************************************************************************************
 *
 * Given a string s, find the length of the longest substring without repeating characters.
 *
 * Example 1:
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 * Example 2:
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 ****************************************************************************************************************/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> heap;
        int res = 0;
        for (int i = 0, j = 0; i < s.size(); i ++ ) {
            heap[s[i]] ++ ;
            while (heap[s[i]] > 1) heap[s[j ++ ]] -- ;
            res = max(res, i - j + 1);
        } 
        return res;
    }
};

