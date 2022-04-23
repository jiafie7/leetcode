// Source : https://leetcode-cn.com/problems/longest-palindromic-substring/
// Author : Hang Zhang
// Date   : 2022-04-23

/****************************************************************************************************************
*
* Given a string s, return the longest palindromic substring in s.
*
* Example 1:
* Input: s = "babad"
* Output: "bab"
* Explanation: "aba" is also a valid answer.
*
* Example 2:
* Input: s = "cbbd"
* Output: "bb"
*
*****************************************************************************************************************/

class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for (int i = 0; i < s.size(); i ++ ) {
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) l -- , r ++ ;
            if (res.size() < r - l - 1) res = s.substr(l + 1, r - l - 1);

            l = i, r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) l -- , r ++ ;
            if (res.size() < r - l - 1) res = s.substr(l + 1, r - l - 1);
        }
        return res;
    }
};

