// Source : https://leetcode-cn.com/problems/implement-strstr/
// Author : Hang Zhang
// Date   : 2021-04-24

/**********************************************************************************************************
 *
 * Implement strStr().
 *
 * Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 *
 * Clarification:
 *
 * What should we return when needle is an empty string? This is a great question to ask during an interview.
 *
 * For the purpose of this problem, we will return 0 when needle is an empty string. 
 * This is consistent to C's strstr() and Java's indexOf().
 *
 * Example 1:
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 *
 * Example 2:
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * Example 3:
 * Input: haystack = "", needle = ""
 * Output: 0
 *
 * Constraints:
 * 0 <= haystack.length, needle.length <= 5 * 104
 * haystack and needle consist of only lower-case English characters.
 *
 **********************************************************************************************************/

// Plain Search
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;
        for (int i = 0; i + m <= n; ++ i) {
            bool flag = true;
            for (int j = 0; j < m; ++ j) {
                if(haystack[i + j] != needle[j]) {  // Matching failure, stop immediately
                    flag = false;
                    break;
                }
            }
            if (flag) return i;   
        }
        return -1;
    }
};

// KMP
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;
        string s = ' ' + haystack, p = ' ' + needle;
        vector<int> next(m + 1);
        // Initialize the Next array, the whole process is only related to the matching string
        // j starts at 0, and j + 1 is compared with i, so i starts at 2
        for (int i = 2, j = 0; i <= m; ++ i) {
            while (j != 0 && p[j + 1] != p[i]) j = next[j];
            if (p[j + 1] == p[i]) j ++ ;
            next[i] = j;
        }
        // Matching process with the original string
        for (int i = 1, j = 0; i <= n; ++ i) {
            while (j != 0 && p[j + 1] != s[i]) j = next[j];
            if (p[j + 1] == s[i]) j ++ ;
            if (j == m) return i - m;
        }
        return -1;
    }
};



 
 
