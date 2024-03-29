// Source : https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
// Author : Garfield Zhang
// Date   : 2024-03-29

/****************************************************************************************
 *
 * Given two strings needle and haystack, return the index of the first occurrence of 
 * needle in haystack, or -1 if needle is not part of haystack.
 *
 ****************************************************************************************/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int n = haystack.size(), m = needle.size();
        haystack = ' ' + haystack, needle = ' ' + needle;
        vector<int> next(m + 1);
        for (int i = 2, j = 0; i <= m; i ++ ) {
            while (j && needle[i] != needle[j + 1]) j = next[j];
            if (needle[i] == needle[j + 1]) j ++ ;
            next[i] = j;
        }
        
        for (int i = 1, j = 0; i <= n; i ++ ) {
            while (j && haystack[i] != needle[j + 1]) j = next[j];
            if (haystack[i] == needle[j + 1]) j ++ ;
            if (j == m) return i - m;
        }

        return -1;
    }
};
